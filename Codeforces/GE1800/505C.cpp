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

const int N = 3e4+5, M = 505;
int n, m;
int dp[N][M];
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        ar[a]++;
    }

    int zero = 250;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            dp[i][j]=-1;
        }
    }
    dp[0][zero] = 0;
    int ans=0;
    for (int i=1;i<=N-2;i++){
        for (int j=0;j<M;j++){
            int delta=j-zero;
            if (m + delta <= 0) continue;
            int ja = m+delta-1, jb = m+delta, jc = m+delta+1;
            if (ja>=1){
                int id = i-ja;
                if (id>=0)
                    if (dp[id][zero + delta - 1]>-1 && zero + delta - 1>-1){
                        dp[i][j]=max(dp[i][j], dp[id][zero + delta - 1] + ar[i]);
                    } 
            }
            if (jb>=1){
                int id = i-jb;
                if (id>=0)
                    if (dp[id][zero + delta]>-1){
                        dp[i][j]=max(dp[i][j], dp[id][zero + delta] + ar[i]);
                    }
            }
            if (jc>=1){
                int id = i-jc;
                if (id>=0)
                    if (dp[id][zero + delta + 1]>-1){
                        dp[i][j]=max(dp[i][j], dp[id][zero + delta + 1] + ar[i]);
                    }
            }
            ans = max(ans, dp[i][j]);
        }
    }

    // for (int i=0;i<M;i++){
    //     ans = max(ans, dp[N-4][i]);
    // }
    cout << ans << el;

    return 0;
}