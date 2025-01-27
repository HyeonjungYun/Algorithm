#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

vector<char> convertK(int n, int k)
{
    vector<char> out;
    stack<char> outStack;
    
    while(n > 0)
    {
        outStack.push(n % k);
        n /= k;
    }
    
    int size = outStack.size();
    for (int i = 0; i < size; i++)
    {        
        out.push_back(outStack.top() + '0');
        outStack.pop();
    }
    
    return out;
}

bool checkPrimeNumber(long tmp)
{
    if (tmp < 2) return false;
    
    for (long i = 2; i <= sqrt(tmp); i++)
    {
        if (tmp % i == 0) return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    vector<char> kBitNumber = convertK(n, k);
    
    long tmp = 0;
    for (char bit : kBitNumber)
    {
        if (bit == '0') 
        {
            if (checkPrimeNumber(tmp)) 
            {
                answer++;
            }
            tmp = 0;
            continue;
        }
        
        tmp *= 10;
        tmp += (bit - '0');
    }
    
    if (checkPrimeNumber(tmp)) 
    {
        answer++;
    }
    
    return answer;
}