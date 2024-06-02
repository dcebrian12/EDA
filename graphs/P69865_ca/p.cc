#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Graph;

const int DXK[8] = {2, 2, -2, -2, 1, 1, -1, -1};
const int DYK[8] = {1, -1, 1, -1, 2, -2, 2, -2};
const int DXA[4] = {1, 1, -1, -1};
const int DYA[4] = {1, -1, 1, -1};

bool pos_ok(const Graph& g, int f, int c, int i, int j)
{
    return i >= 0 and j >= 0 and i < f and j < c and g[i][j] != 'T';
}

void dfs_bishops(Graph& g, int& total, int x, int y, vector<vector<bool>>& v)
{
    for (int i = 0; i < 4; ++i)
    {
        int x2 = x + DXA[i];
        int y2 = y + DYA[i];
        if (pos_ok(g, g.size(), g[0].size(), x2, y2) and !v[x2][y2])
        {
            v[x2][y2] = true;
            if (g[x2][y2] >= '1' and g[x2][y2] <= '9')
            {
                total += g[x2][y2] - '0';
                g[x2][y2] = '.';
            }
            dfs_bishops(g, total, x2, y2, v);
        }
    }
}


void dfs_c(Graph& g, int& total, int x, int y, vector<vector<bool>>& v)
{
    for (int i = 0; i < 8; ++i)
    {
        int x2 = x + DXK[i];
        int y2 = y + DYK[i];
        if (pos_ok(g, g.size(), g[0].size(), x2, y2) and !v[x2][y2])
        {
            v[x2][y2] = true;
            if (g[x2][y2] >= '1' and g[x2][y2] <= '9')
            {
                total += g[x2][y2] - '0';
                g[x2][y2] = '.';
            }
            dfs_c(g, total, x2, y2, v);
        }
    }
}

int main()
{
    int f, c;
    while (cin >> f >> c)
    {
        Graph g(f, vector<char>(c));
        for (int i = 0; i < f; ++i){
            for (int j = 0; j < c; ++j){
                cin >> g[i][j];
            }
        }

        vector<vector<bool>> vis_bishops(f, vector<bool>(c, false));
        vector<vector<bool>> vis_c(f, vector<bool>(c, false));
        int total = 0;
        for (int i = 0; i < f; ++i){
            for (int j = 0; j < c; ++j){
                if (g[i][j] == 'B' and !vis_bishops[i][j])
                {
                    vis_bishops[i][j] = true;
                    dfs_bishops(g, total, i, j, vis_bishops);
                }
                else if (g[i][j] == 'K' and !vis_c[i][j])
                {
                    vis_c[i][j] = true;
                    dfs_c(g, total, i, j, vis_c);
                }
            }
        }

        cout << total << endl;

    }
}