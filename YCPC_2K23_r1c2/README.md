# YCPC Round 1 Contest 2 Solutions

This repository contains C++ solutions for the YCPC Round 1 Contest 2 problems. Each source file corresponds to a specific problem from the contest.

## Problem List

### 1. Work Done
**File:** `work_done.cpp`
**Description:** Calculates the number of farmers needed to complete a harvest in a shorter timeframe.
**Key Concept:** Inverse proportion (Work = Men * Days).

### 2. Ratul is Missing
**File:** `ratul_is_missing.cpp`
**Description:** Checks if the name "Ratul" exists in a given string of names.
**Key Concept:** String searching / Tokenization.

### 3. String Rules
**File:** `string_rules.cpp`
**Description:** Expands a string based on specific rules involving numbers and operators.
**Key Concept:** String parsing and manipulation.

### 4. Lily Can Do It
**File:** `lily_can_do_it.cpp`
**Description:** Determines if an array can be reordered to have consecutive odd and even numbers where the second is smaller or equal.
**Key Concept:** Parity check (Odd/Even existence).
**Note:** Includes Fast I/O optimization.

### 5. Adventure (Easy Version)
**File:** `adventure(easy).cpp`
**Description:** Solves the 0/1 Knapsack problem for a small number of items (N <= 20).
**Key Concept:** Dynamic Programming (Knapsack).

### 6. Adventure (Hard Version)
**File:** `adventure(hard).cpp`
**Description:** Solves the 0/1 Knapsack problem for a larger number of items (N <= 1000).
**Key Concept:** Dynamic Programming (Knapsack) with space optimization.

### 7. Tom and Food
**File:** `tom_and_food.cpp`
**Description:** Finds the maximum calories Tom can absorb by eating at most K dishes serially.
**Key Concept:** Sliding Window technique.

## How to Compile and Run

You can compile any of the solutions using a C++ compiler like `g++`.

**Example for `tom_and_food.cpp`:**

```bash
g++ -o tom_and_food tom_and_food.cpp
./tom_and_food
```

**Using Input Files:**

If you have an input file (e.g., `input.txt`), you can redirect it to the executable:

**Windows (Command Prompt):**
```cmd
tom_and_food.exe < input.txt
```

**Windows (PowerShell):**
```powershell
Get-Content input.txt | .\tom_and_food.exe
```

**Linux/macOS:**
```bash
./tom_and_food < input.txt
```

