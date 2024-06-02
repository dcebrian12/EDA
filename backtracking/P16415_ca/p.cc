#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int>> Matriz;
const int NUMS[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};


void print_sudoku(const Matriz& m)
{
    for (int j = 0; j < 9; ++j)
    {
        for (int k = 0; k < 8; ++k)
        {
            cout << m[j][k] << " ";
        }
        cout << m[j][8] << endl;
    }

    cout << endl;
}

bool busca_num(const Matriz& m, int f, int c, int n)
{
    for (int i = 0; i < 9; ++i)
        if (m[f][i] == n) 
            return false;
    for (int i = 0; i < c; ++i)
        if (m[i][c] == n)
            return false;
    return true;
}

void resolver_sudoku(Matriz& m, int x, int y)
{
    if (x > 8)
        print_sudoku(m);
    else {
        if (m[x][y] == -1)
        {
            for (int i : NUMS)
                if (busca_num(m, x, y, i)){
                    m[x][y] = i;
                    break;
                }
            if (y + 1 > 8){
                y = 0;
                ++x;
            }
            else ++y;

            resolver_sudoku(m, x, y);
        }
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        Matriz m(9,(vector<int>(9, -1)));
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

    }
}