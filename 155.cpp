#define MAX_SIZE 30000

class MinStack {
private:
  int stack[MAX_SIZE];
  int stackTop;
  int min;

public:
  MinStack() {
    stackTop = -1;
    min = 2147483647;
  }

  void push(int val) {
    min = min < val ? min : val;
    stack[++stackTop] = val;
  }

  void pop() {
    int tmp = stack[stackTop--];
    if (tmp == min) {
      min = 2147483647;
      for (int i = 0; i <= stackTop; i++)
        min = min < stack[i] ? min : stack[i];
    }
  }

  int top() { return stack[stackTop]; }

  int getMin() { return min; }
};