/*
Problem: Move Zeros to Left
Link: https://www.codingninjas.com/codestudio/problems/move-zeros-to-left_1094877

Given an array nums, write a function to move all 0's to the beginning of it while maintaining the relative order of the non-zero elements.
*/
#include<bits/stdc++.h>

#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int insertPos = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            nums[insertPos++] = nums[i];
        }
    }
    while (insertPos < nums.size()) {
        nums[insertPos++] = 0;
    }
}