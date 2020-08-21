#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 26;
const int INF = 1e9 + 10;

int q;
int ar[N];

void solve(){
    for (int i=0;i<N;i++){
        cin >> ar[i];
    }
    int cnt1 = 0, cnt2 = 0;
    int ans = INF;
    for (int i=0;i<N;i++){
        if (ar[i] > 1){
            cnt2++;
            ans = min(ans, ar[i] / 2);
        } else if (ar[i]) cnt1++;
    }
    if (cnt1 == 0){
        if (ans == INF){
            cout << cnt2 * 2 << " " << 0 << el;
            return;
        }
        cout << cnt2 * 2 << " " << ans << el;
        return;
    } 
    if (ans == INF){
        cout << cnt2 * 2 + 1 << " " << cnt1 << el;
        return;
    }
    cout << cnt2 * 2 + 1 << " " << min(cnt1, ans) << el;
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