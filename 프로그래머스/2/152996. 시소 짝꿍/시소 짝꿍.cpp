#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    set<array<int, 2>> fairs;
    
    sort(weights.begin(), weights.end());
    
    for(int i = 0; i < weights.size(); i++)
    {
        for (int j = i + 1; j < weights.size(); j++)
        {
            if (weights[i] == weights[j])
            {
                answer++;
            }
            
            if (weights[i] * 3 == weights[j] * 2)
            {
                answer++;
            }
            
            if (weights[i] * 2 == weights[j])
            {
                answer++;
            }
            
            if (weights[i] * 4 == weights[j] * 3)
            {
                answer++;
            }
        }
    }
    
    return answer;
}