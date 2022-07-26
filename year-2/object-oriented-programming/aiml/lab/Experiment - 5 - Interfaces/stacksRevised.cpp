// Code by Desh Iyer

#include <iostream>
#define N 10

using namespace std;

class Stack {
    private:
        int stack[N];
        int top;

    public:
        Stack() {
            top = -1;
        }

        void push(int element) {
            stack[++top] = element;
        }

        void pop() {
            if (top == -1) {
                cout << "Stack underflow!";
                return;
            } else {
                cout << "Popped element: " << stack[top];
                top--;
            }
        }

        void display() {
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << endl;
            }
        }
};

int main() {   
    Stack S;
    S.push(10);
    S.push(10);
    S.push(10);
    S.push(10);
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.display();
}