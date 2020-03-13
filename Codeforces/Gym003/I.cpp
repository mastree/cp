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

const int N = 107;

int t;
int n;
ll a[N], b[N], c[N];
ll dp[N][N][N]; // sampe mana, b ambil berapa, b udh berapa = nilai;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        
        // for (int i=0;i<=n;i++){
        //     for (int j=0;<=n;j++){
        //         for (int k=0;k<=n;k++){
        //             dp[i][j][k]=0;
        //         }
        //     }
        // }
        // for (int i=0;i<=n;i++) dp[0][i][0] = 0;
        for (int i=1;i<=n;i++){
            ll ambil = n - i;
            for (int j=0;j<=n;j++){
                for (int k=0;k<=j;k++){
                    ll ambilb = j - k;    
                    if (ambilb==0){
                        dp[i][j][k] = max(dp[i-1][j][k] + );
                    }  
                }
            }
        }
    }

    return 0;
}