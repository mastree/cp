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
const ll INF = 1e18 + 10;

ll A[N], B[N];
pair<int, ll> le[N], ri[N]; // jarak max, sisa koin
int n, p; // n, pangkat
ll k, c; // uang, cost jarak

ll t1[4 * N];
void build1(int v, int tl, int tr){
    if (tl == tr){
        t1[v] = c * tl - B[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build1(v * 2, tl, tm);
    build1(v * 2 + 1, tm + 1, tr);
    t1[v] = max(t1[v * 2], t1[v * 2 + 1]);
}
ll ask1(int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return -INF;
    if (l <= tl && tr <= r) return t1[v];
    int tm = (tl + tr) / 2;
    return max(ask1(v * 2, tl, tm, l, r), ask1(v * 2 + 1, tm + 1, tr, l, r));
}
ll t1min[4 * N];
void build1min(int v, int tl, int tr){
    if (tl == tr){
        t1min[v] = B[tl] + c * tl;
        return;
    }
    int tm = (tl + tr) / 2;
    build1min(v * 2, tl, tm);
    build1min(v * 2 + 1, tm + 1, tr);
    t1min[v] = min(t1min[v * 2], t1min[v * 2 + 1]);
}
ll ask1min(int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return INF;
    if (l <= tl && tr <= r) return t1min[v];
    int tm = (tl + tr) / 2;
    return min(ask1min(v * 2, tl, tm, l, r), ask1min(v * 2 + 1, tm + 1, tr, l, r));
}

// ll t2[4 * N];


void solve1(){
    build1(1, 1, n);
    build1min(1, 1, n);
    // le
    for (int i=1;i<=n;i++){
        ll base = A[i] + c * i;
        int l = 1, r = i, best = 0;
        ll vbest = k;
        while (l <= r){
            int m = (l + r) / 2;
            ll tot = base - ask1(1, 1, n, 1, m);
            if (tot <= k){
                r = m - 1;
                best = m;
                vbest = k - tot;
            } else{
                l = m + 1;
            }
        }
        le[i] = mp(i - best + 1, vbest);
    }

    // ri 
    for (int i=n;i>=1;i--){
        ll base = c * i - A[i];
        int l = i, r = n, best = 0;
        ll vbest = k;
        while (l <= r){
            int m = (l + r) /2;
            ll tot = ask1min(1, 1, n, m, n) - base;
            if (tot <= k){
                l = m + 1;
                best = m;
                vbest = k - tot;
            } else{
                r = m - 1;
            }
        }
        ri[i] = mp(best - i + 1, vbest);
    }

    for (int i=1;i<=n;i++){
        auto ans = max(le[i], ri[i]);
        cout << ans.fi << " " << ans.se << el;
    }
}

void solve2(){

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> c >> p;
    for (int i=1;i<=n;i++){
        cin >> A[i];
    }
    for (int i=1;i<=n;i++){
        cin >> B[i];
    }

    if (p == 1) solve1();
    else solve2();
    

    return 0;
}