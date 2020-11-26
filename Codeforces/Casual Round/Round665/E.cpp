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

const int N = 1e6 + 10;

int n, m;
vector<pii> ver[N];
vector<int> hora[N], horb[N];

ll bit[N];
void upd(int x, ll val){
    x++;
    while (x < N){
        bit[x] += val;
        x += (x & (-x));
    }
}
ll ask(int x){
    x++;
    ll ret = 0;
    while (x > 0){
        ret += bit[x];
        x -= (x & (-x));
    }
    return ret;
}
ll ask(int l, int r){
    return ask(r) - ask(l - 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    if (1){
        for (int i=1;i<=n;i++){
            int y, a, b;
            cin >> y >> a >> b;
            hora[a].pb(y);
            horb[b].pb(y);
        }
        hora[0].pb(N - 10);
        horb[N - 10].pb(N - 10);
        hora[0].pb(0);
        horb[N - 10].pb(0);
    }
    if (1){
        for (int i=1;i<=m;i++){
            int y, a, b;
            cin >> y >> a >> b;
            ver[y].pb(mp(a, b));
        }
        ver[0].emplace_back(0, N - 10);
        ver[N - 10].emplace_back(0, N - 10);
    }

    ll ans = 0;
    set<int> setdah;
    for (int i=0;i<N;i++){
        for (auto x : hora[i]){
            setdah.insert(x);
        }
        for (auto x : ver[i]){
            ans += max(ask(x.fi, x.se) - 1, 0LL);
            auto it = setdah.lower_bound(x.fi);
            vector<int> pus;
            while (it != setdah.end() && *it <= x.se){
                upd(*it, 1);
                pus.pb(*it);
                it++;
            }
            for (auto x : pus) setdah.erase(x);
        }
        for (auto x : horb[i]){
            if (setdah.find(x) == setdah.end()){
                upd(x, -1);
            } else setdah.erase(x);
        }
    }
    cout << ans << el;

    return 0;
}