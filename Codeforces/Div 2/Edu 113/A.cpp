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
int n;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> s;
        bool ok = 0;
        for (int i=0;i<n - 1;i++){
            if (s[i] != s[i + 1]){
                cout << i << " " << i + 1 << el;
                ok = 1;
                break;
            }
        }
        if (!ok) cout << -1 << " " << -1 << el;
    }

    return 0;
}