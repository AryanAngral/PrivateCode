/*
Problem: Ninja and Sorted Arrays
Link: https://www.codingninjas.com/codestudio/problems/ninja-and-sorted-arrays_1214628

Given two sorted arrays nums1 and nums2 of size m and n respectively, merge nums2 into nums1 as one sorted array.
*/
#include<bits/stdc++.h>

#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}