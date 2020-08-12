#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>; // in deg, val, node

piii mp3(const int& a, const int& b, const int& c){
    return mp(mp(a, b), c);
}

const int N = 2e5 + 10;

int n;
int tar[N];
ll ans = 0;

bool udh[N];
ll ar[N]; // val
int in[N]; // in degree
vector<int> to[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        cin >> tar[i];
        if (tar[i] > 0){
            in[tar[i]]++;
            to[tar[i]].pb(i);
        }
    }

    // set<pii> setdah; // in, id
    // for (int i=1;i<=n;i++){
    //     setdah.insert(mp(in[i], i));
    // }

    vector<int> v;
    // while (!setdah.empty()){
    //     auto tp = *setdah.begin();
    //     setdah.erase(tp);
    //     if (ar[tp.se] < 0 && tar[tp.se] != -1){
    //         int nnode = tar[tp.se];

    //         in[nnode]--;
    //         if (!udh[nnode]){
    //             setdah.erase(mp(in[nnode], nnode));
    //         }
    //         if (!udh[nnode] && ar[nnode] >= 0){
    //             setdah.insert(mp(in[nnode], nnode));
    //         }
    //         continue;
    //     }

    //     v.pb(tp.se);

    //     int nnode = tar[tp.se];
    //     if (nnode == -1){
    //         udh[tp.se] = 1;
    //         ans += ar[tp.se];
    //         continue;
    //     }

    //     if (!udh[nnode]){
    //         setdah.erase(mp(in[nnode], nnode));
    //     }

    //     udh[tp.se] = 1;
    //     ans += ar[tp.se];
    //     ar[nnode] += ar[tp.se];
    //     in[nnode]--;

    //     if (!udh[nnode] && ar[nnode] >= 0){
    //         setdah.insert(mp(in[nnode], nnode));
    //     }
    // }
    // for (int i=1;i<=n;i++){
    //     if (!udh[i]){
    //         setdah.insert(mp(-in[i], i));
    //     }
    // }
    // while (!setdah.empty()){
    //     auto tp = *setdah.begin();
    //     setdah.erase(tp);
    //     v.pb(tp.se);

    //     int nnode = tar[tp.se];
    //     if (nnode == -1){
    //         udh[tp.se] = 1;
    //         ans += ar[tp.se];
    //         continue;
    //     }

    //     if (!udh[nnode]){
    //         setdah.erase(mp(-in[nnode], nnode));
    //     }

    //     udh[tp.se] = 1;
    //     ans += ar[tp.se];
    //     ar[nnode] += ar[tp.se];
    //     in[nnode]--;

    //     if (!udh[nnode]){
    //         setdah.insert(mp(-in[nnode], nnode));
    //     }
    // }
    queue<int> qu;
    for (int i=1;i<=n;i++){
        if (in[i] == 0){
            qu.push(i);
        }
    }
    while (!qu.empty()){
        int tp = qu.front();
        int nex = tar[tp];
        qu.pop();

        if (ar[tp] >= 0){
            ans += ar[tp];
            udh[tp] = 1;
            v.pb(tp);
            if (nex > 0){
                ar[nex] += ar[tp];
            }
        }
        if (nex > 0){
            in[nex]--;
            if (in[nex] == 0){
                qu.push(nex);
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (!udh[i] && (tar[i] == -1 || udh[tar[i]])){
            qu.push(i);
        }
    }
    while (!qu.empty()){
        int tp = qu.front();
        int nex = tar[tp];
        qu.pop();

        ans += ar[tp];
        udh[tp] = 1;
        v.pb(tp);

        for (auto x : to[tp]){
            if (!udh[x]){
                qu.push(x);
            }
        }
    }

    cout << ans << el;
    for (auto x : v){
        cout << x << " ";
    }
    cout << el;

    return 0;
}