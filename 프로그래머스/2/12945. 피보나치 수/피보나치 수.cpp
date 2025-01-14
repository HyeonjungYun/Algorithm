#include <string>
#include <vector>

using namespace std;

void fiv(long long& first, long long& second)
{
    int tempFirst = first, tempSecond = second;
    
    first = tempSecond % 1234567;
    second = (tempFirst + tempSecond) % 1234567;
}

int solution(int n) {
    int answer;
    long long first = 0, second = 1;
    for (int i = 2; i <= n; i++)
    {
        fiv(first, second);
    }
    return second;
}