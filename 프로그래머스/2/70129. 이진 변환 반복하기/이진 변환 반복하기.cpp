#include <string>
#include <vector>
#include <iostream>
using namespace std;

int conversion(string& s)
{
    string tempS = "";
    int count = 0;
    for (char c : s)
    {
        if (c == '0') 
        {
            count++;
            continue;
        }
            
        tempS += c;
    }
    
    int tmp = tempS.size();
    string out = "";
    
    while(tmp > 0)
    {
        out += (tmp % 2) + '0';
        tmp /= 2;
    }
    
    // int i = 0;
    // while(1)
    // {
    //     if (out[i] == '1')
    //     {
    //         out.substr(i);
    //         break;
    //     }
    //     i++;
    // }
    s = out;

    return count;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int count = 0;
    int zeroCount = 0;
    while(1)
    {
        zeroCount += conversion(s);
        count++;
        
        if (s.size() == 1) break;
    }
    
    answer.push_back(count);
    answer.push_back(zeroCount);
    return answer;
}