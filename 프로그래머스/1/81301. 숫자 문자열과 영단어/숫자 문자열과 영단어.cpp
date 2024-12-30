#include <string>
#include <vector>

using namespace std;

int checkNumber(string tmp) {
    if (tmp == "zero") return 0;
    if (tmp == "one") return 1;
    if (tmp == "two") return 2;
    if (tmp == "three") return 3;
    if (tmp == "four") return 4;
    if (tmp == "five") return 5;
    if (tmp == "six") return 6;
    if (tmp == "seven") return 7;
    if (tmp == "eight") return 8;
    if (tmp == "nine") return 9;
    return 10;
}

int solution(string s) {
    int answer = 0;
    
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        tmp += s[i];
        
        if (s[i] >= '0' && s[i] <= '9') {
            answer *= 10;
            answer += s[i] - '0';
            tmp = "";
        }
        
        int num = checkNumber(tmp);
        if (num < 10) {
            answer *= 10;
            answer += num;
            tmp = "";
        }
    }
    
    return answer;
}