#include <bits/stdc++.h>
#define fast std::cin.tie(0);std::ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;

signed main() {
    fast;
    ll n;
    cin >> n;
    vector<string> a;
    for (ll i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        a.push_back(temp);
    }
    for (ll i = 0; i < n; i++) {
        vector<int>bits;
        vector<int>calc_bits;
        for (ll j = 1; j < a[i].size(); j*=2) {
            ll count_b = 0;
            bits.push_back(a[i][j - 1] - '0');
            //01101010000100100
            for (ll z = j; z <= a[i].size(); z += j*2) {
                if (z+j-1 < a[i].size())
                    count_b += count(a[i].begin() + z-1, a[i].begin() + z-1 + j, '1');
                else
                    count_b += count(a[i].begin() + z-1, a[i].end(), '1');
            }
            calc_bits.push_back(count_b % 2);
        }
        ll count_m = 0;
        for (ll y = 0; y < bits.size(); y++) {
            if (calc_bits[y]) {
                count_m += pow(2,y);
            }
        }
        if (count_m != 0 && a[i][count_m-1] == '0') {
            a[i][count_m-1] = '1';
        }
        else if (count_m != 0){
            a[i][count_m-1] = '0';
        }
        ll count_d = 0;
        for (ll h = 1; h <= a[i].size()+count_d; h*=2) {
            a[i].erase(h-1-count_d,1);
            count_d++;
        }
    }
    for (ll i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
    return 0;
}
