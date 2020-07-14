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

const int M = 1e3 + 10, N = 12;

int n, m, k;

int ar[N][M];

int hitung(int r1, int c1, int r2, int c2){
    r1--;
    c1--;
    return ar[r2][c2] - ar[r1][c2] - ar[r2][c1] + ar[r1][c1];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        for (int j=0;j<m;j++){
            int dig = (s[j] == '1');
            ar[i][j + 1] = dig; 
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            ar[i][j] = ar[i - 1][j] + ar[i][j - 1] - ar[i - 1][j - 1] + ar[i][j];
            // cout << ar[i][j] << " ";
        }
        // cout << el;
    }

    if (ar[n][m] <= k){
        cout << 0 << el;
        return 0;
    }

    int ans = MOD;
    for (int mask=0;mask<(1 << (n - 1));mask++){
        vector <int> bates;
        int cur = 0;
        bates.pb(0);
        for (int i=0;i<n-1;i++){
            if (mask & (1 << i)){
                cur++;
                bates.pb(i + 1);
            }
        }
        bates.pb(n);

        int last = 0;
        int len = bates.size();
        bool bisa = 1;

        // cout << mask << "=>" << el;
        for (int i=1;i<=m;i++){
            bool buat = 0;
            for (int j=0;j<len - 1;j++){
                int a = bates[j], b = bates[j + 1];
                
                // cout << a + 1 << " " << last + 1 << " " << b << " " << i << " => " << hitung(a + 1, last + 1, b, i) << el; 

                if (hitung(a + 1, last + 1, b, i) <= k) continue;
                else if (hitung(a + 1, i, b, i) > k){
                    bisa = 0;
                }
                else{
                    buat = 1;
                }
            }
            if (!bisa) break;

            if (buat && last == i - 1){
                bisa = 0;
                break;
            } else if (buat){
                // cout << i << " ";
                last = i - 1;
                cur++;
            }
        }
        // cout << el;

        if (bisa){
            if (cur < ans){
                // cout << cur << " " << mask << el;
                ans = cur;
            }
        } 
    }

    cout << ans << el;

    return 0;
}