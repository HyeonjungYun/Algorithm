#include <string>
#include <vector>

using namespace std;

void searchBestDistance(vector<string> wallpaper, vector<int> &answer) {
    int topEnd = 0, bottomEnd = 0, rightEnd = 0, leftEnd = 999;
    
    for (string element : wallpaper) {
        int rightTemp = 0, leftTemp = 0;
        
        for (int i = 0; i < element.size(); i++) {
            if (element[i] == '#') {
                leftTemp = i;
                if (leftTemp < leftEnd) leftEnd = leftTemp;
            }
        }
        
        for (int i = element.size() - 1; i >= 0; i--) {
            if (element[i] == '#') {
                rightTemp = i;
                if (rightTemp > rightEnd) rightEnd = rightTemp;
            }
        }
    }
    
    for (int i = 0; i < wallpaper.size(); i++) 
        if (wallpaper[i].find("#") != string::npos) {
            topEnd = i;
            break;
        }
    
    for (int i = wallpaper.size() - 1; i >= 0; i--) 
        if (wallpaper[i].find("#") != string::npos) {
            bottomEnd = i;
            break;
        }
    
    answer.push_back(topEnd);
    answer.push_back(leftEnd);
    answer.push_back(bottomEnd + 1);
    answer.push_back(rightEnd + 1);
}

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    searchBestDistance(wallpaper, answer);
    
    return answer;
}