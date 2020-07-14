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

int q;
ll n, k;
ll ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> k;

        map<ll, ll> cnt;
        for (int i=1;i<=(int) n;i++){
            cin >> ar[i];
            ar[i] %= k;
            cnt[(k - ar[i]) % k]++;
        }
        pair<ll, ll> mx = mp(0LL, 0LL); // cnt, number;
        for (auto x : cnt){
            if (x.fi == 0) continue;
            // cout << x.fi << " " << x.se << el;
            if (x.se >= mx.fi){
                mx = mp(x.se, x.fi);
            }
        }
        if (mx.se == 0 || mx.fi == 0){
            cout << 0 << el;
            continue;
        }
        ll ans = k * (mx.fi - 1) + mx.se;
        if (ans == 0LL){
            cout << ans << el;
            continue;
        }
        cout << ans + 1LL << el;
    }

    return 0;
}