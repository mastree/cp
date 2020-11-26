#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110, M = 26;

int n, m;
ll cnt[M];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        char c;
        cin >> c;
        cnt[c - 'A']++;
    }
    while (m--){
        char ch;
        string s;
        cin >> ch >> s;
        ll temp[M];
        fill(temp, temp + M, 0);
        for (auto x : s){
            temp[x - 'A']++;
        }
        ll cur = cnt[ch - 'A'];
        cnt[ch - 'A'] = 0;
        for (int i=0;i<M;i++){
            cnt[i] += temp[i] * cur;
        }
    }
    ll ans = 0;
    for (auto x : cnt) ans += x;
    cout << ans << el;

    return 0;
}