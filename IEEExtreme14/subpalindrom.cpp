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
string s;

void solve(){
    cin >> s;
    int n = s.size();

    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
    int le[n + 3], ri[n + 3];
    fill(le, le + n + 3, 0);
    fill(ri, ri + n + 3, 0);
    for (int i=0;i<n;i++){
        int l = i - d1[i] + 1;
        int r = i + d1[i] - 1;
        le[r + 1] = max(le[r + 1], r - l + 1);
        ri[l + 1] = max(ri[l + 1], r - l + 1);

        if (d2[i] == 0) continue;
        l = i - d2[i];
        r = i + d2[i] - 1;
        le[r + 1] = max(le[r + 1], r - l + 1);
        ri[l + 1] = max(ri[l + 1], r - l + 1);
    }
    for (int i=1;i<=n;i++){
        le[i] = max(le[i], le[i - 1]);
    }
    for (int i=n;i>=1;i--){
        ri[i] = max(ri[i], ri[i + 1]);
    }
    for (int i=1;i<n;i++){
        ri[i + 1] = max(ri[i] - 2, ri[i + 1]);
    }
    for (int i=n;i>=1;i--){
        le[i - 1] = max(le[i] - 2, le[i - 1]);
    }
    int ans = 0;
    for (int i=1;i<n;i++){
        ans = max(ans, le[i] + ri[i + 1]);
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