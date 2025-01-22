#include <string>
#include <vector>
#include <queue>

using namespace std;

bool pop(queue<int>& q, int& location)
{
    q.pop();
    location--;
    
    if (location < 0) return true;
    return false;
}

void popAndPush(queue<int>& q, int& location)
{
    q.push(q.front());
    q.pop();
    
    if (location > 0)
    {
        location--;
        return;
    }
    location = q.size() - 1;
}

const bool check(queue<int> q)
{
    int key = q.front();
    q.pop();
    
    int size = q.size();
    for (int i = 0; i < size - 1; i++)
    {
        int tmp = q.front();
        if (tmp > key) return true;
        
        q.pop();
    }
    
    return false;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    
    for (int priority : priorities)
        q.push(priority);
    
    while(1)
    {
        if (check(q))
        {
            popAndPush(q, location);
            continue;
        }
        
        answer++;
        if (pop(q, location)) break;
    }
    
    return answer;
}