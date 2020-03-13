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

const int N = 1e3 + 7, K = 5;

int n, k;
int ar[K][N];
vector <int> adl[N];
int floyd[N][N];

int ans = 0;
int dp[N];
int dfs(int node){
    if (dp[node]!=-1){
        return dp[node];
    }
    int mx = 0;
    for (auto x : adl[node]){
        mx = max(mx, dfs(x));
    }

    return dp[node] = mx + 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=0;i<k;i++){
        for (int j=1;j<=n;j++){
            int a;
            cin >> a;
            ar[i][a]=j;
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i==j) continue;
            bool ada = 1;
            for (int id=0;id<k;id++){
                if (ar[id][i] > ar[id][j]){
                    ada=0;
                }
            }
            if (ada){
                adl[i].pb(j);
            }
        }
    }

    // for (int i=1;i<=n;i++){
    //     for (auto x : adl[i]) cout << x << " ";
    //     cout << el;
    // }cout << el;

    for (int i=1;i<=n;i++){
        for (int j=0;j<=n;j++){
            dp[j] = -1;
        }
        ans = max(ans, dfs(i));
        // cout << i << " => " << el;
        // for (int j=1;j<=n;j++){
        //     cout << dp[j] << " ";
        // } cout << el;
    }
    cout << ans << el;

    return 0;
}