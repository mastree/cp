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

const int N = 1e5 + 10;

string s;
ll ans;
ll cek[26][26];
int len;

ll cnt[26];
ll pc[N][26];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    len = s.length();
    s = "*" + s;
    for (int i=1;i<=len;i++){
        int dig = s[i] - 'a';
        for (int j=0;j<26;j++){
            pc[i][j] = pc[i-1][j];
        }
        pc[i][dig]++;
    }

    for (int i=0;i<26;i++){
        ans = max(ans, pc[len][i]);
        ans = max(ans, pc[len][i] * (pc[len][i] - 1) / 2);
    }


    for (int i=1;i<=len;i++){
        for (int j=0;j<26;j++){
            for (int k=0;k<26;k++){
                if (j == k) continue;
                int dig = s[i] - 'a';
                if (dig != j) continue;
                cek[j][k] += pc[len][k] - pc[i][k];
                // if (j == 0) cout << pc[len][k] - pc[j][k] << el;
            }
        }
    }

    for (int i=0;i<26;i++){
        for (int j=0;j<26;j++){
            ans = max(ans, cek[i][j]);
            // cout << i << " " << j << " : " << cek[i][j] << el;
        }
    }
    cout << ans << el;

    return 0;
}