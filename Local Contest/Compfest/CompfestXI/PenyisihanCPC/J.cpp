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

const int N = 2010;
const ll MOD = 1e9 + 7;

int n, m;
int ar[N];
int plet[N];
int mx[N][N];

ll dp[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=m;i++){
        cin >> plet[i];
    }
    for (int i=1;i<=n;i++){
        mx[i][i] = ar[i];
        for (int j=i + 1;j<=n;j++){
            mx[i][j] = max(mx[i][j - 1], ar[j]);
        }
    }
    dp[0][0] = 1;
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            dp[i-1][j] = (dp[i-1][j] + dp[i-1][j - 1]) % MOD;
        }
        for (int j=1;j<=n;j++){
            if (mx[j][j] > plet[i]) continue;
            int k = plet[i];
            int l, r;
            int low = 1, high = j;
            while (low < high){
                int mid = (low + high + 1) / 2;
                if (mx[mid][j] < k){
                    high = mid - 1;
                } else{
                    low = mid;
                }
            }
            r = low;
            low = 1;
            high = j;
            while (low < high){
                int mid = (low + high) / 2;
                if (mx[mid][j] > k){
                    low = mid + 1;
                } else{
                    high = mid;
                }
            }
            l = high;
            if (mx[r][j] != k || mx[l][j] != k) continue;
            dp[i][j] = (dp[i - 1][r - 1] - dp[i - 1][l - 2] + MOD) % MOD;
        }
    }
    cout << dp[m][n] << el;

    return 0;
}