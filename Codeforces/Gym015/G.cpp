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
int n, a, b;

void solve(){
    cin >> n >> a >> b;
    int del = a - b;
    int ans = 1;
    n -= a;
    if (n <= 0){
        cout << ans << el;
        return;
    }
    if (del <= 0){
        cout << -1 << el;
        return;
    }
    cout << ans + (n + del - 1) / del << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}