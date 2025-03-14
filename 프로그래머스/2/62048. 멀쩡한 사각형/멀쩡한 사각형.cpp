#include <cmath>

using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    
    double ratio = (double)h / w;
    
    for (int i = 1; i <= w; i++)
    {
        int height = (h - ceil(i * ratio));
        if (height > 0)
        {
            answer += height;
        }
    }
    
    answer *= 2;
    return answer;
}