cmake_minimum_required(VERSION 3.24)
project(test C)

set(CMAKE_C_STANDARD 11)

add_library(test library.c week0/ex0.c week1/ex2.c week1/ex2_sol.c week3/ex4.c week0/PrimeNumbers.c week0/LinearSearch.c week0/SelectionSort.c week0/InsertionSort.c week0/BubbleSort.c week0/FactorialRecursion.c week0/OddEvenRecursion.c week0/RulerRecursion.c week0/SierpinskiRecursion.c week0/HilbertRecursion.c week0/SierpinskiCurveRecursion.c week0/HilbertRecursion.c week1/RecursiveAlgo.cpp week1/FrequencyCountMethod.c)
