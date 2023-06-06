# Table of content
## Algorithms
- Linear search
- Bubble sort
# Linear search
#### pseudo code:
```
LinSearch1(A,v): 
p = NILL;
for i = 1 t on do
    if A[i] == v then p = 1;
return p
```
```
LinSearch2(A,v): 
i = 1;
while i <= n && A[i] != v {i++}
if i<= n then return i;
else return NIL;
```

> LinSearch2 is more efficient as it does not scan the whole array. LinSearch2 returns the first value found, LinSearch1 returns the last value found.

# Bubblesort
#### pseudo code
```
BubbleSort(A):
for i = n to 2 do
  for j = 2 to i do
    if A[j] < A[j-1] then
      t = A[j]
      A[j] = A[j-1]
      A[j-1] = t
```
> elements are moved to the right

Implementation: week0/BubbleSort.c

Working:
```
a = {15, 16, 12, 29, 52, 243, 234, 43, 12, 1}
// iteration 1 
a = {15, *12*, 16, 29, 52, 234, 43, 12, 1, *243*}
// iteration 2 
a = {*12*, 15, 16, 29, 52, 43, 12, 1, *234*, 243}
// iteration 3
a = {12, 15, 16, 29, 43, 12, 1, *52*, 234, 243}
// iteration 4
a = {12, 15, 16, 29, 12, 1, *43*, 52, 234, 243}
// iteration 5
a = {12, 15, 16, 12, 1, *29*, 43, 52, 234, 243}
// iteration 6
a = {12, 15, 12, 1, *16*, 29, 43, 52, 234, 243}
// iteration 7
a = {12, 12, 1, *15*, 16, 29, 43, 52, 234, 243}
// iteration 8
a = {12, 1, *12*, 15, 16, 29, 43, 52, 234, 243}
// iteration 9
a = {1, *12*, 12, 15, 16, 29, 43, 52, 234, 243}
```
### Number of comparisons
- `(n^2-n)/2` 
### Number of moves (swaps)
- `Mmin = 0`
- `Mmax = 3(n^2-n)/2 = (3n^2 -3n) / 2`

(as the swap requires 3 moves)
# Selection sort
```
SelectionSort(A)
for i = 1 to n-1
  k = i;
  for j = i+1 to n
    if A[j] < A[k] then k = j
  swap A[i] and A[k]
```
> select the smallest element and exchange it with the first / current position
### Number of comparisons
- `(n^2-n)/2`
### Number of moves (swaps)
- `3n-3`
> always moving but less than in bubble sort

# Insertion sort
```
InsertionSort(A)
for i = 2 to n 
  j = i-1
  t = A[i]
  while j >= 1 and t < A[j]
    A[j+1] = A[j]
    j = j-1
  A[j+1] = t
```
### Number of comparisons
- `Cmin = n-1 //already sorted` 
- `CMax = (n^2-n)/2`
### Number of moves (swaps)
- `Mmin = 2n-2`
- `Mmax = (n^2+3n-4)/2`
> has the best performance when already sorted but the worst when sorted in opposite direction

# Recursion
## Hilbert Curve
Formula for the length of the curve in a 1x1:
- Order 1: 2^1-1/2^1 = 1.5 (3 lines of 0.5)
- Order 2: 2^2-1/2^2
- Order 3: 2^3-1/2^3
- Formula: 2^n-1/2^n
> Distance calculation: SizeOfSquare * 2^Depth-1/2^n

For a 5x5cm field and 15th depth: 163840

## Sierpinski Curve
## Sierpinski Triangle

# Complexity
## Asymptotic Complexity
## 
## Master theorem
##

# Data structures
## 
### Strength
### Limitations
## 
### Strength
### Limitations
...