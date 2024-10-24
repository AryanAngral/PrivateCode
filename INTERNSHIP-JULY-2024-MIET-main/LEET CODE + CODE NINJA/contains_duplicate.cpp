/*
Problem: Contains Duplicate
Link: https://leetcode.com/problems/contains-duplicate/

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/

#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> num_set(nums.begin(), nums.end());
    return num_set.size() != nums.size();
}