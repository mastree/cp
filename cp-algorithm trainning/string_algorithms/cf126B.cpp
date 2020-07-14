#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.length();
    vector<int> z(n, 0);
    for (int i=1, l=0, r=0;i<n;i++){
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
    int ans = 0;
    int mx = 0;
    for (int i=1;i<n;i++){
        if (i + z[i] - 1 != n - 1) mx = max(mx, z[i]);
        else mx = max(mx, z[i] - 1);
    }
    for (int i=1;i<n;i++){
        if (i + z[i] - 1 == n - 1 && mx >= z[i]){
            ans = max(z[i], ans);
        }
    }
    if (ans){
        for (int i=0;i<ans;i++) cout << s[i];
        cout << el;
    } else cout << "Just a legend" << el;

    return 0;
}