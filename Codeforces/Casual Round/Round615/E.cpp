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

int n, m;
vector <vector<int>> ar;
int ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int cnt[n + 2];
    ar.resize(n + 2, vector<int>(m + 2));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> ar[i][j];
        }
    }

    for (int j=1;j<=m;j++){
        fill(cnt, cnt + n + 2, 0);
        for (int i=1;i<=n;i++){
            int res = ar[i][j] % m;
            if (res == j || (res==0 && j==m)){
                int pos = (ar[i][j] - 1) / m + 1;
                int jarak;
                if (pos <= i) jarak = i-pos;
                else jarak = i + n - pos;
                if (jarak < n && jarak >= 0) cnt[jarak]++;
            }
        }
        int plus = MOD;
        for (int i=0;i<n;i++){
            plus = min(plus, n - cnt[i] + i);
        }
        ans += plus;
    }
    cout << ans << el;

    return 0;
}