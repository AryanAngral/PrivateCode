
/*
Problem: Matrix Diagonal Sum
Link: https://leetcode.com/problems/matrix-diagonal-sum/

Given a square matrix mat, return the sum of the matrix diagonals.
*/
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size();
    int total = 0;
    for (int i = 0; i < n; ++i) {
        total += mat[i][i]; // Primary diagonal
        if (i != n - i - 1) {
            total += mat[i][n - i - 1]; // Secondary diagonal
        }
    }
    return total;
}
