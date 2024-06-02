#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>

using namespace std;

struct Piedra{
	double x, y, r;
};

typedef vector<vector<int>> Graph;
const int INF = numeric_limits<int>::max();

//recorre el grafo (BFS) y devuelve la distancia entre la primera y la ultima roca (nodos)
int buscar_camino(const Graph& g)
{
    int n = g.size();
    queue<int> q;
    vector<int> dist(n, INF);
    vector<bool> vis(n, false);
    dist[0] = 0;
    q.push(0);
    while (!q.empty() and dist[n-1] == INF)
    {
        int a = q.front();
        q.pop();
        if (not vis[a]){
            vis[a] = true;
            for (int u = 0; u < g[a].size() and dist[n-1] == INF; ++u){
                int m = g[a][u];
                if (dist[m] == INF)
                {
                    q.push(m);
                    dist[m] = dist[a] + 1;
                }
            }
        }
    }
    return dist[n - 1];
}

//calcula las distancias entre cada roca, si esta es menor a dmax se conectan entre si en un grafo
void calcular_distancias(const vector<Piedra>& v, double dmax, Graph& g)
{
    int n = v.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            Piedra p1, p2;
            p1 = v[i];
            p2 = v[j];
            double d = (p2.x - p1.x)*(p2.x - p1.x) - (p2.y - p1.y)*(p2.y - p1.y);
            d = sqrt(d);
            d = d - p1.r - p2.r;
            if (d <= dmax)
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
}

int main() 
{
    int n;
    double d;
    while (cin >> n >> d)
    {
        vector<Piedra> v(n);
        for (int i = 0; i < n; ++i)
        {
            Piedra p;
            cin >> p.x >> p.y >> p.r;
            v[i] = p;
        }
        Graph g;
        g = Graph(n);
        calcular_distancias(v, d, g);
        int m = buscar_camino(g);
        if (m != INF) cout << m << endl;
        else cout << "Xof!" << endl;
    }
}