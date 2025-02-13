#include <string>
#include <vector>
#include <stack>

using namespace std;

void saveBox(stack<int>& assistStack, stack<int>& tmpStack)
{
    assistStack.push(tmpStack.top());
    tmpStack.pop();
}

void pushBox(stack<int>& assistStack, stack<int>& tmpStack, stack<int>& answerStack, bool pushMode)
{
    if (!pushMode)   // 임시 컨베이어벨트(assistStack)
    {
        answerStack.push(assistStack.top());
        assistStack.pop();
    }
    else            // 현재 컨베이어 벨트
    {
        answerStack.push(tmpStack.top());
        tmpStack.pop();
    }
}

int solution(vector<int> order) {
    int answer = 0;
    stack<int> tmpStack;
    stack<int> answerStack;
    stack<int> assistStack;
    int seq = 0, size = order.size();
    
    for (int i = size; i >= 1; i--)
    {
        tmpStack.push(i);
    }
    
    while(1)
    {
        if (answerStack.size() == size)
        {
            break;
        }
        if (assistStack.size() > 0 && assistStack.top() == order[seq])
        {
            pushBox(assistStack, tmpStack, answerStack, false);
            seq++;
            continue;
        }
        if (tmpStack.size() == 0)
        {
            break;
        }
        if (tmpStack.top() == order[seq])
        {
            pushBox(assistStack, tmpStack, answerStack, true);
            seq++;
            continue;
        }
        saveBox(assistStack, tmpStack);
    }
    
    return answerStack.size();
}