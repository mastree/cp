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

const int N = 8e3 + 5;

int q;
int n, ar[N], pc[N];

bitset <65000000> bset;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        pc[0] = 0;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            pc[i] = pc[i - 1] + ar[i];
        }

        for (int i=1;i<n;i++){
            for (int j=i+1;j<=n;j++){
                bset[pc[j] - pc[i - 1]] = 1;
            }
        }
        int ans = 0;
        for (int i=1;i<=n;i++){
            if (bset[ar[i]]) ans++;
        }
        for (int i=1;i<n;i++){
            for (int j=i+1;j<=n;j++){
                bset[pc[j] - pc[i - 1]] = 0;
            }
        }
        cout << ans << el;
    }

    return 0;
}