#include <iostream>
#include <vector>
using namespace std;

bool increasingTriplet(vector<int>& nums);

int main() {
	// Given an integer array nums, return true if there exists a triple 
	// of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. 
	// If no such indices exists, return false.


	return 0;
}

bool increasingTriplet(vector<int>& nums) {
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