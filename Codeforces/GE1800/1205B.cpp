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

int n;
ll ar[N];

vector <int> adl[N];

int cnt[N];
int ans = MOD;

int vis[N];
void bfs_loop(int node){
    queue <pii> qu;
    qu.push(mp(node, node));
    while (!qu.empty()){
        auto x = qu.front();
        qu.pop();
        if (vis[x.fi]){
            ans = min(ans, vis[x.fi] + vis[x.se] - 1);
            continue;
        }
        vis[x.fi] = vis[x.se] + 1;

        for (auto dest : adl[x.fi]){
            if (dest == x.se) continue;
            qu.push(mp(dest, x.fi));
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    // int nn = n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        if (ar[i] == 0){
            n--;
            i--;
            continue;
        }
        for (ll j=0;j<61;j++){
            ll bit = (1LL << j);
            if (ar[i] & bit){
                cnt[j]++;
            }
        }
    }

    for (int i=0;i<61;i++){
        if (cnt[i] > 2){
            cout << 3 << el;
            return 0;
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i == j) continue;
            if (ar[i] & ar[j]){
                adl[i].pb(j);
            }
        }
    }
    for (int i=1;i<=n;i++){
        fill(vis, vis + n + 1, 0);
        bfs_loop(i);
    }
    if (ans != MOD) cout << ans << el;
    else cout << -1 << el;

    return 0;
}