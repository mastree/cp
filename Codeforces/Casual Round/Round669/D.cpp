#pragma gcc optimize ("O3")
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
const int INF = 1e9 + 10;

int n;
int ar[N];
int dp[N];

pii t[4 * N];
void build(int v, int tl, int tr){
    if (tl == tr){
        t[v] = mp(ar[tl], tl);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}
pii ask(int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return mp(INF, -1);
    else if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    return min(ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r));
}
pii t2[4 * N];
void build2(int v, int tl, int tr){
    if (tl == tr){
        t2[v] = mp(ar[tl], tl);
        return;
    }
    int tm = (tl + tr) / 2;
    build2(v * 2, tl, tm);
    build2(v * 2 + 1, tm + 1, tr);
    t2[v] = max(t2[v * 2], t2[v * 2 + 1]);
}
pii ask2(int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return mp(-INF, -1);
    else if (l <= tl && tr <= r) return t2[v];
    int tm = (tl + tr) / 2;
    return max(ask2(v * 2, tl, tm, l, r), ask2(v * 2 + 1, tm + 1, tr, l, r));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    {
        map<int, int> getid;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            getid[ar[i]] = 1;
        }
        int tempid = 0;
        for (auto& x : getid){
            x.se = ++tempid;
        }
        for (int i=1;i<=n;i++){
            ar[i] = getid[ar[i]];
        }
    }
    build(1, 1, n);
    build2(1, 1, n);
    fill(dp, dp + n + 2, INF);
    dp[n] = 0;
    for (int i=n - 1;i>=1;i--){
        {
            int l = i + 1, r = n;
            while (l < r){
                int m = (l + r + 1) / 2;
                if (ask2(1, 1, n, i + 1, m).fi >= ar[i]){
                    r = m - 1;
                } else{
                    l = m;
                }
            }
            if (l != n && ar[l] < ar[i]) l++;
            auto temp = ask2(1, 1, n, i + 1, l - 1);
            if (temp.fi < ar[i] && temp.fi < ar[l]) dp[i] = min(dp[i], dp[l] + 1);
        }
        {
            int l = i + 1, r = n;
            while (l < r){
                int m = (l + r + 1) / 2;
                if (ask(1, 1, n, i + 1, m).fi <= ar[i]){
                    r = m - 1;
                } else{
                    l = m;
                }
            }
            if (l != n && ar[l] > ar[i]) l++;
            auto temp = ask(1, 1, n, i + 1, l - 1);
            if (temp.fi > ar[i] && temp.fi > ar[l]) dp[i] = min(dp[i], dp[l] + 1);
        }
    }
    cout << dp[1] << el;

    return 0;
}