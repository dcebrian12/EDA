#include <iostream>
#include <vector>

using namespace std;

// Funció que comprova si cap dels prefixos d'un nombre donat és múltiple de cap divisor prohibit.
bool es_valid(const vector<int>& nombre, const vector<int>& divisors) {
    int prefix = 0;
    for (int digit : nombre) {
        prefix = prefix * 10 + digit;
        for (int divisor : divisors) {
            if (prefix % divisor == 0) {
                return false;
            }
        }
    }
    return true;
}

// Funció recursiva per generar nombres de n dígits utilitzant backtracking.
void genera_nombres(vector<int>& nombre, int n, const vector<int>& divisors) {
    if (nombre.size() == n) {
        for (int digit : nombre) {
            cout << digit;
        }
        cout << endl;
        return;
    }

    for (int digit = 1; digit <= 9; ++digit) { // Els dígits han de ser de 1 a 9
        nombre.push_back(digit);
        if (es_valid(nombre, divisors)) {
            genera_nombres(nombre, n, divisors);
        }
        nombre.pop_back();
    }
}

int main() {
    int n = 2; // Nombre de dígits
    vector<int> divisors = {3}; // Divisors prohibits

    vector<int> nombre; // Vector per emmagatzemar el nombre actual

    genera_nombres(nombre, n, divisors);

    return 0;
}
