// #include <bits/stdc++.h>


// #define fi first
// #define se second
// #define pb(a) push_back(a)
// #define mp(a, b) make_pair(a, b)
// #define el '\n'

// using namespace std;
// using ll = long long;
// using pii = pair<int, int>;

// const int N = 2e5 + 10;

// int n, d;
// unordered_map<int, int> r, c;
// vector<int> v;

// int main () {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n >> d;
//     int ans = d;
//     v.pb(1);
//     for (int i=1;i<=n;i++){
//         int pos;
//         cin >> pos >> r[pos] >> c[pos];
//         if (pos != 1) v.pb(pos);
//     }
//     v.pb(d + 1);
//     int awal = 0;
//     int cur = 0;

//     int len = v.size();
//     for (int i=0;i<len - 1;i++){
//         int but = v[i + 1] - v[i];
//         if (but == 0) continue;
//         if (c[v[i]] == 0){
//             if (cur < but){
//                 awal += but - cur;
//                 cur = but;
//             }
//             cur -= but;
//         } else{
//             int sblm = cur;
//             cur = max(cur, min(cur, r[v[i]]) + c[v[i]]);
//             if (cur < but){
//                 awal += but - cur;
//                 cur = but;
//             }
//             cur -= but;
//         }
//     }
//     bool ok = 1;
//     int a = awal, b = awal;
//     for (int i=0;i<len - 1;i++){
//         int but = v[i + 1] - v[i];
//         if (but == 0) continue;
//         if (c[v[i]] == 0){
//             if (b < but){
//                 ok = 0;
//                 break;
//             }
//             b -= but;
//             a = max(a - but, 0);
//         } else{
//             if (a <= r[v[i]] && r[v[i]] < b){
//                 b = max(b, r[v[i]] + c[v[i]]);
//             } else if (a <= r[v[i]]){
//                 b = b + c[v[i]];
//             }
//             if (b < but){
//                 ok = 0;
//                 break;
//             }
//             b -= but;
//             a = max(a - but, 0);
//         }
//     }
//     if (ok) ans = min(ans, awal);
//     cout << ans << el;

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

int n, d;
unordered_map<int, int> r, c;
vector<int> v;
vector<pii> range;

pii iris(pii a, pii b){
    if (a > b) swap(a, b);
    return mp(b.fi, min(a.se, b.se));
}
pii gabung(pii a, pii b){
    return mp(min(a.fi, b.fi), max(a.se, b.se));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;
    int ans = d;
    v.pb(1);
    for (int i=1;i<=n;i++){
        int pos;
        cin >> pos >> r[pos] >> c[pos];
        if (pos != 1) v.pb(pos);
    }
    v.pb(d + 1);

    int len = v.size();
    for (int i=len - 2;i>=0;i--){
        int dif = v[i + 1] - v[i];
        vector<pii> nx;
        {
            pii temp = mp(dif, d);
            pii temp2;

            int coba = max(dif - c[v[i]], 0);
            if (coba <= r[v[i]]){
                temp2 = mp(coba, r[v[i]]);
                pii temp3 = iris(temp, temp2);
                if (temp3.fi <= temp3.se){
                    nx.pb(gabung(temp, temp2));
                } else{
                    nx.pb(temp2);
                    nx.pb(temp);
                }
            } else nx.pb(temp);
        }
        if (range.empty()){
            for (auto x : nx){
                range.pb(x);
            }
        } else{
            vector<pii> nrange;
            for (auto xx : range){
                auto x = xx;
                x.fi += dif;
                x.se += dif;
                if (x.fi - c[v[i]] <= r[v[i]]) x.fi = max(x.fi - c[v[i]], 0);
                for (auto y : nx){
                    pii temp = iris(x, y);
                    if (temp.fi <= temp.se){
                        nrange.pb(temp);
                    }
                }
            }
            sort(nrange.begin(), nrange.end());
            range.clear();
            for (auto x : nrange){
                if (range.empty()){
                    range.pb(x);
                } else{
                    pii temp = iris(range.back(), x);
                    if (temp.fi <= temp.se){
                        range.back() = gabung(range.back(), x);
                    } else{
                        range.pb(x);
                    }
                }
            }
        }
    }
    cout << range[0].fi << el;

    return 0;
}