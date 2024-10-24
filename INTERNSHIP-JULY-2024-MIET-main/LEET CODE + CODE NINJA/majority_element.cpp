/*
Problem: Majority Element
Link: https://www.codingninjas.com/codestudio/problems/majority-element_842495

Given an array nums of size n, return the majority element.
*/
#include<bits/stdc++.h>

#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0, candidate = 0;
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}