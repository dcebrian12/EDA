//FALLA LA EFICIENCIA!! PRIVADO EE


#include <iostream>
#include <vector>

using namespace std;


void ubicar(const vector<string>& persona, const vector<vector<int>>& manias, vector<string>& ubicacion, vector<bool> &vb, int t, int & min, int idx, vector<string>& f, int l)
{
    if (idx == persona.size())
    {
       if (t < min)
        {
            min = t;
            f = ubicacion;
        }   
    }
    else {
        for (int i = 1; i < persona.size(); ++i)
        {
            if (!vb[i]){
                vb[i] = true;
                ubicacion[idx] = persona[i];
                t += manias[i][l];
                ubicar(persona, manias, ubicacion, vb, t, min, idx + 1, f, i);
                t -= manias[i][l];
                vb[i] = false;
            }
        }
    }
}

int main()
{
    int n;
    while (cin >> n){
        vector<string> personas(n);

        for (int i = 0; i < n; ++i)
            cin >> personas[i];

        vector<vector<int>> manias(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                cin >> manias[i][j];
        }

        vector<bool> vb(n, false);
        vb[0] = true;
        vector<string> ubicacion(n);
        vector<string> f(n);
        ubicacion[0] = personas[0];
        int min = 2e9, t = 0;
        ubicar(personas, manias, ubicacion, vb, t, min, 1, f, 0);
        cout << min << endl << f[0];
        for (int i = 1; i < n; ++i)
            cout << " " << f[i];
        cout << endl;
    }


}