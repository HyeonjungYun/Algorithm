#include <string>
#include <vector>

using namespace std;

vector<vector<int>> discMove(int x, int y, int z, int n) {
    vector<vector<int>> moves;
    if(n == 1) 
    {
        moves.push_back({x, z});
    } 
    else 
    {
        // 첫 번째 재귀 호출: x에서 y로 옮기기 (보조 기둥: z)
        vector<vector<int>> left = discMove(x, z, y, n - 1);
        // 두 번째 재귀 호출: y에서 z로 옮기기 (보조 기둥: x)
        vector<vector<int>> right = discMove(y, x, z, n - 1);
        
        // 왼쪽 결과 결합
        moves.insert(moves.end(), left.begin(), left.end());
        // 중앙 이동
        moves.push_back({x, z});
        // 오른쪽 결과 결합
        moves.insert(moves.end(), right.begin(), right.end());
    }
    return moves;
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    answer = discMove(1, 2, 3, n);
    
    return answer;
}