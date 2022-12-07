#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll inceil(ll a, ll b) {
    return (a + b - 1) / b;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll cost, divide, init, interest, pay;
    ll test;

    cin >> cost;
    cin >> divide;
    cin >> init;

    interest = 10;
    divide = 12;

    assert(init < cost);
    assert(divide > 0);
    if (cost <= init) {
        cout << 0 << '\n';
        return 0;
    }
    cost -= init;
    // ll a = cost * (interest + 100);
    // ll b = divide * 100;
    // cout << a / b << '\n';

    cout << cost * (interest + 100) / (divide * 100) << '\n';

    // cost -= init;
    // pay = (cost + divide / 2) / divide;
    // cout << (pay * (interest + 100) + 50) / 100 << '\n';

    return 0;
}