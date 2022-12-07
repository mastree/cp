#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e4 + 10;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    ll lcm = 1;
    for (int i = 1; i <= t; i++) {
        int y, n;
        cin >> y >> n;
        vector<ll> vec(n);
        for (auto& x : vec) cin >> x;
        for (auto& x : vec) {
            lcm = lcm * x / __gcd(lcm, x);
        }
        cout << lcm << '\n';
    }

    return 0;
}