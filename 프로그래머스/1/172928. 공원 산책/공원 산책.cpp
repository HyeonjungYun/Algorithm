#include <string>
#include <vector>

using namespace std;

vector<int> searchStartPoint(const vector<string>& park) {
    vector<int> temp;
    temp.reserve(2);
    temp.push_back(0);
    temp.push_back(0);
    
    for (int i = 0; i < park.size(); i++)
        for (int j = 0; j < park[0].size(); j++)
            if (park[i][j] == 'S'){
                temp[0] = i;
                temp[1] = j;
                return temp;
            }
    
    return temp;
}

const bool checkObstacle(const vector<string>& park, string route, const vector<int>& temp) {
    int W = park[0].size();
    int H = park.size();
    int distance = route[2] - '0';
    
    if (route[0] == 'E') {
        if (temp[1] + distance > W - 1) return true;
        
        for (int i = temp[1]; i <= temp[1] + distance; i++)
            if (park[temp[0]][i] == 'X') return true;
    }
        
    if (route[0] == 'S'){
        if (temp[0] + distance > H - 1) return true;
        
        for (int i = temp[0]; i <= temp[0] + distance; i++)
            if (park[i][temp[1]] == 'X') return true;
    }
        
    if (route[0] == 'W'){
        if (temp[1] - distance < 0) return true;
        
        for (int i = temp[1] - distance; i <= temp[1]; i++)
            if (park[temp[0]][i] == 'X') return true;
    }
        
    if (route[0] == 'N'){
        if (temp[0] - distance < 0) return true;
        
        for (int i = temp[0] - distance; i <= temp[0]; i++)
            if (park[i][temp[1]] == 'X') return true;
    }
    
    return false;
}

void move(const vector<string>& park, string route, vector<int>& temp) {
    if (route[0] == 'E') 
        temp[1] += route[2] - '0';
       
        
    if (route[0] == 'S')
        temp[0] += route[2] - '0';
        
        
    if (route[0] == 'W')
        temp[1] -= route[2] - '0';
        
    if (route[0] == 'N')
        temp[0] -= route[2] - '0';
    
}

const vector<int> moveRoutes(const vector<string> &park, const vector<string> &routes) {
    vector<int> temp = searchStartPoint(park);
    
    for (const string& route : routes){
        if (checkObstacle(park, route, temp)) continue;
        
        move(park, route, temp);
    }
    
    return temp;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    answer = moveRoutes(park, routes);
    
    return answer;
}