#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e5 + 10;
const int INF = 1e9 + 10;

int n;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(INF);
    ll tot = 0;
    for (int i=1;i<=n;i++){
        pq.push(ar[i]);
        if (pq.top() < ar[i]){
            tot += ar[i] - pq.top();
            pq.pop();
            pq.push(ar[i]);
        } 
    }
    cout << tot << el;

    return 0;
}