#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 110;
const int INF = 1e8;

pii nex[2] = {mp(1, 0), mp(0, 1)};

int r, c;
int n;
string s[N];

pii aw, ak;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    for (int i=1;i<=r;i++){
        string temp;
        cin >> temp;
        s[i] = "*" + temp + "*";
    }
    aw = mp(1, 1);
    ak = mp(r, c);

    set <pair<int, pii>> setdah; // cost, pos
    int dp[r + 2][c + 2];
    for (int i=0;i<r + 2;i++){
        fill(dp[i], dp[i] + c + 2, INF);
    }
    dp[aw.fi][aw.se] = 0;
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++){
            setdah.insert(mp(dp[i][j], mp(i, j)));
            // cout << i << " " << j << el;
        }
    }

    while (!setdah.empty()){
        auto temp = *setdah.begin();
        // cout << temp.fi << " " << temp.se.fi << ", " << temp.se.se << el;
        pii cur = temp.se;
        int cost = temp.fi;
        setdah.erase(setdah.begin());

        for (int i=0;i<2;i++){
            int ni = cur.fi + nex[i].fi;
            int nj = cur.se + nex[i].se;
            if (ni > 0 && nj > 0 && ni <= r && nj <= c){
                int tambah = (s[cur.fi][cur.se] != s[ni][nj]);
                if (cost + tambah < dp[ni][nj]){
                    // pair<int, pii> baru = mp(cost + tambah, mp(ni, nj));
                    setdah.erase(mp(dp[ni][nj], mp(ni, nj)));
                    dp[ni][nj] = cost + tambah;
                    setdah.insert(mp(dp[ni][nj], mp(ni, nj)));
                }
            }
        }
    }

    if (s[1][1] == s[r][c] && s[1][1] == '.') cout << dp[ak.fi][ak.se] / 2 << el;
    else if (s[1][1] == s[r][c]) cout << dp[ak.fi][ak.se] / 2 + 1 << el;
    else cout << (dp[ak.fi][ak.se] - 1) / 2 + 1 << el;

    return 0;
}