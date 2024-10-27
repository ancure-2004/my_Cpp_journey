#include <iostream>
#include <stack>
using namespace std;

int main()
{

    string str = "Ankur";

    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {

        char c = str[i];
        s.push(c);
    }

    string ans = "";

    while (!s.empty())
    {
        char c = s.top();
        ans.push_back(c);

        s.pop();
    }

    cout << " Reverese string is " << ans << endl;

    return 0;
}