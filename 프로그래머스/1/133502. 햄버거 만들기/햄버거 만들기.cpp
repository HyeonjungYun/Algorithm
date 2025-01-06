#include <string>
#include <vector>
#include <stack>

using namespace std;

bool checkSequence (stack<int> &tmp, stack<int> answerSequence) {
    bool out = true;
    stack<int> garbage;
    
    for (int i = 0; i < 4; i++) {
        if (tmp.top() != answerSequence.top())
            out = false;
        
        garbage.push(tmp.top());
        tmp.pop();
        answerSequence.pop();
    }
    
    if (!out) {
        tmp.push(garbage.top());
        garbage.pop();
        tmp.push(garbage.top());
        garbage.pop();
        tmp.push(garbage.top());
        garbage.pop();
        tmp.push(garbage.top());
        garbage.pop();
    }
    
    return out;
}

int checkHamburger(const vector<int> &ingredient, stack<int> answerSequence) {
    stack<int> tmp;
    int out = 0;
                                                                              
    for (int i = 0; i < ingredient.size(); i++) {
        tmp.push(ingredient[i]);
        
        if (tmp.top() == 1 && tmp.size() >= 4) 
            if (checkSequence(tmp, answerSequence)) out++;
    }
                                                                              
    return out;
}

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> answerSequence;
    answerSequence.push(1);
    answerSequence.push(2);
    answerSequence.push(3);
    answerSequence.push(1);
    
    answer = checkHamburger(ingredient, answerSequence);
    
    return answer;
}