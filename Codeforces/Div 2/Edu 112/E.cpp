#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e5 + 10;
const int M = 1e6 + 10;

int n, m;
pair<int, pii> ar[N];
int t[M * 4], lazy[M * 4];

void push(int v){
    t[v * 2] += lazy[v];
    t[v * 2 + 1] += lazy[v];
    lazy[v * 2] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}
void update(int v, int tl, int tr, int l, int r, int val){
    if (l > r || tr < l || r < tl) return;
    if (l <= tl && tr <= r){
        t[v] += val;
        lazy[v] += val;
        return;
    }
    int tm = (tl + tr) / 2;
    push(v);
    update(v * 2, tl, tm, l, r, val);
    update(v * 2 + 1, tm + 1, tr, l, r, val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}
int ask(int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return M;
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    push(v);
    return min(ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r));
}

int solve(){
    int ret = M;
    int l = 1;
    for (int r=1;r<=n;r++){
        pii range = ar[r].se;
        if (range.se < m) range.se--;
        else range.se = m;
        update(1, 1, m, range.fi, range.se, 1);
        while (ask(1, 1, m, 1, m)){
            range = ar[l].se;
            if (range.se < m) range.se--;
            else range.se = m;
            update(1, 1, m, range.fi, range.se, -1);
            l++;
        }
        if (l > 1){
            l--;
            range = ar[l].se;
            if (range.se < m) range.se--;
            else range.se = m;
            update(1, 1, m, range.fi, range.se, 1);
        }
        if (ask(1, 1, m, 1, m)) ret = min(ret, ar[r].fi - ar[l].fi);
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int ans = M;
    for (int i=1;i<=n;i++){
        cin >> ar[i].se.fi >> ar[i].se.se >> ar[i].fi;
    }
    sort(ar + 1, ar + n + 1);
    cout << solve() << el;

    return 0;
}