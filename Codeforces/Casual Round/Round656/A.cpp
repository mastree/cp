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
int asli[3], ar[3], ans[3];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        for (int i=0;i<3;i++){
            cin >> ar[i];
            asli[i] = ar[i];
        }
        sort(ar, ar + 3, greater<int>());
        if (ar[0] == ar[1]){
            cout << "YES" << el;
            for (int i=0;i<3;i++) ans[i] = ar[2];
            if (asli[0] == ar[2]){
                ans[2] = ar[0];
            } else if (asli[1] == ar[2]){
                ans[1] = ar[0];
            } else{
                ans[0] = ar[0];
            }
            for (auto x : ans) cout << x << " ";
            cout << el;
        } else{
            cout << "NO" << el;
            continue;
        }
    }

    return 0;
}