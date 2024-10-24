/* https://leetcode.com/problems/house-robber/description/*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
int f(vector<int>&A, int i)
    {
        if(i<0) return 0;

        return max(A[i]+f(A,i-2) , f(A,i-1));
    }

public:
    int rob(vector<int>& A) {
        int n=A.size();
        return f(A,n-1);
    }
};