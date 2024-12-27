#include <string>
#include <vector>

using namespace std;

void sort(string &s) {
    for (int i = 0; i < s.size(); i++)
        for (int j = 0; j < s.size() - 1; j++){
            if (s[j] < s[j+1]){
                char tmp = s[j];
                s[j] = s[j+1];
                s[j+1] = tmp;
            }
        }
}

string solution(string s) {
    string answer = "";
    
    sort(s);
    
    return s;
}