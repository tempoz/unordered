
//  Copyright Daniel James 2006. Use, modification, and distribution are
//  subject to the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "./containers.hpp"

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/exception_safety.hpp>
#include <string>
#include "../helpers/random_values.hpp"
#include "../helpers/invariants.hpp"
#include "../helpers/strong.hpp"

#include <iostream>

template <class T>
struct rehash_test_base : public test::exception_base
{
    test::random_values<T> values;
    unsigned int n;
    rehash_test_base(unsigned int count = 100, unsigned int n = 0) : values(count), n(n) {}

    typedef T data_type;
    typedef test::strong<T> strong_type;

    data_type init() const {
        T x(values.begin(), values.end(), n);
        return x;
    }

    void check(T const& x, strong_type const& strong) const {
        std::string scope(test::scope);

        if(scope.find_first_of("hash::operator()") == std::string::npos &&
                scope.find_first_of("equal_to::operator()") == std::string::npos)
            strong.test(x);
        test::check_equivalent_keys(x);
    }
};

template <class T>
struct rehash_test0 : rehash_test_base<T>
{
    rehash_test0() : rehash_test_base<T>(0) {}
    void run(T& x) const { x.rehash(0); }
};

template <class T>
struct rehash_test1 : rehash_test_base<T>
{
    rehash_test1() : rehash_test_base<T>(0) {}
    void run(T& x) const { x.rehash(200); }
};

template <class T>
struct rehash_test2 : rehash_test_base<T>
{
    rehash_test2() : rehash_test_base<T>(0, 200) {}
    void run(T& x) const { x.rehash(0); }
};

template <class T>
struct rehash_test3 : rehash_test_base<T>
{
    rehash_test3() : rehash_test_base<T>(10, 0) {}
    void run(T& x) const { x.rehash(200); }
};

template <class T>
struct rehash_test4 : rehash_test_base<T>
{
    rehash_test4() : rehash_test_base<T>(10, 200) {}
    void run(T& x) const { x.rehash(0); }
};

RUN_EXCEPTION_TESTS(
    (rehash_test0)(rehash_test1)(rehash_test2)(rehash_test3)(rehash_test4),
    CONTAINER_SEQ)