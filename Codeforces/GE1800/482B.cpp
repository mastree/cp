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

const int N = 1e5 + 7;
int n, m;
int ar[N], tony[N][30], dp[N][30];
int cur[30];
pair<pii, int> query[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<m;i++){
        int l, r, q;
        cin >> l >> r >> q;
        query[i]=mp(mp(l, r), q);
        for (int j=0;j<30;j++){
            if (q&(1 << j)){
                tony[l][j]++;
                tony[r+1][j]--;
            }
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=0;j<30;j++){
            cur[j]+=tony[i][j];
            if (cur[j]>0){
                ar[i]+=(1 << j);
                dp[i][j]=dp[i-1][j] + 1;
            }
        }
    }

    bool bisa = 1;
    for (int i=0;i<m;i++){
        int l = query[i].fi.fi, r = query[i].fi.se, q = query[i].se;
        int cur = 0;
        for (int j=0;j<30;j++){
            if (dp[r][j] - dp[l-1][j] == r - l + 1){
                cur += (1 << j);
            }
        }
        if (cur!=q){
            bisa = 0;
        }
    }

    if (!bisa){
        cout << "NO" << el;
    } else{
        cout << "YES" << el;
        for (int i=1;i<=n;i++){
            cout << ar[i] << " ";
        }
        cout << el;
    }

    return 0;
}