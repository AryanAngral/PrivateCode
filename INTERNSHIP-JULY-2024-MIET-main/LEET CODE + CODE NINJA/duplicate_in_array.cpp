/*
Problem: Duplicate in Array
Link: https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive, there is only one repeated number.
*/
#include<bits/stdc++.h>

#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}