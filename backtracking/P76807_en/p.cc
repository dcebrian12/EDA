#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int>> Matriz;

void print_sudoku(const Matriz &m)
{
    for (int j = 0; j < 9; ++j)
    {
        for (int k = 0; k < 8; ++k)
        {
            cout << m[j][k] << " ";
        }
        cout << m[j][8] << endl;
    }
}

bool busca_num(const Matriz &m, int f, int c, int n)
{
    for (int i = 0; i < 9; ++i)
        if (m[f][i] == n)
            return false;
    for (int i = 0; i < 9; ++i)
        if (m[i][c] == n)
            return false;
    int startRow = f - f % 3,
        startCol = c - c % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (m[i + startRow][j + startCol] == n)
                return false;
    return true;
}

void resolver_sudoku(Matriz &m, int x, int y)
{
    // cout << "X: " << x << "  Y:  " << y << endl;
    if (x == 9)
        print_sudoku(m);
    else if (y == 9)
        resolver_sudoku(m, x + 1, 0);
    else
    {
        if (m[x][y] == -1)
        {
            for (int i = 1; i <= 9; ++i)
            {
                if (busca_num(m, x, y, i))
                {
                    m[x][y] = i;
                    resolver_sudoku(m, x, y + 1);
                    m[x][y] = -1;
                }
            }
        }
        else
            resolver_sudoku(m, x, y + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << n << endl << endl;
    for (int i = 0; i < n; ++i)
    {
        Matriz m(9, (vector<int>(9, -1)));
        for (int j = 0; j < 9; ++j)
        {
            for (int k = 0; k < 9; ++k)
            {
                char a;
                cin >> a;
                if (a != '.')
                {
                    m[j][k] = a - '0';
                }
            }
        }

        resolver_sudoku(m, 0, 0);
       if (i != n-1) cout << endl;
    }
}