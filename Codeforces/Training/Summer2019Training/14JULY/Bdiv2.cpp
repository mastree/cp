#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    while (q--){
        int n,m;
        cin >> n >> m;

        string s[n+1];
        int dp[n+1][m+1];
        for (int i=0;i<=m;i++) dp[0][i]=0;
        for (int i=1;i<=n;i++){
            string str;
            cin >> str;
            s[i]=".";
            s[i]+=str;
            dp[i][0]=0;
        }

        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
                if (s[i][j]=='*') dp[i][j]++;
            }
        }

        int mn=MOD;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                int tm=0;
                tm+=(n-dp[i][m]+dp[i-1][m]);
                tm+=(m-dp[n][j]+dp[n][j-1]);
                if (s[i][j]=='.') tm--;

                mn=min(mn,tm);
            }
        }

        cout << mn << el;
    }

    return 0;
}