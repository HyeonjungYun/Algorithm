#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int totalSize = queue1.size() + queue2.size();
    
    queue<int> q1, q2;
    long long sum1 = 0, sum2 = 0;
    for(int elem : queue1)
    {
        sum1 += (long long)elem;
        q1.push(elem);
    }
    
    for(int elem : queue2)
    {
        sum2 += (long long)elem;
        q2.push(elem);
    }
    
    while(sum1 != sum2)
    {
        if (sum1 > sum2)
        {
            int tmp = q1.front();
            q1.pop();
            q2.push(tmp);
            sum1 -= (long long)tmp;
            sum2 += (long long)tmp;
            answer++;
        }
        
        if (sum1 < sum2)
        {
            int tmp = q2.front();
            q2.pop();
            q1.push(tmp);
            sum2 -= (long long)tmp;
            sum1 += (long long)tmp;
            answer++;
        }
        
        if (answer > (totalSize * 2))
        {
            answer = -1;
            break;
        }
    }
    
    return answer;
}