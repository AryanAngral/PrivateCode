
//https://leetcode.com/problems/flipping-an-image/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int rows=image.size();
        int cols=image[0].size();

        for(int i=0;i<rows;i++){
            reverse(image[i].begin(),image[i].end());
        }
        for(int j=0;j<rows;j++){
            for(int k=0;k<cols;k++){
                if(image[j][k]==0){
                    image[j][k]=1;
                }
                else{
                    image[j][k]=0;
                }
            }
        }
        return image;
    }
};