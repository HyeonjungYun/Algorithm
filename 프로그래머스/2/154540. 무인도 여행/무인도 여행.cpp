#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<bool>> visited;

vector<pair<int, int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int dfs(const vector<string>& maps, pair<int, int> pos)
{
    auto [x, y] = pos;
    
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return 0;
    }
    if (maps[x][y] == 'X' || visited[x][y])
    {
        return 0;
    }
    
    visited[x][y] = true;
    int sum = maps[x][y] - '0';
    
    for (pair<int, int> dir : directions)
    {
        sum += dfs(maps, {x + dir.first, y + dir.second});
    }
    
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    n = maps.size(), m = maps[0].length();
    visited.assign(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maps[i][j] != 'X' && !visited[i][j])
            {   
                answer.push_back(dfs(maps, {i, j}));
            }
        }
    }
    if (answer.empty())
    {
        answer.push_back(-1);
        return answer;
    }
    else
    {
        sort(answer.begin(), answer.end());   
    }
    
    return answer;
}