#include <vector>
#include <climits>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> maps)
{    
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    
    vector<pair<int, int>> directions = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
    
    q.push({{0,0}, 1});
    
    while(!q.empty())
    {
        auto [pos, count] = q.front();
        q.pop();
        
        int x = pos.first;
        int y = pos.second;
        
        if (x == maps.size() - 1 && y == maps[0].size() - 1)
            return count;
        
        for (auto dir : directions)
        {
            int nextX = x + dir.first;
            int nextY = y + dir.second;
            
            if (nextX <= maps.size() - 1 && nextX >= 0 && nextY <= maps[0].size() - 1 && nextY >= 0 
                && maps[nextX][nextY] != 0 && !visited[nextX][nextY])
            {
                visited[nextX][nextY] = true;
                q.push({{nextX, nextY}, count + 1});
            }
        }
    }
    return -1;
}