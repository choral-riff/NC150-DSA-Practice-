/*
Top K Frequent Elements
Solved 
Given an integer array nums and an integer k, return the k most frequent elements within the array.

The test cases are generated such that the answer is always unique.

You may return the output in any order.

Example 1:

Input: nums = [1,2,2,3,3,3], k = 2

Output: [2,3]
Example 2:

Input: nums = [7,7], k = 1

Output: [7]
Constraints:

1 <= nums.length <= 10^4.
-1000 <= nums[i] <= 1000
1 <= k <= number of distinct elements in nums.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         //init frequency maps to store from nums
        unordered_map<int, int> count;
        //init vector of vector<int> that we will use to keep elements for frequency as i
        vector<vector<int>> freq (nums.size()+1);
        //updating the frequency maps
        for (int n: nums){
            count[n]++;
        }
        //updating the vector of vector<int> using the frequency maps 
        for (const auto& entry: count){
            freq[entry.second].push_back(entry.first);
        }
        //init vector<int> to return 
        vector<int> result;
        for (int i = freq.size()-1; i>0; i--){
            for (int n: freq[i]) {
                result.push_back(n);
                if (result.size() == k){
                    return result;
                }
            }
        }
        return result;
    }
};
