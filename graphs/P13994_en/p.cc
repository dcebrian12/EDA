#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;


const int INFINITO = numeric_limits<int>::max();
const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};
typedef pair<int, int> Node;
typedef vector<vector<Node>> Graph; //first = cost, second = node


//algorismo dijkstra guardando el camino mas corto
vector<int> calcula_camino(const Graph& g, int x)
{
    vector<int> distancia(g.size(), INFINITO);//guarda la distancia desde x hasta los demas vertices
    vector<int> previo(g.size(), -1); //indica que nodo es el previo
    vector<bool> vis(g.size(), false);
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    distancia[x] = 0;
    pq.push({0, x});
    while(!pq.empty())
    {
        Node actual = pq.top();
        pq.pop();
        int vecino = actual.second;
        if (not vis[vecino]){
            vis[vecino] = true;
            for (int i = 0; i < g[vecino].size(); ++i)
            {
                int v = g[vecino][i].second;
                int c = g[vecino][i].first;
                if (distancia[v] > distancia[vecino] + c)
                {
                    distancia[v] = distancia[vecino] + c;
                    previo[v] = vecino;
                    pq.push({distancia[v], v});
                }
            }
        }
    }
    
    return previo;
}

void print_path(vector<int> v, int x, int y)
{
    vector<int> path;
    int i = y;
    while(i != x)
    {
        if (i != -1 and v[i] == -1) 
        {
            cout << "no path from " << x << " to " << y << endl;
            return;
        }
        path.push_back(i);
        i = v[i];
    }
    path.push_back(i);

    for (int i = path.size() - 1; i > 0; i--)
    {
        cout << path[i] << " ";
    }
    cout << path[0] << endl;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        Graph g(n);
        for (int i = 0; i < m; ++i)
        {
            int u, v, c;
            cin >> u >> v >> c;
            g[u].push_back({c, v});
        }
        int x, y;
        cin >> x >> y;
        vector<int> previos = calcula_camino(g, x);
        print_path(previos, x, y);

    }
}