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

const ll INF = 1e18;

ll n, a, b, c;
int q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        ll ans = INF;
        cin >> n >> a >> b >> c;

        for (int i=1;i<=n;i++){
            ll tm;
            cin >> tm;
            ans = min(ans, abs(tm - b) + abs(tm - a));
        }
        cout << ans + c << el;
    }

    return 0;
}