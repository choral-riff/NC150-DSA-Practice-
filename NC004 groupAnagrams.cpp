/*
Group Anagrams
Solved 
Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: strs = ["act","pots","tops","cat","stop","hat"]

Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]
Example 2:

Input: strs = ["x"]

Output: [["x"]]
Example 3:

Input: strs = [""]

Output: [[""]]
Constraints:

1 <= strs.length <= 1000.
0 <= strs[i].length <= 100
strs[i] is made up of lowercase English letters.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //initializing uo_map res
        // we are gonna make frequency count of each 26 letters 
        // we are gonna make a string of that frequency count 
        // we are gonna use that unique frequency count as a key for storing anagrams as a vector in the uo map res 
        unordered_map<string, vector<string>> res;
        for (const auto& s:strs){
            vector<int> count(26,0);
            for (char c:s){
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i<26; i++){
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(s);
        }
        // we extract the second of the pair in each entry of our uo map res 
        vector<vector<string>> result;
        for (const auto& pair:res){
            result.push_back(pair.second);
        }
        return result;
    }
};
