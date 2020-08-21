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
vector <int> adl[N];
map <pii, bool> cek;
int dp[N];

void dfs(int node, int p){
    for (auto ch : adl[node]){
        if (ch == p) continue;
        dfs(ch, node);
        dp[node] += dp[ch] + cek[mp(ch, node)];
    }
}

void dfsb(int node, int p){
    if (node != 1){
        int temp = dp[p] - dp[node] - cek[mp(node, p)];
        dp[node] += temp + cek[mp(p, node)];
    }
    for (auto ch : adl[node]){
        if (ch == p) continue;
        dfsb(ch, node);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
        cek[mp(a, b)] = 1;
    }

    dfs(1, 1);
    dfsb(1, 1);
    int ans = MOD;
    for (int i=1;i<=n;i++){
        ans = min(ans, dp[i]);
    }
    cout << ans << el;
    for (int i=1;i<=n;i++){
        if (dp[i] == ans){
            cout << i << " ";
        }
    }
    cout << el;

    return 0;
}