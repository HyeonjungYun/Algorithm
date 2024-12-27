#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    vector<bool> numbersY(true, 10);
    
    for (auto number : numbers) {
        numbersY[number] = false;
    }
    
    for (int i = 0; i < 10; i++){
        if (numbersY[i]) answer += i;
    }
    
    return answer;
}