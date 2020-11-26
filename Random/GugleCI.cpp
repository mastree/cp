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

int n;
int ar[N]; // asumsi 1 <= ari < N, jika tidak tinggal di kompres

int cnt1 = 0;
int cnt[N];

bool solve(int l, int r){
    if (cnt1 == 0) return 0;
    int pos = -1;
    for (int i=l;i<=r;i++){
        if (cnt[ar[i]] == 1){
            pos = i;
            break;
        }
    }
    assert(pos != -1);
    int cnt12 = 0;
    unordered_map<int, int> cnt2;
    for (int i=l;i<=pos;i++){
        cnt[ar[i]]--;
        if (cnt[ar[i]] == 1) cnt1++;
        else cnt1--;

        if (i <= pos){
            
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        cnt[ar[i]]++;
        if (cnt[ar[i]] == 1) cnt1++;
        else cnt1--;
    }
    if (!cnt1){
        cout << "NO" << el;
        return 0;
    }
    solve(1, n);

    return 0;
}