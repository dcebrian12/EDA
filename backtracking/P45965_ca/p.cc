#include <iostream>
#include <vector>
using namespace std;

void output(vector<int> &v, int unos, int k, int idx)
{
    if (v.size() == idx)
    {
        if (unos == k)
        {
            for (int i = 0; i < v.size() - 1; ++i)
                cout << v[i] << " ";
            cout << v[v.size() - 1] << endl;
        }
    }
    else 
    {
        v[idx] = 0;
        output(v, unos, k, idx + 1);
        v[idx] = 1;
        output(v, unos + 1, k, idx + 1);
    }
}

int main()
{
    int n, u;
    cin >> n >> u;
    vector<int> v(n);
    output(v, 0, u, 0);
}