#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll ret = 1;
    for (int i = 0; i < 3; i++) {
        ll a;
        cin >> a;
        ret = ret * a / __gcd(ret, a);
    }
    cout << ret << '\n';

    return 0;
}