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

const int N = 1e5 + 10;
const int INF = 2e9;

int q;
ll n, x;
ll ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> x;
        map <int, bool> ada;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            ada[ar[i]] = 1;
        }

        ll ans = INF;
        for (int i=1;i<=n;i++){
            if (ar[i] > x){
                ans = min(ans, 2LL);
                continue;
            }
            ll temp = x / ar[i];
            ll sisa = x % ar[i];
            if (sisa){
                temp++;
            }
            ans = min(ans, temp);
        }
        cout << ans << el;
    }

    return 0;
}