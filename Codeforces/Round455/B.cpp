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
const int INF = 1e9;

int n;
int nex[M + 2], bef[M + 2];

int vis[M + 2];
bool ada[M + 2];
int pos[M + 2];
vector<string> ans;

vector<string> ar;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(nex, nex + M + 2, -1);
    fill(bef, bef + M + 2, -1);

    cin >> n;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        ar.pb(s);
        int mn[M];
        fill(mn, mn + M, INF);
        int len = s.size();
        for (int j=0;j<len;j++){
            int dig = (int)(s[j] - 'a');
            ada[dig] = 1;
            if (mn[dig] == INF){
                mn[dig] = j;
            } else{
                cout << "NO" << el;
                return 0;
            }
        }
        for (int j=0;j<len - 1;j++){
            int dig = (int)(s[j] - 'a');
            int ndig = (int)(s[j + 1] - 'a');
            if ((nex[dig] != -1 && nex[dig] != ndig) || (bef[ndig] != -1 && bef[ndig] != dig)){
                cout << "NO" << el;
                return 0;
            }
            nex[dig] = ndig;
            bef[ndig] = dig;
        }
    }
    for (int i=0;i<M;i++){
        if (bef[i] == -1 && ada[i]){
            string s;
            int cur = i;
            s.pb(char('a' + cur));
            while (nex[cur] != -1){
                cur = nex[cur];
                s.pb(char('a' + cur));
            }
            ans.pb(s);
        }
    }
    sort(ans.begin(), ans.end());
    string acum;
    for (auto x : ans){
        for (auto y : x){
            pos[(int)(y - 'a')] = acum.size();
            acum.pb(y);
        }
    }
    int alen = acum.size();
    bool ok = 1;
    for (auto x : ar){
        int len = x.size();
        int awal = pos[(int)(x[0] - 'a')];
        int i;
        for (i=awal;i<alen && i - awal < len;i++){
            if (acum[i] == x[i - awal]) continue;
            ok = 0;
            break;
        }
        if (i - awal == len) continue;
        ok = 0;
        break;
    }
    if (!ok) cout << "NO" << el;
    else cout << acum << el;

    return 0;
}