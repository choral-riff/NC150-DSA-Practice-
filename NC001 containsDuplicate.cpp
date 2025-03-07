/*
Contains Duplicate
Solved 
Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.

Example 1:

Input: nums = [1, 2, 3, 3]

Output: true

Example 2:

Input: nums = [1, 2, 3, 4]

Output: false
*/

class Solution {
public:
  bool containsDuplicate (vector<int>& nums) {
    // setting up a hash set to store unique ints from nums
    unordered_set <int> seen;
    // iterating through nums
    for (int num : nums){
      if (seen.count(num)){
        return true; //if int num is found in the hashset seen then returns true 
      }
      seen.insert(num); //inserts int num not yet in the hashset 
    }
    return false; //if the loop exhausts, returns false coz no duplicates. 
  }
}
