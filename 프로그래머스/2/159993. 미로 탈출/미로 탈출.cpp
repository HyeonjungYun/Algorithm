#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<string> maps) {
    int answer = 0;
    bool bOnLever = false;
    
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].length(), false));
    
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[0].length(); j++)
        {
            if (maps[i][j] == 'S')
            {
                q.push({{i, j}, 0});
                visited[i][j] = true;
                break;
            }
        }
        if (!q.empty())
        {
            break;
        }
    }
    
    while(!q.empty())
    {
        auto [pos, cnt] = q.front();
        auto [y, x] = pos;
        q.pop();
        
        if (bOnLever == false && maps[y][x] == 'L')
        {
            bOnLever = true;
            q = queue<pair<pair<int, int>, int>>();
            visited.assign(maps.size(), vector<bool>(maps[0].length(), false));
            visited[y][x] = true;
        }
        
        if (bOnLever == true && maps[y][x] == 'E')
        {
            answer = cnt;
            break;
        }
        
        if ((y - 1) >= 0 && maps[y - 1][x] != 'X' && !visited[y - 1][x])
        {
            visited[y - 1][x] = true;
            q.push({{y-1, x}, cnt + 1});
        }
        if ((x - 1) >= 0 && maps[y][x - 1] != 'X' && !visited[y][x - 1])
        {
            visited[y][x - 1] = true;
            q.push({{y, x-1}, cnt + 1});
        }
        if ((y + 1) < maps.size() && maps[y + 1][x] != 'X' && !visited[y + 1][x])
        {
            visited[y + 1][x] = true;
            q.push({{y+1, x}, cnt + 1});
        }
        if ((x + 1) < maps[0].length() && maps[y][x + 1] != 'X' && !visited[y][x + 1])
        {
            visited[y][x + 1] = true;
            q.push({{y, x+1}, cnt + 1});
        }
    }
    
    if (answer == 0)
    {
        return -1;
    }
    return answer;
}