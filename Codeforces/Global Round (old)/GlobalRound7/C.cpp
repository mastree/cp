#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
// #define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 2e5 + 10;
const ll MOD = 998244353;

int n, k;
int ar[N];

ll tot;
ll ans = 1;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    ll mx = n;
    ll mn = n - k + 1;
    tot = (mx + mn) * (mx - mn + 1) / 2;

    vector <ll> v;
    for (int i=1;i<=n;i++){
        if (mn <= ar[i]){
            v.pb(i);
        }
    }
    int len = v.size();
    for (int i=0;i<len - 1;i++){
        ans = ans * (v[i + 1] - v[i]) % MOD;
    }

    cout << tot << " " << ans << el;

    return 0;
}