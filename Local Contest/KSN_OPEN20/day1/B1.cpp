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
const ll INF = 1e18;

int n, q;
ll ar[N];

set<int> pos0;
vector<pair<ll, pii>> v;

pair<ll, int> t[4 * N]; // val, pos
ll lazy[4 * N];

void build(int v, int tl, int tr){
    if (tl == tr){
        t[v] = {ar[tl], tl};
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}
void push(int v){
    t[v * 2].fi -= lazy[v];
    t[v * 2 + 1].fi -= lazy[v];
    lazy[v * 2] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}
void update(int v, int tl, int tr, int l, int r, ll val){
    if (l > r || tr < l || r < tl) return;
    else if (l <= tl && tr <= r){
        lazy[v] += val;
        t[v].fi -= val;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, r, val);
    update(v * 2 + 1, tm + 1, tr, l, r, val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}
pair<ll, int> ask(int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return mp(INF, -1);
    else if (l <= tl && tr <= r) return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r));
}

vector<pair<ll, int>> quer;
int ans[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    pos0.insert(n + 1);
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        if (ar[i] == 0LL){
            pos0.insert(i);
        }
    }
    build(1, 1, n);
    {
        int last = 1;
        while (last != n + 1){
            auto pos = *pos0.lower_bound(last);
            if (pos == last){
                last++;
                continue;
            }
            auto mn = ask(1, 1, n, last, pos - 1);
            v.pb(mp(mn.fi, mp(last, pos - 1)));
            update(1, 1, n, last, pos - 1, mn.fi);

            int le = last;
            while (le <= pos - 1){
                auto mn2 = ask(1, 1, n, le, pos - 1);
                if (mn2.fi == 0) pos0.insert(mn2.se);
                else break;
                le = mn2.se + 1; 
            }
        }
    }

    cin >> q;
    for (int i=1;i<=q;i++){
        ll x;
        cin >> x;
        quer.pb(mp(x, i));
    }
    sort(quer.begin(), quer.end());

    ll base = 0;
    int cur = 0;
    for (auto x : quer){
        while (base + v[cur].fi * (v[cur].se.se - v[cur].se.fi + 1) < x.fi){
            base += v[cur].fi * (v[cur].se.se - v[cur].se.fi + 1);
            cur++;
        }
        ll range = v[cur].se.se - v[cur].se.fi + 1;
        ll sisa = x.fi - base;
        ans[x.se] = ((sisa - 1LL) % range) + v[cur].se.fi;
    }
    for (int i=1;i<=q;i++){
        cout << ans[i] << el;
    }

    return 0;
}