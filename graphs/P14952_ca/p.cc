#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> Graph;

vector<int> topological_sort(const Graph& g)
{
    int n = g.size(); 
    vector<int> ge(n, 0); //graus d'entrada

    //deja en ge el grado de entrada de cada nodo [0, ..., g.size() - 1]
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < g[i].size(); ++j)
        {
            int nodo = g[i][j];
            ++ge[nodo]; //sumamos un grado de entrada
        }
    }

    priority_queue<int, vector<int>, greater<int>> s;
    for (int i = 0; i < n; ++i)
        if (ge[i] == 0)
            s.push(i);
    
    vector<int> order;

    while (not s.empty())
    {
        int nodo = s.top();
        s.pop();
        order.push_back(nodo);
        for (int i = 0; i < g[nodo].size(); ++i)
        {
            int a = g[nodo][i];
            if (--ge[a] == 0)
                s.push(a);
        }
    }

    return order;
}

int main()
{
    int n, m;
    while (cin >> n >> m){
        Graph g(n);

        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
        }

        vector<int> o = topological_sort(g);

        for (int i : o){
            cout << i;
            if (i != o[o.size() - 1])
                cout << " ";
        }

        cout << endl;
    }

}