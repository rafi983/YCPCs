# YCPC Beginner Round 2025 - Solutions

This repository contains solutions for the YCPC (Young Coders Programming Competition) Beginner Round 2025.

## 📋 Table of Contents
- [Overview](#overview)
- [Problems](#problems)
- [Compilation & Execution](#compilation--execution)
- [Requirements](#requirements)
- [File Structure](#file-structure)

## 🎯 Overview

This repository contains optimized C++ solutions for various competitive programming problems from YCPC 2025. Each solution is designed to handle large inputs efficiently within the given time and memory constraints.

## 📝 Problems

### 1. Entry to the Arena
**File:** `entry_to_the_arena.cpp`

**Problem:** Simple output formatting problem.

**Description:** Print "Meena is participating in YCPC 2025" exactly 25 times with newlines between them.

**Complexity:** O(1)

**Approach:** Direct loop implementation.

---

### 2. Divide or Be Divided
**File:** `divide_or_be_divided.cpp`

**Problem:** Check divisibility between two digits.

**Input:**
- `n`: Length of string
- `x, y`: Positions (1-indexed)
- `s`: String of digits

**Output:** "YES" if digit at position x divides digit at position y OR vice versa, "NO" otherwise.

**Complexity:** O(1)

**Approach:** Extract digits at given positions and check divisibility in both directions.

---

### 3. Same Parity
**File:** `same_parity.cpp`

**Problem:** Determine if array elements can be rearranged such that all adjacent pair sums have the same parity.

**Input:**
- `T`: Number of test cases
- For each test case:
  - `n`: Array length
  - `n` integers

**Output:** "YES" if possible, "NO" otherwise.

**Complexity:** O(n) per test case

**Approach:** 
- Count odd and even numbers
- Check if either all-even-sums or all-odd-sums arrangement is possible
- For all-even-sums: need enough odds for odd positions and enough evens for even positions
- For all-odd-sums: need mixed placement capability

---

### 4. Median is Easy
**File:** `median_is_easy.cpp`

**Problem:** Track the median of last digits as elements are added one by one.

**Input:**
- `T`: Number of test cases
- For each test case:
  - `n`: Array length
  - `n` integers

**Output:** Space-separated medians after each element addition (median of last digits, 0-indexed).

**Constraints:**
- Time Limit: 2s
- Memory Limit: 512MB

**Complexity:** O(n) per test case

**Approach:**
- Use counting array (size 10) for last digits (0-9)
- After each element, find median by counting from smallest digit
- Median index = (current_size - 1) / 2 (0-indexed)

---

### 5. Sort the Array
**File:** `sort_the_array.cpp`

**Problem:** Find minimum operations to sort an array, where one operation merges two adjacent equal elements.

**Input:**
- `T`: Number of test cases
- For each test case:
  - `n`: Array length
  - `n` integers

**Output:** Minimum number of operations needed.

**Complexity:** O(n log n) per test case

**Approach:**
- Compress consecutive equal elements into blocks
- Find Longest Increasing Subsequence (LIS) of blocks
- Answer = total_blocks - LIS_length
- Uses binary search for efficient LIS calculation

---

### 6. Squid Game: The Rising Formation
**File:** `squid_game_the_rising_formation.cpp`

**Problem:** Count the number of increasing triplets (i < j < k where a[i] < a[j] < a[k]).

**Input:**
- `T`: Number of test cases
- For each test case:
  - `n`: Number of players (1 ≤ n ≤ 10^5)
  - `n` integers representing strength levels

**Output:** Count of valid Rising Formations.

**Constraints:**
- Time Limit: 2s
- Memory Limit: 512MB
- Sum of n over all test cases ≤ 10^5

**Complexity:** O(n log n) per test case

**Approach:**
- **Coordinate Compression:** Map values to smaller range for efficient indexing
- **Fenwick Tree (Binary Indexed Tree):** For efficient range queries
- For each position j (middle element):
  - Count elements smaller than a[j] on the left: `left_smaller[j]`
  - Count elements larger than a[j] on the right: `right_larger[j]`
  - Contribution: `left_smaller[j] * right_larger[j]`
- Sum all contributions

**Key Techniques:**
1. **Fenwick Tree:** Supports O(log n) updates and queries
2. **Coordinate Compression:** Handles large value ranges efficiently
3. **Two-pass approach:** First pass for left counts, second for right counts

---

## 🔧 Compilation & Execution

### Prerequisites
- C++ compiler (g++ recommended)
- C++11 or higher

### Compile a Single File
```bash
g++ -o solution.exe filename.cpp
```

### Run with Input File
```bash
# Windows (PowerShell)
cmd /c "solution.exe < input.txt"

# Windows (Command Prompt)
solution.exe < input.txt

# Linux/Mac
./solution < input.txt
```

### Example
```bash
g++ -o squid_game_triplets.exe squid_game_the_rising_formation.cpp
cmd /c "squid_game_triplets.exe < input.txt"
```

## 💻 Requirements

- **Compiler:** g++ (GCC) or any C++11+ compatible compiler
- **Operating System:** Windows/Linux/macOS
- **C++ Standard:** C++11 or higher

## 📁 File Structure

```
ycpc_beg_round_2k25/
├── divide_or_be_divided.cpp
├── entry_to_the_arena.cpp
├── median_is_easy.cpp
├── same_parity.cpp
├── sort_the_array.cpp
├── squid_game_the_rising_formation.cpp
├── squid_game_triplets.exe          # Compiled executable
├── input.txt                         # Sample test cases
└── README.md                         # This file
```

## 🎓 Key Algorithms & Data Structures Used

### Fenwick Tree (Binary Indexed Tree)
- **Used in:** Squid Game: The Rising Formation
- **Purpose:** Efficient prefix sum queries and point updates
- **Operations:** O(log n) for both query and update

### Coordinate Compression
- **Used in:** Squid Game: The Rising Formation
- **Purpose:** Map large value ranges to smaller indices
- **Benefit:** Reduces memory usage and improves cache performance

### Longest Increasing Subsequence (LIS)
- **Used in:** Sort the Array
- **Algorithm:** Binary search approach
- **Complexity:** O(n log n)

### Counting Sort
- **Used in:** Median is Easy
- **Purpose:** Track frequency of digits (0-9)
- **Complexity:** O(n) with O(1) space (fixed size array)

## 📊 Sample Test Cases

### Squid Game: The Rising Formation
```
Input:
5
4
2 10 3 13
8
13 15 7 9 7 10 4 10
3
1 4 14
8
4 5 14 14 11 10 1 9
3
9 9 10

Output:
2
2
1
5
0
```

**Explanation (First Test Case):**
- Array: [2, 10, 3, 13]
- Valid triplets:
  1. (2, 10, 13) at indices (0, 1, 3)
  2. (2, 3, 13) at indices (0, 2, 3)
- Answer: 2

## 🚀 Performance Tips

1. **Fast I/O:** All solutions use `ios::sync_with_stdio(false)` and `cin.tie(nullptr)` for faster input/output
2. **Memory Management:** Use `reserve()` for vectors when size is known
3. **Algorithm Choice:** Use appropriate data structures (Fenwick Tree, binary search) for optimal complexity
4. **Avoid Global Variables:** Keep variables scoped appropriately

## 📚 Learning Resources

- **Fenwick Tree:** [CP-Algorithms](https://cp-algorithms.com/data_structures/fenwick.html)
- **Coordinate Compression:** Common technique in competitive programming
- **LIS Algorithm:** [GeeksforGeeks](https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/)
- **Binary Indexed Tree:** [Topcoder Tutorial](https://www.topcoder.com/community/competitive-programming/tutorials/binary-indexed-trees/)

## 🐛 Debugging

If you encounter issues:

1. **Compilation Errors:** Ensure C++11 or higher support
2. **Wrong Answer:** Check edge cases (empty arrays, duplicates, boundary values)
3. **Time Limit Exceeded:** Verify algorithm complexity matches constraints
4. **Memory Limit Exceeded:** Check array sizes and memory allocation

## ✅ Testing

Create test input files and verify outputs:

```bash
# Create input.txt with test cases
# Run solution
cmd /c "solution.exe < input.txt > output.txt"
# Compare with expected output
```

## 📝 Notes

- All solutions are optimized for competitive programming
- Code follows clean coding practices with proper spacing
- Edge cases are handled appropriately
- Solutions pass all sample test cases

## 👨‍💻 Author

Solutions prepared for YCPC Beginner Round 2025

---

**Good luck with competitive programming! 🎉**

