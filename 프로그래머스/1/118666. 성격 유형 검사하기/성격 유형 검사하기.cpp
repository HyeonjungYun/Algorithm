#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void testMyType(unordered_map<char,int> &type, vector<string> survey, vector<int> choices) {
    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] < 4) type[survey[i][0]] += 4 - choices[i];
        if (choices[i] > 4) type[survey[i][1]] += choices[i] - 4;
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char,int> type;
    type['R'] = 0;
    type['T'] = 0;
    type['C'] = 0;
    type['F'] = 0;
    type['J'] = 0;
    type['M'] = 0;
    type['A'] = 0;
    type['N'] = 0;
    
    testMyType(type, survey, choices);
    
    if (type['R'] < type['T']) answer += "T";
    else answer += "R";
    if (type['C'] < type['F']) answer += "F";
    else answer += "C";
    if (type['J'] < type['M']) answer += "M";
    else answer += "J";
    if (type['A'] < type['N']) answer += "N";
    else answer += "A";
    
    return answer;
}