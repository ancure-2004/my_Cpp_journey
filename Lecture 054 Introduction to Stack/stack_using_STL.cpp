#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // Creating stack
    stack<int> s;

    // Push Operation
    s.push(2);
    s.push(3);
    s.push(4);

    // Pop Operation
    s.pop();

    // Peek Operation
    cout << "Top Element of Stack is " << s.top() << endl;

    // Empty Operation
    if (s.empty())
    {
        cout << "Stack is Empty" << endl;
    }

    else
    {
        cout << "Stack is not Empty" << endl;
    }

    // Size Operation
    cout << "Size of the Stack is " << s.size() << endl;

    return 0;
}