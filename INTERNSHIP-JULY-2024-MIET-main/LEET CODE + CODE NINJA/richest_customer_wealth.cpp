
/*
Problem: Richest Customer Wealth
Link: https://leetcode.com/problems/richest-customer-wealth/

You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i-th customer has in the j-th bank.
*/
#include<bits/stdc++.h>

#include <vector>
using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
    int max_wealth = 0;
    for (const auto& customer : accounts) {
        int wealth = 0;
        for (int money : customer) {
            wealth += money;
        }
        max_wealth = max(max_wealth, wealth);
    }
    return max_wealth;
}
