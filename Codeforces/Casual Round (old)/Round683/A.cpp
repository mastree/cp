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

int q;
int n;
ll ar[N];
ll w;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> w;
        ll tot = 0;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            if (ar[i] > w) ar[i] = 0;
            tot += ar[i];
        }   
        if (tot < (w + 1) / 2){
            cout << -1 << el;
            continue;
        } 
        vector<ll> ans;
        tot = 0;
        for (int i=1;i<=n;i++){
            if (ar[i] == 0) continue;
            if (ar[i] >= (w + 1) / 2){
                ans.clear();
                ans.pb(i);
                break;
            }
            ans.pb(i);
            tot += ar[i];
            if (tot >= (w + 1) / 2) break;
        }
        cout << ans.size() << el;
        for (auto x : ans){
            cout << x << " ";
        }
        cout << el;
    }

    return 0;
}