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

const int N = 4e5 + 10;

int q, x;
int y;
int cnt[N];
int lap = 1, id = 0;
// priority_queue<pii, vector<pii>, greater<pii>> pq;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q >> x;
    // for (int i=0;i<x;i++){
    //     pq.push(mp(0, x-i));
    // }
    while (q--){
        int a;
        cin >> a;
        a %= x;
        cnt[a]++;

        while (cnt[id] >= lap){
            if (id == x-1){
                lap++;
                id = 0;
            } else{
                id++;
            }
        }

        cout << (lap-1) * x + id << el;

        // pii atas;
        // atas = pq.top();
        // atas.se = x - atas.se;
        // while (cnt[atas.se] != pq.top().fi){
        //     pq.pop();
        //     pq.push(mp(atas.fi, x - atas.se));
        //     atas = pq.top();
        //     atas.se = x - atas.se;
        // }

        // if (atas.fi == 0){
        //     cout << 0 << el;
        // }
    }

    return 0;
}