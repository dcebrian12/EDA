#include <iostream>
#include <vector>
#include <string>

using namespace std;

void combinacion(vector<string>& v, const vector<string>& palabras, vector<bool>& vb)
{
    if (palabras.size() == v.size()){
        for (string u : v)
            cout << u;
        cout << endl;
    }
    else {
        for (int i = 0; i < palabras.size(); ++i)
        {
            if (v.size() == 0){
                v.push_back(palabras[i]);
                vb[i] = true;
                combinacion(v, palabras, vb);
                v.pop_back();
                vb[i] = false;
            }
            else {
                if (!vb[i])
                {
                    int n = v.size();
                    int mida = v[n - 1].length();
                    if (v[n-1][mida-1] != palabras[i][0])
                    {
                        vb[i] = true;
                        v.push_back(palabras[i]);
                        combinacion(v, palabras, vb);
                        v.pop_back();
                        vb[i] = false;
                    }
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> conj_palabras(n);
    vector<bool> vb(n, false);
    vector<string> combi;
    for (int i = 0; i < n; ++i)
        cin >> conj_palabras[i];
    combinacion(combi, conj_palabras, vb);

}