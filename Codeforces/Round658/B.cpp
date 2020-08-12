#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 4e3 + 10;

int q;
int n;
int ar[N];
vector<int> stock;
bool dp[N][N]; // pos, len

void solve(){
    cin >> n;
    for (int i=1;i<=2 * n;i++){
        cin >> ar[i];
    }
    stock.clear();
    bool udh[2 * n + 2];
    fill(udh, udh + 2 * n + 2, 0);

    int last = 2 * n, cur = 0;
    for (int i=2 * n;i>=1;i--){
        cur++;
        udh[ar[i]] = 1;
        if (ar[i] == last){
            stock.pb(cur);
            cur = 0;
            while (udh[last]) last--;
        }
    }
    int len = stock.size();
    for (int i=0;i<=len;i++){
        for (int j=0;j<=n;j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i=1;i<=len;i++){
        int tam = stock[i - 1];
        for (int j=0;j<=n;j++){
            dp[i][j] |= dp[i - 1][j];
            if (j >= tam){
                dp[i][j] |= dp[i - 1][j - tam];
            }
        }
    }
    if (dp[len][n]){
        cout << "YES" << el;
    } else{
        cout << "NO" << el;
    }
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