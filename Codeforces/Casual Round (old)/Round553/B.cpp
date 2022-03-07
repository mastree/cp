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

const int N = 520;
const int M = 1024;

int n, m;
int ar[N][N];
pii dp[N][2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    bool bisa = 0;
    int curxor = 0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> ar[i][j];
        }
        curxor ^= ar[i][1];
    }
    // for (int k=0;k<11;k++){
    //     for (int i=1;i<=n;i++){
    //         fill(dp[i], dp[i] + m + 2, mp(0, 0));
    //     }
    //     int bit = (1 << k);
    //     for (int i=1;i<=n;i++){
    //         for (int j=1;j<=m;j++){
    //             bool nyala = (ar[i][j] & bit);
    //             if (i == 1){
    //                 dp[i][nyala] = mp(j, 0);
    //                 continue;
    //             } 
    //             if (nyala){
    //                 if (dp[i - 1][0].fi){
    //                     dp[i][1] = mp(j, 0);
    //                 } 
    //                 if (dp[i - 1][1].fi){
    //                     dp[i][0] = mp(j, 1);
    //                 }
    //             } else{
    //                 if (dp[i - 1][0].fi){
    //                     dp[i][0] = mp(j, 0);
    //                 } 
    //                 if (dp[i - 1][1].fi){
    //                     dp[i][1] = mp(j, 1);
    //                 }
    //             }
    //         }
    //     }
    //     if (dp[n][1].fi){
    //         bool stat = 1;
    //         cout << "TAK" << el;
    //         vector<int> ans;
    //         for (int i=n;i>=1;i--){
    //             ans.pb(dp[i][stat].fi);
    //             // cout << dp[i][stat].fi << " ";
    //             stat = dp[i][stat].se;
    //         }
    //         reverse(ans.begin(), ans.end());
    //         for (auto x : ans){
    //             cout << x << " ";
    //         }
    //         cout << el;
    //         return 0;
    //     }
    // }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int cur = curxor ^ ar[i][1];
            cur ^= ar[i][j];
            if (cur){
                cout << "TAK" << el;
                for (int id=1;id<=n;id++){
                    if (id == i) cout << j << " ";
                    else cout << 1 << " ";
                }
                cout << el;
                return 0;
            }
        }
    }
    cout << "NIE" << el;

    return 0;
}