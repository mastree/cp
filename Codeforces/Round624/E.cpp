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
int n, d;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> d;

        int mx = n * (n-1) / 2;

        if (mx < d){
            cout << "NO" << el;
            continue;
        }
        int low = 0, high = n-1;
        while (low < high){
            int mid = (low + high + 1) / 2;

            if (mid * (mid + 1) / 2 > d){
                high = mid - 1;
            } else{
                low = mid;
            }
        }
        int dep = low;
        int ar[dep + 3];
        fill(ar, ar + dep + 1, 1);
        int sisa = d - dep * (dep + 1) / 2;
        if (sisa){
            for (int ul=0;ul<=dep;ul++){
                for (int i=dep;i>0;i--){
                    if (ar[dep] < ar[dep-1] * 2){
                        if (sisa > dep)
                    }
                }
            }
        }
    }

    return 0;
}