#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e3 + 10;

int q;
int n;
int ar[N][N];
int down[N][N], le[N];

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> ar[i][j];
        }
    }
    int ans = n;
    for (int i=n;i>=1;i--){
        for (int j=1;j<=n;j++){
            if (i < n && ar[i + 1][j] == ar[i][j]) down[i][j] = down[i + 1][j] + 1;
            else down[i][j] = 1;
        }
    }
    for (int i=1;i<=n;i++){
        stack<pii> st; // down, pos
        st.push(mp(0, 0));
        for (int j=1;j<=n;j++){
            while (st.top().fi >= down[i][j]) st.pop();
            le[j] = st.top().se;
            st.push(mp(down[i][j], j));
        }
        while (st.size()) st.pop();
        st.push(mp(0, n + 1));
        for (int j=n;j>=1;j--){
            while (st.top().fi >= down[i][j]) st.pop();
            int ri = st.top().se;
            ans = max(ans, down[i][j] * (ri - le[j] - 1));
            st.push(mp(down[i][j], j));
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