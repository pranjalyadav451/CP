#include<queue>
class Stack {
    queue<int> toPush, toPop;

public:
    Stack() {
        while (toPush.size()) toPush.pop();
        while (toPop.size()) toPop.pop();
    }
    /*----------------- Public Functions of Stack -----------------*/
    int getSize() {
        int n = toPush.size(), m = toPop.size();
        return n + m;
    }
    bool isEmpty() {
        int n = toPush.size(), m = toPop.size();
        return n == 0 and m == 0;
    }
    void push(int element) {
        while (toPop.size()) {
            toPush.push(toPop.front());
            toPop.pop();
        }
        toPush.push(element);
    }
    int pop() {
        if (this->isEmpty()) return -1;
        while (toPush.size() > 1) {
            toPop.push(toPush.front());
            toPush.pop();
        }
        int ele = toPush.front();
        toPush.pop();
        toPush = toPop;
        while (toPop.size()) {
            toPop.pop();
        }
        return ele;
    }
    int top() {
        if (this->isEmpty()) return -1;
        while (toPush.size() > 1) {
            toPop.push(toPush.front());
            toPush.pop();
        }
        int ele = toPush.front();
        toPush.pop();
        toPush = toPop;
        while (toPop.size()) {
            toPop.pop();
        }
        toPush.push(ele);
        return ele;
    }
};