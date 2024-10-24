//https://leetcode.com/problems/search-a-2d-matrix/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // int rows = matrix.size()/ matrix[0].size();   
    // int cols = matrix[0].size() / sizeof(int); 
    int t=0;
        for(int i=0;i<matrix.size();i++){
            if(target<=matrix[i][matrix[i].size()-1]){
                // if(target==matrix[i][])
                t=i;
                for(auto j: matrix[t]){
                     if(target==j){
                    return true;
                    }
                }
            }
        }
        return false;
    }
};