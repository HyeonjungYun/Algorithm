#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    double tmp = sqrt(n);
    
    if ((double)round(tmp) == tmp) answer = pow((int)tmp+1, 2);
    else answer = -1;
    
    return answer;
}