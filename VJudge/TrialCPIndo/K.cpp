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
bool cat[N];
vector<int> adl[N];
int ans;

void dfs(int node, int p, int mx, int cur){
    mx = max(mx, cur);
    if (adl[node].size() == 1 && node != p && mx <= m){
        ans++;
    }
    for (int x : adl[node]){
        if (x == p) continue;
        if (cat[x]){
            dfs(x, node, mx, cur + 1);
        } else{
            dfs(x, node, mx, 0);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> cat[i];
    }
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    dfs(1, 1, 0, cat[1]);
    cout << ans << el;

    return 0;
}