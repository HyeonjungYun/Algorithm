#include <string>
#include <vector>

using namespace std;

int checkMonth(int a) {
    if (a == 1 || a == 3  || a == 5 || a == 7 || a == 8 || a == 10 || a == 12)
        return 31;
    if (a == 4 || a == 6 || a == 9 || a == 11)
        return 30;
    if (a == 2) return 29;
}

string searchDayOfWeek(int totalDay) {
    totalDay += 4;
    
    int key = totalDay % 7;
    
    if (key == 0) return "SUN";
    if (key == 1) return "MON";
    if (key == 2) return "TUE";
    if (key == 3) return "WED";
    if (key == 4) return "THU";
    if (key == 5) return "FRI";
    if (key == 6) return "SAT";
}

string solution(int a, int b) {
    int totalDay = 0;
    for (int i = 1; i < a; i++)
        totalDay += checkMonth(i);
    totalDay += b;
    
    return searchDayOfWeek(totalDay);
}