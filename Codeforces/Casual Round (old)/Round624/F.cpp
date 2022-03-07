#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 2e5 + 10;

int n;
pair<ll, ll> ar[N];

map <int, int> urut;

ll t[N * 4], lazy[N * 4];
void push(int v, ll range){
    t[v * 2] += lazy[v] * ((range + 1) / 2);
    lazy[v * 2] += lazy[v];
    t[v * 2 + 1] += lazy[v] * (range / 2);
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, ll add){
    if (l > r){
        return;
    } else if (tl == l && tr == r){
        t[v] += add * (ll)(r - l + 1);
        lazy[v] += add;
        return;
    } 
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(tm, r), add);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

ll query(int v, int tl, int tr, int l, int r){
    if (l > r){
        return 0;
    } else if (l <= tl && tr <= r){
        return t[v];
    } 
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}


ll t2[N * 4], lazy2[N * 4];
void push2(int v, ll range){
    t2[v * 2] += lazy2[v] * ((range + 1) / 2);
    lazy2[v * 2] += lazy2[v];
    t2[v * 2 + 1] += lazy2[v] * (range / 2);
    lazy2[v * 2 + 1] += lazy2[v];
    lazy2[v] = 0;
}

void update2(int v, int tl, int tr, int l, int r, ll add){
    if (l > r){
        return;
    } else if (tl == l && tr == r){
        t2[v] += add * (ll)(r - l + 1);
        lazy2[v] += add;
        return;
    } 
    push2(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    update2(v * 2, tl, tm, l, min(tm, r), add);
    update2(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    t2[v] = t2[v * 2] + t[v * 2 + 1];
}

ll query2(int v, int tl, int tr, int l, int r){
    if (l > r){
        return 0;
    } else if (l <= tl && tr <= r){
        return t2[v];
    } 
    push2(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    return query2(v * 2, tl, tm, l, min(r, tm)) + query2(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi;
    }
    for (int i=1;i<=n;i++){
        cin >> ar[i].se;
        urut[ar[i].se] = 1;
    }

    int curid = 0;
    for (auto x : urut){
        curid++;
        urut[x.fi] = curid; 
    }
    for (int i=1;i<=n;i++){
        ar[i].se = urut[ar[i].se];
    }
    sort(ar + 1, ar + n + 1);
    ll ans = 0;
    ll cnt = 0;
    ll tot = 0;
    for (int i=1;i<=n;i++){
        ans += (cnt - query2(1, 0, curid, ar[i].se, ar[i].se)) * ar[i].fi - (tot - query(1, 0, curid, ar[i].se, ar[i].se));
        update(1, 0, curid, 0, ar[i].se - 1, ar[i].fi);
        update2(1, 0, curid, 0, ar[i].se - 1, 1);
        tot += ar[i].fi;
        cnt++;
    }
    cout << ans << el;

    return 0;
}