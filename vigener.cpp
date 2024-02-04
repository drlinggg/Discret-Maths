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
    fast;
    string message, code, new_message;
    string c;
    cin >> c;
    if (c == "--code") {
        cin >> message >> code;
        new_message = message;
        for (ull i = 0; i < message.size(); i++) {
            new_message[i] = (message[i] - 65 + code[i % code.size()] - 65) % 26 + 65;
        }
        cout << "Text:\n" << message << '\n';
        cout << "Code:\n" << code << '\n';
        cout << "Ciphertext:\n" << new_message << '\n';
        return 0;
    }
    else if (c == "--decode") {
        cin >> message >> code;
        new_message = message;
        for (ull i = 0; i < message.size(); i++) {
            if (message[i] < code[i%code.size()]) {
                new_message[i] = message[i] - code[i%code.size()] + 91;
            }
            else{
                new_message[i] = message[i] - code[i%code.size()] + 65;
            }
        }
        cout << "Ciphertext:\n" << message << '\n';
        cout << "Code:\n" << code << '\n';
        cout << "Text:\n" << new_message << '\n';
        return 0;
    }
}
