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
const ll INF = 1e9 + 10;

int n;
ll ar[N];
bool dig[N], goal[N];

ll ans;
vector<int> adl[N];
pair<ll, ll> cnt[N];


void dfs(int node, int p, ll mn){
    mn = min(mn, ar[node]);
    if (dig[node] != goal[node]){
        if (dig[node]) cnt[node].se++;
        else cnt[node].fi++;
    }
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs(x, node, mn);
        cnt[node].fi += cnt[x].fi;
        cnt[node].se += cnt[x].se;
    }
    if (mn == ar[node]){
        ll ubah = min(cnt[node].fi, cnt[node].se);
        ans += ar[node] * ubah * 2;
        cnt[node].fi -= ubah;
        cnt[node].se -= ubah;
    } 
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int c0 = 0, c1 = 0;
    for (int i=1;i<=n;i++){
        int b, c;
        cin >> ar[i] >> b >> c;
        dig[i] = b;
        goal[i] = c;
        if (dig[i]) c1++;
        else c0++;
        if (goal[i]) c1--;
        else c0--;
    }
    if (c0 || c1){
        cout << -1 << el;
        return 0;
    }
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    dfs(1, 1, INF);
    cout << ans << el;

    return 0;
}