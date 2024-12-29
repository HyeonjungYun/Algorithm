#include <string>
#include <vector>

using namespace std;

char convertB(char tmp) {
    if (tmp >= 'a' && tmp <= 'z') 
        return tmp - 32;
    return tmp;
}

char convertS(char tmp) {
    if (tmp >= 'A' && tmp <= 'Z') 
        return tmp + 32;
    return tmp;
}

string solution(string s) {
    int key = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            key = i + 1;
            continue;
        }
        
        if (((i - key) + 1) % 2 == 1) s[i] = convertB(s[i]);
        if (((i - key) + 1) % 2 == 0) s[i] = convertS(s[i]);
    }
    
    return s;
}