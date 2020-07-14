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
int color[N];
vector<int> ans[2];

void dfs(int node, int col){
    color[node] = col;
    for (int x : adl[node]){
        if (color[x]){
            if (color[x] == color[node]){
                cout << -1 << el;
                exit(0);
            }
        } else{
            dfs(x, col % 2 + 1);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    for (int i=1;i<=n;i++){ if (color[i] == 0) dfs(i, 1); }
    for (int i=1;i<=n;i++){
        ans[color[i] - 1].pb(i);
    }
    for (int i=0;i<2;i++){
        cout << ans[i].size() << el;
        for (int x : ans[i]) cout << x << " "; cout << el; 
    }

    return 0;
}