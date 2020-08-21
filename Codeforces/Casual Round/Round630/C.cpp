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

const int N = 2e5 + 10;

int q;
int n, k;

string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> k;
        cin >> s;

        int pc[k][n / k][26];
        for (int i=0;i<k;i++){
            for (int j=0;j<n / k;j++){
                fill(pc[i][j], pc[i][j] + 26, 0);
            }
        }
        for (int i=0;i<k;i++){
            for (int id=i;id<n;id+=k){
                int dig = s[id] - 'a';
                int now = (id - i) / k;
                pc[i][now][dig]++;
                if (now > 0){
                    for (int j=0;j<26;j++){
                        pc[i][now][j] += pc[i][now - 1][j];
                    }
                }
            }
        }

        int ans = 0;
        for (int i=0;i + i<k;i++){
            int mn = MOD;
            if (i + i == k - 1){
                for (int j=0;j<26;j++){
                    mn = min(mn, n / k - pc[i][n / k - 1][j]);
                }
            } else{
                for (int j=0;j<26;j++){
                    mn = min(mn, n / k - pc[i][n / k - 1][j] + n / k - pc[k - i - 1][n / k - 1][j]);
                }
            }
            ans += mn;
        }
        cout << ans << el;
    }

    return 0;
}