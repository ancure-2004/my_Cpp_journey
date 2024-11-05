#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Doubly Ended Queue

    deque<int> d;

    d.push_front(10);
    d.push_back(15);

    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_front();
    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_back();

    if (d.empty())
    {
        cout << "Queue is Empty" << endl;
    }

    else
    {
        cout << "Queue is Not Empty" << endl;
    }

    /*
     *
     *
     *
     *
     *
     */

    // Creatigng Queue
    // queue<int> q;

    // q.push(5);
    // cout << "Front of the Queue is " << q.front() << endl;

    // q.push(10);
    // cout << "Front of the Queue is " << q.front() << endl;

    // q.push(13);
    // cout << "Front of the Queue is " << q.front() << endl;

    // cout << "Size of the Queue is " << q.size() << endl;

    // q.pop();
    // q.pop();
    // q.pop();

    // cout << "Size of the Queue is " << q.size() << endl;

    // if (q.empty())
    // {
    //     cout << "Queue is empty" << endl;
    // }

    // else
    // {
    //     cout << "Queue is not empty" << endl;
    // }

    return 0;
}