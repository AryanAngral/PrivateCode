
/*
Problem: Flipping an Image
Link: https://leetcode.com/problems/flipping-an-image/

Given an n x n binary matrix image, flip the image horizontally, then invert it.
*/
#include<bits/stdc++.h>

#include <vector>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    for (auto& row : A) {
        reverse(row.begin(), row.end());
        for (int& pixel : row) {
            pixel ^= 1;
        }
    }
    return A;
}
