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

int n;
vector<pair<int, pii>> vec;
vector<pii> range;

int t[N * 4], lazy[N * 4];
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
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}
int ask(int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return 0;
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    push(v);
    return max(ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r));
}

int t2[N * 4], lazy2[N * 4];
void push2(int v){
    t2[v * 2] += lazy2[v];
    t2[v * 2 + 1] += lazy2[v];
    lazy2[v * 2] += lazy2[v];
    lazy2[v * 2 + 1] += lazy2[v];
    lazy2[v] = 0;
}
void update2(int v, int tl, int tr, int l, int r, int val){
    if (l > r || tr < l || r < tl) return;
    if (l <= tl && tr <= r){
        t2[v] += val;
        lazy2[v] += val;
        return;
    }
    int tm = (tl + tr) / 2;
    push2(v);
    update2(v * 2, tl, tm, l, r, val);
    update2(v * 2 + 1, tm + 1, tr, l, r, val);
    t2[v] = t2[v * 2] + t2[v * 2 + 1];
}
int ask2(int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return 0;
    if (l <= tl && tr <= r) return t2[v];
    int tm = (tl + tr) / 2;
    push2(v);
    return ask2(v * 2, tl, tm, l, r) + ask2(v * 2 + 1, tm + 1, tr, l, r);
}

int bit[N];
void upd(int x, int val){
    while (x){
        bit[x] += val;
        x -= (x & (-x));
    }
}
int askbit(int x){
    int ret = 0;
    while (x < N){
        ret += bit[x];
        x += (x & (-x));
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int mx = 0;
    for (int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        mx = max(mx, b);
        vec.pb(mp(b - a, mp(a, b - 1)));
        range.emplace_back(a, b - 1);
    }
    int ans1 = 0, ans2 = 0;
    sort(range.begin(), range.end(), [&](const pii& a, const pii& b)->bool{
        if (a.se != b.se) return a.se < b.se;
        return a.fi > b.fi;
    });
    for (auto& rn : range){
        update2(1, 1, mx, rn.fi, rn.fi, 1);
        update2(1, 1, mx, rn.se, rn.se, 1);
    }
    {
        int last = 0;
        vector<pii> sisa;
        for (auto& rn : range){
            if (last != rn.se){
                last = rn.se;
                for (auto& x : sisa){
                    ans1 = max(ans1, ask2(1, 1, mx, x.fi, x.se) - askbit(x.fi));
                }
                sisa.clear();
            }
            upd(rn.fi, 1);
            sisa.pb(rn);
        }
        for (auto& x : sisa){
            ans1 = max(ans1, ask2(1, 1, mx, x.fi, x.se) - askbit(x.fi));
        }
    }
    sort(vec.begin(), vec.end());
    for (auto& x : vec){
        pii rn = x.se;
        auto temp = ask(1, 1, mx, rn.fi, rn.se);
        ans2 = max(ans2, temp + 1);
        update(1, 1, mx, rn.fi, rn.se, 1);
    }
    cout << ans1 << " " << ans2 << el;

    return 0;
}