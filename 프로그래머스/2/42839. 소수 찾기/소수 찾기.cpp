#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool comp (int a, int b)
{
    return a > b;
}

int searchBigNumber(vector<int> v)
{
    sort(v.begin(), v.end(), comp);
    
    int out = 0;
    
    for (const int& number : v)
    {
        out *= 10;
        out += number;
    }
    
    return out;
}

void makeVector (int i, vector<int>& num)
{
    while(i > 0)
    {
        num.push_back(i % 10);
        i /= 10;
    }
}

bool check(vector<int> nums, unordered_map<int, int> numberCount)
{
    for (int n: nums)
    {
        if (numberCount[n] <= 0)
        {
            return false;
        }
        else
        {
            numberCount[n]--;
        }
    }
            
    return true;   
}

int solution(string numbers) {
    int answer = 0;
    
    vector<int> v;
    
    for (const char& number : numbers)
    {
        v.push_back(number - '0');
    }
    int num = searchBigNumber(v);
    
    vector<bool> vNumbers(num + 1, true);
    
    for (int i = 2; i * i <= num; i++)
    {
        if (vNumbers[i])
        {
            for (int k = i * i; k <= num; k += i)
            {
                vNumbers[k] = false;
            }
        }
    }
    
    unordered_map<int, int> numberCount;
    vector<int> n;
    makeVector(num, n);
    
    for (int number : n)
    {
        numberCount[number]++;
    }
    
    for (int i = 2; i <= num; i++)
    {
        if (vNumbers[i])
        {
            vector<int> nums;
            makeVector(i, nums);
            
            if(check(nums, numberCount))
            {
                answer++;
            }
        }
    }
    
    return answer;
}