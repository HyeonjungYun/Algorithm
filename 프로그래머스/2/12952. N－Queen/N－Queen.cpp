#include <vector>
#include <cmath>

using namespace std;

bool isSafePosition(const std::vector<int>& queen, int col, int row) 
{
    for (int i = 0; i < col; i++) 
    {
        if (queen[i] == row || std::abs(i - col) == std::abs(queen[i] - row)) 
        {
            return false;
        }
    }
    return true;
}

// col번째 열에 퀸을 놓았을 때, 이후로 나올 수 있는 해의 개수를 반환
int countSolutions(std::vector<int>& queen, int col) 
{
    int n = queen.size();
    if (col == n) 
    {
        return 1;  // 한 가지 배치 완성
    }
    int count = 0;
    for (int row = 0; row < n; row++) 
    {
        if (isSafePosition(queen, col, row)) 
        {
            queen[col] = row;
            count += countSolutions(queen, col + 1);
            queen[col] = -1;  // 백트래킹
        }
    }
    return count;
}

int solution(int n) {
    vector<int> queen(n, -1);
    return countSolutions(queen, 0);
}
