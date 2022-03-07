#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;
const int MOD = 1e9 + 7;

int q;
int m, n;

ll dp[N][N]; // telur, piring

void solve(){
    cin >> m >> n;

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<N;i++){
        dp[0][i] = 1;
    }
    for (int i=1;i<N;i++){
        for (int j=i;j<N;j++){
            dp[i][j] = 
        }
    }

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}