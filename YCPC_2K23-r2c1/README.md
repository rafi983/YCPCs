# YCPC 2023 (Round 2) Solutions

This repository contains C++ solutions for the problems from the YCPC 2023 (Round 2) competitive programming contest.

## Problem List

Here is a list of the problems solved in this repository:

### 1. Can You Multiply? (`can_you_multiply.cpp`)
**Problem:** Calculate the last two digits of the product of two non-negative integers $A$ and $B$.
**Approach:** Use modular arithmetic `(A % 100 * B % 100) % 100` to avoid overflow and find the last two digits.

### 2. Jingle Bells (`jingle_bells.cpp`)
**Problem:** Print a Christmas tree pattern of a given size $N$.
**Approach:** Construct the tree using nested loops. The tree consists of a top pyramid part and a rectangular trunk.

### 3. Marbles (`marbles.cpp`)
**Problem:** Given $N$ baskets and $Q$ updates, where each update adds $X$ marbles to baskets in the range $[A, B]$, find the final number of marbles in each basket.
**Approach:** Use the **Difference Array** technique to handle range updates in $O(1)$ time, followed by a prefix sum pass to compute the final values in $O(N)$. Total complexity: $O(N + Q)$.

### 4. Tourists (`tourists.cpp`)
**Problem:** Select $C$ hotel rooms from $N$ available floors such that the minimum distance between any two chosen floors is maximized.
**Approach:** Use **Binary Search on the Answer**. We binary search for the maximum possible minimum distance and use a greedy check to verify if it's possible to place $C$ tourists with at least that distance. Complexity: $O(N \log N + N \log(\text{max\_coord}))$.

### 5. King's Order (`kings_order.cpp`)
**Problem:** Given a set of cities and roads with construction costs, determine the number of redundant roads that can be removed while keeping all cities connected with the minimum total cost.
**Approach:** Use **Kruskal's Algorithm** with a Disjoint Set Union (DSU) data structure to find the Minimum Spanning Tree (MST). The roads not in the MST are the ones to be removed.

### 6. Bank Robbery (`bank_robbery.cpp`)
**Problem:** Find the maximum gold a thief can steal from a row of lockers, given that he cannot open consecutive lockers and cannot open lockers with trackers.
**Approach:** Use **Dynamic Programming**. This is a variation of the "House Robber" problem. We maintain the maximum gold stolen up to the previous two lockers to decide the optimal move for the current locker. Space complexity is optimized to $O(1)$.

## How to Run

You can compile and run any of the solutions using a C++ compiler like `g++`.

**Example:**

To run the solution for "Can You Multiply?":

```bash
g++ can_you_multiply.cpp -o can_you_multiply
./can_you_multiply
```

Then enter the input as specified in the problem description.

## Requirements

- A C++ compiler (supporting C++11 or later).

