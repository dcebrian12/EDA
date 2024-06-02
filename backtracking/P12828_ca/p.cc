#include <iostream>
#include <vector>

using namespace std;

void output(vector<int>& v, int idx)
{
    if (idx == v.size())
    {
        for (int i = 0; i < v.size() - 1; ++i)
            cout << v[i] << " ";
        cout << v[v.size()-1] << endl;
    }
    else {
        v[idx] = 0;
        output(v, idx + 1);
        v[idx] = 1;
        output(v, idx + 1);
    }
   
}


int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    output(v, 0);
}