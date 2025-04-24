#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int32_t answer = 0;
    
    vector<vector<int32_t>> priority;
    
    int32_t max_idx = fmin(((picks[0] + picks[1] + picks[2]) * 5), minerals.size());
    
    int32_t dur_d = 0;
    int32_t dur_i = 0;
    int32_t dur_s = 0;
    for (int i = 0; i < max_idx; i++)
    {
        if ((i % 5 == 0) && i != 0)
        {
            priority.push_back(vector<int32_t>({dur_d, dur_i, dur_s}));
            
            dur_d = 0;
            dur_i = 0;
            dur_s = 0;
        }
        if (minerals[i] == "diamond")
        {
            dur_d += 1;
            dur_i += 5;
            dur_s += 25;
        }
        if (minerals[i] == "iron")
        {
            dur_d += 1;
            dur_i += 1;
            dur_s += 5;
        }
        if (minerals[i] == "stone")
        {
            dur_d += 1;
            dur_i += 1;
            dur_s += 1;
        }
    }
    if (dur_d)
    {
        priority.push_back(vector<int>({dur_d, dur_i, dur_s}));
    }
    
    sort(priority.begin(), priority.end(), [](vector<int>& a, vector<int>& b) {
        return a[2] > b[2];
    });
    
    int32_t idx = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < picks[i]; j++)
        {
            if (i == 0)
            {
                answer += priority[idx][0];
            }
            if (i == 1)
            {
                answer += priority[idx][1];
            }
            if (i == 2)
            {
                answer += priority[idx][2];
            }
            idx++;
            
            if (idx == (priority.size()))
            {
                break;
            }
        }
        if (idx == (priority.size()))
        {
            break;
        }
    }    
    
    return answer;
}