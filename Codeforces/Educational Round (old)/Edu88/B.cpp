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

const int N = 110, M = 1e3 + 10;

int q;
int n, m, x, y;
string ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        int ans = 0;
        cin >> n >> m >> x >> y;
        if (y > x + x) y = x + x;

        for (int i=1;i<=n;i++){
            cin >> ar[i];
            ar[i] = "*" + ar[i];
            char bef = '*';
            int cnt = 0;
            for (int j=1;j<=m;j++){
                if (bef == ar[i][j]){
                    cnt++;
                } else{
                    if (bef == '.'){
                        ans += (cnt / 2) * y + (cnt & 1) * x;
                    }
                    bef = ar[i][j];
                    cnt = 1;
                }
            }
            if (bef == '.'){
                ans += (cnt / 2) * y + (cnt & 1) * x;
            }
        }
        cout << ans << el;
    }

    return 0;
}