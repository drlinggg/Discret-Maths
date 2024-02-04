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

string to_bin(ll n, ll count){
    string ans;
    for (ll i = 0; i < count; i++) {
        ans += (char) (n%2+'0');
        n /= 2;
    }
    return ans;
}

signed main() {
    fast;
    ll n;
    cin >> n;
    ll number = pow(2,n);
    string array[number];
    vector<char>saved;
    vector<char>saved_uniq;
    char c;
    ll count = 0;
    while (cin >> c) {
        if (c == '1') {
            break;
        }
        count++;
        saved.push_back(c);
        int flag = 0;
        for (ll i = 0; i < saved_uniq.size(); i++) {
            if (saved_uniq[i] == c) {
                flag = 1;
            }
        }
        if (flag == 0) {
            saved_uniq.push_back(c);
        }
    }
    for (ll i = 0; i < number; i++) {
        array[i] = to_bin(i, n);
        for (ll j = 0; j < n-1; j++) {
            array[i][j] = (char) (((ll) (array[i][j] - '0')) ^ ((ll) (array[i][j+1] - '0'))) + '0';
        }
    }
    for (ll i = 0; i < saved_uniq.size(); i++) {
        reverse(array[i].begin(), array[i].end());
        cout << saved_uniq[i] << ": " << array[i] << '\n';
    }
    for (ll i = 0; i < saved.size(); i++) {
        for (ll j = 0; j < saved_uniq.size(); j++) {
            if (saved_uniq[j] == saved[i]) {
                cout << array[i];
            }
        }
    }
    return 0;
}
