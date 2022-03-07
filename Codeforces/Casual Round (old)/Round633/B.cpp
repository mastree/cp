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
const int INF = 1e8;

int n;
vector <int> adl[N];
int dp[N];

int ans = 1;

void dfs_dp(int node, int p){
    if ((int) adl[node].size() == 1 && node != p){
        dp[node] = 0;
        return;
    }
    int cod = 0, cev = 0;
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs_dp(x, node);
        if (dp[x]){
            cod++;
        } else{
            cev++;
        }
    }
    if (cod && cev){
        ans = 3;
        dp[node] = 1;
    } else if (cod){
        dp[node] = 0;
    } else{
        dp[node] = 1;
    }
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
    int mn_ans = -INF;
    int mx_ans = n - 1;

    int temp = 0;
    for (int i=1;i<=n;i++){
        int cur = 0;
        for (auto x : adl[i]){
            if (adl[x].size() == 1) cur++;
        }
        temp += max(cur - 1, 0);
    }

    dfs_dp(1, 1);
    mn_ans = ans;
    mx_ans = n - 1 - temp;
    cout << mn_ans << " " << mx_ans << el;

    return 0;
}