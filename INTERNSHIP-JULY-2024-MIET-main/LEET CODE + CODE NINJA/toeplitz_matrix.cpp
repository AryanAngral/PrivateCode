
/*
Problem: Toeplitz Matrix
Link: https://leetcode.com/problems/toeplitz-matrix/

Given an m x n matrix, return true if the matrix is Toeplitz. A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
*/
#include<bits/stdc++.h>

#include <vector>
using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 1; j < matrix[0].size(); ++j) {
            if (matrix[i][j] != matrix[i - 1][j - 1]) return false;
        }
    }
    return true;
}
