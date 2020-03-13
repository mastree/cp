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

const int N = 1e5 + 9;

int q;
ll ar[N], pc[N], s;
int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> s;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }

        pc[0] = 0;
        for (int i=1;i<=n;i++){
            pc[i] = pc[i-1] + ar[i];
        }

        int ans = 0;
        int tot = 0;
        for (int i=0;i<=n;i++){
            int low = 0, high = n;
            // int best = 0;
            while (low < high){
                int mid = (low + high + 1) / 2;

                ll now = pc[mid];
                if (i <= mid){
                    now -= ar[i];
                }

                if (now <= s){
                    // best = now;
                    low = mid;
                } else{
                    high = mid - 1;
                }
            }

            if (low >= i) low--;
            if (tot < low){
                tot = low;
                ans = i;
            }
        }

        cout << ans << el;

    }


    return 0;
}