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

const int N = 1e6 + 10;

int n;
int ar[N];
int bit[N];
map <int, int> kompres;
int le[N], ri[N];

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

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        kompres[ar[i]] = 1;
    }
    int subt = 1;
    for (auto x : kompres){
        kompres[x.fi] = subt;
        subt++;
    }
    for (int i=1;i<=n;i++){
        ar[i]=kompres[ar[i]];
        ri[ar[i]]++;
    }

    for (int i=1;i<subt;i++){
        update(1, 1, n, 1, ri[i], 1);
    }

    ll ans = 0;
    for (int i=1;i<n;i++){
        int up = ar[i];
        le[up]++;
        update(1, 1, n, ri[up], ri[up], -1);
        ri[up]--;
        if (le[up]==1) continue;
        ans = (ans + (ll)query(1, 1, n, 1, le[up]-1));
    }
    cout << ans << el;

    return 0;
}