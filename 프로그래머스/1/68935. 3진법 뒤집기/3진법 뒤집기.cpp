#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> convertToThree(int n) {
    vector<int> out;

    int tmp = n;
    while (tmp > 0) {
        out.push_back(tmp % 3);
        tmp /= 3;
    }
    return out;
}

int convertToX(vector<int> three) {
    int size = three.size();

    int out = 0;

    for (int i = 0; i < size; i++) {
        out += three[i] * pow(3, size - i - 1);
    }

    return out;
}

int solution(int n) {
    int answer = 0;

    answer = convertToX(convertToThree(n));

    return answer;
}