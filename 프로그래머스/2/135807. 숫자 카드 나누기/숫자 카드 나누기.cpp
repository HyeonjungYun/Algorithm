#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int searchGcd(const vector<int>& array)
{
    int out = array[0];
    
    for (int i = 1; i < array.size(); i++)
    {
        out = __gcd(out, array[i]);
    }
    
    return out;
}

bool check(const vector<int>& array, int gcd)
{
    for (const int& elem : array)
    {
        if (elem % gcd == 0)
            return false;
    }
    
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    
    int gcdA = searchGcd(arrayA);
    int gcdB = searchGcd(arrayB);
    
    int maxGcd = max(gcdA, gcdB);
    int minGcd = min(gcdA, gcdB);
        
    int answerA = 0, answerB = 0;
        if (check(arrayA, gcdB))
        {
            answerB = gcdB;
            cout << gcdB << endl;
        }
            
        if (check(arrayB, gcdA))
        {
            answerA = gcdA;
            cout << gcdA << endl;
        }
            
        answer = max(answerA, answerB);
    
    if (answer == 1)
    {
        answer = 0;
    }
    return answer;
}