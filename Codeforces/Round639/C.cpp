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

const int N = 2e5 + 10;

int q, n;
// ll ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        bool ada[n];
        fill(ada, ada + n, 0);
        for (int i=0;i<n;i++){
            ll a;
            cin >> a;
            a %= n;
            a = (a + i + n + n) % n;
            ada[a] = 1;
        }
        bool bisa = 1;
        for (int i=0;i<n;i++){
            if (ada[i] == 0) bisa = 0;
        }
        if (bisa){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}