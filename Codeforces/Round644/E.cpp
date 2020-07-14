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

const int N = 100;

int q, n;
int ar[N][N];
bool vis[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=1;i<=n;i++){
            fill(vis[i], vis[i] + n + 2, 0);
            string s;
            cin >> s;
            for (int j=1;j<=n;j++){
                ar[i][j] = (s[j - 1] == '1');
            }
        }
        for (int ulang = 1;ulang <= n;ulang++){
            for (int i=1;i<=n;i++){
                vis[i][n + 1] = 1;
                for (int j=n;j>0;j--){
                    if (vis[i][j + 1] && ar[i][j]){
                        vis[i][j] = 1;
                    }
                }
            }
            for (int i=1;i<=n;i++){
                vis[n + 1][i] = 1;
                for (int j=n;j>0;j--){
                    if (vis[j + 1][i] && ar[j][i]){
                        vis[j][i] = 1;
                    }
                }
            }
        }
        bool bisa = 1;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (ar[i][j] && !vis[i][j]){
                    bisa = 0;
                }
            }
        }
        if (bisa){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}