#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<int> v;
    
    for (int i = 0; i < dungeons.size(); i++)
        v.push_back(i);
    
    do
    {
        int tmp = k;
        int count = 0;
        
        for (int i = 0; i < v.size(); i++)
        {
            if (tmp >= dungeons[v[i]][0])
            {
                tmp -= dungeons[v[i]][1];
                count++;
                continue;
            }
            break;
        }
        
        answer = max(answer, count);
    }while(next_permutation(v.begin(), v.end()));
    
    return answer;
}