#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    int i = 0, j = 1, k = 2, len = number.size() - 1;
    
    while (1) {
        int sum = number[i] + number[j] + number[k];
        
        if (sum == 0) answer++;
        cout << "i:" << number[i] << " j:" << number[j] << " k:" << number[k] << " sum:" << sum << endl;
        
        k++;
        if (k > len) {
            j++;
            k = j + 1;
            if (j > len - 1){
                i++;
                j = i + 1;
                k = j + 1;
                if (i > len - 2) break;
            }
                
        }
    }
    
    return answer;
}