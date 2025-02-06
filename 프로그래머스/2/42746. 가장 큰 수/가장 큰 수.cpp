#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp (int a, int b)
{
    string tmpA = to_string(a);
    string tmpB = to_string(b);
    
    string AB = tmpA + tmpB;
    string BA = tmpB + tmpA;
    
    return stoi(AB) > stoi(BA);
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), comp);
    
    for (int number : numbers)
    {
        string tmp = to_string(number);
        
        answer += tmp;
    }
    
    if (answer[0] == '0')
    {
        answer = "0";
    }
    
    return answer;
}