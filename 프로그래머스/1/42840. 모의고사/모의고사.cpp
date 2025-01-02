#include <string>
#include <vector>

using namespace std;

void submission(vector<int> &out, int size, int num) {
    vector<int> num1 = {1,2,3,4,5};
    vector<int> num2 = {2,1,2,3,2,4,2,5};
    vector<int> num3 = {3,3,1,1,2,2,4,4,5,5};
    
    for (int i = 0; i < size; i++) {
        if (num == 1) out.push_back(num1[i % 5]);
        if (num == 2) out.push_back(num2[i % 8]);
        if (num == 3) out.push_back(num3[i % 10]);
    }
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> correctAnswer;
    int max = 0;
    
    for (int i = 1; i <= 3; i++) {
        vector<int> submitter;
        submission(submitter, answers.size(), i);
        
        int correct = 0;
        for (int j = 0; j < answers.size(); j++) 
            if (submitter[j] == answers[j]) correct++;
        
        if (max < correct) max = correct;
        
        correctAnswer.push_back(correct);
    }
    
    for (int i = 0; i < 3; i++)
        if (max == correctAnswer[i]) answer.push_back(i + 1);
    
    return answer;
}