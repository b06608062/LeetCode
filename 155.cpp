// 155. Min Stack
#define MAX_SIZE 30000

class MinStack {
private:
  int stack[MAX_SIZE];
  int t;
  int min;

public:
  MinStack() {
    t = -1;
    min = 2147483647;
  }

  void push(int val) {
    min = min < val ? min : val;
    stack[++t] = val;
  }

  void pop() {
    int tmp = stack[t--];
    if (tmp == min) {
      min = 2147483647;
      for (int i = 0; i <= t; i++)
        min = min < stack[i] ? min : stack[i];
    }
  }

  int top() { return stack[t]; }

  int getMin() { return min; }
};