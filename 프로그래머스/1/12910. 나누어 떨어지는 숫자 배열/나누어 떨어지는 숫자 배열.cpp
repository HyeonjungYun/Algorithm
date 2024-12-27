#include <string>
#include <vector>

using namespace std;

void sort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++)
        for (int j = 0; j < arr.size() - 1; j++) 
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for (auto num : arr) {
        if (num % divisor == 0)
            answer.push_back(num);
    }
    
    if (answer.size() == 0) answer.push_back(-1);
    
    sort(answer);
    
    return answer;
}