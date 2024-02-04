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