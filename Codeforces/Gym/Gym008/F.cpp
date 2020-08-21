#include <bits/stdc++.h>


#define xx first.first
#define yy first.second
#define zz second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int INF = 1e9;
const int N = 1e3 + 10, M = 10, MX = 86400;

typedef pair<pii, int> sched;

int n;
vector<sched> stage[M + 2];
vector<sched> startat[MX + 10]; // akhir, val, panggung

sched cons(int a, int b, int c){ return mp(mp(a, b), c); }

int dp[MX + 10][(1 << M)];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        int len;
        cin >> len;
        for (int j=0;j<len;j++){
            int a, b, w;
            cin >> a >> b >> w;
            stage[i].pb(cons(a, b, w));
            startat[a].pb(cons(b, w, i));
        }
    }
    for (int i=1;i<=MX;i++){
        dp[i][0] = 0;
        for (int j=1;j<(1 << M);j++){
            dp[i][j] = -INF;
        }
    }
    int ans = -1;
    for (int i=1;i<=MX;i++){
        for (int j=0;j<(1 << M);j++){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            for (sched x : startat[i]){
                int id1 = x.xx;
                int id2 = (j | (1 << x.zz));
                dp[id1][id2] = max(dp[id1][id2], dp[i][j] + x.yy);
                if (id2 == (1 << n) - 1){
                    ans = max(ans, dp[id1][id2]);
                }
            }
        }
    }
    cout << ans << el;

    return 0;
}