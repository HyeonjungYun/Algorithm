#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    
    int sum = 0;
    for (auto number : numbers) 
        sum += number;
    
    answer = (float)sum / numbers.size();
    
    return answer;
}