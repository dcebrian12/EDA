#include <iostream>
#include <vector>
using namespace std;


int convierte_num(const vector<int>& v){
    int n = 0;
    for (int i : v){
        n = n*10 + i;
    }
    return n;
}

int cifras(int n){
    int c = 0;
    while (n != 0){
        ++c;
        n/=10;
    }
    return c;
}

void print(const vector<int> &v)
{
    int n = convierte_num(v);
    if (cifras(n) == v.size())
        cout << convierte_num(v) << endl;

}

bool forbidden(int n, const vector<int> &p)
{

    while (n != 0)
    {
        for (int i : p)
        {
            if (n % i == 0)
                return true;
        }
        n /= 10;
    }

    return false;
}

void nums(vector<int> &v,const vector<int> &p, int n)
{
    if (v.size() == n)
        print(v);
    else
    {
        for (int i = 0; i <= 9; ++i)
        {
            v.push_back(i);
            int num = convierte_num(v);
            if (!forbidden(num, p))
            {
                nums(v, p, n);
                
            }
            v.pop_back();
        }
    }
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> prohibidas(m);
        vector<int> v;
        for (int i = 0; i < m; ++i)
        {
            cin >> prohibidas[i];
        }

        nums(v, prohibidas, n);

        cout << "----------" << endl;
    }
}