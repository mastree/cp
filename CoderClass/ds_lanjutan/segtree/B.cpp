#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int n, q;
int ar[N];
int t[4 * N];

void build(int v, int tl, int tr){
    if (tl == tr){
        t[v] = ar[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}
int ask(int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return 0;
    else if (l <= tl && tr <= r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    build(1, 1, n);
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;

        if (ar[l] != ar[r]){
            cout << "TIDAK" << el;
            continue;
        }
        int temp = ask(1, 1, n, l + 1, r - 1);
        if (temp <= ar[l]) cout << "YA" << el;
        else cout << "TIDAK" << el;
    }

    return 0;
}