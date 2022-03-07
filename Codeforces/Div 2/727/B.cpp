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

int n, q;
string s;
int pre[N];

void solve(){
    int l, r;
    cin >> l >> r;
    cout << pre[r] - pre[l - 1] << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    cin >> s;
    for (int i=0;i<n;i++){
        int dig = (s[i] - 'a') + 1;
        pre[i + 1] = pre[i] + dig;
    }
    while (q--){
        solve();
    }

    return 0;
}