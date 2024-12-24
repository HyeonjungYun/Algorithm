#include <string>
#include <vector>

using namespace std;

bool isPossible(int mat, int f, int s, vector<vector<string>> park) {
    for (int i = f; i < f + mat; i++)
        for (int j = s; j < s + mat; j++)
            if (park[i][j] != "-1") return false;

    return true;

}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    int fsize = park.size();
    int ssize = park[0].size();

    for (auto mat : mats) {
        for (int i = 0; i < fsize; i++)
            for (int j = 0; j < ssize; j++) {
                if ((i + mat) > fsize || (j + mat) > ssize) continue;
                if (isPossible(mat, i, j, park)) {
                    if (mat > answer) answer = mat;
                }
            }
    }
    if (answer == 0) return -1;
    return answer;
}