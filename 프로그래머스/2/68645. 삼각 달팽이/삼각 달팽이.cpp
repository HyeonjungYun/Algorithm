#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> triangle(n);
    
    for (int i = 0; i < n; i++)
    {
        triangle[i].assign(i + 1, 0);
    }
    
    int dx[] = { 1, 0, -1 };
    int dy[] = { 0, 1, -1 };
    int i, j, num = 1, dir = 0, cnt = 0, len = n;
    i = j = 0;
    
    while(len > 0)
    {
        triangle[i][j] = num++;
        cnt++;
        
        if (cnt == len)
        {
            dir = (dir + 1) % 3;
            cnt = 0;
            len--;
        }
        i += dx[dir];
        j += dy[dir];
    }
    
    for (const vector<int> v : triangle)
    {
        for (const int e : v)
        {
            answer.push_back(e);
        }
    }
    
    return answer;
}