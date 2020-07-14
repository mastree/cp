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

const int N = 50;

int q;
int n, m;
bool ar[N][N];
int cnt[N + N][2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m;
        for (int i=0;i<=n + m + 2;i++){
            cnt[i][0] = cnt[i][1] = 0;
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin >> ar[i][j];
                cnt[i + j - 1][ar[i][j]]++;
            }
        }
        int ans = 0;
        int len = n + m - 1;
        for (int i=1;i<=len / 2;i++){
            int j = len - i + 1;
            if (i == j) continue;
            ans += min(cnt[i][0] + cnt[j][0], cnt[i][1] + cnt[j][1]);
        }
        cout << ans << el;
    }

    return 0;
}