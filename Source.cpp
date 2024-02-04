#include <iostream>
#include <vector>
using namespace std;

bool increasingTriplet(const vector<int>& nums);

int main() {
	// Given an integer array nums, return true if there exists a triple 
	// of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. 
	// If no such indices exists, return false.

	// Case 1: Non-decreasing values
	cout << "Test 1: [1, 2, 3, 4, 5]\nExpected: true\nActual: " <<
		(increasingTriplet({ 1, 2, 3, 4, 5 }) == 1 ? "true\n\n" : "false\n\n");

	// Case 2: Only decreasing values
	cout << "Test 2: [5, 4, 3, 2, 1]\nExpected: false\nActual: " <<
		(increasingTriplet({ 5, 4, 3, 2, 1 }) == 1 ? "true\n\n" : "false\n\n");

	// Case 3: Negative values
	cout << "Test 3: [2, 4, -2, -3]\nExpected: false\nActual: " <<
		(increasingTriplet({ 2, 4, -2, -3 }) == 1 ? "true\n\n" : "false\n\n");

	// Case 4: Mixed values with a valid increasing triplet in the middle
	cout << "Test 4: [10, 1, 2, 7, 9, 5]\nExpected: true\nActual: " <<
		(increasingTriplet({ 10, 1, 2, 7, 9, 5 }) == 1 ? "true\n\n" : "false\n\n");

	// Case 5: Mixed values without any increasing triplet
	cout << "Test 5: [8, 6, 5, 4, 3, 2]\nExpected: false\nActual: " <<
		(increasingTriplet({ 8, 6, 5, 4, 3, 2 }) == 1 ? "true\n\n" : "false\n\n");

	// Case 6: Contains duplicates and a valid increasing triplet
	cout << "Test 6: [1, 5, 5, 2, 4, 6]\nExpected: true\nActual: " <<
		(increasingTriplet({ 1, 5, 5, 2, 4, 6 }) == 1 ? "true\n\n" : "false\n\n");

	// Case 7: Long sequence with one valid increasing triplet near the end
	cout << "Test 7: [10, 9, 8, 7, 1, 2, 3]\nExpected: true\nActual: " <<
		(increasingTriplet({ 10, 9, 8, 7, 1, 2, 3 }) == 1 ? "true\n\n" : "false\n\n");

	// Case 8: Large range of values, including negatives, with multiple valid triplets
	cout << "Test 8: [-10, -8, -5, -3, 0, 2, 4, 6]\nExpected: true\nActual: " <<
		(increasingTriplet({ -10, -8, -5, -3, 0, 2, 4, 6 }) == 1 ? "true\n\n" : "false\n\n");

	// Case 9: Increasing sequence with a dip that still contains a valid triplet
	cout << "Test 9: [1, 2, 0, 3]\nExpected: true\nActual: " <<
		(increasingTriplet({ 1, 2, 0, 3 }) == 1 ? "true\n\n" : "false\n\n");

	// Case 10: All elements are the same, no increasing triplet
	cout << "Test 10: [4, 4, 4, 4]\nExpected: false\nActual: " <<
		(increasingTriplet({ 4, 4, 4, 4 }) == 1 ? "true\n\n" : "false\n\n");

	return 0;
}

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