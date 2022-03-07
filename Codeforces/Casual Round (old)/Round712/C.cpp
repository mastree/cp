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
// const ll INF = 1e18;

int n;
int ar[N]; // beauty point
int cost[N];

// vector<pii> vec;
// vector<bool> bisa;
// vector<ll> tam, butuh;
int root = 0;
vector<int> mnId, need;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ll ans = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i] >> cost[i];
        ans += cost[i];
        vec.pb(mp(ar[i], cost[i]));
    }
    sort(vec.begin(), vec.end());
    for (int i=0;i<n;i++){
        if (vec[i] == mp(ar[1], cost[1])){
            root = i;
            break;
        }
    }
    // bool ok = 0;
    // {
    //     bisa.resize(n, 0);
    //     bisa[n - 1] = 1;
    //     int mn = n - 1;
    //     for (int i=n - 1;i>=0;i--){
    //         if (vec[i].fi + vec[i].se >= vec[mn].fi){
    //             bisa[i] = 1;
    //             mn = i;
    //         }
    //     }
    //     // cout << mn << " " << vec[mn].fi << " " << vec[mn].se << el;
    //     // cout << ans << el;
    //     if (mn > root){
    //         ans += max(0, vec[mn].fi - vec[root].fi - vec[root].se);
    //     } else{
    //         ok = 1;
    //         root = mn;
    //     }
    // }
    // // cout << ans << el;
    // if (ok) {
    //     tam.resize(n, 0LL);
    //     int mn = root;
    //     for (int i=root - 1;i>=0;i--){
    //         if (vec[i].fi + vec[i].se >= vec[mn].fi){
    //             mn = i;
    //         } else{
    //             tam[i] = (ll)max(0, vec[mn].fi - vec[i].fi - vec[i].se);
    //         }
    //     }
    //     ans += tam[0];
    // } else{

    // }
    {
        vector<pii> temp;
        for (int i=0;i<n;i++){
            temp.pb(mp(vec[i].fi + vec[i].se, i));
        }
        sort(temp.begin(), temp.end(), greater<pii>());
        need.resize(N, N + N);
        int last = n - 1;
        need[last] = 0;
        for (auto& x : temp){
            int cur = x.se;
            if (cur == n - 1) continue;
            
        }
    }
    cout << ans << el;

    return 0;
}