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

    ll mn, percent, mx, cost, count;
    cin >> mn >> percent >> mx >> cost >> count;
    cost = cost * count;
    if (cost < mn) {
        cout << cost << '\n';
        return 0;
    }
    cost -= min(mx, cost * percent / 100);
    cout << cost << '\n';

    return 0;
}