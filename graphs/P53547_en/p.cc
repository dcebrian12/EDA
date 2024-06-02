#include <iostream>
#include <vector>

using namespace std;

const int DX[4] = {1, 1, -1, -1};
const int DY[4] = {1, -1, 1, -1};
typedef vector<vector<int>> Graph;
typedef vector<vector<bool>> MB;

Graph leer_entrada(int f, int c, int& nodos, int& total)
{
    char a;
    Graph g(f, vector<int>(c));
    for (int i = 0; i < f; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> a;

            if (a == 'X')
                g[i][j] = -1;
            else {
                g[i][j] = int(a);
                ++nodos;
                total += int(a);
            }
        }
    }
    return g;
}


bool posicion_correcta(int i, int j, int f, int c, const Graph& g)
{
    return i >= 0 and j >= 0 and i < f and j < c and g[i][j] != -1;
}

void dfs(const Graph& g, int x, int y, MB& vis, int& tot, int nodos)
{
    int f = g.size(), c = g[0].size();
    for (int i = 0; i < 4; ++i)
    {
        int x2 = x + DX[i];
        int y2 = y + DY[i];

    }
}

int main(){
    int n;
    cin >> n;
    int f, c;
    for (int k = 1; k <= n; ++k){
        cin >> f >> c;
        Graph g(f, vector<int>(c, -1));
        int nodos = 0, tot = 0;
        g = leer_entrada(f, c, nodos, tot);
        cout << nodos << "   " << tot << endl;
        MB vis(f, vector<bool>(c, false));
        for (int i = 0; i < f; ++i){
            for (int j = 0; j < c; ++j){
                if (! vis[i][j]){
                    vis[i][j] = true;
                    if (g[i][j] != -1) 
                        dfs(g, i, j, vis, tot, nodos);
                }
            }
        }
    }
}