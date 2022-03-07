#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int n;
ll k, x;
ll ar[N];
vector<ll> diff;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> x;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1);
    ll ans = 1;
    for (int i=2;i<=n;i++){
        ll temp = ar[i] - ar[i - 1];
        if (temp > x){
            diff.pb((temp + x - 1) / x);
            ans++;
        }
    }
    sort(diff.begin(), diff.end());
    for (auto &d : diff){
        if ((d - 1) <= k){
            k -= d - 1;
            ans--;
        }
    }
    cout << ans << el;

    return 0;
}