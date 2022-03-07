#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>

#define el '\n'
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1e6 + 10;
const int INF = 1e9 + 10;

int q;
int n;

void solve(){
    cin >> n;
    vector<int> fac;
    for (int i=1;i<=13;i++){
        if (n % i == 0){
            fac.pb(i);
        }
    }
    int len = fac.size();
    vector<int> ans = {INF};
    for (int mask=0;mask<(1 << len);mask++){
        vector<int> take;
        int tot = 0;
        for (int i=0;i<len;i++){
            if (mask & (1 << i)){
                take.pb(fac[i]);
                tot += fac[i];
            }
        }
        if (tot == 13){
            ans = min(ans, take);
        }
    }
    if (ans[0] == INF){
        cout << -1 << el;
    } else{
        for (auto& x : ans) cout << x << ' ';
        cout << el;
    }
}

int main(){
    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}