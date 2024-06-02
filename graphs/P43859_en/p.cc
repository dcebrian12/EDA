#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> Nodo; // first -> coste; second -> vertice
typedef vector<vector<Nodo>> Graph;
const int INF = numeric_limits<int>::max();

int calcula_camino_menor(const Graph &G, int x, int y)
{
    vector<int> distancias(G.size(), INF);
    // vector<bool> visitados(G.size(), false);
    distancias[x] = 0;
    // indica la distancia minima desde x a distancias[i]
    priority_queue<Nodo, vector<Nodo>, greater<Nodo>> pq; // priority_queue minheap
    pq.push({0, x});

    while (not pq.empty())
    {
        Nodo n = pq.top();
        pq.pop();

        for (int i = 0; i < G[n.second].size(); ++i)
        {
            int v = G[n.second][i].second; // nodo vecino
            int c = G[n.second][i].first;  // coste
            if (distancias[v] > distancias[n.second] + c)
            {
                distancias[v] = distancias[n.second] + c;
                pq.push({distancias[v], v});
            }
        }
    }
    return distancias[y];
}

void leer_grafo(Graph &G, int m)
{
    for (int i = 0; i < m; ++i)
    {
        int v1, v2, coste;
        cin >> v1 >> v2 >> coste;
        G[v1].push_back({coste, v2});
    }
}

int main()
{
    int v, m, x, y;
    while (cin >> v >> m)
    {
        Graph g(v);
        leer_grafo(g, m);
        cin >> x >> y;
        int distancia = calcula_camino_menor(g, x, y);
        if (distancia != INF)
            cout << distancia << endl;
        else
            cout << "no path from " << x << " to " << y << endl;
    }
}