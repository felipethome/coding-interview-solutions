#include <iostream>
#include <stack>

using namespace std;

class MinStack {
  public: 
    MinStack();
    void push(int x);
    void pop();
    int top();
    int getMin();
    void print(stack<int> &p);
};

stack<int> s;
stack<int> m;
int cmin;

MinStack::MinStack() {
  while (!s.empty()) {
    s.pop();
  }
  while (!m.empty()) {
    m.pop();
  }
}

void MinStack::push(int x) {
  if (s.empty()) {
    cmin = x;
  }
  else if (cmin >= x) {
    m.push(cmin);
    cmin = x;
  }

  s.push(x);
}

void MinStack::pop() {
  if (s.empty()) return;

  if (!m.empty() && cmin == s.top()) {
    cmin = m.top();
  }

  if (!m.empty() && m.top() == cmin) {
    m.pop();
  }

  s.pop();
}

int MinStack::top() {
  if (s.empty()) return -1;
  return s.top();
}

int MinStack::getMin() {
  if (s.empty()) return -1;
  return cmin;
}

void MinStack::print(stack<int> &p) {
  cout << "Stack: ";

  for (std::stack<int> dump = p; !dump.empty(); dump.pop())
    std::cout << dump.top() << ' ';

  cout << '\n';
}

int main() {
  MinStack *r = new MinStack();
  r->push(2);
  r->push(4);
  r->push(3);
  r->push(1);
  r->push(8);
  r->push(9);

  r->print(s);
  r->print(m);
  cout << "Top: " << r->top() << '\n';
  cout << "Min: " << r->getMin() << '\n';
  cout << '\n';

  r->pop();
  r->pop();
  r->pop();

  r->print(s);
  r->print(m);
  cout << "Top: " << r->top() << '\n';
  cout << "Min: " << r->getMin() << '\n';
  cout << '\n';

  return 0;
}