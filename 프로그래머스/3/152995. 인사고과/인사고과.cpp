#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 1;
    
    vector<vector<int>> survivors;
    pair<int, int> key = make_pair(scores[0][0], scores[0][1]);
    
    sort(scores.begin(), scores.end(), [](vector<int> a, vector<int> b)
         {
             if (a[0] != b[0]) return a[0] > b[0];
             return a[1] < b[1];
         });
    
    int max_1 = -1;
    for (vector<int>& score : scores)
    {
        if (score[1] >= max_1)
        {
            max_1 = score[1];
            survivors.push_back(score);
        }
        else
        {
            if (score[0] == key.first && score[1] == key.second)
            {
                return -1;
            }
        }
    }
    
    for (vector<int>& score : survivors)
    {
        if ((key.first + key.second) < (score[0] + score[1]))
        {
            answer++;
        }
    }
    
    return answer;
}