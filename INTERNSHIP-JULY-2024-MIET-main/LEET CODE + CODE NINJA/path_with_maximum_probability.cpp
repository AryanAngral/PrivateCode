/*
Problem: Path with Maximum Probability
Link: https://leetcode.com/problems/path-with-maximum-probability/

You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
*/

#include <vector>
#include <queue>
using namespace std;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<vector<pair<int, double>>> graph(n);
    for (int i = 0; i < edges.size(); ++i) {
        graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
        graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
    }
    
    priority_queue<pair<double, int>> pq;
    pq.emplace(1.0, start);
    vector<double> probabilities(n, 0.0);
    probabilities[start] = 1.0;
    
    while (!pq.empty()) {
        auto [prob, node] = pq.top(); pq.pop();
        if (node == end) return prob;
        for (auto [neighbor, edgeProb] : graph[node]) {
            double newProb = prob * edgeProb;
            if (newProb > probabilities[neighbor]) {
                probabilities[neighbor] = newProb;
                pq.emplace(newProb, neighbor);
            }
        }
    }
    
    return 0.0;
}