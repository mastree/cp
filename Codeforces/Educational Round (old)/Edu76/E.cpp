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

const int N = 2e5 + 7;

int k[4], n;

vector <int> v[3];

vector <pii> mix;
int dp[N][2];

int ar[N][3];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<3;i++){
        cin >> k[i];
    }

    for (int i=0;i<3;i++){
        for (int j=0;j<k[i];j++){
            int a;
            n = max(n,a);
            cin >> a;
            v[i].pb(a);
            ar[a][i]=1;
        }

        sort(v[i].begin(), v[i].end());
    }

    for (auto x : v[1]){
        mix.pb(mp(x,0));
    }

    for (auto x : v[2]){
        mix.pb(mp(x,1));
    }

    sort(mix.begin(), mix.end());
    int len = mix.size();
    for (int i=len-1;i>=0;i--){
        dp[i][0]=dp[i+1][0];
        dp[i][1]=dp[i+1][1];

        if (mix[i].se){
            dp[i][0]++;
        } else{
            dp[i][1]++;
        }
    }

    for (int i=1;i<=n+1;i++){
        for (int j=0;j<3;j++){
            ar[i][j]+=ar[i-1][j];
        }
    }

    int ans=MOD;
    int bef=MOD;
    for (int i=n;i>=0;i--){
        int res=0;
        res+=k[0]-ar[i][0];
        
        int sisa1=k[1]-ar[i][1];
        int sisa2=k[2]-ar[i][2];
        int sisa=sisa1+sisa2;
        res+=ar[i][1]+ar[i][2];

        // int plus=MOD;
        // for (int j=0;j<=sisa;j++){
        //     plus=min(dp[len-j][1]+dp[len-sisa][0]-dp[len-j][0], plus);
        // }
        
        bef=min(dp[len-sisa][1], bef+mix[len-sisa].se); 

        // cout << res + plus << el;
        ans = min(ans, res+bef);
        // bef = plus;
        // binser luar(1)
        //int low1=0, high
    }

    cout << ans << el;

    return 0;
}