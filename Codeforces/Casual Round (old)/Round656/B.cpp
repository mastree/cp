#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 200;

int q;
int n;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=1;i<=2 * n;i++){
            cin >> ar[i];
        }
        vector<int> ans;
        vector<bool> udah(n + 1, 0);
        for (int i=1;i<=2 * n;i++){
            if (udah[ar[i]]) continue;
            ans.pb(ar[i]);
            udah[ar[i]] = 1;
        }
        for (auto x : ans) cout << x << " ";
        cout << el;
    }

    return 0;
}