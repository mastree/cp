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
const int INF = 1e9;

int n;
string s;
int pre[N][2]; // 0 => smiley, 1 => reverse smiley
int ans = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.size();
    s = ")" + s + "(";
    for (int i=1;i<=n;i++){
        if (s[i - 1] == ':' && s[i] == ')') pre[i][0]++;
        else if (s[i - 1] == '(' && s[i] == ':') pre[i][1]++;
        pre[i][0] += pre[i - 1][0];
        pre[i][1] += pre[i - 1][1];
    }

    int base = pre[n][0];
    int mn[2][2] = {{INF, INF}, {INF, INF}};
    for (int i=0;i<=n;i++){
        int cur = pre[i][1] - pre[i][0];
        bool cek0 = 0, cek1 = 0;
        if (s[i] == '(') cek0 = 1;
        if (s[i + 1] == ')') cek1 = 1;

        int kur = 0;
        if (s[i] == ':' && s[i + 1] == ')') kur = 1;
        for (int j=0;j<2;j++){
            for (int k=0;k<2;k++){
                int tam = (j && cek0) + (k && cek1);
                ans = max(ans, cur - mn[j][k] + tam - kur);
            }
        }
        cek0 = cek1 = 0;
        if (s[i] == ':') cek0 = 1;
        if (s[i + 1] == ':') cek1 = 1;
        if (s[i] == '(' && s[i + 1] == ':') kur++;
        mn[cek0][cek1] = min(mn[cek0][cek1], cur + kur);
    }
    cout << ans + base << el;

    return 0;
}