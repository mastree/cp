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
const ll INF = 1e18;

ll n, m;
ll ar[N];

set<ll> setdah;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        ll a;
        cin >> a;
        setdah.insert(a);
    }
    n = setdah.size();
    int id = 1;
    for (auto x : setdah){
        ar[id] = x;
        id++;
    }
    if (n == 1){
        cout << 0 << el;
        return 0;
    }
    sort(ar + 1, ar + n + 1);
    ll ans = INF;
    for (int i=1;i<=n;i++){
        if (i == 1){
            ans = min(ans, m - (ar[i + 1] - ar[i]));
            ans = min(ans, m - (ar[i] + (m - ar[n])));
        } else{
            ans = min(ans, m - (ar[i + 1] - ar[i]));
            ans = min(ans, m - (ar[i] - ar[i - 1]));
        }
    }
    cout << ans << el;

    return 0;
}