#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] < sizes[i][1]) {
            int temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
    }
    
    int wMax = 0, hMax = 0;
    for (vector<int> size : sizes) {
        if (wMax < size[0]) wMax = size[0];
        if (hMax < size[1]) hMax = size[1];
    }
    
    answer = wMax * hMax;
    
    return answer;
}