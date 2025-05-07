#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int changeAlp(char& c)
{
    if ((c - 'A') < (('Z' - c) + 1))
    {
        return c - 'A';
    }
    return ('Z' - c) + 1;
}

int moveLeft(int idx, int size)
{
    if (idx - 1 < 0)
    {
        return size;
    }
    return idx - 1;
}

int moveRight(int idx, int size)
{
    if (idx + 1 > size)
    {
        return 0;
    }
    return idx + 1;
}

int solution(string name) {
    int answer = 0;
    
    queue<pair<pair<string, int>, int>> q;
    q.push({{string(name.size(), 'A'), 0}, 0});
    
    while(!q.empty())
    {
        auto [tmp, cnt] = q.front();
        q.pop();
        auto [tmpStr, idx] = tmp;
       
        if (name[idx] != tmpStr[idx])
        {
            cnt += changeAlp(name[idx]);
            tmpStr[idx] = name[idx];
        }
        if (tmpStr == name)
        {
            answer = cnt;
            break;
        }
        
        q.push({{tmpStr, moveLeft(idx, name.size() - 1)}, cnt + 1});
        q.push({{tmpStr, moveRight(idx, name.size() - 1)}, cnt + 1});
    }
    return answer;
}