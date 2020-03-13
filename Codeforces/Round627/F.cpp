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

const int N = 2e5 + 10;

int n;
int color[N];
vector <int> adl[N];
int ans[N];

void dfs(int node, int p){
    if (color[node]) ans[node]++;
    else ans[node]--;
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs(x, node);
        if (ans[x] > 0) ans[node] += ans[x];
    }
}

void dfs2(int node, int p){
    if (node != p){
        int plus = 0;
        if (ans[p] > 0){
            if (ans[node] > 0){
                plus = ans[p] - ans[node];
            } else{
                plus = ans[p];
            }
        }   
        ans[node] += max(plus, 0);
    }
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs2(x, node);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> color[i];
    }
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }

    dfs(1, 1);
    dfs2(1, 1);
    for (int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << el;

    return 0;
}