// #include <bits/stdc++.h>


// #define fi first
// #define se second
// #define pb(a) push_back(a)
// #define mp(a, b) make_pair(a, b)
// #define el '\n'

// using namespace std;
// using ll = long long;
// using pii = pair<int, int>;

// const int N = 1e5 + 10;

// int n, m, k;
// pii ar[N];
// pair<int, pii> ans[N];

// int main () {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n >> m >> k;
//     for (int i=1;i<=k;i++){
//         cin >> ar[i].fi;
//         ar[i].se = i;
//     }
//     sort(ar + 1, ar + k + 1);
//     int last = 0;
//     int rr = 0;
//     for (int i=1;i<=k;i++){
//         int sisa = k - i;
//         int slot = m - last - ar[i].fi;
//         if (slot >= 0){
//             int gmsk = sisa - slot;
//             if (gmsk > 2 && rr == n - 1){
//                 for (int j=i;j<=k;j++){
//                     if (last >= m) ans[ar[j].se] = {rr, mp(-1, -1)};
//                     else ans[ar[j].se] = {rr, mp(last, last + 1)};
//                     last++;
//                 }
//                 break;
//             } else if (gmsk > 2){
//                 rr++;
//                 i--;
//                 last = 0;
//                 continue;
//             }
//         } else if (rr == n - 1){
//             for (int j=i;j<=k;j++){
//                 if (last >= m) ans[ar[j].se] = {rr, mp(-1, -1)};
//                 else ans[ar[j].se] = {rr, mp(last, last + 1)};
//                 last++;
//             }
//             break;
//         } else{
//             rr++;
//             i--;
//             last = 0;
//             continue;
//         }
//         ans[ar[i].se] = {rr, mp(last, last + ar[i].fi)};
//         last += ar[i].fi;
//     }
//     for (int i=1;i<=k;i++){
//         if (ans[i].se.fi == ans[i].se.se) cout << -1 << " " << -1 << " " << -1 << " " << -1 << el;
//         else{
//             cout << ans[i].fi << " " << ans[i].fi + 1 << " " << ans[i].se.fi << " " << ans[i].se.se << el;
//         }
//     }

//     return 0;
// }
// // #include <bits/stdc++.h>


// // #define fi first
// // #define se second
// // #define pb(a) push_back(a)
// // #define mp(a, b) make_pair(a, b)
// // #define el '\n'

// // using namespace std;
// // using ll = long long;
// // using pii = pair<int, int>;

// // const int N = 1e5 + 10;

// // int n, m, k;
// // int ar[N];

// // pii ans[N];

// // int main () {
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(0);
// //     cout.tie(0);

// //     cin >> n >> m >> k;
// //     for (int i=1;i<=k;i++){
// //         cin >> ar[i];
// //     }
// //     pii cur = mp(0, 0);
// //     for (int i=1;i<=k;i++){
// //         ans[i] = cur;
// //         cur.fi++;
// //         if (cur.fi == n){
// //             cur.fi = 0;
// //             cur.se++;
// //         }
// //     }
// //     for (int i=1;i<=k;i++){
// //         if (ans[i].fi >= n || ans[i].se >= m){
// //             cout << "-1 -1 -1 -1" << el;
// //         } else{
// //             cout << ans[i].fi << " " << ans[i].fi + 1 << " " << ans[i].se << " " << ans[i].se + 1 << el;
// //         }
// //     }

// //     return 0;
// // }
// // #include <bits/stdc++.h>


// // #define fi first
// // #define se second
// // #define pb(a) push_back(a)
// // #define mp(a, b) make_pair(a, b)
// // #define el '\n'

// // using namespace std;
// // using ll = long long;
// // using pii = pair<int, int>;

// // const int N = 1e5 + 10;

// // int n, m, k;

// // int main () {
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(0);
// //     cout.tie(0);

// //     cin >> n >> m >> k;
// //     for (int i=1;i<=k;i++){
// //         cout << i - 1 << " " << i << " " << 0 << " " << m << el;
// //     }    

// //     return 0;
// // }

// #include <bits/stdc++.h>


// #define fi first
// #define se second
// #define pb(a) push_back(a)
// #define mp(a, b) make_pair(a, b)
// #define el '\n'

// using namespace std;
// using ll = long long;
// using pii = pair<int, int>;

// const int N = 1e5 + 10;

// int n, m, k;
// pii ar[N];
// pair<int, pii> ans[N];

// int main () {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n >> m >> k;
//     swap(n, m);
//     for (int i=1;i<=k;i++){
//         cin >> ar[i].fi;
//         ar[i].se = i;
//     }
//     sort(ar + 1, ar + k + 1);
//     int last = 0;
//     int rr = 0;
//     for (int i=1;i<=k;i++){
//         int sisa = k - i;
//         int slot = m - last - ar[i].fi;
//         if (slot >= 0){
//             int gmsk = sisa - slot;
//             if (gmsk > 2 && rr == n - 1){
//                 for (int j=i;j<=k;j++){
//                     if (last >= m) ans[ar[j].se] = {rr, mp(-1, -1)};
//                     else ans[ar[j].se] = {rr, mp(last, last + 1)};
//                     last++;
//                 }
//                 break;
//             } else if (gmsk > 2){
//                 rr++;
//                 i--;
//                 last = 0;
//                 continue;
//             }
//         } else if (rr == n - 1){
//             for (int j=i;j<=k;j++){
//                 if (last >= m) ans[ar[j].se] = {rr, mp(-1, -1)};
//                 else ans[ar[j].se] = {rr, mp(last, last + 1)};
//                 last++;
//             }
//             break;
//         } else{
//             rr++;
//             i--;
//             last = 0;
//             continue;
//         }
//         ans[ar[i].se] = {rr, mp(last, last + ar[i].fi)};
//         last += ar[i].fi;
//     }
//     for (int i=1;i<=k;i++){
//         if (ans[i].se.fi == ans[i].se.se) cout << -1 << " " << -1 << " " << -1 << " " << -1 << el;
//         else{
//             cout << ans[i].se.fi << " " << ans[i].se.se << " " << ans[i].fi << " " << ans[i].fi + 1 << el;
//         }
//     }

//     return 0;
// }

// #include <bits/stdc++.h>


// #define fi first
// #define se second
// #define pb(a) push_back(a)
// #define mp(a, b) make_pair(a, b)
// #define el '\n'

// using namespace std;
// using ll = long long;
// using pii = pair<int, int>;

// const int N = 1e5 + 10;
// const int A = 9973;
// const int B = 99991;

// int n, m, k;
// int ar[N];

// pii ans[N];

// int main () {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n >> m >> k;
//     for (int i=1;i<=k;i++){
//         cin >> ar[i];
//     }
//     int a = 0, b = 0;
//     for (int i=1;i<=k;i++){
//         ans[i] = mp(a, b);
//         a += A;
//         if (a == n){
//             a = 0;
//             b += B;
//         }
//     }
//     for (int i=1;i<=k;i++){
//         cout << ans[i].fi << " " << ans[i].fi + A << " " << ans[i].se << " " << ans[i].se + B << el;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>


// #define fi first
// #define se second
// #define pb(a) push_back(a)
// #define mp(a, b) make_pair(a, b)
// #define el '\n'

// using namespace std;
// using ll = long long;
// using pii = pair<int, int>;

// const int INF = 1e9;

// pii aw[10], ak[10];

// int main () {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     for (int i=1;i<=10;i++){
//         aw[i] = mp(INF, INF);
//         ak[i] = mp(-1, -1);
//     }

//     for (int i=1;i<=5;i++){
//         string s;
//         cin >> s;
//         for (int j=1;j<=5;j++){
//             int dig = s[j - 1] - '0';
//             aw[dig] = min(aw[dig], mp(j, i));
//             ak[dig] = max(ak[dig], mp(j, i));
//         }
//     }
//     for (int i=1;i<=5;i++){
//         cout << aw[i].fi - 1 << " " << ak[i].fi << " " << aw[i].se - 1 << " " << ak[i].se << el;
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

const int N = 1e5 + 10;

int n, m, k;
int ar[N];

pair<pii, pii> ans[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1;i<=k;i++){
        cin >> ar[i];
    }
    ans[k] = {{0, n}, {m - 1, m}};
    for (int i=1;i<k - i;i++){
        ans[i] = {{0, i}, {i - 1, i}};
        ans[k - i] = {{i, n}, {i - 1, i}};
    }
    for (int i=1;i<=k;i++){
        cout << ans[i].fi.fi << " " << ans[i].fi.se << " " << ans[i].se.fi << " " << ans[i].se.se << el; 
    }

    return 0;
}