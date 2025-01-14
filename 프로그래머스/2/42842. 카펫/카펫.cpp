#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> divisor(int sum)
{
    vector<int> div;
    
    for (int i = 1; i <= sum; i++)
        if (sum % i == 0) div.push_back(i);
    
    return div;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> yelloDiv = divisor(yellow);
    
    for (int i = 0; yelloDiv[i] <= sqrt(yellow); i++)
    {
        int row = yellow / yelloDiv[i];
        int col = yelloDiv[i];
        
        if (brown == (row * 2) + (col * 2) + 4)
        {
            answer.push_back(row + 2);
            answer.push_back(col + 2);
        }
    }
    return answer;
}