#include <string>
#include <vector>

using namespace std;

bool isPossible(vector<int> wallet, vector<int> bill) {
    if (wallet[0] >= bill[0] && wallet[1] >= bill[1])
        return true;
    if (wallet[0] >= bill[1] && wallet[1] >= bill[0])
        return true;

    return false;
}

vector<int> foldBill(vector<int> bill) {
    if (bill[0] > bill[1]) bill[0] = (int)(bill[0] / 2.0);
    else if (bill[0] < bill[1]) bill[1] = (int)(bill[1] / 2.0);

    return  bill;
}

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;

    while (!isPossible(wallet, bill)) {
        bill = foldBill(bill);
        answer++;
    }

    return answer;
}