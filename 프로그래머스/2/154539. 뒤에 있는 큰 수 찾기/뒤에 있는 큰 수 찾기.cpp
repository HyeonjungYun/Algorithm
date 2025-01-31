#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    int size = numbers.size();
    vector<int> answer(size , -1);
    stack<int> s;
    
    for (int i = size - 1; i >= 0; i--)
    {
        while(!s.empty() && numbers[i] >= s.top())
            s.pop();
        
        if (!s.empty())
            answer[i] = s.top();
            
        s.push(numbers[i]);
    }
    
    return answer;
}