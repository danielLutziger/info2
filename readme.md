Lol guys I passed. So this stuff here is actually useful. 

# Table of content
## Algorithms
- Linear search
- Bubble sort
# Linear search
#### pseudo code:
```c
LinSearch1(A,v): 
p = NILL;
for i = 1 t on do
    if A[i] == v then p = 1;
return p
```
```c
LinSearch2(A,v): 
i = 1;
while i <= n && A[i] != v {i++}
if i<= n then return i;
else return NIL;
```

> LinSearch2 is more efficient as it does not scan the whole array. LinSearch2 returns the first value found, LinSearch1 returns the last value found.

# Bubblesort
#### pseudo code
```c
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
```c
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
```c
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
```c
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
```c
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
```c
for(i = 0; i < n; i++)          // n + 1
    for(j = 0; j < n; j++)      // n (n + 1)
        someStatement;          // n * n
=> O(n^2)
```

##### Loop in loop smaller first loop
```c
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
```c
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
| 4 |     6+4      | ...          |
| k | 1+2+3+4...+k | k            |

##### Loop terminating based on multiplication
> Always O(log(n)) (ceel value)
```c
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
```c
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

```c
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

```c
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
```c
i = 0;          // 1
while (i < n){  // n + 1
    statemetn;  // n
    i++;        // n 
}
f(n) = 3n + 2 => O(n)
```

```c
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

```c
a = n;
while (a > b){  
    statemetn;  
    a = a/2;        // same as for loop     
}
```

```c
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

#### if-loop complexity
```c
if(n<5) printf("something");        // 1
else{
    for(i = 0; i < n; i++){printf("pp");}   // n + 1
}

=> best O(1)
=> worst O(n)
```
### Big O
O(f(n)) => indicates the upper bound (do not mix it up with worst runtime!)
-  f(n) = O(g(n)) if and only if there exist constants c > 0 and n0 > 0 such that f(n) ≤ cg(n) for n ≥ n0

```c
2^n+1 = O(2^n) holds true
    n = 1
    c = 2
    2^n+1 <= c*2^n
    2^1+1 <= 2*2^1
    4 <= 4

2^2^n = O(2^n) x false
    2^2^n grows exponentially faster than 2^n

2n^1.5 = O(n log(n)) x false
    for enough n, n^3/2 > n log n 
```
### Theta
Θ(g(n)) => indicates the average runtime 
- f(n) = Θ(g(n)) if and only if there exist constants c1 > 0,
  c2 > 0, and n0 > 0 such that c1g(n) ≤ f(n) ≤ c2g(n) for
  n ≥ n0
-  f(n) = Θ(g(n)) iff f(n) = O(g(n)) and f(n) = Ω(g(n))

### Omega
Ω(h(n)) => indicates the lower bound (do not mix this up with best runtime!)
- f(n) = Ω(g(n)) if and only if there exist constants c > 0
  and n0 > 0 such that cg(n) ≤ f(n) for n ≥ n0

|           f(n)            |                     Big O                      |                                      Theta                                      |        Omega         |
|:-------------------------:|:----------------------------------------------:|:-------------------------------------------------------------------------------:|:--------------------:|
|         2n^2+3n+4         | <=2n^2+3n^2+4n^2<br/>2n^2+3n+4<=9n^2 => O(n^2) |                             1n^2 <= 9n^2 => O(n^2)                              | <=1n^2 => Omega(n^2) |
|        n^2log(n)+n        |        <=10n^2log(n)+n => O(n^2*log(n))        |                                  O(n^2*log(n))                                  |    O(n^2*log(n))     |
|   n!  = n*(n-1)*(n-2)..   |                     O(n^n)                     | No theta possible<br/>Smaller values are closer to omega, large closer to big O |         O(1)         |
| log(n!) = log(1*2*3...*n) |                  O(n*log(n))                   |                           Same again. No tight bound.                           |         O(1)         |

> Theta is preferred if possible. Always give the nearest value

#### Properties & Asymptotic notations
##### General Properties
- if f(n) is O(g(n)) then a*f(n) is O(g(n))

Example:
```c
f(n) = 2n^2 + 5 is O(n^2)
then 7*f(n) = 7*(2n^2 + 5) = 14n^2+35 => O(n^2)
```
> True for Big O, Omega and Theta

##### Transitivity
- if f(n) is O(g(n)) and g(n) is O(h(n)) then f(n) = O(h(n))
```c
f(n) = n || g(n) = n^2 || h(n) = n^3
n is O(n^2) and n^2 is O(n^3)
then n is O(n^3)
```
##### Reflexivity
- if f(n) is given then f(n) is O(f(n))
```c
f(n) = n^2 => O(n^2)
```
##### Symmetric
- if f(n) is Θ(g(n)) then g(n) is Θ(f(n))
```c
f(n) = n^2 || g(n) = n^2 
=> Θ(n^2)
```
> Only for Theta notation
##### Transpose symmetric
- if f(n) = O(g(n)) then g(n) is Ω(f(n))
```c
f(n) = n || g(n) = n^2
then n is O(n^2) and n^2 is Ω(n)
```
> True for big O and omega Ω

```c
if f(n) = O(g(n))
and d(n) = O(e(n))
then f(n) + d(n) = O(max(g(n), e(n))

specific example:
f(n) = n
d(n) = n^2
f(n) + d(n) = n + n^2 => O(n^2)
```

```c
if f(n) = O(g(n))
and d(n) = O(e(n))
then f(n) * d(n) = O(g(n)*e(n))
```
### Function comparison and prove
- use numbers to see which one is bigger
  - | n | n^2 | n^3 |
    |:-:|:---:|:---:|
    | 5 | 25  | 125 |

- apply log on each side
  - |         n^2         |         n^3         |
    |:-------------------:|:-------------------:|
    | log(n^2) = 2*log(n) | log(n^3) = 3*log(n) |
### Best, worst and average analysis
#### Linear Search
```c
A[] = {8,6,12,5,9,7,4,3,16,18}
search = 7

for(int i = 0; i < A.length; i++){
    if(search == A[i]) return i;
}
return NILL;
```
> Best case: Searching key element at P1 => best case time is constant O(1), Θ(1), Ω(1) (notation in this case does not matter as the time will always be constant in the best case)
 
> Worst Case: Searching element not in array => worst case O(n), Θ(n), Ω(n) (notation in this case does not matter as the time will always be polynomial in the worst case)
 
> Average A(n): Searching an element somewhere in the middle => (n+1)/2 => average Θ(n)

#### Binary Search Tree
```c
Balanced BST:
             50             | height log(n)
           /     \          |
          30      70        |
         /  \    /  \       |
       20   40  60   80     |

Skewed BST (aka a list): 
        80                  | height n
        /                   |
       70                   | 
       /                    |
      60                    |
      /                     |
     50                     |
     /                      |
    40                      |
    /                       |
   30                       |
   /                        |
  20                        |

// structure for BST
struct node* {
    int key;
    struct node *left, *right;
}
```
> Best case: Searching root element => constant time => O(1)

> Worst Case: Searching for leaf elements: </br><b>Minimum Worst case time</b> (balanced) = log(n);</br><b>Maximum worst case time</b>: n


## Time Complexity for recursive functions - recurrence relation
```c
void Test(int n){ 
    if (n > 0){
        printf("%d", n);        // 1 unit of time
        Test(n-1);
    }
}
```
|     Tracing tree / recursive tree: Calls      |
|:---------------------------------------------:|
|     Test(3)<br/>print 3<br/> Call Test(2)     |
|     Test(2)<br/>print 2<br/> Call Test(1)     |
|     Test(1)<br/>print 1<br/> Call Test(0)     |
|               Test(0)<br/>stop                |
| n+1 calls<br/>n prints<br/>f(n) = n+1 => O(n) |

```c
void Test(int n){               // T(n) = T(n-1)+1  
    if (n > 0){
        printf("%d", n);        // 1 unit of time
        Test(n-1);              // T(n-1)
    }
}
        /   1               n = 0
T(n) = {
        \   T(n-1) + 1      n > 0
```
> Substitution method
> ```c
> T(n) = T(n-1) + 1
> T(n-1) = T(n-2) + 1
> Substitute T(n-1)
> T(n) = [T(n-2)+1]+1
> T(n) = T(n-2)+2
> T(n) = [T(n-3)+1]+2
> T(n) = T(n-3) + 3
> ... continue for k times
> T(n) = T(n-k) + k     => Assume n-k = 0
> therefore, n = k
> => T(n) = T(n-n) + n
> T(n) = T(0) + n
> T(n) = 1 + n => O(n)
> ```

#### Loop in recurrence
```c
void Test(int n){                       // T(n)  
    if (n > 0){                         // 1
        for(int i = 0; i < n; i++){     // n+1
            printf("%d", n);            // n
        }
        Test(n-1);                      // T(n-1)
    }
}

Recurrence relation:
        /   1                    n = 0
T(n) = {
        \   T(n-1) + 2n + 2      n > 0

T(n-1) + 2n + 2 => form is complicated, take asymptotic notation
T(n) = T(n-1) + n
        /   1                n = 0
T(n) = {
        \   T(n-1) + n       n > 0
```
> Recursion tree
> ```c
>    T(n)                       // n
>    / \    
>   n  T(n-1)                   // n-1
>       /  \
>     n-1   T(n-2)              // n-2
>            / \
>         n-2   T(n-3)... until T(0)
> 
> Time used: 0+1+2+3...+n-2+n-1+n = n(n+1)/2
> T(n) = n(n+1)/2 => O(n^2)
> ```

> Backsubstitution
> ```c
>         /   1                n = 0
> T(n) = {
>         \   T(n-1) + n       n > 0
> 
> T(n) = T(n-1) + n
> since T(n) = T(n-1) + n
> T(n-1) = T(n-2) + n - 1
> T(n) = [T(n-2) + n - 1] + n
> T(n) = T(n-2) + (n-1) + n
> T(n-2) = T(n-3) + n - 2
> T(n) = [T(n-3) + n - 2] + (n-1) + n
> T(n) = T(n-3) + (n-2) + (n-1) + n 
> T(n) = T(n-k) + (n-(k-1)) + (n-(k-2)) + (n-1) + n
> Assume n - k = 0 => n = k
> T(n) = T(n-n) + (n-n+1) + (n-n+2) + (n-1) + n
> T(n) = T(0) + 1 + 2 + 3...+n-1+n 
> T(n) = 1 + n(n+1)/2 => O(n^2)
> ```
#### Loop but log increase
```c
void Test(int n){                       // T(n)  
    if (n > 0){                         // 1
        for(int i = 0; i < n; i=i*2){   // log(n) + 1
            printf("%d", n);            // log(n)
        }
        Test(n-1);                      // T(n-1)
    }
}

         /   1                n = 0
 T(n) = {
         \   T(n-1) + log(n)  n > 0
```
> Recursion tree
> ```c
>    T(n)                       // log(n)
>    / \    
> logn  T(n-1)                  // log(n-1)
>       /  \
> log(n-1) T(n-2)              // log(n-2)
>            / \
>    log(n-2)   T(n-3)... until T(0)
>
> Time used: log(0)+log(1)+log(2)+log(n-1)+log(n) = n*log(n) 
> log[n*(n-1)*(n-2)...*2*1]
> T(n) = log(n!) => O(n*log(n))
> ```

### Master theorem
- Above were recurrence relations mentioned, together with substitution and tree methods. The 3rd method to find the recurrence of a (recursive ) algorithm is the master method.

Recurrence relation form:
```T(n) = aT(n/b) + f(n)```
- a >= 1
- b > 1
- f(n) asymptotically positive

> 3 different cases for the master theorem
> - running time dominated by cost at the root (case 3)
> - running time dominated by cost at the leaves (case 1)
> - running time dominated by  throughout the tree (case 2)

Solving the master theorem: compare logb(a) = f(n)
> - Case 1: logb(a) = f(n) => O(n^logb(a))
> - Case 2: logb(a) > f(n) => O(n^logb(a)*logb(n))
> - Case 3: logb(a) < f(n) => O(f(n))

Merge sort example:
```         c
        /  O(1)             if n = 1
T(n) = {
        \  2T(n/2) + O(n)   if n > 1
```
## MergeSort
```c
MergeSort(A, l, r){
    if(l<r){                    // more than 1 element
        m = (l+r)/2
        MergeSort(A,l,m)        // sort left part
        MergeSort(A,m+1,r)      // sort right part 
        Merge(A, l, r, m)       // actual merge
    }
}

Merge(A,l,r,m){
    for(int i = l; i < m; i++) B[i] = A[i];         //copy elements in a reverse order into a new array B
    for(int i = m+1; i < r; i++) B[r+m-i+1] = A[i]; // the new array will look like this: i= 1,2,3,4 | 9,8,7,6,5 = j
    i = l; j = r;
    
    for(int k = l; k < r; k++){ // merge the "partially inverse array B back into A"
        if(B[i] < B[j]){
            A[k] = B[i];
            i = i+1;
        }
        else {
            A[k] = B[j];
            j = j-1;
        }
    } 
}
```
## HeapSort
- complexity: O(nlog(n))
- build upon the selection sort with a smart data structure
  - =>maintain the data structure in time

> binary tree is a binary heap iff
>   - it is a nearly complete binary tree
>   - each node is greater than or equal to all its children: A[parent] >= A[i]
> 
> can be efficiently stored as an array

````c
HeapSort(A, n){
    s = n;
    BuildHeap(A);
    for(int i = n; i >= 2; i--){
        swap A[i] and A[1];
        s = s-1;
        Heapify(A, 1, s);
    }
}
````

### Algorithms for heaps and trees
````c
int Parent(int i){
    return i/2;
}
int Left(int i){
    return 2*i
}
int Right(int i){
    return 2*i+1
}
````

## Tree
- Each node may have a left or a right child
- each node has at most one parent
- root has no parent
- leaf has no children
- depth/level of a node is the length from the root to the node
  - root depth is 0
- height is the longest path from the position to a leaf
  - tree height = height of the root

### Complete binary tree
- all leaves have the same depth
- all internal nodes have 2 children => requires 2^k-1 children
- has no order of nodes

### Nearly complete binary tree
- all levels of non-maximal depth d are full (2^d nodes)
- all the leaves with maximal depth are as far left as possible

### MaxHeap
- largest element is at root node
  - used for sorting arrays
  - A[parent] >= A[i]
### MinHeap
- Smallest element is at root node
  - priority queues
  - A[parent] <= A[i]

### Heapify
- heapify transforms the binary tree rooted at i into a binary tree
- move A[i] down the heap until the heap property is satisfied  (push element down where larger element is)
> worst case performance of heapify is O(log(n))
> - occurs when imbalanced
````c
/**
 * @s = number of elements to look at
 */
Heapify(A, i, s){
    m = i;
    l = Left(i); //2*i
    r = Right(i); //2*i+1
    // left element exists && is larger than parent
    if(l <= s && A[l] > A[m]) 
        m = l;
    // right element exists && is larger than m
    if(r <=s && A[r] > A[m])
        m = r;
    if(i != m){
        // swap
        int t = A[i];
        A[i] = A[m];
        A[m] = t;
        Heapify(A, m, s)
    }
    
}
````

### BuildHeap
- convert an array of n elements into a heap
- complexity of O(n) where n is the height

````c
BuildHeap(A, n){
    for(int i = (n/2); i > 1; i--){
        Heapify(A, i, n);
    }
}
````

### Insert into Heap
- insert at last level
- move up level by level => log(n)
````c
void Insert(int A[], int n){
    int temp, i = n;
    temp = A[n];
    // copy temp value from new slot and compare with parent
    while(i > 1 && temp > A[i/2]){
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}
````

### Deleting from a Heap
- only root element can be deleted
  - place deleted element at free empty position in array (delete root element place at last element)
- move last element from heap into root position, compare children and replace with bigger one
- complexity: O(n*log(n))
  - delete 1 element: log(n)
  - delete all elements: n*log(n)
## Priority Queue
- Define priority for a priority queue => the larger element higher the priority
- insert = O(1)
- delete = O(n)
  - check all elements for max
  - shift all elements 
````c
A = [4,9,5,10,6,20,8];
````
> <b>Speed up a priority queue with a max heap
> Insert and delete will take O(log(n)) time </b>
> ```c
> A_as_max_heap = [20,9,10,4,6,5];
>```

## QuickSort
- idea: pivoting value and moving the i and j values
  - So called "partitioning procedure"
- Worst case time of quicksort: O(n^2) with a sorted list (asc or desc) (because of partitioning at the end / beginning)
- Best case (partitioning in the middle) / avg case time complexity: O(n*log(n))
- we could replace the middle element with the first and making it the pivot => this will make the best case the worst case, meaning quicksort works best on sorted lists, and worst on random lists
- randomized quicksort: select a random element as pivot

- quicksort vs selectionsort
- selection sort: select a position and find an element for that position (selection of index)
- quicksort: select an element and find a position for that element (selection of element: partition exchange sort, selection exchange sort, quicksort)
````c
pivot
|
50, 70, 60, 90, 40, 80, 10, 20, 30  infinity
i                                   j
     i---------------------------j
50, 30, 60, 90, 40, 80, 10, 20, 70 infinity
         i..................j
50, 30, 20, 90, 40, 80, 10, 60, 70 infinity
             i----------j
50, 30, 20, 10, 40, 80, 90, 60, 70 infinity // 40 < 90
                 i------j
50, 30, 20, 10, 40, 80, 90, 60, 70 infinity // 80 < 90
                     i--j
50, 30, 20, 10, 40, 80, 90, 60, 70 infinity // i will become > j
                         j---i
put 50 at j
(40, 30, 20, 10), (50), (80, 90, 60, 70)
````
> QuickSort is recursively applied to a subset of values 

### Partitioning in QuickSort

````c
int Partition(int A[], int i, int n){
    int pivot = A[l];
    int i = l, j = n;
    do{
        do{i++}while(A[i]<=pivot);
        do{j--}while(A[j]>pivot);
        if(i < j){
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }while(i < j);
    int t = A[l];
    A[l] = A[j];
    A[j] = t;
    return j;
}
````

# Data structures
## Linked lists
- insertion at beginning: O(1)
- insertion at end: O(n)
- isEmpty: O(1)
- delete: O(n)
- print: O(n)
> there can at most be one linked list (since you have to work with root) => ADT as solution


|                            Linked List                            |                  Binary Tree                  |
|:-----------------------------------------------------------------:|:---------------------------------------------:|
|                   Pointing to the next element                    |       Pointing to children (2 elements)       |
|                    Sort order does not matter                     |        children have to be < than root        |
|                       linear data structure                       |          hierarchical data structure          |
|              sequential traversal from head to tail               |   in-order, pre-order, post-order traversal   |
| Insertion: traversing form beginning to n element, time consuming | balanced tree more efficient due to structure |
| Searching: traversing form beginning to n element, time consuming | balanced tree more efficient due to structure |

## Stacks
- LIFO, last in first out
  - insert: LIFO
  - delete: LIFO, item which as been added last is deleted first
- operations
  - push: new element (insert)
    - at beginning of linked list
    - at end of array
  - pop: latest element (delete)
    - root of linked list
    - last element of array
## Queues
- FIFO, first in first out
  - insert: FIFO
  - delete: FIFO, item which has been the longest in the queue is deleted first
- operations
  - enqueue: new element (insert)
    - at end of an array
    - at end of a linked list
  - dequeue: oldest element (delete)
    - fist element of array, shift all values in array
    - first element of linked list
## Ordered Lists
- linked lists where items are ordered based on a key

## Handle changing pointers
- using a sentinel: dummy element in front of the list
- using another pointer: pointer to a pointer so that the root root does not change
- modify functions: functions which modify the root shall return the altered object

## Circular property
- last node is circularly connected with first node
  - one of the nodes is called head, but there is no actual head
- a circular object cannot be NULL!
  - use a sentinel or a pointer head node
    - head node will point on itself => prove that it is circular

## Binary Tree
- x = node of tree
- left subtree <= x
- right subtree >= x
- complexity:
  - search: worst case O(h) (h = height)
    - h can represent all n (if the tree looks like a list, else it is log(n) in best case)
  - find minimum: O(h) (furthest element to the left)
  - find max: O(h) (furthest element to the right)
  - insert: 
  - delete: 
  - traversal: O(n)
### Inorder Tree Walk
- visit left subtree before right one
- O(n)
````c
InorerTreeWalk(p):
    if(p!=NULL){
        InorderTreeWalk(p->left)
        VisitNode(p)
        InorderTreeWalk(p->right)
    }
````
### Postorder Tree Walk
- visit node after its subtrees
````c
InorerTreeWalk(p):
    if(p!=NULL){
        InorderTreeWalk(p->left)
        InorderTreeWalk(p->right)
        VisitNode(p)
    }
````
### Preorder Tree Walk
- visit node before its subtrees
````c
InorerTreeWalk(p):
    if(p!=NULL){
        VisitNode(p)
        InorderTreeWalk(p->left)
        InorderTreeWalk(p->right)
    }
````
## Red Black Tree
> Balanced binary tree. A binary tree has worst case O(n) runtime. The balanced search tree ensures O(log(n))
- Every node is either red or black
- root is black
- leaf is black
- for a red node, children are black
- each path contains the same number of black nodes

- blackHeight(x): number of black nodes from any path
  -  ▶ n internal nodes
  - ▶ h - height of tree
  - ▶ bh - black height
  - ▶ h/2 ≤ bh
  - ▶ 2^bh − 1 ≤ n
  - ▶ 2^h/2 ≤ n + 1
  - ▶ h/2 ≤ lg(n + 1)
  - ▶ h ≤ 2 lg(n + 1)
> Operations take O(h) time (search, insert, delete) and the height is bound to 2lg(n+1)

<i>
<ul>
<li>root property: the root is black</li>
<li>external property: every external node is black</li>
<li>red property: the children of a red node are BLACK</li>
<li>depth property: all external nodes have the same black depth</li>
</ul>
</i>

### RB Rotations
- alters the tree structure 
- goal: decreaes the height
- Complexity O(1)
````c
Left Rotataion:
--------------------------
                
                  5 -> t
                /  \
               2    10 -> c
                    / \
                   8   12
                 /  \
                6    9
LeftRotate(5);

                 10
                /  \
               5    12
              / \    
             2   8   
                /  \
               6    9

RightRotate(10);
                 5 
                /  \
               2    10 
                    / \
                   8   12
                 /  \
                6    9
````
### RB Insertions
- identify: current, parent, grandfather, uncle
- Case 0: parent of inserted node is black
- Case 1: parent and uncle of inserted node are red
  - -> change parent color to black, uncle color to black and grandfather to red
- Case 2: inserted is right child: parent is red, grandfather and uncle are black
  - -> left rotate on parent, follow case 3
- Case 3: parent is red, inserted is red (left child), gradfather black and uncle black
  - -> right rotate on grandfather, set parent black and grandfather red
### RB Search

### RBT Deletions
- identify: current, parent, sibling, uncle
- standard BST delete with special cases (ASSUMPTION CURRENT IS LEFT NODE)
- Case 1: The sibling is red. 
- Case 2: The sibling is black and both of sibling's children are black. 
- Case 3: The sibling is black, sibling's left child is red, sibling's right child is black. 
- Case 4: The sibling is black, and sibling's right child is red.

````c
Case 1:
       B               R
      / \             / \
    N    r    -->   B     B
        / \        / \   / \
       b   b      N   b b   N

       
Case 2:
         B             B           (New root is black)
        / \           / \
      N     B  -->  R     r
           / \           / \
          N   N         N   N

          
Case 3:
        B            B
       / \          / \
     N    B  -->  N    r
         / \          / \
        r   N        B   N
       / \          / \
      N   N        N   N

     
Case 4:
      B             B
     / \           / \
   N    B   -->   r   B
       / \       / \   \
      N   r     N   B   N
      
      Parent (any color)
       /     \
      X    Sibling (Black)
          /   \
        Any  (Red)

````
# Dynamic Programming
## Matrix chain multiplication
````c
    A    *   B       =       C
 |--  --| |--  --|        |--  --|
 | xxxx | |x     |        |      | 
 |      | |x     |        |      | 
 |--  --| |--  --|        |--  --|
 
 A = 5x4
 B = 4x3
   => A*B is possible bc A has 4 columns and B 4 rows 
           => C = 5x3 = 15
           => multiply first row with first column (A01,A02,A03,A04)x(B01,B11,B21,B31)
           => required calculations: 5x3x4 (4 = number of multiplications for every cell in C) = 60
   => B*A is NOT possible (but this is not possible)
````
Matrix chain Multiplication

````c
A1 = (5x4);
A2 = (4x6);
A3 = (6x2);
A4 = (2x7);

m[1,1] = 0;
m[2,2] = 0;
m[3,3] = 0;
m[4,4] = 0;

````
|   | 1 | 2 | 3 | 4 |
|---|---|---|---|---|
| 1 | 0 |   |   |   |
| 2 |   | 0 |   |   |
| 3 |   |   | 0 |   |
| 4 |   |   |   | 0 |

````c
m[1,2] = A1 * A2;
m[1,2] = (5x4) * (4x6) = 5 * 6 * 4 = 120;

m[2,3] = A2 * A3;
m[2,3] = (4x6) * (6x2) = 4 * 2 * 6 = 48;

m[3,4] = A3 * A4;
m[3,4] = (6x2) * (2x7) = 6 * 7 * 2 = 84;

=> All possible pairs
````
|   | 1 | 2 | 3  | 4  |
|---|---|---|----|----|
| 1 | 0 | 120 |    |    |
| 2 |   | 0 | 48 |    |
| 3 |   |   | 0  | 84 |
| 4 |   |   |    | 0  |

|   | 1 | 2 | 3 | 4 |
|---|--|---|--|--|
| 1 |  | 1 |  |  |
| 2 |  |   | 2 |  |
| 3 |  |   |  | 3 |
| 4 |  |   |  |  |


````c
m[1,3] = (A1 * A2) * A3;
m[1,3] = A1 * (A2 * A3);
m[1,3] = [(5x4) * (4x6)] * (6x2) = m[1,2] + m[3,3] + 5 * 6 * 2 = 120 + 0 + 60 = 180;
m[1,3] = (5x4) * [(4x6) * (6x2)] = m[1,1] + m[2,3] + 5 * 4 * 2 = 0 + 48 + 40 = 88;
=> take minimum;

m[2,4] = A2 * (A3 * A4);
m[2,4] = (A2 * A3) * A4;
m[2,4] = (4x6) * [(6x2) * (2x7)] = m[2,2] + m[3,4] + 4 * 6 * 7 = 0 + 84 + 168 = 252;
m[2,4] = [(4x6) * (6x2)] * (2x7) = m[2,3] + m[4,4] + 4 * 2 * 7 = 48 + 0 + 56 = 104;

        
=> All possible pairs
````
|   | 1 | 2 | 3  | 4   |
|---|---|---|----|-----|
| 1 | 0 | 120 | 88 |     |
| 2 |   | 0 | 48 | 104 |
| 3 |   |   | 0  | 84  |
| 4 |   |   |    | 0   |

|   | 1 | 2 | 3 | 4 |
|---|--|---|---|--|
| 1 |  | 1 | 1 |  |
| 2 |  |   | 2 | 3 |
| 3 |  |   |   | 3 |
| 4 |  |   |   |  |

````c       
              / m[1,1] + m[2,4] + 5 * 4 * 7,
                  0        104      140
m[1,4] = min {  m[1,2] + m[3,4] + 5 * 6 * 7,
                  120       84        210
              \ m[1,3] + m[4,4] + 5 * 2 * 7,
                   88       0          70
               
=> All possible pairs
````
|   | 1 | 2 | 3  | 4   |
|---|---|---|----|-----|
| 1 | 0 | 120 | 88 | 158 |
| 2 |   | 0 | 48 | 104 |
| 3 |   |   | 0  | 84  |
| 4 |   |   |    | 0   |

Table for the key on which the value in the prev tablewas achieved (3 = m[1,3])

|   | 1 | 2 | 3 | 4 |
|---|--|---|---|---|
| 1 |  | 1 | 1 | 3 |
| 2 |  |   | 2 | 3 |
| 3 |  |   |   | 3 |
| 4 |  |   |   |   |

> 3 is equal to the split (A1 * A2 * A3) * A4
> 
> And for A1, A3  this is the most efficient set: (A1 * (A2 * A3)) * A4

> m[i,j] = min{ m[i,k] + m[k+1, j] + di-1 * dk * dj

- (k = a random value e.g. m[1,4] = m[1,1] + m[2,4], thus k is a placeholder for the split)
- dimensions: 4 matrix => 5 dimensions
- > di-1 = dimension 0 = in case of i = 1 => d0 = 5 from (5x4) then k = 2 => m[1,1] * m[2,4] => 5 * 4 * 7 whereas 7 is dj (dimension j)

> time complexity: O(n^3)
> 
> Time complexity for getting the value is n^2 and for getting the min is n => n^3

### Inorder traversal on a matrix
with the s helper table (which keeps track of the different k's) we can create the inorder traversal


|   | 1 | 2 | 3 | 4 |
|---|---|---|---|---|
| 1 | 0 | 1 | 1 | 3 |
| 2 |   | 0 | 2 | 3 |
| 3 |   |   | 0 | 3 |
| 4 |   |   |   | 0 |

````c
Starting off as a tree:
                    
                x               k = 3
              /   \
            1-3   4-4           k = 2
           /   \
          1-1  2-3              k = 1
              /   \
            2-2   3-3
````

# Quick Overview

| Data Structure | Action | Time Complexity | Properties |
| --- | --- | --- | --- |
| **Stack** | Push (insert) | O(1) | LIFO, linear, dynamic size |
|  | Pop (delete) | O(1) |  |
|  | isEmpty() | O(1) |  |
|  | Traversal | O(n) |  |
| **Queue** | Enqueue (insert) | O(1) | FIFO, linear, dynamic size |
|  | Dequeue (delete) | O(1) |  |
|  | isEmpty() | O(1) |  |
|  | Traversal | O(n) |  |
| **Linked List** | Insert | O(1) | Linear, dynamic size, nodes connected through pointers |
|  | Delete | O(1) |  |
|  | Search | O(n) |  |
|  | Traversal | O(n) |  |
| **Binary Tree** | Insert | O(n) | Hierarchical, nodes have parent-child relationship, each node has at most two children |
|  | Delete | O(n) |  |
|  | Search | O(n) |  |
|  | Traversal | O(n) |  |
| **Binary Search Tree** | Insert | O(log n) | Like a binary tree, but left child is less than parent and right child is greater than parent |
|  | Delete | O(log n) |  |
|  | Search | O(log n) |  |
|  | Traversal | O(n) |  |
| **Heap** | Insert | O(log n) | Binary tree with heap property, complete or almost complete |
|  | Delete | O(log n) |  |
|  | Search | O(n) |  |
|  | Traversal | O(n) |  |
| **Max Heap** | Insert | O(log n) | Like Heap, but parent node is greater than or equal to its children |
|  | Delete | O(log n) |  |
|  | Search | O(n) |  |
|  | Traversal | O(n) |  |
| **Min Heap** | Insert | O(log n) | Like Heap, but parent node is less than or equal to its children |
|  | Delete | O(log n) |  |
|  | Search | O(n) |  |
|  | Traversal | O(n) |  |
| **Red-Black Tree** | Insert | O(log n) | Self-balancing BST, nodes have an extra bit for denoting color |
|  | Delete | O(log n) |  |
|  | Search | O(log n) |  |
|  | Traversal | O(n) |  |
| **Graph** | Add Edge | O(1) | Nodes with pairwise connections, connections can be weighted/unweighted, graph can be directed/undirected |
|  | Remove Edge | O(1) or O(n) |  |
|  | Add Vertex | O(1) |  |
|  | Remove Vertex | O(v + e) |  |
|  | DFS Traversal | O(v + e) |  |
|  | BFS Traversal | O(v + e) |  |




| Criteria | Min Heap | Max Heap | Binary Search Tree (BST) |
| --- | --- | --- | --- |
| **Order Property** | Parent node is less than or equal to its children. | Parent node is greater than or equal to its children. | Left child is less than parent and right child is greater than parent. |
| **Shape Property** | Complete binary tree. All levels are fully filled except possibly for the last level, which is filled from left to right. | Same as Min Heap. | Not necessarily a complete binary tree. |
| **Insertion** | O(log n) | O(log n) | O(log n) in average case, O(n) in worst case |
| **Deletion (of min/max)** | O(log n) | O(log n) | O(log n) in average case, O(n) in worst case |
| **Search (for min/max)** | O(1) | O(1) | O(log n) in average case, O(n) in worst case |
| **Search (for arbitrary element)** | O(n) | O(n) | O(log n) in average case, O(n) in worst case |
| **Suitability** | Suitable when you need quick access to the smallest element. | Suitable when you need quick access to the largest element. | Suitable for search operations and when you need to keep elements in order. |

Notes:
1. Time complexities for BST operations assume a balanced tree. In a skewed BST, these operations can degrade to O(n).
2. Heap does not maintain any specific order among nodes on any single level or among the siblings while BST does.


| Sorting Algorithm | Best Case | Average Case | Worst Case | Space Complexity | Stability |
| --- | --- | --- | --- | --- | --- |
| **Heapsort** | O(n log n) | O(n log n) | O(n log n) | O(1) | No |
| **Quicksort** | O(n log n) | O(n log n) | O(n^2) | O(log n) | No |
| **Selection Sort** | O(n^2) | O(n^2) | O(n^2) | O(1) | No |
| **Insertion Sort** | O(n) | O(n^2) | O(n^2) | O(1) | Yes |
| **Bubble Sort** | O(n) | O(n^2) | O(n^2) | O(1) | Yes |
| **Merge Sort** | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |

Notes:
1. Best, average, and worst case scenarios refer to the performance of the sorting algorithm based on the input.
2. Space complexity refers to the maximum extra space required by the algorithm.
3. Stability refers to the behavior of the algorithm when two elements have the same key. If the order of equal elements remains the same before and after sorting, the algorithm is stable.

| Data Structure | Action | Time Complexity | Deletion | Search | Traversal | Properties | Use Case |
| --- | --- | --- | --- | --- | --- | --- | --- |
| **Stack** | Push (insert) | O(1) | O(1) | O(n) | O(n) | LIFO, linear, dynamic size | Useful in algorithmic situations like depth-first search, where you want to explore one branch of a tree/graph fully before moving onto the next one. |
| **Queue** | Enqueue (insert) | O(1) | O(1) | O(n) | O(n) | FIFO, linear, dynamic size | Useful in situations where you want things to happen in the order they were inserted, such as task scheduling and in breadth-first search. |
| **Linked List** | Insert | O(1) | O(1) | O(n) | O(n) | Linear, dynamic size, nodes connected through pointers | Useful when you need constant-time insertions/deletions from the list (such as in real-time computing where time predictability is absolutely critical). |
| **Binary Tree** | Insert | O(n) | O(n) | O(n) | O(n) | Hierarchical, nodes have parent-child relationship, each node has at most two children | Binary trees are used when rapid searching of sorted data is important, such as in database indexing. |
| **Binary Search Tree** | Insert | O(log n) | O(log n) | O(log n) | O(n) | Like a binary tree, but left child is less than parent and right child is greater than parent | Used in many search applications where data is constantly entering/exiting, such as map and set objects in many languages' libraries. |
| **Heap** | Insert | O(log n) | O(log n) | O(n) | O(n) | Binary tree with heap property, complete or almost complete | Used in efficient implementations of priority queues and in sorting algorithms such as heapsort. |
| **Max Heap** | Insert | O(log n) | O(log n) | O(n) | O(n) | Like Heap, but parent node is greater than or equal to its children | Used in algorithms that need to quickly find the maximum element, such as in scheduling processes in the operating system. |
| **Min Heap** | Insert | O(log n) | O(log n) | O(n) | O(n) | Like Heap, but parent node is less than or equal to its children | Used in algorithms that need to quickly find the minimum element, such as in implementing Dijkstra's algorithm. |
| **Red-Black Tree** | Insert | O(log n) | O(log n) | O(log n) | O(n) | Self-balancing BST, nodes have an extra bit for denoting color | Used in programming languages libraries, like Java's TreeMap and TreeSet, to maintain a balanced tree structure after many insertions and deletions. |
| **Graph** | Add Edge | O(1) | O(1) | O(n+e) | O(n+e) | Nodes with pairwise connections, connections can be weighted/unweighted, graph can be directed/undirected | Used to model relationships between pairs, such as a network of web pages, or a social network. |
