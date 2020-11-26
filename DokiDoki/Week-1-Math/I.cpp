#pragma gcc optimize ("O3")
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

const int N = 1e6 + 10;

vector<int> prime[N * 10];

// Find the number of 1..m that is coprime with x
int coprime(int x, int m) {
    ll ret = 0; int len = prime[x].size();  
    for (int i = 0; i < (1 << len); i++) {
        ll num = 1;
        for (int j = 0; j < len; j++) {
            if (i & (1 << j)) {
                num *= (ll)prime[x][j];
            }
        }
        int bit = __builtin_popcount(i);
        int curval = ((ll)m) / num;
        if (bit & 1) curval *= -1;
        ret += curval;
    }
    return (int)ret;
}
ll solve(int n){
    vector<int> fac;
    fac.pb(n);
    for (auto x : prime[n]){
        int len = fac.size();
        int cnt = 0;
        int temp = n;
        while (temp % x == 0){
            temp /= x;
            cnt++;
        }
        int cur = 1;
        for (int i=0;i<cnt;i++){
            cur *= x;
            for (int j=0;j<len;j++){
                fac.pb(fac[j] / cur);
            }
        }
    }
    ll ret = 0;
    for (auto x : fac){
        int temp = n / x;
        ret += coprime(temp, temp) * temp;
    }
    return ret;
}

int q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=2;i * i<N;i++){
        if (!prime[i].empty()) continue;
        for (int j=i;j<N;j+=i){
            prime[j].pb(i);
        }
    }

    cin >> q;
    while (q--){
        int n;
        cin >> n;
        cout << solve(n) << el;
    }

    return 0;
}