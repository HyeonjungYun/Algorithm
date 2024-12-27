#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    for (auto p : s){
        if (!(p >= '0' && p <='9')){
            answer = false;
            break;
        }
        if (!(s.size() == 4 || s.size() == 6)){
            answer = false;
            break;
        }
    }
    
    return answer;
}