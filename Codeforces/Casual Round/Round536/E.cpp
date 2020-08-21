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

const int N = 1e5 + 10;
const int M = 210;
const ll INF = 1e18;

int n, m, k;
int s[N], t[N], d[N];
ll w[N];

vector<pair<pli, int>> mulai[N], selesai[N];
pli ar[N];
bool udah[N];

ll dp[N][M];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1;i<=k;i++){
        cin >> s[i] >> t[i] >> d[i] >> w[i];
        mulai[s[i]].pb(mp(mp(w[i], d[i]), i));
        selesai[t[i]].pb(mp(mp(w[i], d[i]), i));
    }
    priority_queue<pair<pli, int>> pq;
    for (int i=1;i<=n;i++){
        for (auto x : mulai[i]){
            pq.push(x);
        }
        while (!pq.empty() && udah[pq.top().se]) pq.pop();
        pair<pli, int> temp = mp(mp(0, i), 0);
        if (!pq.empty()) temp = pq.top();
        // ar[i] = mp(temp.fi.fi, temp.fi.se + 1);
        ar[i] = temp.fi;
        for (auto x : selesai[i]){
            udah[x.se] = 1;
        }
    }
    // for (int i=1;i<=n;i++){
    //     cout << i << ". " << ar[i].fi << " " << ar[i].se << el;
    // }
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=m;j++){
            ll cur = dp[i - 1][j];
            if (j != 0){
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
            dp[ar[i].se][j] = min(dp[ar[i].se][j], cur + ar[i].fi);
        }
    }
    ll ans = INF;
    for (int i=0;i<=m;i++){
        ans = min(ans, dp[n][i]);
    }
    cout << ans << el;

    return 0;
}