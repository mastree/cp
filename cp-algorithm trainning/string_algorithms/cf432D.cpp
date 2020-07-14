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
int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.length();
    vector<int> z(n, 0), cnt(n + 1, 0);
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
    cnt[0]++;
    vector<int> anslen;
    for (int i=1;i<n;i++){
        if (i + z[i] - 1 == n - 1) anslen.pb(z[i]);
        cnt[0]++;
        cnt[z[i] + 1]--;
    }
    int cur = 0;
    for (int i=0;i<=n;i++){
        cur += cnt[i];
        cnt[i] = cur;
    }
    anslen.pb(n);
    sort(anslen.begin(), anslen.end());
    cout << (int)anslen.size() << el;
    for (auto x : anslen){
        cout << x << " " << cnt[x] << el;
    }

    return 0;
}