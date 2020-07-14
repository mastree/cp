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

const int N = 2e3 + 10;

int n, x, y;
int ans;

int dp[N];

vector <int> adl[N];

bool vis[N];
void bfs(int awal){
    fill(vis, vis + n + 2, 0);
    queue <pair<int, int>> qu; // node, dist
    
    qu.push(mp(awal, 0));

    while (!qu.empty()){
        auto fr = qu.front();
        qu.pop();
        if (vis[fr.fi]) continue;
        // cout << fr.fi << " " << fr.se << el;
        dp[fr.se]++;
        vis[fr.fi] = 1;

        // cout << "tetangga => ";
        for (auto x : adl[fr.fi]){
            if (vis[x]) continue;
            // cout << x << " ";
            qu.push(mp(x, fr.se + 1));
        }
        // cout << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> y;
    for (int i=1;i<n;i++){
        adl[i].pb(i + 1);
        adl[i + 1].pb(i);
    }
    adl[x].pb(y);
    adl[y].pb(x);

    for (int i=1;i<=n;i++){
        bfs(i);
    }
    for (int i=1;i<n;i++){
        cout << dp[i] / 2 << el;
    }

    return 0;
}