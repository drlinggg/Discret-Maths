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
        vector<int> new_message;
        for (ull i = 0; i < message.size(); i++) {
            new_message.push_back(message[i] ^ code[i%code.size()]);
        }
        cout << "Text:\n" << message << '\n';
        cout << "Code:\n" << code << '\n';
        cout << "Ciphertext:\n";
        for (ll i = 0; i < new_message.size(); i++) {
            cout << new_message[i] << " ";
        }
        return 0;
    }
    else if (c == "--decode") {
        int n;
        vector<int>message;
        cin >> n;
        for (ull i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            message.push_back(temp);
        }
        cin >> code;
        for (ull i = 0; i < message.size(); i++) {
            new_message += (char) (message[i] ^ code[i%code.size()]);
        }
        cout << "Ciphertext:\n";
        for (ll i = 0; i < message.size(); i++) {
            cout << message[i] << " ";
        }
        cout << '\n';
        cout << "Code:\n" << code << '\n';
        cout << "Text:\n" << new_message << '\n';
        return 0;
    }
}
