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

void solve(){
    cin >> n;
    vector<bool> tar(n + 2, 0), ar(n + 2, 0), forbid(n + 2, 0);
    for (int i=1;i<=n;i++){
        char c;
        cin >> c;
        tar[i] = (c == '1');
    }
    for (int i=1;i<=n;i++){
        char c;
        cin >> c;
        ar[i] = (c == '1');
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (ar[i]){
            for (int j=-1;j<=1;j++){
                if (j && tar[i + j] && !forbid[i + j]){
                    ans++;
                    forbid[i + j] = 1;
                    break;
                } else if (j == 0 && !tar[i + j] && !forbid[i + j]){
                    ans++;
                    forbid[i + j] = 1;
                    break;
                }
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