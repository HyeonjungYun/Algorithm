#include <string>
#include <vector>

using namespace std;

bool checkDuplication(vector<int>& answer, int num) {
    for (int n : answer) 
        if (num == n) return true;        
    return false;
}

void sort(vector<int>& numbers) {
    for (int number : numbers) 
        for (int i = 0; i < numbers.size() - 1; i++) 
            if (numbers[i] > numbers[i + 1]){
                int tmp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = tmp;
            }
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for (int i = 0; i < numbers.size(); i++)
        for (int j = 0; j < numbers.size(); j++) {
            if (i == j) continue;
            
            int num = numbers[i] + numbers[j];
            
            if (!checkDuplication(answer, num)) answer.push_back(num);
        }
    
    sort(answer);
    
    return answer;
}