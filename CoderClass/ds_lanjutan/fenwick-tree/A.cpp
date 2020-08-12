#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 100;

int n, m;
ll ar[N];
ll bit[N];

void upd(int x, int val){
    int id = x;
    while (x < N){
        bit[x] += val - ar[id];
        x = x + (x & (-x));
    }
    ar[id] = val;
}
ll ask(int x){
    ll ret = 0;
    while (x > 0){
        ret += bit[x];
        x = x - (x & (-x));
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
    for (int i=1;i<=n;i++){
        ll a;
        cin >> a;
        upd(i, a);
    }
    while (m--){
        int tipe;
        cin >> tipe;
        if (tipe == 1){
            int pos;
            ll val;
            cin >> pos >> val;
            upd(pos, (ar[pos] ^ val));
        } else{
            int l, r;
            cin >> l >> r;
            cout << ask(l, r) << el;
        }
    }

    return 0;
}