#include <iostream>

using namespace std;

void convertEven(int& tmp, int n)
{
    if (tmp % 2 == 1 && (tmp + 1) <= n)
        tmp += 1;
}

void conditionalSwap(int& a, int& b)
{
    if (a > b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
}

int solution(int n, int a, int b)
{
    int answer = 1;

    conditionalSwap(a, b);
    
    while(a >= 1)
    {
        if(a % 2 == 1 && b % 2 == 0 && a == b - 1)
            return answer;
        
        convertEven(a, n);
        convertEven(b, n);
        
        a /= 2;
        b /= 2;
        answer++;
    }

    return answer;
}