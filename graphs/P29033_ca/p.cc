#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> graph;  //lista de adyacencia

void pintar(const graph& g, int u, vector<int>& colors, int col, bool& colorable)
{
    colors[u] = col; //pintamos

    for (int v : g[u])
    {
        if (colors[v] == col) 
            colorable = false; //si el nodo esta pintado del mismo color que su vecino -> no colorable
        else if (colors[v] == -1)
            pintar(g, v, colors, (col+1)%2, colorable);
    }
}

int main()
{
    int n, m;

    while (cin >> n >> m)
    {
        graph g;
        g = graph(n);
    
        for (int i = 0; i < m; ++i)
        {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<int> c(g.size(), -1); //color de los nodos [0 es un color, 1 es otro color, -1 es no pintado]
        bool color = true;

        for (int i = 0; i < g.size(); ++i)
        {
            if (c[i] == -1) //si el nodo no esta pintado lo pintamos con la llamada
                pintar(g, i, c, 0, color);
        }

        if (color) cout << "yes" << endl;
        else cout << "no" << endl;
            
    }
}

