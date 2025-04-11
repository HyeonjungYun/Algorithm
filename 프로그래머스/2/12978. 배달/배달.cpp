#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    
    vector<vector<pair<int,int>>> graph(N + 1, vector<pair<int,int>>());
    for (vector<int> r : road)
    {
        graph[r[0]].push_back({r[1], r[2]});
        graph[r[1]].push_back({r[0], r[2]});
    }
    
    vector<int> dist(N + 1, INT_MAX);
    dist[1] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    
    while(!q.empty())
    {
        auto [curTime, curVillage] = q.top();
        q.pop();
        
        if (curTime > dist[curVillage])
        {
            continue;
        }
        
        for (auto& [nextVillage, roadTime] : graph[curVillage])
        {
            int nextTime = curTime + roadTime;
            
            if (nextTime < dist[nextVillage])
            {
                dist[nextVillage] = nextTime;
                q.push({nextTime, nextVillage});
            }
        }
    }
    
    for (int d : dist)
    {
        if (d <= K)
        {
            answer++;
        }
    }
    
    return answer;
}