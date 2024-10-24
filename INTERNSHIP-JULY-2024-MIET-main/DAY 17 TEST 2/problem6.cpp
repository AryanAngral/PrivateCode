/*https://leetcode.com/problems/sorting-the-sentence/ */
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string sortSentence(string s) {
      vector<string> words;
        string word;
        for (char c : s)
        {
            if (c == ' ') {
                words.push_back(word);
                word.clear();
        }
        else
        {
            word += c;
        }
         }
    words.push_back(word);

    vector<pair<int, string>> sortedWords;
    for (string w : words)
    {
        int pos = w.back() - '0';
        string cleanWord = w.substr(0, w.size() - 1);
        sortedWords.push_back({pos, cleanWord});
    }

    sort(sortedWords.begin(), sortedWords.end());

    string result;
    for (auto &p : sortedWords)
    {
        result += p.second + " ";
    }

    return result.substr(0, result.size() - 1);

        
    }
};