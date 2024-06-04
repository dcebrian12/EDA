#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> P;
typedef vector<vector<char>> Graph;
typedef vector<vector<bool>> MB;
typedef vector<vector<int>> MI;
const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};
const int INF = 2e9;

void leer_entrada(Graph& g, int f, int c)
{
    for (int i = 0; i < f; ++i){
        for (int j = 0; j < c; ++j)
            cin >> g[i][j]; 
    }
}

bool pos_ok(const Graph& g, int f, int c, int x, int y){
    return x>=0 and y>=0 and x < f and y < c and g[x][y] != 'X';
}

int segon_mes_proper(const Graph& g, P origen)
{
    int f = g.size(), c = g[0].size();
    MB vis(f, vector<bool>(c, false));
    MI dist(f, vector<int>(c, INF));
    vector<int> d_tresor;
    int x = origen.first, y = origen.second;
    dist[x][y] = 0;
    queue<P> q;
    q.push(origen);
    
    while (not q.empty()){
        P n = q.front();
        x = n.first;
        y = n.second;
        q.pop();

        if (g[x][y] == 't'){
            d_tresor.push_back(dist[x][y]);
        }

        if (!vis[x][y]){
            vis[x][y] = true;
            for (int i = 0; i < 4; ++i){
                int nx = x + DX[i];
                int ny = y + DY[i];
                if (pos_ok(g, f, c, nx, ny) and dist[nx][ny] == INF){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    if (d_tresor.size() < 2)
        return -1;
    else 
        return d_tresor[d_tresor.size() - 2];
    
}

int main()
{
    int f, c;
    cin >> f >> c;
    Graph g(f, vector<char>(c));
    leer_entrada(g, f, c);
    int x, y;
    cin >> x >> y;
    int d = segon_mes_proper(g, {x-1, y-1});
    if (d == -1)
        cout << "no es pot arribar a dos o mes tresors" << endl;
    else 
        cout << "segona distancia maxima: " << d << endl;
}