#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> s;
    stack<int> minS;

    MinStack() {
    }

    void push(int val) {
        minS.push((s.empty() || minS.top() > val) ? val : minS.top());
        s.push(val);
    }

    void pop() {
        s.pop();
        minS.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minS.top();
    }
};
