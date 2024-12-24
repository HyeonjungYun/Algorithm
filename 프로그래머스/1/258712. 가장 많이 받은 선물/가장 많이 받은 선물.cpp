#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findIndex(vector<string> friends, vector<string> direction) {
    vector<int> out;

    out.push_back(find(friends.begin(), friends.end(), direction[0]) - friends.begin());
    out.push_back(find(friends.begin(), friends.end(), direction[1]) - friends.begin());

    return out;
}

vector<string> findDirection(string gift) {

    vector<string> result;
    stringstream ss(gift);
    string word;

    while (ss >> word)
        result.push_back(word);

    return result;
}

void editIndicator(vector<string> friends, vector<string> &gifts, vector<vector<int>> &currentGifts, vector<int> &giftIndex, vector<int> &getGifts) {
    for (auto gift : gifts) {
        vector<string> direction = findDirection(gift);
        vector<int> presentedFriendsIndex = findIndex(friends, direction);

        int from = presentedFriendsIndex[0];
        int to = presentedFriendsIndex[1];

        currentGifts[from][to]++;

        giftIndex[from]++;
        giftIndex[to]--;
    }
}

void calRelation(int size, vector<vector<int>>& currentGifts, vector<int>& giftIndex, vector<int>& getGifts) {
    for (int row = 0; row < size; row++)
        for (int col = 0; col < size; col++) {
            if (row < col) continue;

            if (currentGifts[row][col] < currentGifts[col][row]) {
                getGifts[col]++;
            }
            else if (currentGifts[row][col] > currentGifts[col][row]) {
                getGifts[row]++;
            }
            else if (currentGifts[row][col] == currentGifts[col][row]) {
                if (giftIndex[row] > giftIndex[col]) getGifts[row]++;
                if (giftIndex[row] < giftIndex[col]) getGifts[col]++;
            }
        }
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int size = friends.size();

    vector<vector<int>> currentGifts(size, vector<int>(size, 0));   // 선물을 누가 누구에게 줬는지 알려주는 지표
    vector<int> giftIndex(size, 0);     // 선물지수를 나타내는 지표
    vector<int> getGifts(size, 0);      // 받아야 할 선물을 나타내는 지표

    editIndicator(friends, gifts, currentGifts, giftIndex, getGifts);

    calRelation(size, currentGifts, giftIndex, getGifts);

    for (auto getGift : getGifts)
        if (answer < getGift) answer = getGift;

    return answer;
}