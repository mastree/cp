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

int n, q;
int tin[N], tout[N];
int up[19][N];
vector <int> adl[N];
int timer;
int depth;
int dep[N];

void dfs(int node, int p){
    tin[node] = timer++;
    up[0][node] = p;
    dep[node] = depth;
    for (int i=1;i<19;i++){
        up[i][node] = up[i-1][up[i-1][node]];
    }

    for (auto dest : adl[node]){
        if (dest == p)continue;
        depth++;
        dfs(dest, node);
        depth--;
    }
    tout[node] = timer++;
}

bool is_ancestor(int a, int b){
    return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

int lca(int a, int b){
    if (is_ancestor(a, b)) return a;
    if (is_ancestor(b, a)) return b;
    for (int i=18;i>=0;i--){
        if (!is_ancestor(up[i][a], b)) a = up[i][a];
    }
    return up[0][a];
}

int jarak(int a, int b){
    int c = lca(a, b);
    return dep[a] + dep[b] - 2 * dep[c];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }

    dfs(1, 1);
    cin >> q;
    while (q--){
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        vector<int> ans;

        ans.pb(jarak(a, b));
        ans.pb(jarak(a, x) + 1 + jarak(y, b));
        ans.pb(jarak(b, x) + 1 + jarak(y, a));
        bool bisa = 0;
        for (auto x : ans){
            if (x <= k && (x&1) == (k&1)){
                bisa = 1;
                break;
            }
        }
        if (bisa){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}