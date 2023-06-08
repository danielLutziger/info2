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
## Arithmetic complexity 
- Identify each line of code and it's complexity and calculate all the lines of code together
- examples below show part of the arithmetic but mostly asymptotic complexity => for more examples check out this file
- week1/FrequencyCountMethod.c
## Asymptotic complexity
##### Time complexity code examples
```
for(int i = 0; i < n; i++){     // n + 1 
    someStatement;              // n
}
=> O(n)

for(int i = 1; i < n; i++){     // n 
    someStatement;              // n-1
}
=> O(n)

for(int i = 1; i < n; i+2){
    someStatement;              // n/2
}
=> O(n)

for(int i = 1; i < n; i+20){ 
    someStatement;              // n/20
}
=> O(n)
```
> As long as it is "< n" => time will be polynomial not constant

##### Loop in loop
```
for(i = 0; i < n; i++)          // n + 1
    for(j = 0; j < n; j++)      // n (n + 1)
        someStatement;          // n * n
=> O(n^2)
```

##### Loop in loop smaller first loop
```
for(i = 0; i < n; i++)          // n + 1
    for(j = 0; j < i; j++)      // n (n + 1)
        someStatement;          // n * n

=> After tracing executions
=> f(n) = 1+2+3+4...+n = n(n+1)/2 => (n^2 + 1)/2
=> O(n) = n^2
```
> Tracing executions for j < i:
 
| i |             j             | # executions |
|---|:-------------------------:|-------------|
| 0 |          0 stop           |            0 |
| 1 |    0<br/>1 stop           |            1 |
| 2 |  0<br/>1<br/>2 stop<br/>  |            2 |
| 3 | 0<br/>1<br/>2<br/>3 stop  |            3 |

##### Loop condition terminates based on outside variable
```
p = 0
for(i = 1; p <= n; i++)          // 
    p = p+i;
    
=> Assume p > n
since p = k(k+1)/2 (from tracing table)
k(k+1)/2 > n        => k^2
k^2 > n
k > sqrt(n)
=> O(sqrt(n))
```
> Tracing executions for i and p:

| i |      p       | # executions |
|---|:------------:|--------------|
| 1 |     0+1      | 1            |
| 2 |     1+2      | 2            |
| 3 |     3+3      | 3            |
| 4 |     6+4      | ...         |
| k | 1+2+3+4...+k | k         |

##### Loop terminating based on multiplication
> Always O(log(n)) (ceel value)
```
for(i = 1; i < n; i = i*2){
    statement;
}

Assume i >= n
since i = 2^k
2^k >= n
2^k = n
k = log2(n)
=> O(log(n))
```
> Tracing executions for i:

|        i         |
|:----------------:|
|        1         |
|    1 * 2  = 2    |
|  2 * 2   = 2^2   |
| 2^2 * 2    = 2^3 |
|       2^k        |

##### Loop terminating based on division
> Always O(log(n)) (ceel value)
```
for(i = n; i >= 1; i = i/2){
    statement;
}

Assume i < 1
since n/2^k < 1
n/2^k < 1
n/2^k = 1
k = log2(n) //base 2
=> O(log(n))
```
> Tracing executions for i:

|   i   |
|:-----:|
|   n   |
|  n/2  |
| n/2^2 |
| n/2^3 |
| n/2^k |
##### LogLog loop

```
p = 0;
for(i = 1; i < n; i = i*2){
    p++;            // log(n)
}
for(j = 1; j < p; j = j*2){
    statement;      // log(p)
}

=> O(loglog(n))
```
> p is evaluated in first loop => loglog(n)

##### nLog loop

```
for(i = 0; i < n; i = i++){         // n + 1
    for(j = 1; j < n; j = j*2){     // n * log(n) + 1
        statement;                  // n * log(n)
    }
}

f(n) = 2n*log(n) + 2
=> O(n*log(n))
```
|         function         | complexity        |
|:------------------------:|-------------------|
|   `for(i=0; i<n; i++)`   | `O(n)`            |
|  `for(i=0; i<n; i=i+2)`  | `n/2` => `O(n)`   |
| `for(i=0; i<n; i=i+200)` | `n/200` => `O(n)` |
|   `for(i=0; i<n; i--)`   | `O(n)`            |
|  `for(i=0; i<n; i=i*2)`  | `O(log2(n))`      |
|  `for(i=0; i<n; i=i*3)`  | `O(log3(n))`      |
|  `for(i=n; i>1; i=i/2)`  | `O(log2(n))`      |


#### while loop complexity
> same as the for loops, no biggie
```
i = 0;          // 1
while (i < n){  // n + 1
    statemetn;  // n
    i++;        // n 
}
f(n) = 3n + 2 => O(n)
```

```
a = 1;
while (a < b){  
    statemetn;  
    a = a*2;        // same as for loop     
}

Assume that 2^k > b
since 2^k > b
2^k = b
k = log2(b)
=> O(log2(n))
```
|   a   |
|:-----:|
|   1   |
|   2   |
|  2^2  |
| 2^3 |
| 2^k |

```
a = n;
while (a > b){  
    statemetn;  
    a = a/2;        // same as for loop     
}
```

```
i = 1
k = 1;
while (k < n){  
    statemetn;  
    k = k+i;
    i++;     
}

Assume that k >= n
k = m(m+1)/2
m(m+1)/2 >= n       //for degree of order (O(?))
m^2 >= n
m = sqrt(n)

=> O(sqrt(n))
```
| i |             k             |
|:-:|:-------------------------:|
| 1 |             1             |
| 2 |          1+1 = 2          |
| 3 |            2+2            |
| 4 |           2+2+3           |
| 5 |          2+2+3+4          |
| m | 2+2+3+4...+m = `m(m+1)/2` |

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