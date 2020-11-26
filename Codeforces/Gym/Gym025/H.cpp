#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using plii = pair<ll, pii>;

plii mp3(ll a, int b, int c){
    return mp(a, mp(b, c));
}

const int N = 1e5 + 10;
const ll INF = 1e18;

int n, m, s, t;
vector<pil> adj[N]; // reverse
int in[N];

// turn1: lari-lari, turn2: nyampe
ll dp[N][2];

void dijkstra(){
    for (int i=0;i<n;i++){
        dp[i][0] = 0;
        dp[i][1] = INF;
    }
    set<pli> setdah, setdah2;
    dp[t][0] = 0;
    dp[t][1] = 0;
    setdah.insert(mp(dp[t][1], t));
    setdah2.insert(mp(dp[t][0], t));
    while (!setdah.empty() || !setdah2.empty()){
        if (!setdah2.empty()){
            auto tp = *setdah2.begin();
            setdah2.erase(tp);
            int node = tp.se;
            for (auto x : adj[node]){
                if (dp[x.fi][1] > dp[node][0] + x.se){
                    setdah.erase(mp(dp[x.fi][1], x.fi));
                    dp[x.fi][1] = dp[node][0] + x.se;
                    setdah.insert(mp(dp[x.fi][1], x.fi));
                }
            }   
        } else {
            auto tp = *setdah.begin();
            setdah.erase(tp);
            int node = tp.se;
            for (auto x : adj[node]){
                in[x.fi]--;
                if (dp[x.fi][0] < dp[node][1] + x.se){
                    dp[x.fi][0] = dp[node][1] + x.se;
                }
                if (in[x.fi] == 0) setdah2.insert(mp(dp[x.fi][0], x.fi));
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s >> t;
    if (s == t){
        cout << 0 << el;
        return 0;
    }
    for (int i=1;i<=m;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[b].pb(mp(a, w));
        in[a]++;
    }
    dijkstra();
    if (dp[s][0] <= 0 || in[s] != 0){
        cout << "infinity" << el;
        return 0;
    }
    cout << dp[s][0] << el;

    return 0;
}