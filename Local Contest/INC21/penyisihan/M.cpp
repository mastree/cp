#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll k, s, n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> s >> n;
    if (k * s <= n && n <= (k + k - 2) * s){
        cout << "YES" << el;
        return 0;
    } else if (n < k * s){
        cout << "NO" << el;
        return 0;
    }
    n -= (k + k - 2) * s;
    if (s == 1 && (n & 1)) cout << "NO" << el;
    else cout << "YES" << el;

    return 0;
}