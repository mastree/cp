#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10, M = 26;

int n;
string s, t;
int cnt[M][M];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> s >> t;
    int ans = 0;
    for (int i=0;i<n;i++){
        if (s[i] == t[i]) continue;
        int a = s[i] - 'a';
        int b = t[i] - 'a';
        if (cnt[b][a]){
            ans++;
            cnt[b][a]--;
        } else{
            cnt[a][b]++;
        }
    }
    for (int i=0;i<M;i++){
        for (int j=0;j<M;j++){
            ans += cnt[i][j];
        }
    }
    cout << ans << el;

    return 0;
}