#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    
    while(1)
    {
        bool check = true;
        for (int i = 0; i < number.size() - 1; i++)
        {
            if (number[i] < number[i + 1] && k > 0)
            {
                number.erase(i, 1);
                k--;
                check = false;
                break;
            }
        }
        
        if (k < 1 || check)
        {
            break;
        }
    }
    
    if (k > 0)
    {
        number.erase(number.length() - k, k);
    }
    
    return number;
}