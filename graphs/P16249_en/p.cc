#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef vector<vector<int>> Graph;

vector<int> topological(const Graph& g)
{
    int n = g.size();
    vector<int> ge(n, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < g[i].size(); ++j)
        {
            ++ge[g[i][j]];
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; ++i)
    {
        if (ge[i] == 0)
            pq.push(i);
    }

    vector<int> vec(n);
    while (!pq.empty())
    {
        int v = pq.top();
        pq.pop();
        vec.push_back(v);
        for (int i = 0; i < g[v].size(); ++i)
        {
            if (--ge[g[v][i]] == 0)
                pq.push(g[v][i]);
        }
    }

    return vec;

}

//ordenar vector string por tamañp (?)
int returns_key(const map<string, int>& m, string p)
{
    return (m.find(p)->second);
}

string returns_string(const map<string, int>& m, int p)
{
    map<string, int>::const_iterator it = m.begin();
    for (; it != m.end(); it++)
    {
        if (it->second == p)
            return it->first;
    }

    return "hola";
}

int main(){
    int n;
    while (cin >> n)
    {
        map<string, int> s;
        for (int i = 0; i < n; ++i)
        {
            string p;
            cin >> p;
            s.insert({p, i});
            
        }

        Graph g(n);
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            string a, b;
            cin >> a >> b;
            int valor = returns_key(s, a);
            int valor1 = returns_key(s, b);
            g[valor].push_back(valor1);
        }

        vector<int> ve = topological(g);
        for (int i = 0; i < n; ++i)
        {
            cout << returns_string(s, i);
        }
        cout << endl;
    }
    
}