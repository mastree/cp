#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;

int q;
int n, ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        bool ok = 0;
        for (int i=2;i<=n - 1;i++){
            int le = i, ri = i;
            for (int j=1;j<i;j++){
                if (ar[j] < ar[le]) le = j;
            }   
            for (int j=i + 1;j<=n;j++){
                if (ar[j] < ar[ri]) ri = j;
            }
            if (le != i && ri != i){
                ok = 1;
                cout << "YES" << el;
                cout << le << " " << i << " " << ri << el;
                break;
            }
        }
        if (!ok) cout << "NO" << el;
    }

    return 0;
}