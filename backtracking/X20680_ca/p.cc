#include <iostream>
#include <vector>

using namespace std;


void print(const vector<char>& v){
    for (char u : v)
        cout<< u;
    cout <<endl;
}


void combi(vector<char>& v, int consec, int max_consec, int idx)
{
    if (idx == v.size()){
        print(v);
    }
    else {
        for (char i = 'x'; i <= 'z'; ++i){
            if (idx == 0)
            {
                v[idx] = i;
                combi(v, consec+1, max_consec, idx+1);
            }
            else if (v[idx-1] != i){
                v[idx] = i;
                combi(v, 1, max_consec, idx+1);
            }
            else { //poner letras consecutivas
                if (consec + 1 <= max_consec){
                    v[idx] = i;
                    combi(v, consec + 1, max_consec, idx+1);
                }
            }
        }
    }
}

int main(){
    int n, c;
    while (cin >> n >> c){
        vector<char> v(n);
        combi(v, 0, c, 0);
        cout << "--------------------" << endl;
    }
}
