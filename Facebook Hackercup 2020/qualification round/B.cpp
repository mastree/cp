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
int n;
string s;

void solve(){
    cin >> n >> s;
    int cnt0 = 0, cnt1 = 0;
    for (auto x : s){
        if (x == 'A') cnt0++;
        else cnt1++;
    }
    if (abs(cnt0 - cnt1) <= 1) cout << "Y" << el;
    else cout << "N" << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("alchemy_input.txt", "r", stdin);
    freopen("B.out", "w", stdout);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}