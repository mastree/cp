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

const int N = 1e3 + 10;

int t;
int n, k;
vector <int> adl[N];
bool vis[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--){
        cin >> n >> k;

        for (int i=1;i<=n;i++){
            adl[i].clear();
            adl[i].shrink_to_fit();
        }

        for (int i=1;i<=n;i++){
            string s;
            cin >> s;

            // s = "*" + s;
            for (int j=-k;j<=k;j++){
                int id = i + j;
                if (id<1 || id>n) continue;
                if (s[id-1] == '1'){
                    adl[i].pb(id);
                }
            }
        }

        int ans = MOD;
        queue <pii> qu;
        fill(vis, vis + n + 2, 0);
        qu.push(mp(1, 0));

        while (!qu.empty()){
            auto now = qu.front();
            qu.pop();
            if (vis[now.fi]) continue;
            vis[now.fi] = 1;
            if (now.fi == n){
                ans = min(ans, now.se);
            }

            for (auto x : adl[now.fi]){
                if (!vis[x]){
                    qu.push(mp(x, now.se + 1));
                }
            }
        }

        if (ans != MOD)cout << ans << el;
        else cout << -1 << el;
    }

    return 0;
}