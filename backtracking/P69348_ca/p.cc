#include <iostream>
#include <vector>

using namespace std;


void print(const vector<int>& v)
{
    int n = v.size();
    if (n == 1)
    {
        cout << "(" << v[0]+1 << ")" << endl;
    }
    else{
        cout << "(" << v[0]+1 << ",";
        for (int i = 1; i < n-1; i++)
            cout << v[i] + 1 << ",";
        cout << v[n-1]+1 << ")" << endl;
    }
}

void output(vector<int>& v, vector<bool>& vb, int idx)
{
    int n = v.size();
    if(idx == n)
        print(v);
    else {
        for (int i = 0; i < n; ++i)
        {
            if (!vb[i])
            {
                v[idx] = i;
                vb[i] = true;
                output(v, vb, idx + 1);
                vb[i] = false;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<bool> vb(n, false);
    output(v, vb, 0);

}