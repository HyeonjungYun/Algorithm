#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int checkCard(vector<int>& cards)
{
    
    set<set<int>> selectedCards;
    vector<bool> isSelected(cards.size(), true);
    
    for (int i = 0; i < cards.size(); i++)
    {
        int key = i;
        set<int> tmp;  
        
        while(isSelected[key])
        {
            tmp.insert(cards[key]);
            isSelected[key] = false;
            key = cards[key] - 1;
        }
        
        selectedCards.insert(tmp);
    }
    
    vector<int> sizes;
    
    for (const set<int>& cards : selectedCards)
    {
        sizes.push_back(cards.size());
    }
    
    if (sizes.size() == 1)
    {
        return 0;
    }
    
    sort(sizes.begin(), sizes.end(), std::greater<int>());
    
    return sizes[0] * sizes[1];
}

int solution(vector<int> cards) {
    int answer = 0;
    
    answer = checkCard(cards);
    
    return answer;
}