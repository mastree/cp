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

int q;
int n, x;
int ar[N];
int ans[N];

void solve(){
    {
        string s;
        cin >> s;
        n = s.size();
        for (int i=1;i<=n;i++){
            ar[i] = s[i - 1] - '0';
        }
        fill(ans + 1, ans + n + 1, 2); // artinya sabeb
    }
    cin >> x;
    for (int i=1;i<x;i++){
        if (i + x > n) break;
        ans[i + x] = ar[i];
    }
    for (int i=n;i + x > n;i--){
        if (i - x < 1) break;
        if (ans[i - x] == 2) ans[i - x] = ar[i];
        else if (ans[i - x] != ar[i]){
            cout << -1 << el;
            return;
        }
    }
    for (int i=1;i<=n;i++){
        int ia = i - x;
        int ib = i + x;
        if (ia < 1 && ib > n){
            if (ar[i] == 1){
                cout << -1 << el;
                return;
            }
            continue;
        }
        if (ia < 1){
            if (ar[i] != ans[ib]){
                if (ans[ib] == 2) ans[ib] = ar[i];
                else{
                    cout << -1 << el;
                    return;
                }
            }
        } else if (ib > n){
            if (ar[i] != ans[ia]){
                if (ans[ia] == 2) ans[ia] = ar[i];
                else{
                    cout << -1 << el;
                    return;
                }
            }
        } else{
            if (ar[i] == 0){
                if (ans[ia] == 1 || ans[ib] == 1){
                    cout << -1 << el;
                    return;
                } else{
                    ans[ia] = ans[ib] = 0;
                }
            } else{
                if (ans[ia] == 1 || ans[ib] == 1) continue;
                if (ans[ia] == 2){
                    ans[ia] = 1;
                } else if (ans[ib] == 2){
                    ans[ib] = 1;
                } else{
                    cout << -1 << el;
                    return;
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (ans[i] == 2) ans[i] = 0;
        cout << ans[i];
    }
    cout << el;
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