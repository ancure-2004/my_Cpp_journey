#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

// To Generalize the data type
template <typename T>
class graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction)
    {

        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the No. of nodes: " << endl;
    cin >> n;

    int m;
    cout << "Enter the No. of edges: " << endl;
    cin >> m;

    // Data Type is Defined here only one time n
    graph<int> g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.print();

    return 0;
}