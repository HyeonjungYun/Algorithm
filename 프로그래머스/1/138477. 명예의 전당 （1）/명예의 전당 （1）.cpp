#include <string>
#include <vector>

using namespace std;

void sort(vector<int> &hallOfFame) {
    for(int i = 0; i < hallOfFame.size(); i++)
        for(int j = 0; j < hallOfFame.size() - 1; j++) {
            if(hallOfFame[j] < hallOfFame[j+1]){
                int tmp = hallOfFame[j];
                hallOfFame[j] = hallOfFame[j + 1];
                hallOfFame[j + 1] = tmp;
            }
        }
}

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> hallOfFame;
    
    for (int i = 0; i < score.size(); i++){
        hallOfFame.push_back(score[i]);
        sort(hallOfFame);
        
        if (hallOfFame.size() > k) {
            hallOfFame.pop_back();
            answer.push_back(hallOfFame[k - 1]);
        }
        else answer.push_back(hallOfFame[hallOfFame.size() - 1]);
        
    }
    
    return answer;
}