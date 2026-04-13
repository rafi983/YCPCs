# YCPC Final 2k25 Solutions

This repository contains solutions for the **YCPC Final 2k25** contest problems. Each solution is implemented in C++.

## Repository Structure

The repository includes the following solution files:

- `bekub_and_rice.cpp`
- `kingdom_of_paharpur.cpp`
- `railway_platform.cpp`
- `secret_number.cpp`
- `survivors.cpp`
- `xorry_pairs.cpp`

## Problem Descriptions & Approaches

### 1. Bekub and Rice (`bekub_and_rice.cpp`)
**Problem:** Determine if a continuous segment of rice bag types can be chosen such that taking an equal number of bags from each type results in a total weight of exactly `W`.
**Approach:**
- The sum of the segment must be a divisor of `W`.
- The solution iterates through all divisors of `W`.
- For each divisor, it uses a **Sliding Window** technique to check if any continuous subarray sums to that divisor.

### 2. Kingdom of Paharpur (`kingdom_of_paharpur.cpp`)
**Problem:** Given an array of heights, answer queries to check if a subarray `[l, r]` forms a specific shape (likely unimodal or mountain-like).
**Approach:**
- Precomputes `next_drop` (index of the next element that is smaller) and `prev_rise` (index of the previous element that is smaller) arrays.
- Uses these precomputed arrays to answer queries in `O(1)` time.

### 3. Railway Platform (`railway_platform.cpp`)
**Problem:** Involves counting valid pairs or inversions in an array using a Fenwick Tree.
**Approach:**
- Uses a **Fenwick Tree (Binary Indexed Tree)** to efficiently count elements smaller than the current element.
- Coordinate compression is used to handle large values.

### 4. Secret Number (`secret_number.cpp`)
**Problem:** A simple problem that involves reading a large number as a string and outputting its last digit.
**Approach:**
- Reads the input as a string and prints the last character.

### 5. Survivors (`survivors.cpp`)
**Problem:** Finds a minimum value satisfying a condition related to gaps and demands using binary search.
**Approach:**
- **Binary Search on Answer**: The solution searches for the smallest value `mid` that satisfies a specific demand condition.
- The check function iterates through calculated gaps to verify the condition.

### 6. Xorry Pairs (`xorry_pairs.cpp`)
**Problem:** Counts the number of pairs satisfying bitwise conditions related to `N`.
**Approach:**
- **Bit Manipulation**: The solution analyzes the binary representation of `N`.
- It calculates combinations based on the set bits up to the Most Significant Bit (MSB).

## How to Compile and Run

You can compile any of the solutions using a C++ compiler like `g++`.

**Generic Compilation Command:**
```bash
g++ -o <output_filename> <source_filename>.cpp
```

**Example for `bekub_and_rice.cpp`:**
```bash
g++ -o bekub_and_rice bekub_and_rice.cpp
./bekub_and_rice
```

**Running with Input File:**
```bash
./bekub_and_rice < input.txt
```

## Requirements
- C++ Compiler (GCC recommended)
- Standard C++ Libraries


