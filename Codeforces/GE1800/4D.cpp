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

const int N = 5e3 + 5;

int n, w, h;
vector <pair<pii, int>> v;
int dp[N];
int par[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w >> h;
    v.pb(mp(mp(0, 0), 0));
    for (int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        if (a>w && b>h){
            v.pb(mp(mp(a, b), i));
        }
    }

    sort(v.begin(), v.end());
    // for (auto x : v){
    //     cout << x.fi.fi << " " << x.fi.se << el;
    // }
    int len = v.size();
    for (int i=1;i<len;i++){
        for (int j=0;j<i;j++){
            // dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if (v[i].fi.fi > v[j].fi.fi && v[i].fi.se > v[j].fi.se){
                if (dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    par[i] = j;
                }
            }
        }
        // cout << dp[i][i] << " ";
    }

    int last=0;
    for (int i=1;i<=len;i++){
        if (dp[last]<dp[i]){
            last = i;
        }
    }
    // cout << last << el;
    if (last==0){
        cout << 0 << el;
        return 0;
    }
    vector <int> ans;
    while (last!=0){
        ans.pb(v[last].se);
        last = par[last];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << el;
    for (auto x : ans){
        cout << x << " ";
    }cout << el;

    return 0;
}