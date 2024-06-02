#include <iostream>
#include <vector>

using namespace std;

vector<char> buffer = {'A', 'C', 'G', 'T'};

void print(const vector<char> &p)
{
    for (char i : p)
        cout << i;
    cout << endl;
}

void print(vector<bool> &vb, int idx, vector<char> &p)
{
    int n = p.size();
    if (idx == n)
        print(p);
    else
    {
        for (int i = 0; i < 4; ++i)
        {

            if (!vb[i] or idx != n)
            {
                vb[i] = true;
                p[idx] = buffer[i];
                print(vb, idx + 1, p);
                vb[i] = false;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<bool> v(n, false);
    vector<char> pal(n);
    print(v, 0, pal);
}