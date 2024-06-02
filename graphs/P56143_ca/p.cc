#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<char>> Tablero;
typedef pair<int, int> Pos;
const int DX[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int DY[8] = {0, 1, 0, -1, 1, -1, 1, -1};

bool pos_ok(const Tablero &t, int f, int c, int x, int y)
{
    return x >= 0 and y >= 0 and x < f and y < c and t[x][y] != 'X';
}

bool bfs(const Tablero &t, Pos &origen, vector<vector<Pos>> &v)
{
    int f = t.size(), c = t[0].size();
    // vector<vector<int>> distancia(f, vector<int>(c, INF));
    vector<vector<bool>> vis(f, vector<bool>(c, false));
    queue<Pos> q;
    q.push(origen);
    // distancia[x][y] = 0;
    int x = origen.first;
    int y = origen.second;
    v[x][y] = {-1, -1};

    while (!q.empty())
    {
        Pos p = q.front();
        q.pop();
        x = p.first;
        y = p.second;
        if (t[x][y] == 'F')
        {
            origen.first = x;
            origen.second = y;
            return true;
        }

        if (!vis[x][y])
        {
            vis[x][y] = true;
            Pos nueva;
            for (int i = 0; i < 8; ++i)
            {
                nueva.first = x + DX[i];
                nueva.second = y + DY[i];
                if (pos_ok(t, f, c, nueva.first, nueva.second))
                {
                    q.push(nueva);
                    v[nueva.first][nueva.second] = p;
                }
            }
        }
    }
    return false;
}

vector<Pos> find_path(const vector<vector<Pos>> &p, Pos origen)
{
    vector<Pos> v;
    int x = origen.first, y = origen.second;
    while (x != -1 and y != -1)
    {
        v.push_back({x, y});
        origen = p[x][y];
        x = origen.first;
        y = origen.second;
    }
    return v;
}

int main()
{
    int f, c;
    while (cin >> f >> c)
    {
        Pos p;
        Tablero t(f, vector<char>(c, '.'));
        for (int i = 0; i < f; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                char m;
                cin >> m;
                t[i][j] = m;
                if (t[i][j] == 'K')
                {
                    p.first = i;
                    p.second = j;
                }
            }
        }


        vector<vector<Pos>> v(f, vector<Pos>(c, {-1, -1}));
        if (not bfs(t, p, v))
            cout << "0" << endl;
        else
        {
            vector<Pos> path = find_path(v, p);
            int n = path.size();
            cout << n;
            for (int i = 0; i < n - 1; ++i)
                cout << "  " << path[i].first << " " << path[i].second;
            cout << "  " << path[n - 1].first << " " << path[n - 1].second << endl;
        }
    }
}