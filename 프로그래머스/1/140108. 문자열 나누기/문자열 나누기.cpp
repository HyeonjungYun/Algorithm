#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0, keyCount = 0, nonKeyCount = 0;
    char key = s[0];
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == key) keyCount++;
        if (s[i] != key) nonKeyCount++;
        
        if (keyCount == nonKeyCount) {
            keyCount = 0;
            nonKeyCount = 0;
            
            key = s[i + 1];
            answer++;
        }
    }
    
    if (keyCount > 0 || nonKeyCount > 0) answer++;
    
    return answer;
}