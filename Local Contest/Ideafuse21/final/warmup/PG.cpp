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
const int C = 26;

int q;
int n;
string s;

void solve(){
    cin >> n >> s;
    vector<vector<int>> pre(n + 1, vector<int>(C, 0));
    for (int i=1;i<=n;i++){
        for (int j=0;j<C;j++){
            pre[i][j] = pre[i - 1][j];
        }
        pre[i][(int)(s[i - 1] - 'A')]++;
    }
    int ans = 1;
    for (int pt=1;pt<n;pt++){
        if (n % pt == 0){
            bool bisa = 1;
            for (int i=pt + pt;i<=n;i+=pt){
                for (int j=0;j<C;j++){
                    if (pre[pt][j] != pre[i][j] - pre[i - pt][j]){
                        bisa = 0;
                        break;
                    }
                }
                if (!bisa) break;
            }
            if (bisa){
                ans = n / pt;
                break;
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
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}