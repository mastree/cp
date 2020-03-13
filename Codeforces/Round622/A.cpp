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

int t;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--){
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        int ans = 0;
        sort(a, a + 3, greater<int>());

        for (int cnt=1;cnt<=3;cnt++){
            for (int i=1;i<(1 << 3);i++){
                int temp = 0;
                for (int j=0;j<3;j++){
                    if (i&(1 << j)) temp++;
                }
                if (temp != cnt) continue;
                bool bisa = 1;
                for (int j=0;j<3;j++){
                    if (i&(1 << j)){
                        if (a[j] <= 0){
                            bisa = 0;
                        }
                    }
                }
                if (bisa){
                    ans++;
                    for (int j=0;j<3;j++){
                        if (i&(1 << j)){
                            a[j]--;
                        }
                    }
                }
            }
        }
        cout << ans << el;
    }

    return 0;
}