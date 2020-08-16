#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 40;

string kons = "aiueo";

bool is_kons[300];

int q;
int n;
string s[N];
bool ok[N][N];

bool bisa(int id1, int id2){
    for (int i=0;i<s[id1].size();i++){
        for (int j=0;j<s[id2].size();j++){
            bool stat[2] = {0, 0};
            for (int pl=0;pl<4;pl++){
                if (i + pl >= s[id1].size() || j + pl >= s[id2].size() || s[id1][i + pl] != s[id2][j + pl]) break;

                if (is_kons[s[id1][i + pl] - 'a']) stat[0] = 1;
                else stat[1] = 1;
                if (stat[0] && stat[1]) return 1;
            }
        }
    }
    return 0;
}

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> s[i];
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        for (int j=i + 1;j<=n;j++){
            if (bisa(i, j)) ans++;
        }
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (auto x : kons){
        is_kons[x - 'a'] = 1;
    }
    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}