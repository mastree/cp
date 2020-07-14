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

int q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int cas = 1; cas <= q; cas++){
        int n;
        cin >> n;
        int mat[n + 1][n + 1];
        int r = 0, c = 0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                cin >> mat[i][j];
            }
        }
        
        for (int i=1;i<=n;i++){
            int cnt[n + 1];
            fill(cnt, cnt + n + 1, 0);
            for (int j=1;j<=n;j++){
                if (++cnt[mat[i][j]] > 1){
                    r++;
                    break;
                }
            }
        }
        for (int i=1;i<=n;i++){
            int cnt[n + 1];
            fill(cnt, cnt + n + 1, 0);
            for (int j=1;j<=n;j++){
                if (++cnt[mat[j][i]] > 1){
                    c++;
                    break;
                }
            }
        }
        ll trace = 0;
        for (int i=1;i<=n;i++){
            trace += (ll)mat[i][i];
        }
        cout << "Case #" << cas << ": " << trace << " " << r << " " << c << el;
    }

    return 0;
}