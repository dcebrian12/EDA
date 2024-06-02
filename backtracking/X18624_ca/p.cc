#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void print(const vector<char>& p){
    for (char i : p)
        cout << i;
    cout << endl;
}

bool es_vocal(char a){
    return a == 'a' or a == 'e' or a == 'i' or a == 'o' or a == 'u';
}

void permuta(vector<char>& p, vector<char>& letras, int idx)
{
    if (idx == p.size())
        print(p);
    else
    {
        for (int i = 0; i < letras.size(); ++i)
        {
            if (idx == 0 or not es_vocal(letras[i]) or not es_vocal(p[idx-1]))
            {
                p[idx] = letras[i];
                permuta(p, letras,idx+1);
            }
        }
    }
}

int main(){
    int n, m;
    while (cin >> n >> m){
        vector<char> p(m);
        for (int i = 0; i < m; ++i){
            char a; cin >> a;
            p[i] = a;
        }
        vector<char> f(n);
        sort(p.begin(), p.end());
        permuta(f, p, 0);
        cout << "----------" << endl;
    }
}