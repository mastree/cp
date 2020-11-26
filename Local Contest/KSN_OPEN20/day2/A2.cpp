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

const int N = 2e5 + 10;
const int MK = (1 << 20);
const int INF = 1e9;
const int K = 20;

int n, k;

vector<int> anode;

vector<int> isi[MK];
int bitCnt[MK];
int dp[MK];

bool mat[K][K];
bool bisa[MK][K];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<MK;i++){
        bitCnt[i] = __builtin_popcount(i);
    }
    cin >> n >> k;
    for (int i=0;i<(1 << k);i++){
        if (bitCnt[i] == 4){
            anode.pb(i);
            dp[i] = -INF;
            for (int j=0;j<k;j++){
                if (i & (1 << j)){
                    isi[i].pb(j);
                }
            }
        }
    }
    int aw = 0;
    for (int i=0;i<4;i++){
        int a;
        cin >> a;
        a--;
        aw += (1 << a);
    }
    vector<int> unode;
    dp[aw] = 0;
    unode.pb(aw);
    for (int i=0;i<k;i++){
        string s;
        cin >> s;
        for (int j=0;j<k;j++){
            mat[i][j] = (s[j] == '1');
        }
    }
    for (auto x : anode){
        for (auto y : isi[x]){
            for (int i=0;i<k;i++){
                if (mat[y][i]){
                    bisa[x][i] = 1;
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        int tipe;
        cin >> tipe;
        if (tipe == 1){
            int pp;
            cin >> pp;
            pp--;
            for (auto x : unode){
                dp[x] += bisa[x][pp];
            }
        } else{
            vector<pii> ub;
            for (auto x : unode){
                for (int j=0;j<k;j++){
                    if (x & (1 << j)) continue;
                    for (auto y : isi[x]){
                        ub.pb(mp((x - (1 << y)) + (1 << j), dp[x]));
                    }
                }
            }
            for (auto x : ub){
                if (dp[x.fi] == -INF) unode.pb(x.fi);
                dp[x.fi] = max(dp[x.fi], x.se);
            }
        }
    }
    int mx = -INF;
    for (auto x : anode){
        mx = max(mx, dp[x]);
    }
    cout << mx << el;

    return 0;
}