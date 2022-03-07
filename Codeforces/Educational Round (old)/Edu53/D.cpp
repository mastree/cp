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

int n;
ll t;
ll ar[N];

priority_queue<pair<ll, int>> pq;

ll bit[N];
int bit2[N];

void update(int x, ll val){
    while (x < N){
        bit[x] += val;
        if (val >= 0){
            bit2[x]++;
        } else{
            bit2[x]--;
        }
        x = x + (x & (-x));
    }
}

ll ask(int a){
    ll ret = 0;
    while (a > 0){
        ret += bit[a];
        a = a - (a & (-a));
    }   
    return ret;
}
int ask2(int a){
    ll ret = 0;
    while (a > 0){
        ret += bit2[a];
        a = a - (a & (-a));
    }   
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        tot.fi += ar[i];
        tot.se++;
        update(i, ar[i]);
    }  
    ll ans = 0;
    while (t && tot.se){// && !pq.empty()){
        if (t >= tot.fi){
            ans += tot.se * (t / tot.fi);
            t %= tot.fi;
        }
        if (t < tot.fi){
            int bawah = 0;
            while (tot.se){
                int low = bawah, high = n;
                while (low < high){
                    int mid = (low + high + 1) / 2;
                    if (ask(mid) - ask(bawah - 1) <= t){
                        low = mid;
                    } else{
                        high = mid - 1;
                    }
                }
                ll temptot = ask(low) - ask(bawah - 1);
                t -= temptot;
                ans += ask2(low) - ask2(bawah - 1);
                if (low == n) break;
                update(low + 1, -ar[low + 1]);
                tot.fi -= ar[low + 1];
                tot.se--;
                bawah = low + 1;
            }
        }
    }
    cout << ans << el;

    return 0;
}