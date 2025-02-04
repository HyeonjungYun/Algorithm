#include <string>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    
    for (long long& number : numbers)
    {
        bitset<100> num = number;
        bitset<100> tmpNum;
        
        int digit = (int)log2(number) + 1;
        
        if (num.count() == digit)
            answer.push_back(number + (long long)pow(2, digit) - (long long)pow(2, digit - 1));
        else
        {
            if (num[0] == 0) answer.push_back(number + 1);
            else
            {
                for (int i = 0; i < digit; i++)
                {
                    if (num[i] == 0)
                    {
                        answer.push_back(number + (long long)pow(2, i) - (long long)pow(2, i - 1));
                        break;
                    }
                }
            }
        }
    }
    
    return answer;
}