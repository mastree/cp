//pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
    
    
#define fi first
#define se second
#define pb push_back
#define mp make_pair
// #define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'
    
using namespace std;
    
const int N = 2e5 + 10;
const ll MOD = 1e9 + 7;
const int BORD = 1e6 + 10;
    
int n;
int ar[N];
ll cnt[BORD + 2];
ll kurang[BORD + 2];
// vector<int> ter[N];
ll fac[N];
    
ll fpow(ll a, ll b){
    if (b == 0) return 1;
    ll temp = fpow(a, b / 2);
    temp = temp * temp % MOD;
    if (b & 1) temp = temp * a % MOD;
    return temp;
}
    
ll inv(ll a){
    return fpow(a, MOD - 2);
}
    
ll comb(ll a, ll b){
    return fac[a] * inv(fac[a - b] * fac[b] % MOD) % MOD;
}
    
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    fac[0] = 1;
    for (ll i=1;i<N;i++){
        fac[i] = fac[i - 1] * i % MOD;
    }
    
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        cnt[ar[i]]++;
        int bef = 0;
        for (int j=2;j * j<=ar[i];j++){
            if (ar[i] % j == 0){
                int k = ar[i] / j;
                cnt[j]++;
                if (k != j) cnt[k]++;
            }
        }
    }
    // cout << fac[0] << " " << fac[1] << " " << fac[2] << el;return 0;
    ll ans = 0;
    for (int i=2;i<BORD;i++){
        if (cnt[i] == 0) continue;
        ll gg = i - kurang[i];
        for (int j=i + i;j<BORD;j+=i){
            kurang[j] += (ll)gg;
        }
        ll temp;
        temp = (((fpow(2, cnt[i]) - 2) * cnt[i] % MOD) * inv(2) % MOD + cnt[i]) % MOD;
        ans = (ans + temp * gg % MOD + MOD) % MOD;
    }
    cout << ans << el;
    
    return 0;
}