#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> Graph;
typedef vector<vector<bool>> MB;
const int DX[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int DY[8] = {0, 1, 0, -1, 1, -1, 1, -1};


void leer_entrada(int f, int c, Graph& g, int& x, int& y)
{
    for (int i = 0; i < f; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            char a;
            cin >> a;
            g[i][j] = a;
            if (a == 'P') 
            {
                x = i;
                y = j;
            }
        }
    }
}


//devuelve true si la posicion es correcta dentro de la matriz. La opcion pared indica si tiene en cuenta o no las paredes al
//determinar la validez de una posicion
bool posicion_correcta(int f, int c, int x, int y, const Graph& g, bool pared)
{
    if (pared) return x >= 0 and y >= 0 and x < f and y < c and g[x][y] != 'X';
    else return x >= 0 and y >= 0 and x < f and y < c;
}

//devuelve true si lhay un fantasma 'F' en una posicion adyacente a la posicion actual {x, y}
bool fantasma_cerca(int x, int y, const Graph& g)
{
    int f = g.size(), c = g[0].size();
    for (int i = 0; i < 8; ++i)
    {
        int new_x, new_y;
        new_x = x + DX[i];
        new_y = y + DY[i];
        if (posicion_correcta(f, c, new_x, new_y, g, false))
        {
            if (g[new_x][new_y] == 'F')
                return true;
        }
            
    }

    return false;
}

//realiza una busqueda DFS para encontrar o no una seta 'B'
bool encuentra_setas(const Graph& g, int x, int y, MB& vis)
{
    int f = g.size();
    int c = g[0].size();
    
    if (!vis[x][y])
    {
        vis[x][y] = true;

        if (g[x][y] == 'B' and not fantasma_cerca(x, y, g))  //quiza se pueda quitar la opcion de buscar el fantasma, no especifica el enunciado que hacer
            return true;

        int x_new, y_new;
        for (int i = 0; i < 4; ++i)
        {
            x_new = x + DX[i];
            y_new = y + DY[i];
            if (posicion_correcta(f, c, x_new, y_new, g, true) and not fantasma_cerca(x_new, y_new, g))
            {
                if (encuentra_setas(g, x_new, y_new, vis))
                    return true;
            }
        }
    }

    return false;

}


int main(){
    int f, c;
    while (cin >> f >> c)
    {
        Graph g(f, vector<char>(c));
        int x, y;
        leer_entrada(f, c, g, x, y);
        MB vis(f, vector<bool>(c, false));
        if (not fantasma_cerca(x, y, g) and encuentra_setas(g, x, y, vis)) 
            cout << "si" << endl;
        else cout << "no" << endl;

    }
}