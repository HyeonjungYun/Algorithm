#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    string word;
    stringstream ss(s);
    
    int max = -99999, min = 99999;
    while(ss >> word)
    {
        int tmp = stoi(word);
        
        if (tmp > max) max = tmp;
        if (tmp < min) min = tmp;
    }
    
    answer += to_string(min);
    answer += " ";
    answer += to_string(max);
        
    return answer;
}