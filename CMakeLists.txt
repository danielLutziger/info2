cmake_minimum_required(VERSION 3.24)
project(test C)

set(CMAKE_C_STANDARD 11)

add_library(test library.c week0/ex0.c week1/ex2.c week1/ex2_sol.c week3/ex4.c week0/PrimeNumbers.c week0/LinearSearch.c week0/SelectionSort.c week0/InsertionSort.c week0/BubbleSort.c week0/FactorialRecursion.c week0/OddEvenRecursion.c week0/RulerRecursion.c week0/SierpinskiRecursion.c week0/HilbertRecursion.c week0/SierpinskiCurveRecursion.c week0/HilbertRecursion.c week1/RecursiveAlgo.cpp week1/FrequencyCountMethod.c week1/Gcd.c week6/BinarySearchTree.c week1/ArrayReductionRecursion.c week1/HanoiRecursion.c week2/ex3_21.c week3/ex4_2.c week3/MergeSort.c week4/HeapSort.c week4/ex5.c week4/Heap.c)
