#include <numeric>
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = accumulate(arr.begin(), arr.end(), 0);

    return answer / arr.size();
}