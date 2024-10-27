#include <iostream>
#include <stack>
using namespace std;

class Stack
{

public:
    int top;
    int *arr;
    int size;

    // behaviour
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    int push(int element)
    {
        if (size - top > 0)
        {
            top++;
            arr[top] = element;
        }

        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    int pop()
    {
        if (top >= 0)
        {
            top--;
        }

        else
        {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }

        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }

        else
        {
            return false;
        }
    }
};

int main()
{
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << st.peek() << endl;
    st.pop();

    cout << st.peek() << endl;
    st.pop();

    cout << st.peek() << endl;
    st.pop();

    cout << st.peek() << endl;

    if (st.isEmpty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack is Not Empty" << endl;
    }

    return 0;
}