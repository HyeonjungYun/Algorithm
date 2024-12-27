#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    
    int key;
    
    for (int i = 0; i < seoul.size(); i++) {
        if (seoul[i] == "Kim")
            key = i;
    }
    
    answer += "김서방은 ";
    answer += to_string(key);
    answer += "에 있다";
    
    return answer;
}