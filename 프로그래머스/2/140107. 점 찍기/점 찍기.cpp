#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    int x = 0, y;
    while(1)
    {
        long long tmp = pow(d, 2) - pow((x * k), 2);
        if (tmp < 0)
        {
            break;
        }
        
        y = (int)(sqrt(tmp) / k);
        answer += y + 1;
        x++;
    }
    
    return answer;
}