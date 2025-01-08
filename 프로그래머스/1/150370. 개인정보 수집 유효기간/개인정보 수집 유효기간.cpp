#include <string>
#include <vector>

using namespace std;

const int calInterval(string &today, string privacy) {
    int yearGap = stoi(today.substr(0, 4)) - stoi(privacy.substr(0, 4));
    int monthGap = stoi(today.substr(5, 2)) - stoi(privacy.substr(5, 2));
    int dayGap = stoi(today.substr(8, 2)) - stoi(privacy.substr(8, 2));
    
    yearGap *= 12 * 28;
    monthGap *= 28;
    
    return yearGap + monthGap + dayGap;
}

const bool checkPeriod(vector<string> &terms, string privacy, int &gap) {
    int type;
    
    for (const string &term : terms)
        if (term[0] == privacy[11])
            type = stoi(term.substr(2));
    
    type *= 28;
    
    if (gap >= type) return true;
    return false;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int index = 1;
    for (const string &privacy : privacies) {
        int gap = calInterval(today, privacy);
        
        if (checkPeriod(terms, privacy, gap)) answer.push_back(index);
        index++;
    }
    
    return answer;
}