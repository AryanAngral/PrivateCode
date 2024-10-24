
/*
Problem: Total Negative Numbers in a Sorted Matrix
Link: https://www.codingninjas.com/codestudio/problems/total-negative-numbers-in-a-sorted-matrix_3161878

Given an m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.
*/
#include<bits/stdc++.h>

#include <vector>
using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    int count = 0;
    for (const auto& row : grid) {
        for (int num : row) {
            if (num < 0) count++;
        }
    }
    return count;
}
