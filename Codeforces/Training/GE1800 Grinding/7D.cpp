#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e6 + 10;

int n;
string s;
int z[N], dp[N];
int pref[N], suf[N], suf2[N];

void make_pref_suf(){
    int l = 0;
    for (int r=1;r<n;r++){
        while (l != 0 && s[l] != s[r]) l = pref[l - 1];
        if (s[l] == s[r]) l++;
        pref[r] = l;
    }
    l = 0;
    for (int r=n - 1;r>=0;r--){
        while (l != 0 && s[l] != s[r]) l = pref[l - 1];
        if (s[l] == s[r]) l++;
        while (l != 0 && l > r) l = pref[l - 1];
        suf[r] = l;
        suf2[r] = pref[l - 1];
    }
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.length();
    for (int i=1, l=0, r=0;i<n;i++){
        if (r >= i){
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (z[i] + i < n && s[z[i]] == s[z[i] + i]) z[i]++;
        if (i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
    make_pref_suf();
    dp[0] = 1;
    for (int i=1;i<n;i++){
        if (dp[i - 1]){
            // not-center
            if (z[i] >= i) dp[i * 2 - 1] = dp[i - 1] + 1;
            // center
            if (i + 1 < n && z[i + 1] >= i) dp[i * 2] = dp[i - 1] + 1;
        } else{
            if (suf[i] == i) dp[i * 2 - 1] = 1;
            if (i + 1 < n && suf[i + 1] == i || suf2[i + 1] == i) dp[i * 2] = 1;
        }
    }
    ll ans = 0;
    for (int i=0;i<n;i++) ans += (ll)dp[i];
    cout << ans << el;

    return 0;
}