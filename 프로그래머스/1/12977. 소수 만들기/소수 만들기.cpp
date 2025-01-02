#include <vector>
#include <iostream>
using namespace std;

bool checkDecimal(int num) {
    int count = 0;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) count++;
    }
    
    if (count > 0) return false;
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    int i = 0, j = 1, k = 2, len = nums.size();
    
    while(1) {
        if (checkDecimal(nums[i] + nums[j] + nums[k])) answer++;
        cout << i << " " << j << " " << k << endl;
        
        k++;
        if (k >= len){
            j++;
            k = j + 1;
            if (j >= len - 1) {
                i++;
                j = i + 1;
                k = j + 1;
                if (i >= len - 2) break;
            }
        }
    }
    
    return answer;
}