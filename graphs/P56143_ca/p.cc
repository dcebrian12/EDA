#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<char>> Graph;
typedef vector<vector<int>> MI;
typedef vector<vector<bool>> MB;
typedef pair<int, int> Pos;
const int DX[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int DY[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int INF = 2e9;

bool pos_ok(const Graph &g, int f, int c, int i, int j)
{
    return i >= 0 and j >= 0 and i < f and j < c and g[i][j] != 'X';
}

// si encuentra un pages devuelve la posicion donde se encuentra
Pos bfs(const Graph &g, Pos origen, vector<vector<Pos>> &prev)
{
    int f = g.size(), c = g[0].size();
    MB vis(f, vector<bool>(c, false));
    MI dist(f, vector<int>(c, INF));
    int x = origen.first, y = origen.second;
    dist[x][y] = 0;
    queue<Pos> q;
    q.push({x, y});

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (g[x][y] == 'F')
            return {x, y};

        if (!vis[x][y])
        {
            vis[x][y] = true;
            for (int i = 0; i < 8; ++i)
            {
                int nx = x + DX[i];
                int ny = y + DY[i];
                if (pos_ok(g, f, c, nx, ny) and dist[nx][ny] == INF)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    prev[nx][ny] = {x, y};
                    q.push({nx, ny});
                }
            }
        }
    }

    return {-1, -1};
}

vector<Pos> find_path(const vector<vector<Pos>> prev, Pos origen, Pos destino)
{
    vector<Pos> v;
    while (origen != destino)
    {
        int x = origen.first, y = origen.second;
        v.push_back(origen);
        origen = prev[x][y];
    }
    v.push_back(destino);
    return v;
}

int main()
{
    int f, c;
    while (cin >> f >> c)
    {
        Pos origen;
        Graph g(f, vector<char>(c));
        for (int i = 0; i < f; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                cin >> g[i][j];
                if (g[i][j] == 'K')
                    origen = {i, j};
            }
        }

        vector<vector<Pos>> prev(f, vector<Pos>(c, {-1, -1}));
        Pos destino = bfs(g, origen, prev);
        if (destino.first == -1)
            cout << '0' << endl;
        else
        {
            vector<Pos> v = find_path(prev, destino, origen);
            int n = v.size();
            cout << n;
            for (int i = n - 1; i >= 0; --i)
                cout << "  " << v[i].first << " " << v[i].second;
            cout << endl;
        }
    }
}
