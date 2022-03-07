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
    while (q--){
        int n, m;
        cin >> n >> m;

        int ar[n+10];
        bool p[n+10];
        fill(p, p+n+10, 0);

        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        for (int i=1;i<=m;i++){
            int a;
            cin >> a;
            p[a] = 1;
        }

        bool bisa = 1;
        for (int i=1;i<=n;i++){
            // int temp[n + 10];
            // for (int j=0;j<n+10;j++){
            //     temp[i] = ar[i];
            // }
            for (int j=1;j<n;j++){
                if (ar[j] > ar[j + 1]){
                    if (p[j]){
                        swap(ar[j], ar[j + 1]);
                    } else{
                        bisa = 0;
                        break;
                    }
                }
            }

            if (bisa == 0) break;
        }
        if (bisa){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}