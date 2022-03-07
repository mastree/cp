#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const int MX = 2e9;

int q;
int n;
int ar[N];

void solve(){
    vector<vector<int>> ans;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    int posmn = 1;
    for (int i=1;i<=n;i++){
        if (ar[i] < ar[posmn]){
            posmn = i;
        }
    }
    if (posmn != 1){
        ans.push_back({posmn, 1, ar[1], ar[posmn]});
    }
    for (int i=2;i<=n;i++){
        ans.push_back({1, i, ar[posmn], ar[posmn] + i - 1});
    }
    cout << ans.size() << el;
    for (auto &x : ans){
        for (auto &y : x){
            cout << y << ' ';
        }
        cout << el;
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