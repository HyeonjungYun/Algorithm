#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, int k, vector<int> enemy) 
{    
    if (k >= enemy.size())
    {
        return enemy.size();
    }
    
    int tmp = 0;
    
    priority_queue<int> pq;
    
    for (int i = 0; i < enemy.size(); i++)
    {
        tmp += enemy[i];
        pq.push(enemy[i]);
        
        if (tmp > n)
        {
            if (k <= 0)
            {
                return i;
            }
            
            tmp -= pq.top();
            pq.pop();
            k--;
            
            if (tmp > n)
            {
                return i;
            }
                
        }
    }
    
    return enemy.size();
}