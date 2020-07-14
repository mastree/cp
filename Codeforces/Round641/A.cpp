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

int n;
ll ar[N];
ll t[4 * N];

void build(int v, int tl, int tr){
    if (tl == tr){
        t[v] = ar[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = __gcd(t[v * 2], t[v * 2 + 1]);
}

ll query(int v, int tl, int tr, int l, int r){
    if (l > r) return 0;
    else if (l <= tl && tr <= r){
        return t[v];
    } else if (tr < l || tl > r) return 0;
    int tm = (tl + tr) / 2;
    ll temp1 = query(v * 2, tl, tm, l, min(tm, r));
    ll temp2 = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    if (temp1 == 0) return temp2;
    if (temp2 == 0) return temp1;
    return __gcd(temp1, temp2);
}

ll flcm(ll a, ll b){
    return a * b / __gcd(a, b);
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
    ll ans = 0;
    for (int i=1;i<=n;i++){
        if (i == 1){
            ans = flcm(query(1, 1, n, 2, n), ar[i]);
        } else{
            if (i == n){
                ans = __gcd(ans, flcm(query(1, 1, n, 1, n - 1), ar[i]));
            } else{
                ans = __gcd(ans, flcm(__gcd(query(1, 1, n, 1, i - 1), query(1, 1, n, i + 1, n)), ar[i]));
            }
        }
    }
    cout << ans << el;

    return 0;
}