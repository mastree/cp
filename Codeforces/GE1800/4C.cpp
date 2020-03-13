#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e3 + 10;

double dp[N][N];//[2][2]; // turn ke berapa, sisa-w, terakhir 
// 0 putih, 1 hitam
int w, b;
int tot;
double ans = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> b;
    tot = w + b;
    dp[0][w] = 1.0;
    for (int i=0;i<=(tot+2)/3;i++){
        for (int j=1;j<=w;j++){
            double putih = j;
            double sisa = (double)(w + b - 3 * i);
            double hitam = sisa - putih;
            if (sisa == 0) continue;
            ans += dp[i][j] * putih / sisa;
            if (sisa >= 3){
                double temp;
                temp = dp[i][j] * hitam * (hitam - 1) * (hitam - 2) / (sisa * (sisa - 1) * (sisa - 2));
                dp[i+1][j] += temp;
                temp  = dp[i][j] * hitam * (hitam - 1) * (putih) / (sisa * (sisa - 1) * (sisa - 2));
                dp[i+1][j-1] += temp;
            }
        }
    }

    cout << fixed << setprecision(10) << ans << el;

    return 0;
}