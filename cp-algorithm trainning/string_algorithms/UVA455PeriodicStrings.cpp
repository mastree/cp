#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string s;
int q, n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> s;
        n = s.length();
        vector<int> z(n, 0);
        for (int i=1, l=0, r=0;i<n;i++){
            if (i <= r){
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
            if (i + z[i] - 1 > r){
                l = i;
                r = i + z[i] - 1;
            }
        }

        int ans = n;
        for (int i=1;i<n;i++){
            if (n % i == 0){
                bool ok = 1;
                for (int j=i;j<n;j+=i){
                    if (z[j] < i){
                        ok = 0;
                        break;
                    }
                }
                if (ok){
                    ans = i;
                    break;
                }
            }
        }
        cout << ans << el << el;
    }


    return 0;
}