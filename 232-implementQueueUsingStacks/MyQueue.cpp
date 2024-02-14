#include <vector>
#include <stack>

class MyQueue
{
private:
    std::vector<std::stack<int>> stacks;

public:
    MyQueue() : stacks(2, std::stack<int>())
    {
    }

    void push(int x)
    {
        while (!stacks[0].empty())
        {
            stacks[1].push(stacks[0].top());
            stacks[0].pop();
        }
        stacks[0].push(x);
        while (!stacks[1].empty())
        {
            stacks[0].push(stacks[1].top());
            stacks[1].pop();
        }
    }

    int pop()
    {
        int top = peek();
        stacks[0].pop();
        return top;
    }

    int peek()
    {
        return stacks[0].top();
    }

    bool empty()
    {
        return stacks[0].empty();
    }
};