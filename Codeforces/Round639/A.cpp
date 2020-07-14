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

void push(int v, ll range){
    lazy[v * 2 + 1] += lazy[v];
    lazy[v * 2 + 2] += lazy[v];
    t[v * 2 + 1] += lazy[v] * (range + 1) / 2;
    t[v * 2 + 2] += lazy[v] * range / 2;
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, ll add){
    if (l > r){
        return;
    } else if (tl == l && tr == r){
        ll range = (ll)(r - l + 1);
        t[v] += range * add;
        lazy[v] += add;
        return;
    } 
    int tm = (tl + tr) / 2;
    push(v, (ll)(tr - tl + 1));
    update(v * 2 + 1, tl, tm, l, min(tm, r), add);
    update(v * 2 + 2, tm + 1, tr, max(l, tm + 1), r, add);
    t[v] += t[v * 2 + 1] + t[v * 2 + 2];
}

int query(int v, int tl, int tr, int l, int r){
    if (l > r){
        return 0;
    } else if (l <= tl && tr <= r){
        return t[v];
    }
    psuh(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    return query(v * 2 + 1, tl, tm, l, min(tm, r)) + query(v * 2 + 2, tm + 1, tr, max(l, tm + 1), r);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    

    return 0;
}