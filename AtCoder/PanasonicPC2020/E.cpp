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

const int N = 2e3 + 10;

bool dp[3][3][N];
string s[3];
int len[3];
int tot = 0;
int ans = MOD;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s[0] >> s[1] >> s[2];
    len[0] = s[0].length();
    len[1] = s[1].length();
    len[2] = s[2].length();
    tot = len[0] + len[1] + len[2];

    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (i == j) continue;
            for (int k=0;k<=len[i];k++){
                bool bisa = 1;
                int id2 = -1;
                for (int id1=k;id1<len[i];id1++){
                    id2++;
                    if (id2 >= len[j]) break;
                    if (s[i][id1] == s[j][id2] || s[i][id1] == '?' || s[j][id2] == '?') continue;
                    bisa = 0;
                    break;
                }
                dp[i][j][len[i] - k] = bisa;
            }
            dp[i][j][0] = 1;
        }
    }
    
    for (int id1=0;id1<3;id1++){
        for (int id2=0;id2<3;id2++){
            if (id1 == id2) continue;
            int id3 = 0;
            if (id3 == id1 || id3 == id2) id3++;
            if (id3 == id1 || id3 == id2) id3++;

            for (int i=0;i<=len[id1];i++){
                for (int j=i;j<=4001;j++){
                    if (dp[id1][id2][len[id1] - i] && dp[id2][id3][max(0, len[id2] - j + i)] && dp[id1][id3][max(0, len[id1] - j)]){
                        ans = min(ans, max(len[id1], max(len[id2] + i, len[id3] + j)));
                    }
                }
            }
        }
    }
    if (ans != MOD) cout << ans << el;
    else cout << tot << el;
    return 0;
}