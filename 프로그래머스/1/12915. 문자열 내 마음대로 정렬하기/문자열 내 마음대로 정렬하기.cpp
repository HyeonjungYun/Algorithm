#include <string>
#include <vector>

using namespace std;

void sort(vector<string> &strings, int n) {
    for (int i = 0; i < strings.size(); i++) 
        for (int j = 0; j < strings.size() - 1; j++) {
            if (strings[j][n] > strings[j + 1][n]){
                string tmp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = tmp;
            }
            if (strings[j][n] == strings[j + 1][n]) {
                if (strings[j] > strings[j + 1]){
                string tmp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = tmp;
            }
            }
        }
}

vector<string> solution(vector<string> strings, int n) {
    sort(strings, n);
    return strings;
}