#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;
const int M = 2e4 + 10;
const int INF = 1e9 + 10;

int n, m;
vector<pii> adj[N];
vector<int> nadj[N];

int dp1[N], dp2[N], ndp[N];
int in[N];

bool qual[N];

void preproc(){
    fill(dp1, dp1 + n + 1, INF);
    set<pii> setdah;
    dp1[1] = 0;
    setdah.insert(mp(0, 1));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int node = tp.se;
        int cur = tp.fi;
        for (auto x : adj[node]){
            if (dp1[x.fi] > cur + x.se){
                setdah.erase(mp(dp1[x.fi], x.fi));
                dp1[x.fi] = cur + x.se;
                setdah.insert(mp(dp1[x.fi], x.fi));
            }
        }
    }
    fill(dp2, dp2 + n + 1, INF);
    dp2[n] = 0;
    setdah.insert(mp(0, n));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int node = tp.se;
        int cur = tp.fi;
        for (auto x : adj[node]){
            if (dp2[x.fi] > cur + x.se){
                setdah.erase(mp(dp2[x.fi], x.fi));
                dp2[x.fi] = cur + x.se;
                setdah.insert(mp(dp2[x.fi], x.fi));
            }
        }
    }
    for (int i=1;i<=n;i++){
        qual[i] = (dp1[i] + dp2[i] == dp1[n]);
    }
    for (int i=1;i<=n;i++){
        if (!qual[i]) continue;
        for (auto x : adj[i]){
            if (!qual[x.fi]) continue;
            if (dp1[i] < dp1[x.fi]){
                if (dp1[i] + dp2[x.fi] + x.se == dp1[n]){
                    nadj[i].pb(x.fi);
                    in[x.fi]++;
                }
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }
    preproc();

    int ans = 0;
    queue<int> qu;
    for (int i=1;i<=n;i++){
        if (qual[i] && in[i] == 0){
            qu.push(i);
        }
    }

    return 0;
}