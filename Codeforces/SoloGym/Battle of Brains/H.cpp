#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int tc;
int n, q;
string s;

void solve(){
    cin >> s;
    n = s.size();

    vector<vector<int>> pre(n + 2, vector<int>(n + 2, 0));
    for (int len=2;len<=n;len++){
        for (int i=1;i + len - 1<=n;i++){
            int j = i + len - 1;
            pre[i][j] = pre[i + 1][j - 1] + abs(int(s[i - 1] - s[j - 1]));
        }
    }
    cin >> q;
    while (q--){
        int le, ri, mx;
        cin >> le >> ri >> mx;
        int md = (le + ri) / 2;
        int mspan = (ri - le + 1) / 2;

        int ans = 0;
        if ((ri - le) & 1){ // genap
            int l = 0, r = mspan;
            while (l <= r){
                int m = (l + r) / 2;
                if (pre[md - (m - 1)][md + m] <= mx){
                    l = m + 1;
                    ans = m;
                } else{
                    r = m - 1;
                }
            }
            ans += ans;
        } else{
            int l = 0, r = mspan;
            while (l <= r){
                int m = (l + r) / 2;
                if (pre[md - m][md + m] <= mx){
                    l = m + 1;
                    ans = m;
                } else{
                    r = m - 1;
                }
            }
            ans += ans + 1;
        }
        cout << ans << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int i=1;i<=tc;i++){
        solve();
    }

    return 0;
}