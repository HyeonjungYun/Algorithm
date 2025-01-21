#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<unsigned int, unsigned int> count;
    
    for (int t : tangerine)
        count[t]++;
    
    vector<int> totalCount;
    
    for (auto pair : count)
        totalCount.push_back(pair.second);
    
    sort(totalCount.begin(), totalCount.end());
    
    int sum = 0, c = 0;
    
    for (int i = totalCount.size() - 1; i >= 0; i--)
    {
        sum += totalCount[i];
        c++;
        
        if (sum >= k) 
        {
            answer = c;
            break;
        }
    }
    
    return answer;
}