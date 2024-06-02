#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void print(const vector<int> &v)
{
    for (int u : v)
        cout << u;
    cout << endl;
}

bool forbidden(int n, const vector<int> &p)
{
    while (n != 0)
    {
        for (int i = 0; i < p.size(); ++i)
        {
            if (n % p[i] == 0)
                return true;
        }
        n /= 10;
    }

    return false;
}

void numeros(int n, const vector<int> &p)
{
    for (int i = pow(10, n - 1); i < pow(10, n); ++i)
    {
        if (!forbidden(i, p))
            cout << i << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (cin >> n >> m)
    {
        vector<int> prohibidas(m);
        for (int i = 0; i < m; ++i)
        {
            int num;
            cin >> num;
            prohibidas[i] = num;
        }
        numeros(n, prohibidas);
        cout << "----------" << endl;
    }
}