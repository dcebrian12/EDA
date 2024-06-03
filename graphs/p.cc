#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 2e9;
const int DX[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int DY[8] = {2, -2, 2, -2, 1, -1, 1, -1};
typedef vector<vector<char>> Graph;
typedef pair<int, int> Pos;

bool pos_ok(const Graph& g, int f, int c, int i, int j)
{
    return i >= 0 and j >= 0 and j < c and i < f and g[i][j] != 'a';
}

pair<int, double> buscar_flors(const Graph& g, Pos origen)
{
    int f = g.size(), c = g[0].size();
    int t = 0;
    double suma_dist = 0;
    vector<vector<int>> distancia(f, vector<int>(c, INF));
    vector<vector<bool>> vis(f, vector<bool>(c, false));
    distancia[origen.first][origen.second] = 0;
    queue<Pos> q;
    q.push(origen);

    while (not q.empty())
    {
        Pos p = q.front();
        int x = p.first, y = p.second;
        q.pop();
        if (!vis[x][y])
        {
            vis[x][y] = true;
            if (g[x][y] == 'F')
            {
                suma_dist += distancia[x][y];
                ++t;
            }
            for (int i = 0; i < 8; ++i){
                int nx = x + DX[i];
                int ny = y + DY[i];
                if (pos_ok(g, f, c, nx, ny) and distancia[nx][ny] == INF)
                {
                    distancia[nx][ny] = distancia[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    if (t == 0)
        return {-1, -1};
    double mitj = suma_dist/t;
    return {t, mitj};
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(4);

    int f, c;
    cin >> f >> c;
    Graph g(f, vector<char>(c));
    Pos origen;
    for (int i = 0; i < f; ++i){
        for (int j = 0; j < c; ++j)
        {
            cin >> g[i][j];
            if (g[i][j] == 'C')
                origen = {i, j};
        }
    }

    pair<int, double> p = buscar_flors(g, origen);
    if (p.first == -1)
        cout << "el cavall no pot arribar a cap flor" << endl;
    else 
        cout << "flors accessibles: " << p.first << endl << "distancia mitjana: " << p.second << endl;
}