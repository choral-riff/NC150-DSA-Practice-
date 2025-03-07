/*
Valid Anagram
Solved 
Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: s = "racecar", t = "carrace"

Output: true
Example 2:

Input: s = "jar", t = "jam"

Output: false
Constraints:

s and t consist of lowercase English letters.
*/

#include <algorithm>

class Solution {
public:
   bool isAnagram(string s, string t){
        //checking if s and t are same length
        if (s.size() != t.size()){
            return false; //false if t and s are not the same size
        }
        //initializing smap and tmap
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;
        //populating the smap and tmap
        for (int i = 0; i<s.size(); i++){
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        //iterating through the smap and verifying key/value in tmap
        for (const auto& [key, value]:smap){
            if (value != tmap[key]){
                return false;
            }
        }
        return true;
   }
};
