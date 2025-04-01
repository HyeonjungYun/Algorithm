#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <climits>

using namespace std;

int calc(int y, int opar, int n)
{
    if (opar == 0)
    {
        return y - n;
    }
    if (opar == 1)
    {
        if (y % 2 == 0)
        {
            return y / 2;
        }
        else
        {
            return 0;
        }
    }
    if (opar == 2)
    {
        if (y % 3 == 0)
        {
            return y / 3;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

int bfs(int x, int y, int n)
{
    queue<pair<int, int>> q;
    unordered_set<int> visited;
    
    q.push({y, 0});
    visited.insert(y);
    
    while(!q.empty())
    {
        auto [cur, count] = q.front();
        q.pop();
        
        if (cur == x)
            return count;
        
        for (int i = 0; i < 3; i++)
        {
            int next = calc(cur, i, n);
            
            if (next >= x && visited.find(next) == visited.end())
            {
                q.push({next, count + 1});
                visited.insert(next);
            }
        }
    }
    
    return -1;
}

int solution(int x, int y, int n) {
    
    return bfs(x, y, n);
}