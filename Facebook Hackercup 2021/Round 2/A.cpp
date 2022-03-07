#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e6 + 10;

int q;

int n, m;

void solve(){
    cin >> n >> m;
    vector<vector<int>> vec(2); // [sisa-nyawa] = list kostum
    for (int i=1;i<=m;i++){
        int a;
        cin >> a;
        vec[1].pb(a);
    }
    int ans = 0;
    for (int rd=1;rd<=n;rd++){
        vector<vector<int>> nvec(2);
        unordered_map<int, int> nx;
        for (int i=1;i<=m;i++){
            int a;
            cin >> a;
            nx[a]++;
        }
        for (auto& x : vec[0]){
            if (nx[x] > 0){
                nx[x]--;
                nvec[0].pb(x);
            } else{
                ans++;
            }
        }
        for (auto& x : vec[1]){
            if (nx[x] > 0){
                nx[x]--;
                nvec[1].pb(x);
            } else{
                // nothing
            }
        }
        for (auto& x : nx){
            while (x.se){
                nvec[0].pb(x.fi);
                x.se--;
            }
        }
        vec.swap(nvec);
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}