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

const int N = 5e2 + 10;

int q;
int n;
int ar[N], br[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        for (int i=1;i<=n;i++){
            cin >> br[i];
        }
        if (n & 1){
            int pos = (n + 1) / 2;
            if (ar[pos] != br[pos]){
                cout << "NO" << el;
                continue;
            }
        }
        map<pii, int> cek;
        int hn = n / 2;
        for (int i=1;i<=hn;i++){
            int a, b;
            a = min(ar[i], ar[n - i + 1]);
            b = max(ar[i], ar[n - i + 1]);
            cek[mp(a, b)]++;
            a = min(br[i], br[n - i + 1]);
            b = max(br[i], br[n - i + 1]);
            cek[mp(a, b)]--;
        }
        bool bisa = 1;
        for (auto x : cek){
            if (x.se){
                bisa = 0;
                break;
            }
        }
        if (bisa){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}