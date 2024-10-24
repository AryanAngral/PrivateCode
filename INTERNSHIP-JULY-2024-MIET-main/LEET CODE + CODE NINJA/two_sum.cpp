/*
Problem: Two Sum
Link: https://www.codingninjas.com/codestudio/problems/two-sum_839653

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
*/
#include<bits/stdc++.h>

#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement], i};
        }
        num_map[nums[i]] = i;
    }
    return {};
}