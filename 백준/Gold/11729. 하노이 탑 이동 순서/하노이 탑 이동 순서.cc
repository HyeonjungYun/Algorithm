#include <iostream>
using namespace std;

void hanoi(int n, int from, int to, int aux) 
{
    if (n == 1) 
    {
        cout << from << ' ' << to << '\n';
        return;
    }
    hanoi(n-1, from, aux, to);
    cout << from << ' ' << to << '\n';
    hanoi(n-1, aux, to, from);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // 1) 이동 횟수 출력
    long long cnt = (1LL << N) - 1;
    cout << cnt << '\n';

    // 2) 재귀로 바로 이동 순서 출력
    hanoi(N, 1, 3, 2);
    return 0;
}
