#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 20;
const int MASK = (1 << 9);
const int MD = 50;
const int MXSISA = 3e3;

int q;
ll l, r;
int MOD[MASK];
int SISA;
int _nsisa[MXSISA][10];

set<int> amod;
vector<int> vmod;
vector<int> adj[MD];
int vlen;

ll lcm(ll a, ll b){
    ll ret = a * b / __gcd(a, b);
    return ret;
}

ll ans[MD][MXSISA];    
ll dp[N][MXSISA][2]; // pos, sisa, lower = count
ll solve(ll n){
    if (n <= 0) return 0;
    string s = to_string(n);
    ll ret = 0;
    int len = s.size();

    for (int id=0;id<vlen;id++){
        int mod = vmod[id];
        for (int i=0;i<=len;i++){
            for (int j=0;j<SISA;j++){
                for (int k=0;k<2;k++){
                    dp[i][j][k] = 0;
                }
            }
        }
        dp[0][0][0] = 1;
        for (int pos=0;pos<len;pos++){
            int dig = s[pos] - '0';
            int npos = pos + 1;
            for (int sisa=0;sisa<SISA;sisa++){
                // equal
                for (auto& ndig : adj[id]){
                    if (ndig >= dig) break;
                    dp[npos][_nsisa[sisa][ndig]][1] += dp[pos][sisa][0];
                }
                {
                    int ndig = dig;
                    if (ndig == 0 || mod % ndig == 0){
                        dp[npos][_nsisa[sisa][ndig]][0] += dp[pos][sisa][0];
                    }
                }
                // lower
                for (auto& ndig : adj[id]){
                    dp[npos][_nsisa[sisa][ndig]][1] += dp[pos][sisa][1];
                }
            }
        }
        for (int sisa=0;sisa<SISA;sisa++){
            ans[id][sisa] = 0;
            for (int low=0;low<2;low++){
                ans[id][sisa] += dp[len][sisa][low];
            }
        }
        ans[id][0]--;
    }
    for (int i=0;i<vlen;i++){
        for (int j=i + 1;j<vlen;j++){
            if (vmod[j] % vmod[i] == 0){
                for (int sisa=0;sisa<SISA;sisa++){
                    ans[j][sisa] -= ans[i][sisa];
                }
            }
        }
        for (int sisa=0;sisa<SISA;sisa++){
            if (sisa % vmod[i] == 0){
                ret += ans[i][sisa];
            }
        }
    }
    return ret;
}

void solve(){
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << '\n';
}

int main(){
    for (int i=0;i<MASK;i++){
        MOD[i] = 1;
        for (int j=0;j<9;j++){
            if (i & (1 << j)){
                MOD[i] = lcm((ll)MOD[i], (ll)j + 1);
            }
        }
        amod.insert(MOD[i]);
    }
    SISA = MOD[MASK - 1];
    for (auto& x : amod) vmod.push_back(x);
    vlen = vmod.size();

    for (int i=0;i<vlen;i++){
        for (int j=0;j<=9;j++){
            if (j == 0 || vmod[i] % j == 0) adj[i].push_back(j);
        }
    }
    for (int i=0;i<MXSISA;i++){
        for (int j=0;j<10;j++){
            _nsisa[i][j] = (i * 10 + j) % SISA; 
        }
    }

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}