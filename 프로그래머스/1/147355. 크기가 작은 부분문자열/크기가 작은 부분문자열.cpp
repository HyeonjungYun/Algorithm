#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    int pLen = p.size();
    int tLen = t.size();
    
    for (int i = 0; i < tLen - pLen + 1; i++) {
        string tmp = "";
        
        for (int j = i; j < i + pLen; j++)
            tmp += t[j];
        
        if(stoll(tmp) <= stoll(p)) answer++;
        cout << tmp << " " << p << endl;
    }
    
    return answer;
}