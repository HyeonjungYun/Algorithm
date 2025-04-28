#include <string>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> moveRobot(vector<string>& board,pair<int, int> tmp, int way)
{
    auto [y, x] = tmp;
    // 1 상 2 하 3 좌 4 우
    if (way == 1)
    {
        for (int i = 0; i < board.size(); i++)
        {
            if ((y - i - 1) < 0 || board[y - i - 1][x] == 'D')
            {
                return make_pair((y - i), x);
            }
        }
    }
    if (way == 2)
    {
        for (int i = 0; i < board.size(); i++)
        {
            if ((y + i + 1) >= board.size() || board[y + i + 1][x] == 'D')
            {
                return make_pair((y + i), x);
            }
        }
    }
    if (way == 3)
    {
        for (int i = 0; i < board[0].length(); i++)
        {
            if ((x - i - 1) < 0 || board[y][x - i - 1] == 'D')
            {
                return make_pair(y, (x - i));
            }
        }
    }
    if (way == 4)
    {
        for (int i = 0; i < board[0].length(); i++)
        {
            if ((x + i + 1) >= board[0].length() || board[y][x + i + 1] == 'D')
            {
                return make_pair(y, (x + i));
            }
        }
    }
    
    return tmp;
}

pair<int, int> searchStart(vector<string>& board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].length(); j++)
        {
            if (board[i][j] == 'R')
            {
                return make_pair(i, j);
            }
        }
    }
    
    return make_pair(0, 0);
}

int solution(vector<string> board) {
    int answer = -1;
    
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].length(), false));

    pair<int, int> startPoint = searchStart(board);
    q.push({startPoint, 0});
    visited[startPoint.first][startPoint.second] = true;
    
    while(!q.empty())
    {
        auto [point, cnt] = q.front();
        auto [y, x] = point;
        q.pop();
        
        if (board[y][x] == 'G')
        {
            answer = cnt;
            break;
        }
        
        for (int i = 1; i <= 4; i++)
        {
            auto [nextY, nextX] = moveRobot(board, make_pair(y, x), i);
            
            if (!(nextY == y && nextX == x) && !visited[nextY][nextX])
            {
                q.push({{nextY, nextX}, cnt + 1});
                visited[nextY][nextX] = true;
            }
        }
    }
    
    return answer;
}