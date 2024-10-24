
/*
Problem: Special Positions in a Binary Matrix
Link: https://leetcode.com/problems/special-positions-in-a-binary-matrix/

Given an m x n binary matrix, return the number of special positions in the matrix.
*/
#include<bits/stdc++.h>

#include <vector>
using namespace std;

int numSpecial(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> rows(m, 0), cols(n, 0);

    // Calculate row and column sums
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 1) {
                rows[i]++;
                cols[j]++;
            }
        }
    }

    // Count special positions
    int count = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) {
                count++;
            }
        }
    }

    return count;
}
