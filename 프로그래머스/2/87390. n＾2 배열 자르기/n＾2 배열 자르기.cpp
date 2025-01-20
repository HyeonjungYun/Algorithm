#include <string>
#include <vector>

using namespace std;

long long searchTempNumber(int n, long long temp)
{
    long long tempNumber;
    
    long long tempRow, tempCol;
    tempRow = temp / n + 1;
    if (temp % n == 0)
        tempRow = n;
    tempCol = temp % n;
    
    if (tempRow > tempCol) return tempRow;
    return tempCol;
}

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long i = left; i <= right; i++)
    {
        answer.push_back(searchTempNumber(n, i + 1));
    }
    
    return answer;
}