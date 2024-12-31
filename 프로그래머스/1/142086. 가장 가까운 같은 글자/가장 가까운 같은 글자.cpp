#include <string>
#include <vector>

using namespace std;

int checkSameAlp(string s, int index) {
    for (int i = index - 1; i >= 0; i--) 
        if (s[i] == s[index]) return index - i;
    return -1;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    for (int i = 0; i < s.size(); i++) 
        answer.push_back(checkSameAlp(s, i));
    
    return answer;
}