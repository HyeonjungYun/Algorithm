#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void checkNumber(vector<int> &words, string word) {
    for (int i = 0; i < 10; i++)
        words.push_back(0);
    
    for (int i = 0; i < word.size(); i++) {
        words[word[i] - '0']++;
    }
}

string makeBigNumber(vector<int> wordX, vector<int> wordY) {
    vector<int> tmp;
    string out = "";
    
    for (int i = 0; i < wordX.size(); i++) {
        
        if (wordX[i] > 0 && wordY[i] > 0) {
            
            int len = wordX[i] < wordY[i] ? wordX[i] : wordY[i];
                
            for (int j = 0; j < len; j++)
                tmp.push_back(i);
        }
    }
    
    if (tmp.empty()) return "-1";
    
    sort(tmp.begin(), tmp.end());
    
    for (int i = tmp.size() - 1; i >=  0; i--)
        out += to_string(tmp[i]);
    
    if (out[0] == '0') return "0";
    
    return out;
}

#include <iostream>
string solution(string X, string Y) {
    string answer = "";
    
    vector<int> wordX, wordY;
    
    checkNumber(wordX, X);
    checkNumber(wordY, Y);
    
    return makeBigNumber(wordX, wordY);
}