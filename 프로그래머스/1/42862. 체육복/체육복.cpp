#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void deleteElement(vector<int> &tmp, int key) {
    tmp.erase(tmp.begin() + key);
}

void checkSpy(vector<int> &lost, vector<int> &reserve) {
    vector<int> lostI;
    
    for (int i = 0; i < lost.size(); i++) 
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] == reserve[j]){
                lostI.push_back(i);
                deleteElement(reserve, j);
                break;
            }
        }
    
    for (int i = lostI.size() - 1; i >= 0; i--) deleteElement(lost, lostI[i]);
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
}

int unsavedStudent(vector<int> lost, vector<int> reserve) {
    int len = lost.size();
    int saved = 0;
    
    for (int i = 0; i < len; i++) 
        for (int j = 0; j < reserve.size(); j++) 
            if (lost[i] + 1 == reserve[j] || lost[i] - 1 == reserve[j]){
                saved++;
                deleteElement(reserve, j);
                break;
            }
    
    return len - saved;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    checkSpy(lost, reserve);
    if (lost.empty()) return n; 
    answer = n - unsavedStudent(lost, reserve);
    
    return answer;
}