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
using ld = long double;

const int N = 8e3 + 10;

int q;
int n;
ld p, pr;

ld dp[2][N]; // sisa, next_eliminated -> expectation

void init(){
    for (int i=0;i<2;i++){
        for (int j=0;j<=n;j++){
            dp[i][j] = (ld)0;
        }
    }
}

void solve(){
    cin >> n >> p;
    pr = ((ld)1 - p);
    init();

    dp[1][1] = (ld)(n - 1);
    dp[1][2] = (ld)(n - 1);
    for (int i=3;i<=n;i++){
        for (int j=1;j<=i - 1;j++){
            dp[0][j] = dp[1][j];
        }
        for (int j=0;j<N;j++){
            dp[1][j] = (ld)0;
        }
        for (int j=1;j<=i;j++){
            {
                ld temp = ((ld)2) / ((ld)i);
                ld lose = temp * ((ld)(i - j)) / ((ld)(i - 1));
                ld win = temp * ((ld)(j - 1)) / ((ld)(i - 1));

                dp[1][j] += lose * p * ((ld)(n - i + 1));
                if (j < i) dp[1][j] += lose * pr * dp[0][j];
                dp[1][j] += win * pr * ((ld)(n - i + 1));
                if (j > 1) dp[1][j] += win * p * dp[0][j - 1];
            }
            // bawah-bawah
            if (j > 2){
                ld temp = ((ld)((j - 1))) / ((ld)i);
                temp *= ((ld)(j - 2)) / ((ld)(i - 1));
                dp[1][j] += temp * dp[0][j - 1];
            }
            // atas-atas
            if (i - j >= 2){
                ld temp = ((ld)((i - j))) / ((ld)i);
                temp *= ((ld)(i - j - 1)) / ((ld)(i - 1));
                dp[1][j] += temp * dp[0][j];
            }
            // bawah-atas
            if (j > 1 && i - j >= 1){
                ld temp = ((ld)(2 * (j - 1))) / ((ld)i);
                temp *= ((ld)(i - j)) / ((ld)(i - 1));
                dp[1][j] += temp * p * dp[0][j - 1] + temp * pr * dp[0][j];
            }
        }
    }
    for (int i=1;i<=n;i++){
        cout << dp[1][i] << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("elimination_input.txt", "r", stdin);
    freopen("B.out", "w", stdout);

    cout << fixed << setprecision(11);
    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ":\n";
        solve();
    }

    return 0;
}