#include <string>
#include <vector>
#include <sstream>

using namespace std;
void upChar(char& c)
{
    if (c <= 'z' && c >= 'a')
        c -= 'a' - 'A';
}

void downChar(char& c)
{
    if (c <= 'Z' && c >= 'A')
        c += 'a' - 'A';
}

string solution(string s) {
    string answer = "";
    
    for (int i = 0; i < s.size(); i++)
    {
        if (i == 0) 
        {
            upChar(s[0]);
            continue;
        }
        
        if (s[i - 1] == ' ' && s[i] != ' ')
        {
            upChar(s[i]);
        }
        else if (s[i - 1] != ' ' && s[i] != ' ') 
        {
            downChar(s[i]);
        }
        
        
    }
    return s;
}