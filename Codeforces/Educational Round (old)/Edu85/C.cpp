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

const int N = 3e5 + 10;
const ll INF = 1e18;

int q;
int n;
pair<ll, ll> ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> ar[i].fi >> ar[i].se;
        }
        ll tot = 0, mn = INF;
        for (int i=1;i<=n;i++){
            int bi = i - 1;
            if (bi == 0) bi = n;
            tot += max(0LL, ar[i].fi - ar[bi].se);
            ar[i].fi = min(ar[i].fi, ar[bi].se);
            mn = min(ar[i].fi, mn);
        }
        cout << tot + mn << el;
    }

    return 0;
}