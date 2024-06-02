#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> Node;
typedef vector<vector<Node>> Graph;

Node steps(const Graph &g, int x, int y)
{
    int n = g.size();
    vector<bool> vis(n, false);
    vector<int> distancias(n, numeric_limits<int>::max());
    vector<int> previo(n, -1);
    vector<int> steps(n, numeric_limits<int>::max());
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    distancias[x] = 0;
    steps[x] = 0;
    pq.push({0, x});

    Node m;
    m.first = 0;
    
    while (!pq.empty())
    {
        Node a = pq.top();
        pq.pop();
        int v = a.second;
        if (!vis[v])
        {
            vis[v] = true;
            for (int i = 0; i < g[v].size(); ++i)
            {
                int c = g[v][i].first;
                int v1 = g[v][i].second;
                if (distancias[v1] > distancias[v] + c)
                {
                    distancias[v1] = distancias[v] + c;
                    previo[v1] = v;
                    pq.push({distancias[v1], v1});
                }
            }
        }
    }

    queue<int> q;
    vis = vector<bool>(n, false);
    steps[x] = 0;
    q.push(x);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        if (not vis[v])
        {
            vis[v] = true;
            for (int i = 0; i < g[v].size(); ++i)
            {
                int m = g[v][i].second;
                if (steps[m] == numeric_limits<int>::max())
                {
                    steps[m] = steps[v] + 1;
                    q.push(m);
                }
            }
        }
    }
    m.second = distancias[y];
    m.first = steps[y];
    return m;

}

int main()
{
    int v, a;
    while (cin >> v >> a)
    {
        Graph g(v);
        for (int i = 0; i < a; ++i)
        {
            int x, y, c;
            cin >> x >> y >> c;
            g[x].push_back({c, y});
        }

        int x, y;
        cin >> x >> y;
        Node n = steps(g, x, y);

        if (n.first == numeric_limits<int>::max())
            cout << "no path from " << x << " to " << y << endl;
        else
            cout << "cost " << n.second << ", " << n.first << " step(s)" << endl;
    }
}