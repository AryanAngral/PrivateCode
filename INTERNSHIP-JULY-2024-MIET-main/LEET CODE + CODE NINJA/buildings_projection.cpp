
/*
Problem: Buildings Projection
Link: https://www.codingninjas.com/codestudio/problems/buildings-projection_1466964

Given an n x n grid, where 0 represents empty space and 1 represents a building, find the max sum of projections of the grid.
*/
#include<bits/stdc++.h>

#include <vector>
using namespace std;

int projectionArea(vector<vector<int>>& grid) {
    int n = grid.size();
    int area = 0;
    for (int i = 0; i < n; ++i) {
        int rowMax = 0, colMax = 0;
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] > 0) area++;
            rowMax = max(rowMax, grid[i][j]);
            colMax = max(colMax, grid[j][i]);
        }
        area += rowMax + colMax;
    }
    return area;
}
