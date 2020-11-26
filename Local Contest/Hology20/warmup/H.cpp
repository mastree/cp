#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 7e3 + 10;

int n;
ll ar[N], val[N], par[N];
unordered_map<ll, int> cnt;

bool bisa[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        cnt[ar[i]]++;
        par[i] = i;
    }
    for (int i=1;i<=n;i++){
        cin >> val[i];
        if (cnt[ar[i]] >= 2) bisa[i] = 1;
    }
    for (int i=1;i<=n;i++){
        if (par[i] != i || !bisa[i]) continue;
        for (int j=1;j<=n;j++){
            if (i == j) continue;
            ll gab = (ar[i] | ar[j]);
            if (par[j] == j && gab == ar[i]){
                par[j] = i;
                val[i] += val[j];
            }
        }
    }
    ll ans = 0;
    for (int i=1;i<=n;i++){
        if (par[i] == i && bisa[i]){
            ans += val[i];
        }
    }
    cout << ans << el;

    return 0;
}