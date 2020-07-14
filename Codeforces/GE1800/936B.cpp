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

int n, m;
vector<int> adl[N];
vector<int> radl[N];
int mulai;
int in[N];
bool vis[N];
int par[N], color[N];

pii dp[N]; // node-kalah, node-menang;

bool dfs_cycle(int node, int p){
    par[node] = p;
    if (color[node] == 2) return 0;
    if (color[node] == 1) return 1;
    color[node] = 1;
    bool ret = 0;
    for (auto x : radl[node]){
        ret = ret || dfs_cycle(x, node);
    }
    color[node] = 2;
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        int len;
        cin >> len;
        dp[i] = mp(0, 0);
        for (int j=1;j<=len;j++){
            int dest;
            cin >> dest;
            adl[dest].pb(i);
            radl[i].pb(dest);
            in[i]++;
        }
    }
    cin >> mulai;
    queue<int> qu;
    for (int i=1;i<=n;i++){
        if (in[i] == 0){
            qu.push(i);
            dp[i] = mp(i, 0);
        }
    }
    while (!qu.empty()){
        int cur = qu.front();
        qu.pop();
        for (auto x : adl[cur]){
            bool ambil = 0;
            if (dp[cur].fi){
                if (!dp[x].se){
                    dp[x].se = cur;
                    ambil = 1;
                }
            } 
            if (dp[cur].se){
                if (!dp[x].fi){
                    dp[x].fi = cur;
                    ambil = 1;
                }
            }
            if (ambil) qu.push(x);
        }
    }
    bool seri = dfs_cycle(mulai, mulai);
    if (dp[mulai].se){
        cout << "Win" << el;
        int cur = mulai;
        bool stat = 1;
        while (1){
            cout << cur << " ";
            if (stat){
                if (cur == dp[cur].se) break;
                cur = dp[cur].se;
            } else{
                if (cur == dp[cur].fi) break;
                cur = dp[cur].fi;
            }
            stat = !stat;
        }
        cout << el;
    } else if (seri){
        cout << "Draw" << el;
    } else {
        cout << "Lose" << el;
    }

    return 0;
}