#include <string>
#include <vector>

using namespace std;

int gcd(int n, int m) {
    int key, nkey;
    if (n > m) {key = n; nkey = m;}
    else {key = m; nkey = n;}
    
    vector<int> arr;
    for (int i = 1; i <= key; i++)
        if (key % i == 0) arr.push_back(i);
    
    int out;
    for (auto a : arr)
        if (nkey % a == 0) out = a;
    
    return out;
}

int lcm(int n, int m) {
    int key, nkey;
    if (n > m) {key = n; nkey = m;}
    else {key = m; nkey = n;}
    
    int out;
    
    for (int i = nkey; i <= n * m; i++)  
        if (i % n == 0 && i % m ==0) {
            out = i;
            return out;
        }
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(gcd(n,m));
    answer.push_back(lcm(n,m));
    return answer;
}