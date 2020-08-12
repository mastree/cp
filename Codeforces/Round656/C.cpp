#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int q;
int n, ar[N];

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
        bool stat = 0;
        int cnt = 1;
        for (int i=n - 1;i>=1;i--){
            if (!stat){
                if (ar[i + 1] <= ar[i]) cnt++;
                else{
                    cnt++;
                    stat = 1;
                }
            } else{
                if (ar[i + 1] < ar[i]) break;
                cnt++;
            }
        }
        cout << n - cnt << el;
    }

    return 0;
}