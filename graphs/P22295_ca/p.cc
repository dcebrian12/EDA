#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<vector<bool>> MB;
typedef vector<vector<char>> Graph;
const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

void leer_entrada(Graph &g, int f, int c)
{
    for (int i = 0; i < f; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            char m;
            cin >> m;
            g[i][j] = m;
        }
    }
}

bool pos_ok(int f, int c, int x, int y)
{
    return x >= 0 and y >= 0 and x < f and y < c;
}

void dfs(const Graph &g, int xi, int yi, int xf, int yf, vector<char> &s, MB &vis)
{
    int f = g.size(), c = g[0].size();
    if (xi == xf and yi == yf)
    {
        for (char i : s)
            cout << i;
        cout << endl;
        //s.pop_back();
    }
    else
    {
        if (!vis[xi][yi])
        {
            vis[xi][yi] = true;
            for (int i = 0; i < 4; ++i)
            {
                int xn = xi + DX[i];
                int yn = yi + DY[i];
                if (pos_ok(f, c, xn, yn))
                {
                    s.push_back(g[xn][yn]);
                    dfs(g, xn, yn, xf, yf, s, vis);
                    if (s.size() > 1)
                        s.pop_back();
                }
            }
            vis[xi][yi] = false;
        }
    }
}

int main()
{
    int f, c;
    cin >> f >> c;
    Graph g(f, vector<char>(c));
    leer_entrada(g, f, c);
    int xi, yi, xf, yf;
    cin >> xi >> yi >> xf >> yf;
    vector<char> s;
    s.push_back(g[xi][yi]);
    MB vis(f, vector<bool>(c, false));
    dfs(g, xi, yi, xf, yf, s, vis);
}