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

const int N = 5e5 + 10;
const int SN = (int)sqrt(N) - 50;

int q;
int cnt[SN + 10][SN + 10];
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        int tipe;
        int x, y;
        cin >> tipe >> x >> y;
        if (tipe == 1){
            ar[x] += y;
            for (int i=1;i<=SN;i++){
                cnt[i][x % i] += y;
            }
        } else{
            if (x > SN){
                int ans = 0;
                for (int i=y;i<N;i+=x){
                    ans += ar[i];
                }
                cout << ans << el;
            } else{
                cout << cnt[x][y] << el;
            }
        }
    }

    return 0;
}