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

typedef pair<ll, ll> pll;

const int N = 1e5 + 10;

int n, m;
ll ar[N], cost[N];
// ll t[N], d[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    priority_queue<pli, vector<pli>, greater<pli>> pq; // cost, id;
    for (int i=1;i<=n;i++){
        cin >> cost[i];
        pq.push(mp(cost[i], i));
    }
    ll t, d;
    for (int i=1;i<=m;i++){
        cin >> t >> d;
        ll harga = 0;
        ll cur = d;
        if (ar[t] >= cur){
            ar[t] -= cur;
            harga = cost[t] * cur;
        } else{
            harga = ar[t] * cost[t];
            cur -= ar[t];
            ar[t] = 0;
            while (cur && !pq.empty()){
                auto temp = pq.top();
                if (ar[temp.se] <= 0){
                    pq.pop();
                    continue;
                }
                ll kurang = min(ar[temp.se], cur);
                cur -= kurang;
                ar[temp.se] -= kurang;
                harga += kurang * cost[temp.se];
            }
            if (cur > 0){
                harga = 0;
            }
        }
        cout << harga << el;
    }


    return 0;
}