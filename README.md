## Introduction

This repository contains a C++ implementation designed to solve the problem of identifying an increasing triplet subsequence within an array. The core function, `increasingTriplet`, takes an array of integers and returns `true` if there exists a triplet of indices `(i, j, k)` such that `i < j < k` and `nums[i] < nums[j] < nums[k]`. This problem is significant for understanding sequences and their properties in data analysis and algorithmic challenges.

## Algorithm

### **Increasing Triplet Subsequence Detection**

#### Logic

The algorithm iterates through the array while maintaining two variables, `lowestValue` and `secondLowestValue`, to track the smallest and the second smallest numbers encountered so far. It leverages a single pass through the array, updating these variables based on the current element's value. If an element larger than `secondLowestValue` is found, it confirms the presence of an increasing triplet subsequence and returns `true`. This method efficiently identifies the desired subsequence without needing to compare every possible triplet explicitly.

#### Complexity Analysis

- **Time Complexity:** O(n), where n is the number of elements in the input array. The algorithm requires only a single pass through the array, making it highly efficient for large datasets.
- **Space Complexity:** O(1), as it uses only a constant amount of extra space regardless of the input size.

### Code Snippet

```cpp
bool increasingTriplet(const vector<int>& nums) {
	int numsLength = nums.size();
	if (numsLength < 3) { return false; }

	int lowestValue = nums[0];
	int secondLowestValue = INT_MAX;

	for (int i = 1; i < numsLength; ++i) {
		if (nums[i] > secondLowestValue) {
			return true;
		}
		else if (nums[i] > lowestValue) {
			// Ensure that the secondLowestValue always comes after the lowest value
			secondLowestValue = nums[i];
		}
		else {
			// Ensure that lowestValue is always the lowest number seen so far
			lowestValue = nums[i];
		}
	}
	return false;
}
```

## Test Cases

1. **Non-decreasing Values:** Evaluates the function with an array of strictly increasing values.
2. **Only Decreasing Values:** Tests with an array where values strictly decrease, ensuring the function correctly identifies the lack of a triplet.
3. **Negative Values:** Uses an array with negative numbers to assess handling of both positive and negative integers.
4. **Mixed Values with Valid Triplet in Middle:** A scenario with a valid increasing triplet hidden among mixed values.
5. **Mixed Values without Increasing Triplet:** Checks the algorithm's accuracy in a case without any increasing triplet.
6. **Duplicates with Valid Triplet:** Verifies detection of an increasing triplet amidst duplicate values.
7. **Long Sequence with Late Triplet:** A lengthy array test where the triplet appears near the end, challenging the algorithm's efficiency.
8. **Large Range Including Negatives:** Tests the function's performance across a broad range of values, including negative numbers.
9. **Increasing Sequence with Dip:** Ensures the algorithm detects a triplet despite a temporary decrease in values.
