/*
Problem: Pascal's Triangle
Link: https://www.codingninjas.com/codestudio/problems/pascal-s-triangle_1089580

Given an integer numRows, return the first numRows of Pascal's triangle.
*/
#include<bits/stdc++.h>

#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;
    for (int i = 0; i < numRows; ++i) {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }
    return triangle;
}