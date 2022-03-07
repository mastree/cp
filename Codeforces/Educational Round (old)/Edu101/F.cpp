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

int n, k;
int ar[N];

struct Solver{
    int t[N * 4];
    int lazy[N * 4];
    int h;

    Solver(){}
    Solver(int hh) : h(hh) {
        update(1, 0, h, 0, 0, 1);
    }
    void push(int v, int range){
        if (lazy[v]){
            t[v * 2] += lazy[v] * ((range + 1) / 2);
            t[v * 2 + 1] += lazy[v] * (range / 2);
            lazy[v * 2] += lazy[v];
            lazy[v * 2 + 1] += lazy[v];
            lazy[v] = 0;
        }
    }
    void update(int v, int tl, int tr, int l, int r, int val){
        if (l > r || tr < l || r < tl) return;
        else if (tl <= l && r <= tr){
            t[v] += val * (tr - tl + 1);
            lazy[v] += val;
            return;
        }
        push(v, tr - tl + 1);
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, r, val);
        update(v * 2 + 1, tm + 1, tr, l, r, val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
    int ask(int v, int tl, int tr, int l, int r){
        if (l > r || tr < l || r < tl) return 0;
        else if (tl <= l && r <= tr){
            return t[v];
        }
        push(v, tr - tl + 1);
        int tm = (tl + tr) / 2;
        return ask(v * 2, tl, tm, l, r) + ask(v * 2 + 1, tm + 1, tr, l, r);
    }
    int get(){
        return t[1];
    }
};
bool bisa(int h){
    int cur = 1;
    Solver(h);
    while (cur < k){

    }
}
void solve(){
    int l = 1, r = N * 2;
    while (l < r){
        int m = (l + r) / 2;
        if (bisa(m)){
            r = m;
        } else{
            l = m + 1;
        }
    }
    if (r == N * 2){
        cout << -1 << el;
    } else{
        cout << r << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1, greater<int>());
    solve();

    return 0;
}