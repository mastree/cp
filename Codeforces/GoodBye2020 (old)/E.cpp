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

const int N = 5e5 + 10;
const ll MOD = 1e9 + 7;
const int DIG = 60;

int q;
int n;
ll ar[N];

void solve(){
    cin >> n;
    vector<int> alldig(DIG, 0);
    ll ans = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        for (int j=0;j<DIG;j++){
            alldig[j] += ((ar[i] & (1LL << j)) > 0);
        }
    }
    for (int i=1;i<=n;i++){
        ll dig1 = 0;
        for (int j=0;j<DIG;j++){
            if (ar[i] & (1LL << j)){
                dig1 = (dig1 + ((1LL << j) % MOD) * alldig[j] % MOD) % MOD;
            }
        }
        for (int k=0;k<DIG;k++){
            if (ar[i] & (1LL << k)){
                ans = (ans + dig1 * n) % MOD;
            } else{
                ans = (ans + dig1 * alldig[k]) % MOD;
            }
            dig1 = dig1 * 2 % MOD;
        }
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}