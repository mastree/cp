#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int q;
int ar[3], br[3];

void solve(){
    for (int i=0;i<=2;i++){
        cin >> ar[i];
    }
    for (int i=0;i<=2;i++){
        cin >> br[i];
    }
    int ans = 0;
    int mn = min(ar[2], br[1]);
    ans += 2 * mn;
    ar[2] -= mn;
    br[1] -= mn;

    mn = min(ar[0], br[2]);
    ar[0] -= mn;
    br[2] -= mn;
    mn = min(ar[1], br[1]);
    ar[1] -= mn;
    br[1] -= mn;
    mn = min(ar[2], br[2]);
    ar[2] -= mn;
    br[2] -= mn;

    for (int i=0;i<=2;i++){
        for (int j=0;j<=2;j++){
            if (ar[i] && br[j]){
                int mn = min(ar[i], br[j]);
                if (i < j) ans -= mn * i * j;
                else if (i > j) ans += mn * i * j;
                ar[i] -= mn;
                br[j] -= mn; 
            }
        }
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}