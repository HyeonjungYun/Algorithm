#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    int y1, y2;
    for (int i = 1; i <= r2; i++)
    {
        y1 = ceil(sqrt(pow(r1, 2) - pow(i, 2)));
        y2 = floor(sqrt(pow(r2, 2) - pow(i, 2)));
        
        if (y1 < 0) y1 = 0;
        
        answer += (y2 - y1 + 1);
    }
    
    return answer * 4;
}