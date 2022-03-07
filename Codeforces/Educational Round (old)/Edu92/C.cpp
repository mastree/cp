#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10, M = 10;

int q;
int n;
string s;
int cnt[M];

void solve(){
    cin >> s;
    n = s.length();
    if (n <= 2){
        cout << 0 << el;
        return;
    }
    int ans = n - 2;
    
    fill(cnt, cnt + M, 0);
    for (auto x : s){
        int dig = (int)(x - '0');
        cnt[dig]++;
    }
    int mx = 0;
    for (int i=0;i<M;i++) mx = max(mx, cnt[i]);
    ans = min(ans, n - mx);

    for (int i=0;i<M;i++){
        for (int j=0;j<M;j++){
            int len = 0;
            int dig[2] = {i, j};
            bool stat = 0;
            for (auto x : s){
                int cur = (int)(x - '0');
                if (cur == dig[stat]){
                    len++;
                    stat ^= 1;
                }
            }
            // cout << i << " " << j << " " << len << el;
            if (len & 1) len--;
            ans = min(ans, n - len);
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