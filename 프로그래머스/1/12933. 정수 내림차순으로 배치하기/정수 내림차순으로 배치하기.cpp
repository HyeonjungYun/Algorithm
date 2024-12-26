#include <string>
#include <vector>

using namespace std;

void sort(vector<int> &tmp) {
    for (int i =0; i < tmp.size(); i++)
        for (int j =0; j < tmp.size() - 1; j++)
            if (tmp[j] < tmp[j+1]){
                int t = tmp[j];
                tmp[j] = tmp[j+1];
                tmp[j+1] = t;
                }
}

long long to_int(vector<int> tmp) {
    long long out = 0;
    
    for (int i = 0; i < tmp.size(); i++){
        out += tmp[i];
        if (i == tmp.size() - 1) break;
        out *= 10;
    }
    
    return out;
}

long long solution(long long n) {
    long long answer = 0;
    
    vector<int> tmp;
    
    while(n != 0) {
        tmp.push_back(n % 10);
        n /= 10;
    }
    sort(tmp);
    answer = to_int(tmp);
    return answer;
}