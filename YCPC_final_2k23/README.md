# YCPC Final 2k23 Solutions

This repository contains C++ solutions for the YCPC Final 2023 programming contest problems.

## Problems

### 1. Divided by Three
**File:** `divided_by_three.cpp`

**Description:**
Determines whether a very large integer (given as a string) is divisible by 3. The logic is based on the property that a number is divisible by 3 if the sum of its digits is divisible by 3.

**Compilation & Execution:**
```bash
g++ -o divided_by_three divided_by_three.cpp
./divided_by_three
```

### 2. Valid Phone Number
**File:** `valid_phone_number.cpp`

**Description:**
Validates a phone number string. A valid number must start with `+880`, be 14 characters long, contain only digits after the prefix, and have a valid operator code (e.g., 17, 13, 19, 14, 15, 11, 18, 16).

**Compilation & Execution:**
```bash
g++ -o valid_phone_number valid_phone_number.cpp
./valid_phone_number
```

### 3. Elimination
**File:** `elimination.cpp`

**Description:**
Solves a range query problem on a binary string where `10` pairs eliminate each other. It uses a Segment Tree to efficiently answer queries about the number of eliminated elements in a given range.

**Compilation & Execution:**
```bash
g++ -o elimination elimination.cpp
./elimination
```

### 4. GCD LCM
**File:** `GCD_LCM.cpp`

**Description:**
Computes the sum of `LCM(A[i], A[j]) / GCD(A[i], A[j])` for all pairs in an array. The solution uses an optimized approach involving inclusion-exclusion and counting multiples for values up to $10^6$, and falls back to brute force for larger values.

**Compilation & Execution:**
```bash
g++ -o GCD_LCM GCD_LCM.cpp
./GCD_LCM
```

### 5. Yet Another LCS
**File:** `yet_another_LCS.cpp`

**Description:**
Calculates the maximum Longest Common Subsequence (LCS) of two strings after performing at most $K$ insertion operations. The result depends on whether $K$ is large enough to merge the strings into a common supersequence.

**Compilation & Execution:**
```bash
g++ -o yet_another_LCS yet_another_LCS.cpp
./yet_another_LCS
```

### 6. Gun Shots
**File:** `gun_shots.cpp`

**Description:**
A dynamic programming problem similar to "Burst Balloons". It calculates the maximum points obtainable by shooting glasses in a specific order, where points depend on adjacent glasses.

**Compilation & Execution:**
```bash
g++ -o gun_shots gun_shots.cpp
./gun_shots
```

## Requirements
- A C++ compiler (e.g., g++) supporting C++11 or later.

