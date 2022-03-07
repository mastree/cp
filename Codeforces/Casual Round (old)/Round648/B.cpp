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

const int N = 510;

int q;
int n;
int a[N], b[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> a[i];
        }
        int c1 = 0 , c0 = 0;
        for (int i=1;i<=n;i++){
            cin >> b[i];
            if (b[i]) c1++;
            else c0++;
        }
        if (c0 && c1){
            cout << "YES" << el;
        } else{
            bool ok = 1;
            for (int i=1;i<n;i++){
                if (a[i] > a[i + 1]){
                    ok = 0;
                    break;
                }
            }
            if (ok){
                cout << "YES" << el;
            } else{
                cout << "NO" << el;
            }
        }
    }

    return 0;
}