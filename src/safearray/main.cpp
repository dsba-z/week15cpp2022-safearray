﻿/*! \file       main.cpp
 *  \author     Sergey Shershakov
 *  \version    0.1
 *  \date       06.02.2020
 *
 *  →
 */

#include <iostream>
#include <stdexcept>
#include <cassert>
#include <iomanip>

#include "safe_array.hpp"


void test1()
{
    SafeArray<int> arr1;
    assert(arr1.getSize() == 0);
    assert(arr1.getPtr() == nullptr);
}


void test2()
{
    SafeArray<int> arr1(5, 42);
    assert(arr1.getSize() == 5);
    assert(arr1.getPtr() != nullptr);
    assert(arr1[0] == 42);
    assert(arr1.at(4) == 42);
}


void test3()
{
    // check uniform inititalization
    int a;
    int b{};
    int c = int();

    SafeArray<int> arr1;
    assert(arr1.getSize() == 0);
    assert(arr1.getPtr() == nullptr);

    arr1.resize(6, 42);
    assert(arr1.getSize() == 6);
    assert(arr1.getPtr() != nullptr);
    assert(arr1[0] == 42);
    assert(arr1.at(5) == 42);
}

void test4()
{
    SafeArray<int> arr1(5, 42);
    assert(arr1.getSize() == 5);
    assert(arr1.getPtr() != nullptr);
    assert(arr1[0] == 42);
    assert(arr1.at(4) == 42);

    // new array — copied
    SafeArray<int> arr2 = arr1;      // arr2(arr1)

    assert(arr2.getSize() == 5);
    assert(arr2.getPtr() != nullptr);
    assert(arr2[0] == 42);
    assert(arr2.at(4) == 42);

    // check that this is another memory
    arr2[0] = 43;
    arr2.at(4) = 43;
    assert(arr2[0] == 43);
    assert(arr2.at(4) == 43);

    // initial must be the same
    assert(arr1[0] == 42);
    assert(arr1.at(4) == 42);
}


void test5()
{
    SafeArray<int> arr1(5, 42);
    assert(arr1.getSize() == 5);
    assert(arr1.getPtr() != nullptr);
    assert(arr1[0] == 42);
    assert(arr1.at(4) == 42);

    // new array
    SafeArray<int> arr2(1, 10);
    arr2 = arr1;
    assert(arr2[0] == 42);
    assert(arr2.at(4) == 42);
}


void test6()
{
    SafeArray<int> arr1( {10, 20, 30} );
    assert(arr1.getSize() == 3);
    assert(arr1.getPtr() != nullptr);
    assert(arr1[0] == 10);
    assert(arr1.at(2) == 30);

    std::cout << arr1 << '\n';
}


int main()
{
//    test1();
//    test2();
//    test3();
//    test4();        // copy constr
//    test5();        // copy assgn op
//    test6();        // const initial list


    return 0;
}
