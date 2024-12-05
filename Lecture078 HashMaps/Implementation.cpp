#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{

    // Creation
    map<string, int> m;

    // Insertion
    // 1:
    pair<string, int> p = make_pair("Ankur", 1);
    m.insert(p);
    // 2:
    pair<string, int> pair2("singhal", 2);
    m.insert(pair2);
    // 3
    m["daksh"] = 3;

    // Searching
    cout << m["daksh"] << endl;
    cout << m.at("Ankur") << endl;

    // cout << m.at("anshul") << endl;
    cout << m["anshul"] << endl;
    cout << m.at("anshul") << endl;

    // size
    cout << m.size() << endl;

    // To check presencec
    cout << m.count("daksh") << endl;

    // Erase
    m.erase("daksh");
    cout << m.size() << endl;

    // iterator
    map<string, int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}