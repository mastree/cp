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
int ar[N];

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    vector<int> ans;
    int l = -1;
    bool l0 = 0;
    for (int i=1;i<=n;i++){
        if (ar[i] == 0 && l == -1){
            l0 = 1;
            continue;
        }
        if (ar[i] == 0){
            if ((i - l) & 1 ^ 1){
                for (int j=i - 2;j>=l;j-=2){
                    ans.pb(j);
                }
                l0 = 1;
                l = -1;
            } else{
                if (i == n){
                    cout << "NO" << el;
                    return;
                }
                if (ar[i + 1] == 0){
                    ans.pb(i - 1);
                    ar[i] = ar[i + 1] = 1;
                } else{
                    ans.pb(i - 1);
                    ar[i + 1] = 0;
                    for (int j=i - 3;j>=l;j-=2){
                        ans.pb(j);
                    }
                    l0 = 1;
                    l = -1;
                }
            }
        } else{
            if (l == -1) l = i;
            if (((i - l + 1) & 1 ^ 1) > 0 && l0){
                for (int j=l - 1;j<=i - 2;j+=2){
                    ans.pb(j);
                }
                l0 = 1;
                l = -1;
            }
        }
    }
    if (l != -1){
        cout << "NO" << el;
        return;
    }
    cout << "YES" << el;
    cout << ans.size() << el;
    if (ans.size()) {for (auto& x : ans) cout << x << ' '; cout << el;}
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