// #include <bits/stdc++.h>


// #define fi first
// #define se second
// #define pb push_back
// #define mp make_pair
// #define MOD 1000000007
// #define pii pair<int,int>
// #define pli pair<long long,int>
// #define pil pair<int,long long>
// #define ll long long
// #define el '\n'

// using namespace std;

// const int N = 2e5 + 10;

// int q, n;
// // ll ar[N];

// int main () {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> q;
//     while (q--){
//         cin >> n;
//         bool ada[n];
//         fill(ada, ada + n, 0);
//         for (int i=0;i<n;i++){
//             ll a;
//             cin >> a;
//             a %= n;
//             a = (a + i + n + n) % n;
//             ada[a] = 1;
//         }
//         bool bisa = 1;
//         for (int i=0;i<n;i++){
//             if (ada[i] == 0) bisa = 0;
//         }
//         if (bisa){
//             cout << "YES" << el;
//         } else{
//             cout << "NO" << el;
//         }
//     }

//     return 0;
// }

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

int q, n;
bool ada[N];

void solve(){
    cin >> n;
    fill(ada, ada + n + 2, 0);
    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        ada[((i + a) % n + n) % n] = 1;
    }
    bool ok = 1;
    for (int i=0;i<n;i++){
        if (!ada[i]){
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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}