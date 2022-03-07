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

void solve(){
    vector<int> vec;
    int m;
    int tot = 0;
    for (int i=1;i<=3;i++){
        int a;
        cin >> a;
        if (a){
            vec.pb(a);
            tot += a;
        }
    }
    cin >> m;
    int mx = tot - (int)vec.size();
    sort(vec.begin(), vec.end(), greater<int>());
    int mn = 0;
    if (vec[0] > tot - vec[0]){
        mn = vec[0] * 2 - tot - 1;
    }
    if (mn <= m && m <= mx){
        cout << "YES" << el;
    } else{
        cout << "NO" << el;
    }
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