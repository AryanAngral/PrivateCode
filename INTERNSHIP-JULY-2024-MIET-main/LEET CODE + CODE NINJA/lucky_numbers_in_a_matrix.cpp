
/*
Problem: Lucky Numbers in a Matrix
Link: https://leetcode.com/problems/lucky-numbers-in-a-matrix/

Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
*/
#include<bits/stdc++.h>

#include <vector>
using namespace std;

vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    vector<int> result;
    for (int i = 0; i < matrix.size(); ++i) {
        int min_row = *min_element(matrix[i].begin(), matrix[i].end());
        int col = find(matrix[i].begin(), matrix[i].end(), min_row) - matrix[i].begin();
        bool is_lucky = true;
        for (int j = 0; j < matrix.size(); ++j) {
            if (matrix[j][col] > min_row) {
                is_lucky = false;
                break;
            }
        }
        if (is_lucky) result.push_back(min_row);
    }
    return result;
}
