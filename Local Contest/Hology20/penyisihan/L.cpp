#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int n, k, l;
int len;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> l;
    len = n * k;
    for (int i=1;i<=len;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + 1 + len);
    int bat = ar[1] + l;
    int byk = 0;
    for (int i=1;i<=len;i++){
        if (ar[i] <= bat){
            byk++;
        } else break;
    }
    if (byk < n){
        cout << 0 << el;
        return 0;
    }
    ll ans = 0;
    int sisa = n;

    int kan = len - byk;
    for (int i=byk;i>=1&&sisa>0;i--){
        if (kan >= k - 1){
            ans += ar[i];
            kan -= k - 1;
            sisa--;
        } else{
            kan++;
        }
    }
    cout << ans << el;

    return 0;
}