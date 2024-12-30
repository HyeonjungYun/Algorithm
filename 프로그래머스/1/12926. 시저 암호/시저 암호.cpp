#include <string>
#include <vector>

using namespace std;

char pushUpChar(char tmp, int n) {
    if (tmp + n > 'Z') return tmp + n - ('Z' - 'A'  + 1);
    return tmp + n;
}

char pushDownChar(char tmp, int n) {
    if (tmp + n > 'z') return tmp + n - ('z' - 'a' + 1);
    return tmp + n;
}

string solution(string s, int n) {
    string answer = "";
    
    for (char c : s) {
        if (c >= 'a' && c <= 'z') answer += pushDownChar(c, n);
        else if (c >= 'A' && c <= 'Z') answer += pushUpChar(c, n);
        else answer += c;
    }
    
    return answer;
}