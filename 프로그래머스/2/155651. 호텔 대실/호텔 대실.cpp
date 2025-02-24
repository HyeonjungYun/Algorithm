#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int calMin(string time)
{
    int out = 0;    
    out += time[4] - '0';
    out += (time[3] - '0') * 10;
    out += (time[1] - '0') * 60;
    out += (time[0] - '0') * 600;
    
    return out;
}

const bool isEmpty(vector<vector<string>*>& book)
{
    for (auto elem : book)
    {
        if (!elem) return false;
    }
    
    return true;
}

const int count(vector<vector<string>*> room)
{
    int cnt = 0;
    for (const auto elem : room)
    {
        if (elem) cnt++;
    }
    
    return cnt;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<vector<string>*> rooms(book_time.size(), nullptr);
    
    sort(book_time.begin(), book_time.end(), [](vector<string> a, vector<string> b)
         {
             return calMin(a[1]) < calMin(b[1]);
         });
    sort(book_time.begin(), book_time.end(), [](vector<string> a, vector<string> b)
         {
             return calMin(a[0]) < calMin(b[0]);
         });
    
    for (vector<string>& book : book_time)
    {
        if (isEmpty(rooms))
        {
            rooms[0] = &book;
            continue;
        }
        
        for (auto& room : rooms)
        {
            if(room && (calMin((*room)[1]) + 10) <= calMin(book[0]))
            {
                room = &book;
                break;
            }
            if(!room)
            {
                room = &book;
                break;
            }
        }
    }
    return count(rooms);
}