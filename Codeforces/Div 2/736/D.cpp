#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int q;
int n;
ll ar[N], inp[N];
ll t[N * 4];

void build(int v, int tl, int tr){
    if (tl == tr){
        t[v] = ar[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = __gcd(t[v * 2], t[v * 2 + 1]);
}
ll ask(int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return 0;
    else if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    return __gcd(ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r));
}

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> inp[i];
        ar[i] = abs(inp[i] - inp[i - 1]);
    }
    fill(t + 1, t + n * 4 + 1, 0);
    build(1, 1, n);
    int ans = 0;
    int l = 1;
    for (int r=1;r<=n;r++){
        ll temp = ask(1, 1, n, l + 1, r);
        while (l <= r && temp == 1){
            l++;
            temp = ask(1, 1, n, l + 1, r);
        }
        if (l > r) continue;
        ans = max(ans, r - l + 1);
    }
    cout << ans << el;
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