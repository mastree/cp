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

const int N = 1e6 + 10;
const ll INF = 1e18;

int q;
int n;
string s;
ll pre[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> s;
        n = s.length();
        s = "*" + s;

        pre[0] = 0;
        for (int i=1;i<=n;i++){
            ll dig = 1;
            if (s[i] == '-') dig = -1;
            pre[i] = pre[i - 1] + dig;
        }
        ll mn = 0;
        ll ans = 0;
        vector<pair<ll, ll>> v;
        for (int i=1;i<=n;i++){
            if (mn > pre[i]){
                v.pb(mp(pre[i], i));
                mn = pre[i];
            }
        }
        for (auto x : v){
            ans += x.se;
        }
        ans += (ll)n;
        cout << ans << el;
    }

    return 0;
}