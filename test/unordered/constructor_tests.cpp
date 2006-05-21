
//  Copyright Daniel James 2006. Use, modification, and distribution are
//  subject to the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>
#include <boost/detail/lightweight_test.hpp>
#include "../objects/test.hpp"
#include "../helpers/random_values.hpp"
#include "../helpers/tracker.hpp"
#include "../helpers/equivalent.hpp"

#include <iostream>

template <class T>
void constructor_tests1(T* = 0)
{
    typename T::hasher hf;
    typename T::key_equal eq;
    typename T::allocator_type al;

    std::cerr<<"Construct 1\n";
    {
        T x(0, hf, eq);
        BOOST_TEST(x.empty());
        BOOST_TEST(x.bucket_count() >= 0);
        BOOST_TEST(test::equivalent(x.hash_function(), hf));
        BOOST_TEST(test::equivalent(x.key_eq(), eq));
        BOOST_TEST(test::equivalent(x.get_allocator(), al));
    }

    std::cerr<<"Construct 2\n";
    {
        T x(100, hf);
        BOOST_TEST(x.empty());
        BOOST_TEST(x.bucket_count() >= 100);
        BOOST_TEST(test::equivalent(x.hash_function(), hf));
        BOOST_TEST(test::equivalent(x.key_eq(), eq));
        BOOST_TEST(test::equivalent(x.get_allocator(), al));
    }

    std::cerr<<"Construct 3\n";
    {
        T x(2000);
        BOOST_TEST(x.empty());
        BOOST_TEST(x.bucket_count() >= 2000);
        BOOST_TEST(test::equivalent(x.hash_function(), hf));
        BOOST_TEST(test::equivalent(x.key_eq(), eq));
        BOOST_TEST(test::equivalent(x.get_allocator(), al));
    }

    std::cerr<<"Construct 4\n";
    {
        T x;
        BOOST_TEST(x.empty());
        BOOST_TEST(test::equivalent(x.hash_function(), hf));
        BOOST_TEST(test::equivalent(x.key_eq(), eq));
        BOOST_TEST(test::equivalent(x.get_allocator(), al));
    }

    std::cerr<<"Construct 5\n";
    {
        test::random_values<T> v(1000);
        T x(v.begin(), v.end(), 10000, hf, eq);
        BOOST_TEST(x.bucket_count() >= 10000);
        BOOST_TEST(test::equivalent(x.hash_function(), hf));
        BOOST_TEST(test::equivalent(x.key_eq(), eq));
        BOOST_TEST(test::equivalent(x.get_allocator(), al));
        check_container(x, v);
    }

    std::cerr<<"Construct 6\n";
    {
        test::random_values<T> v(10);
        T x(v.begin(), v.end(), 10000, hf);
        BOOST_TEST(x.bucket_count() >= 10000);
        BOOST_TEST(test::equivalent(x.hash_function(), hf));
        BOOST_TEST(test::equivalent(x.key_eq(), eq));
        BOOST_TEST(test::equivalent(x.get_allocator(), al));
        check_container(x, v);
    }

    std::cerr<<"Construct 7\n";
    {
        test::random_values<T> v(100);
        T x(v.begin(), v.end(), 100);
        BOOST_TEST(x.bucket_count() >= 100);
        BOOST_TEST(test::equivalent(x.hash_function(), hf));
        BOOST_TEST(test::equivalent(x.key_eq(), eq));
        BOOST_TEST(test::equivalent(x.get_allocator(), al));
        check_container(x, v);
    }

    std::cerr<<"Construct 8\n";
    {
        test::random_values<T> v(1);
        T x(v.begin(), v.end());
        BOOST_TEST(test::equivalent(x.hash_function(), hf));
        BOOST_TEST(test::equivalent(x.key_eq(), eq));
        BOOST_TEST(test::equivalent(x.get_allocator(), al));
        check_container(x, v);
    }

    std::cerr<<"Construct 9\n";
    {
        T x(0, hf, eq, al);
        BOOST_TEST(x.empty());
        BOOST_TEST(x.bucket_count() >= 0);
        BOOST_TEST(test::equivalent(x.hash_function(), hf));
        BOOST_TEST(test::equivalent(x.key_eq(), eq));
        BOOST_TEST(test::equivalent(x.get_allocator(), al));
    }

    std::cerr<<"Construct 10\n";
    {
        test::random_values<T> v(1000);
        T x(v.begin(), v.end(), 10000, hf, eq, al);
        BOOST_TEST(x.bucket_count() >= 10000);
        BOOST_TEST(test::equivalent(x.hash_function(), hf));
        BOOST_TEST(test::equivalent(x.key_eq(), eq));
        BOOST_TEST(test::equivalent(x.get_allocator(), al));
        check_container(x, v);
    }
}

template <class T>
void constructor_tests2(T* = 0)
{
    typename T::hasher hf;
    typename T::hasher hf1(1);
    typename T::hasher hf2(2);
    typename T::key_equal eq;
    typename T::key_equal eq1(1);
    typename T::key_equal eq2(2);
    typename T::allocator_type al;
    typename T::allocator_type al1(1);
    typename T::allocator_type al2(2);

    std::cerr<<"Construct 1\n";
    {
        T x(10000, hf1, eq1);
        BOOST_TEST(x.bucket_count() >= 10000);
        BOOST_TEST(test::equivalent(x.hash_function(), hf1));
        BOOST_TEST(test::equivalent(x.key_eq(), eq1));
        BOOST_TEST(test::equivalent(x.get_allocator(), al));
    }

    std::cerr<<"Construct 2\n";
    {
        T x(100, hf1);
        BOOST_TEST(x.empty());
        BOOST_TEST(x.bucket_count() >= 100);
        BOOST_TEST(test::equivalent(x.hash_function(), hf1));
        BOOST_TEST(test::equivalent(x.key_eq(), eq));
        BOOST_TEST(test::equivalent(x.get_allocator(), al));
    }

    std::cerr<<"Construct 3\n";
    {
        test::random_values<T> v(100);
        T x(v.begin(), v.end(), 0, hf1, eq1);
        BOOST_TEST(test::equivalent(x.hash_function(), hf1));
        BOOST_TEST(test::equivalent(x.key_eq(), eq1));
        BOOST_TEST(test::equivalent(x.get_allocator(), al));
        check_container(x, v);
    }

    std::cerr<<"Construct 4\n";
    {
        test::random_values<T> v(5);
        T x(v.begin(), v.end(), 1000, hf1);
        BOOST_TEST(x.bucket_count() >= 1000);
        BOOST_TEST(test::equivalent(x.hash_function(), hf1));
        BOOST_TEST(test::equivalent(x.key_eq(), eq));
        BOOST_TEST(test::equivalent(x.get_allocator(), al));
        check_container(x, v);
    }


    std::cerr<<"Construct 5\n";
    {
        test::random_values<T> v(100);
        T x(v.begin(), v.end(), 0, hf, eq, al1);
        T y(x.begin(), x.end(), 0, hf1, eq1, al2);
        check_container(x, v);
        check_container(y, x);
    }

    std::cerr<<"Construct 6\n";
    {
        test::random_values<T> v(100);
        T x(v.begin(), v.end(), 0, hf1, eq1);
        T y(x.begin(), x.end(), 0, hf, eq);
        check_container(x, v);
        check_container(y, x);
    }

    std::cerr<<"Construct 7\n";
    {
        test::random_values<T> v(100);
        T x(v.begin(), v.end(), 0, hf1, eq1);
        T y(x.begin(), x.end(), 0, hf2, eq2);
        check_container(x, v);
        check_container(y, x);
    }
}

int main()
{
    std::cerr<<"Test1 unordered_set<int>\n";
    constructor_tests1((boost::unordered_set<int>*) 0);
    std::cerr<<"Test1 unordered_multiset<int>\n";
    constructor_tests1((boost::unordered_multiset<int>*) 0);
    std::cerr<<"Test1 unordered_map<int, int>\n";
    constructor_tests1((boost::unordered_map<int, int>*) 0);
    std::cerr<<"Test1 unordered_multimap<int, int>\n";
    constructor_tests1((boost::unordered_multimap<int, int>*) 0);

    std::cerr<<"Test1 unordered_set<test::object>\n";
    constructor_tests1((boost::unordered_set<test::object, test::hash, test::equal_to, test::allocator<test::object> >*) 0);
    std::cerr<<"Test1 unordered_multiset<test::object>\n";
    constructor_tests1((boost::unordered_multiset<test::object, test::hash, test::equal_to, test::allocator<test::object> >*) 0);
    std::cerr<<"Test1 unordered_map<test::object, test::object>\n";
    constructor_tests1((boost::unordered_map<test::object, test::object, test::hash, test::equal_to, test::allocator<test::object> >*) 0);
    std::cerr<<"Test1 unordered_multimap<test::object, test::object>\n";
    constructor_tests1((boost::unordered_multimap<test::object, test::object, test::hash, test::equal_to, test::allocator<test::object> >*) 0);

    std::cerr<<"Test2 unordered_set<test::object>\n";
    constructor_tests2((boost::unordered_set<test::object, test::hash, test::equal_to, test::allocator<test::object> >*) 0);
    std::cerr<<"Test2 unordered_multiset<test::object>\n";
    constructor_tests2((boost::unordered_multiset<test::object, test::hash, test::equal_to, test::allocator<test::object> >*) 0);
    std::cerr<<"Test2 unordered_map<test::object, test::object>\n";
    constructor_tests2((boost::unordered_map<test::object, test::object, test::hash, test::equal_to, test::allocator<test::object> >*) 0);
    std::cerr<<"Test2 unordered_multimap<test::object, test::object>\n";
    constructor_tests2((boost::unordered_multimap<test::object, test::object, test::hash, test::equal_to, test::allocator<test::object> >*) 0);

    return boost::report_errors();
}