#include <bits/stdc++.h>
#define fast std::cin.tie(0);std::ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll RBN = 1e9+7;
const ll RSN = -(1e9+7);
const double PI = 3.141592653589793;
//mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()); ll gen(){return rnd()%100;}

signed main() {
    fast
    char alph[5][5] = {
            {'F', 'N', 'H', 'E', 'Q'},
            {'R', 'D', 'Z', 'O', 'C'},
            {'I', 'S', 'A', 'G', 'U'},
            {'B', 'V', 'K', 'P', 'W'},
            {'X', 'M', 'Y', 'T', 'L'}
    };
    string letters = "ADFGX";
    string message, code, c;
    cin >> c >> message >> code;
    if (c == "--code") {
        char new_message[message.size()*2];
        for (ll i = 0; i < message.size(); i++) {
            for (ll j = 0; j < 5; j++) {
                for (ll z = 0; z < 5; z++) {
                    if (alph[j][z] == message[i]) {
                        new_message[i*2] = letters[j];
                        new_message[i*2+1] = letters[z];
                    }
                }
            }
        }
        //j высота i ширина
        char matrix[code.size()][sizeof new_message / code.size()];
        for (ll i = 0; i < code.size(); i++) {
            for (ll j = 0; j < sizeof new_message / (code.size()); j++) {
                matrix[i][j] = new_message[j*code.size()+i];
            }
        }
        for (ll i = 0; i < code.size(); i++) {
            for (ll j = 0; j < code.size(); j++) {
                if (code[i] < code[j]) {
                    swap(code[i],code[j]);
                    for (ll z = 0; z < sizeof new_message / code.size(); z++) {
                        swap(matrix[i][z],matrix[j][z]);
                    }
                }
            }
        }
        for (ll i = 0; i < code.size(); i++) {
            for (ll j = 0; j < sizeof matrix[i]; j++) {
                cout << matrix[i][j] << " ";
            }
        }
    }
    else if (c == "--decode") {
        //to be continue
    }
    return 0;
}
