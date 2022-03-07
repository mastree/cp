#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int q;
ll a, b, n, m;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> a >> b >> n >> m;
        if (a + b < n + m){
            cout << "NO" << el;
            continue;
        }
        if (min(a, b) >= m){
            cout << "YES" << el;
            continue;
        }
        cout << "NO" << el;
    }

    return 0;
}