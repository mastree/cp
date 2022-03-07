#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int q;
void solve(){
    int n, m;
    cin >> n;
    vector<int> pre(n + 2, 0);
    for (int i=1;i<=n;i++){
        cin >> pre[i];
        pre[i] += pre[i - 1];
    }
    cin >> m;
    vector<int> pre2(m + 2, 0);
    for (int i=1;i<=m;i++){
        cin >> pre2[i];
        pre2[i] += pre2[i - 1];
    }
    int ans = 0;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            ans = max(ans, pre[i] + pre2[j]);
        }
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }    

    return 0;
}