#include <iostream>
#include <vector>
using namespace std;

void print(const vector<char> &v)
{
    for (char i : v)
        cout << i;
    cout << endl;
}

void permuta(vector<char> &v, int idx, vector<bool>& vb)
{
    int n = v.size();
    if (n == idx)
        print(v);
    else
    {
        for (int i = 0; i <  n; ++i)
        {
            char letra = 'a' + i;
            if (!vb[i] && (idx == 0 || v[idx - 1] + 1 != letra))
            {
                v[idx] = letra;
                vb[i] = true;
                permuta(v, idx + 1, vb);
                vb[i] = false;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<char> v(n);
    vector<bool> vb(n, false);
    permuta(v, 0, vb);
}