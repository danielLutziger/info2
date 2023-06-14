cmake_minimum_required(VERSION 3.24)
project(test C)

set(CMAKE_C_STANDARD 11)

add_library(test library.c exercises/ex0.c exercises/ex2.c exercises/ex2_sol.c exercises/ex4.c structures/PrimeNumbers.c searching/LinearSearch.c sorting/SelectionSort.c sorting/InsertionSort.c sorting/BubbleSort.c recursions/FactorialRecursion.c recursions/OddEvenRecursion.c recursions/RulerRecursion.c recursions/SierpinskiRecursion.c recursions/HilbertRecursion.c recursions/SierpinskiCurveRecursion.c recursions/HilbertRecursion.c recursions/RecursiveAlgo.cpp exercises/FrequencyCountMethod.c recursions/Gcd.c searching/BinarySearchTree.c recursions/ArrayReductionRecursion.c recursions/HanoiRecursion.c exercises/ex3_21.c exercises/ex4_2.c sorting/MergeSort.c sorting/HeapSort.c exercises/ex5.c sorting/Heap.c sorting/QuickSort.c exercises/ex5_qs.c structures/Structures.c structures/Pointers.c structures/StructuresWithPointers.c)
