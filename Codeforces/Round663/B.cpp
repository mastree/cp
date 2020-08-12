#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110;

int q;
int n, m;

void solve(){
    cin >> n >> m;
    int ans = 0;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        if (i != n){
            if (s[m - 1] != 'D') ans++;
        } else{
            for (int i=0;i<m - 1;i++){
                if (s[i] != 'R') ans++;
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