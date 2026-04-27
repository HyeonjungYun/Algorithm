#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> registerList;
    
    for (string s: participant)
    {
        registerList[s] = 0;
    }
    
    for (string s: participant)
    {
        ++registerList[s];
    }
    
    for (string s: completion)
    {
        --registerList[s];
    }
    
    for (string s: participant)
    {
        if (registerList[s] > 0)
        {
            answer = s;
            break;
        }
    }
    
    return answer;
}