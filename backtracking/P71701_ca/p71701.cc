#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> Tablero;
const int DX[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int DY[8] = {0, 0, 1, -1, 1, -1, 1, -1};

void print(const Tablero &t)
{
    for (int i = 0; i < t.size(); ++i)
    {
        for (int j = 0; j < t.size(); ++j)
        {
            cout << t[i][j];
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

bool pos_ok(int n, int x, int y)
{
    return x >= 0 and y >= 0 and x < n and y < n;
}

bool valid(const Tablero &t, int x, int y)
{

    for (int i = 0; i < 8; ++i)
    {
        int x2 = x + DX[i];
        int y2 = y + DY[i];
        if (pos_ok(t.size(), x2, y2) and t[x2][y2] == 'K')
            return false;
    }
    return true;
}

void backtrack(Tablero &t, int i, int j, int tot, int k)
{
    int n = t.size();
    if (i == n)
        return;
    else if (k == tot)
        print(t);
    else {
        if (j == n)
            backtrack(t, i + 1, 0, tot, k);
        else
        {
            if (valid(t, i, j))
            {
                t[i][j] = 'K';
                tot++;
                backtrack(t, i, j + 1, tot, k);
                tot--;
                t[i][j] = '.';
            }
            backtrack(t, i, j + 1, tot, k);
        }
    }
}

int main()
{
    int s, k;
    cin >> s >> k;
    Tablero t(s, vector<char>(s, '.'));
    backtrack(t, 0, 0, 0, k);
}