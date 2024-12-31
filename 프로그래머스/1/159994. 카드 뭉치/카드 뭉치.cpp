#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int card1I = 0, card2I = 0;
    
    for (string g : goal) {
        bool isThereCard = false;
        if (g == cards1[card1I]) { isThereCard = true; card1I++;}
        else if (g == cards2[card2I]) { isThereCard = true; card2I++;}
        
        if (!isThereCard) return "No";
    }
    
    return "Yes";
}