#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> clothesCount;
    
    for (vector<string> clothe : clothes)
        clothesCount[clothe[1]]++;
    
    for (auto pair : clothesCount)
    {
        answer *= pair.second + 1;
    }
    
    return answer - 1;
}