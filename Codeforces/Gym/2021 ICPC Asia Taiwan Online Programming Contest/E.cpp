#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll p, q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> p >> q;
    // p <= q * d^5
    ll a = (p + q - 1) / q;
    ll d = 1;
    for (;;d++){
        ll temp = d * d * d * d * d;
        if (a <= temp) break;
    }
    // d -> hari pertama untung

    return 0;
}