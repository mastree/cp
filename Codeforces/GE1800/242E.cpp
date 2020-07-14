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

const int N = 1e5 + 10;

int n, q;

int t[4 * N][21];
bool lazy[4 * N][21];

void push(int v, int range){
    for (int i=0;i<20;i++){
        if (lazy[v][i]){
            lazy[2 * v][i] ^= 1;
            lazy[2 * v + 1][i] ^= 1;
            t[2 * v][i] = ((range + 1) / 2) - t[2 * v][i];
            t[2 * v + 1][i] = (range / 2) - t[2 * v + 1][i];
            lazy[v][i] = 0;
        }
    }
}

void update(int v, int tl, int tr, int l, int r, int x){
    int range = tr - tl + 1;
    if (l > r) return;
    else if (tl == l && r == tr){
        for (int i=0;i<20;i++){
            if (x & (1 << i)){
                lazy[v][i] ^= 1;
                t[v][i] = range - t[v][i];
            }
        }
        return;
    }
    push(v, range);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(tm, r), x);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    for (int i=0;i<20;i++){
        t[v][i] = t[v * 2][i] + t[v * 2 + 1][i];
    }
}

ll query(int v, int tl, int tr, int l, int r){
    if (l > r) return 0;
    else if (l <= tl && tr <= r){
        ll temp = 0;
        for (int i=0;i<20;i++){
            temp += (ll)(1LL << i) * (ll)t[v][i];
        }
        return temp;
    }
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(tm, r)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        int temp;
        cin >> temp;
        update(1, 1, n, i, i, temp);
    }

    cin >> q;
    while (q--){
        int tipe;
        cin >> tipe;
        if (tipe == 1){
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << el; 
        } else{
            int l, r, x;
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        }
    }

    return 0;
}