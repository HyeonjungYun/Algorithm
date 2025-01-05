#include <string>
#include <vector>

using namespace std;

bool checkSkip (string skip, char c) {
    for (char skipAlp : skip) 
        if (skipAlp == c) return true;
    
    return false;
}

char nextAlp (char c, string skip, int index) {
    int count = 0;
    
    while (count < index) {
        c++;
        
        if (c > 'z') c = 'a';
        
        if (checkSkip(skip, c)) continue;
       
        count++;
    }
    
    return c;
}

string solution(string s, string skip, int index) {
    string answer = "";
    
    for (int i = 0; i < s.size(); i++) 
        answer += nextAlp(s[i], skip, index);
    
    return answer;
}