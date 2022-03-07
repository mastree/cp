#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const int H = 1e9 + 1;
const int MX = H + H;
const ll INF = 1e18;

int q;
int n;

void solve(){
    cin >> n;
    vector<int> vec[2], lvec[2], rvec[2]; // x vector, y vector
    for (int i=0;i<n;i++){
        int xa, ya;
        int xb, yb;
        cin >> xa >> ya >> xb >> yb;
        lvec[0].pb(xa);
        rvec[0].pb(xb);
        lvec[1].pb(ya);
        rvec[1].pb(yb);
        
        vec[0].pb(xa);
        vec[0].pb(xb);
        vec[1].pb(ya);
        vec[1].pb(yb);
    }
    vector<int> ans;
    for (int id=0;id<2;id++){
        sort(vec[id].begin(), vec[id].end());
        sort(lvec[id].begin(), lvec[id].end());
        sort(rvec[id].begin(), rvec[id].end());
        vector<ll> lpre(n + 2, 0), rpre(n + 2, 0);
        for (int i=1;i<=n + 1;i++){
            lpre[i] = lpre[i - 1];
            if (i <= n) lpre[i] += rvec[id][i - 1];
        }
        for (int i=n;i>=0;i--){
            rpre[i] = rpre[i + 1];
            if (i > 0) rpre[i] += lvec[id][i - 1];
        }
        pair<ll, int> ret = {INF, -1};
        for (int i=0;i<n + n - 1;i++){
            int x = vec[id][i];
            int xx = vec[id][i + 1];
            vector<ll> cand = {x, xx};

            int l = upper_bound(rvec[id].begin(), rvec[id].end(), x) - rvec[id].begin();
            int r = lower_bound(lvec[id].begin(), lvec[id].end(), xx) - lvec[id].begin() + 1;

            ll cntl = l;
            ll cntr = n - r + 1;

            ll cur = -lpre[l] + rpre[r];
            ll tot = lpre[l] + rpre[r]; 

            cand.pb(tot / 2);
            cand.pb(tot / 2 + 1);
            for (auto& pos : cand){
                if ((ll)x <= pos && pos <= (ll)xx){
                    ll temp = cur + pos * cntl - pos * cntr;
                    ret = min(ret, mp(temp, (int)pos));
                }
            }
        }
        ans.pb(ret.se);
    }
    for (auto& x : ans) cout << x << ' ';
    cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}