#include <iostream>
#include <vector>
using namespace std;



void print(const vector<string>& v)
{
    cout << "(" << v[0];

    for (int i = 1; i < v.size(); i++)
        cout << "," <<  v[i];
    cout << ")" << endl;
}

void print(vector<pair<string, bool>>& v, int idx, vector<string>& pal)
{
    int n = v.size();
    if (n == idx)
        print(pal);
    else 
    {
        for (int i = 0; i < n; ++i)
        {
            if (!v[i].second)
            {
                pal[idx] = v[i].first;
                v[i].second = true;
                print(v, idx + 1, pal);
                v[i].second = false;
            }
        }
    }
}


int main()
{
    int n;
    cin >> n;
    vector<pair<string, bool>> v(n);
    for (int i = 0; i < n; ++i)
    {
        string p;
        cin >> p;
        v[i].first = p;
        v[i].second = false;
    }
    vector<string> pal(n);
    print(v, 0, pal);
}