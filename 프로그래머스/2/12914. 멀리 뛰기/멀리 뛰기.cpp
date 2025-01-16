#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long> m{1,1};
    for(int i = 1;i < n; i++) m.emplace_back((m[i-1]+m[i])%1234567LL);
    return m.back();
}