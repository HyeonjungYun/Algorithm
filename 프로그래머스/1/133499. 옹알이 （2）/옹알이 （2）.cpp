#include <string>
#include <vector>

using namespace std;

int searchBabbling(vector<string> babbling) {
    int count = 0;
    
    string pretmp;
    for (string b : babbling) {
        string tmp;
        
        for (int i = b.size() - 1; i >= 0; i--){
            tmp += b[i];
            
            if (pretmp == tmp) break;
            
            if (tmp == "aya") {
                pretmp = tmp;
                tmp.clear();
            }
            if (tmp == "ey"){ 
                pretmp = tmp;
                tmp.clear();
            }
            if (tmp == "am") {
                pretmp = tmp;
                tmp.clear();
            }
            if (tmp == "oow") {
                pretmp = tmp;
                tmp.clear();
            }
        }
        pretmp.clear();
        
        if (tmp == "") count++;
    }
    
    return count;
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    answer += searchBabbling(babbling);
    
    return answer;
}