/*
Problem: Best Time to Buy and Sell Stock
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

You are given an array prices where prices[i] is the price of a given stock on the ith day. Find the maximum profit you can achieve.
*/
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int min_price = INT_MAX;
    int max_profit = 0;
    for (int price : prices) {
        if (price < min_price) {
            min_price = price;
        } else if (price - min_price > max_profit) {
            max_profit = price - min_price;
        }
    }
    return max_profit;
}