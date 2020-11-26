#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int n;
int len = 14;
ll ans;
unordered_map<string, ll> cek;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        for (int j=0;j<14;j++){
            char pc = s[j];
            s[j] = '_';
            cek[s]++;
            s[j] = pc;
        }
    }
    for (auto x : cek){
        ans += x.se * (x.se - 1) / 2;
    }
    cout << ans << el;

    return 0;
}