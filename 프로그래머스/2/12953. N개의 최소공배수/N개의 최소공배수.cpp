#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    
    if (arr.size() == 1) return arr[0];
    
    answer = lcm(arr[0], arr[1]);
    
    for (int i = 2; i < arr.size(); i++)
    {
        answer = lcm(arr[i], answer);
    }
    return answer;
}