
/*
Problem: Available Captures for Rook
Link: https://leetcode.com/problems/available-captures-for-rook/

On an 8x8 chessboard, there is exactly one white rook and some number of black bishops and white pawns. Return the number of available captures for the white rook.
*/
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int numRookCaptures(vector<vector<char>>& board) {
    int captures = 0, rookX, rookY;

    // Find the rook's position
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == 'R') {
                rookX = i;
                rookY = j;
                break;
            }
        }
    }

    // Check in all four directions
    int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    for (auto& dir : directions) {
        int x = rookX + dir[0], y = rookY + dir[1];
        while (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (board[x][y] == 'B') break;
            if (board[x][y] == 'p') {
                captures++;
                break;
            }
            x += dir[0];
            y += dir[1];
        }
    }

    return captures;
}
