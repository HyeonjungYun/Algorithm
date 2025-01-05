#include <string>
#include <vector>

using namespace std;

int searchKeyIndex(string keymap, char key) {
    
    for (int i = 0; i < keymap.size(); i++)
        if (keymap[i] == key) return i;
    
    return -1;
}

int searchTimeNumber(vector<string> keymaps, char key) {
    int min = 999999;
    
    for (string keymap : keymaps) {
        int tmp = searchKeyIndex(keymap, key);
        if (tmp >= 0 && min > tmp) min = tmp;
    }
    
    if (min == 999999) return -1;
    return min + 1;
}

int searchTotalTimeNumber(vector<string> keymaps, string target) {
    int totalTimeNumber = 0;
    
    for (char key : target) {
        int tmp = searchTimeNumber(keymaps, key);
        
        if (tmp < 0) return -1;
        
        totalTimeNumber += tmp;
    }
    
    return totalTimeNumber;
}

vector<int> solution(vector<string> keymaps, vector<string> targets) {
    vector<int> answer;
    
    for (string target : targets) 
        answer.push_back(searchTotalTimeNumber(keymaps, target));
    
    return answer;
}