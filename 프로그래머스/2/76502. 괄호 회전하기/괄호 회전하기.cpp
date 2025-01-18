#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(string s, int size)
{
    stack<char> sStack;
    
    
    for (int i = 0; i < size; i++)
    {       
        if (sStack.empty())
        {
            sStack.push(s[i]);
            continue;
        }
        char tmp = s[i];
        
        if (sStack.top() == '{')
            if (tmp == '}'){
                sStack.pop();
                continue;
            }
        
        if (sStack.top() == '(')
            if (tmp == ')') {
                sStack.pop();
                continue;
            }
        
        if (sStack.top() == '[')
            if (tmp == ']') {
                sStack.pop();
                continue;
            }
        
        sStack.push(tmp);
    }
    
    if (sStack.empty()) return true;
    return false;
}

int solution(string s) {
    int answer = 0;
    
    int size = s.size();
    for(int i = 0; i < size; i++)
    {
        string tmp = "";
        
        for (int j = 0; j < size; j++)
        {
            if (i + j < size)
                tmp += s[i + j];
            if (i + j >= size)
                tmp += s[(i + j) - size];
        }
        if (check(tmp, size))
            answer++;
    }
    
    return answer;
}