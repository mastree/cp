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

const int N = 2e5 + 7;
const ll INF = 1e18;

ll n, d, a;
vector<pair<ll, ll>> pos; 
ll tot, ans;

map <ll, ll> cek;

ll t[N * 4], lazy[N * 4];
 
void push(int v, ll range) {
    t[v*2] += lazy[v] * ((range + 1) / 2);
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v] * (range / 2);
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}
 
void update(int v, int tl, int tr, int l, int r, ll addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend * (ll)(r - l + 1);
        lazy[v] += addend;
    } else {
        push(v, tr - tl + 1);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = t[v*2] + t[v*2+1];
    }
}
 
ll query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l <= tl && tr <= r)
        return t[v];
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm)) + query(v*2+1, tm+1, tr, max(l, tm+1), r);
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d >> a;
    for (int i=1;i<=n;i++){
        ll tm1, tm2;
        cin >> tm1 >> tm2;
        cek[tm1] = max(cek[tm1], tm2);
    }
    pos.pb(mp(0, 0));
    for (auto x : cek){
        pos.pb(x);
    }
    n = pos.size() - 1;

    for (int i=1;i<=n;i++){
        update(1, 1, n, i, i, pos[i].se);
    }

    for (int i=1;i<=n;i++){
        ll sisa = query(1, 1, n, i, i);
        if (sisa > 0){
            ll atk = (sisa + a - 1) / a;
            ans += atk;
            atk *= a;
            auto it = upper_bound(pos.begin(), pos.end(), mp(pos[i].fi + d + d, INF));
            int last = (int)(it - pos.begin()) - 1;
            update(1, 1, n, i, last, -atk);
        }
    }
    cout << ans << el;

    return 0;
}