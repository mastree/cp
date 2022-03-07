#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e5 + 10;

int q;
int n, m;
int ar[N];
int br[N];

void solve(){
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=m;i++){
        cin >> br[i];
    }
    vector<int> vec;
    for (int i=1;i<=n;i++){
        vec.pb(br[ar[i]]);
    }
    sort(vec.begin(), vec.end());
    int last = 1;
    ll ans = 0;
    while (!vec.empty()){
        if (last <= m && br[last] < vec.back()){
            ans += br[last++];
        } else{
            ans += vec.back();
        }
        vec.pop_back();
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