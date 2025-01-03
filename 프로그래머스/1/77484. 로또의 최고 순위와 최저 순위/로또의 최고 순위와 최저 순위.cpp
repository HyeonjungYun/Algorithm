#include <string>
#include <vector>

using namespace std;

void calculate(const vector<int> &lottos, const vector<int> &win_nums, int &max, int &min) {
    int count = 0, zeroCount = 0;
    for (int i = 0; i < lottos.size(); i++){
        if (lottos[i] == 0) zeroCount++;
        
        for (int num : win_nums) 
            if (lottos[i] == num) count++;
    }
    
    max = count + zeroCount;
    min = count;
}

int searchRank(int count) {
    if (count == 6) return 1;
    if (count == 5) return 2;
    if (count == 4) return 3;
    if (count == 3) return 4;
    if (count == 2) return 5;
    if (count == 1) return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int max, min;
    calculate(lottos, win_nums, max, min);
    
    answer.push_back(searchRank(max));
    answer.push_back(searchRank(min));
    
    return answer;
}