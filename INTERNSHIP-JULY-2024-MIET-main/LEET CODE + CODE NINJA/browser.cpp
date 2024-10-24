
/*
Problem: Browser History
Link: https://www.codingninjas.com/codestudio/problems/browser_2427908

Implement a simple browser history system.
*/

#include <stack>
#include <string>
#include<bits/stdc++.h>
using namespace std;


class BrowserHistory {
private:
    stack<string> history;
    stack<string> future;

public:
    BrowserHistory(string homepage) {
        history.push(homepage);
    }
    
    void visit(string url) {
        history.push(url);
        while (!future.empty()) future.pop();
    }
    
    string back(int steps) {
        while (steps-- && history.size() > 1) {
            future.push(history.top());
            history.pop();
        }
        return history.top();
    }
    
    string forward(int steps) {
        while (steps-- && !future.empty()) {
            history.push(future.top());
            future.pop();
        }
        return history.top();
    }
};
