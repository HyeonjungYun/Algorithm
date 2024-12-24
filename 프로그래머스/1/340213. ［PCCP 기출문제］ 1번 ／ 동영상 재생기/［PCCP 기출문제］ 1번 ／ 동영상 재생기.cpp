#include <string>
#include <cstring>
#include <vector>

using namespace std;

int convertNumber(string time) {
    int out = 0;
    
    out += (time[0] - '0') * 600;
    out += (time[1] - '0') * 60;
    out += (time[3] - '0') * 10;
    out += time[4] - '0';
    
    return out;
}

int prev(int time) {
    time -= 10;
    
    if (time < 0) time = 0;
    
    return time;
}

int next(int time, int endTime) {
    time += 10;
    
    if (time >= endTime) time = endTime;
    
    return time;
}

int checkOPtime(int time, int op_start_time, int op_end_time) {
    if  (time >= op_start_time && time <= op_end_time)
        time = op_end_time;
    
    return time;
}

string convertTime (int time) {
    string out = "";
    out += (time / 600) + '0';
    out += ((time % 600) / 60) + '0';
    out += ':';
    out += ((time % 60) / 10) + '0';
    out += (time % 10) + '0';
    
    return out;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int time = convertNumber(pos);
    int endTime = convertNumber(video_len);
    int op_start_time = convertNumber(op_start);
    int op_end_time = convertNumber(op_end);
    
    for (auto command : commands) {
        time = checkOPtime(time, op_start_time, op_end_time);
        if  (command == "prev")
            time = prev(time);
        if  (command == "next")
            time = next(time, endTime);
    }
    time = checkOPtime(time, op_start_time, op_end_time);
    
    answer = convertTime(time);
    return answer;
}