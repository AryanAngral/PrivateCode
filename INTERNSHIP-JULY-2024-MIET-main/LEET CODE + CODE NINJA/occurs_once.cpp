/*
Problem: Occurs Once
Link: https://www.codingninjas.com/codestudio/problems/occurs-once_1214969

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
*/
#include<bits/stdc++.h>

#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}