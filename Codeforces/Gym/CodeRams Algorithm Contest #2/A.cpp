#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int C = 26;
const int INF = 1e9;

string tar = "coderams";
int cnt[C];
int n;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (auto& x : s){
        cnt[(int)(x - 'a')]++;
    }
    int ans = INF;
    for (auto& x : tar){
        ans = min(ans, cnt[(int)(x - 'a')]);
    }
    cout << ans << el;

    return 0;
}