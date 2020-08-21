#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10, M = 30;

int q;
int n;
int ar[N];

int cnt[M];

void solve(){
    cin >> n;
    for (int i=0;i<M;i++){
        cnt[i] = 0;
    }

    int cnt0 = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];   
        if (ar[i] == 0) cnt0++;
    }
    int temp = 0;
    for (int i=1;i<=n;i++){
        temp ^= ar[i];
    }
    if (temp == 0){
        cout << "DRAW" << el;
        return;
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<M;j++){
            if (ar[i] & (1 << j)){
                cnt[j]++;
            }
        }
    }
    for (int i=M - 1;i>=0;i--){
        if (cnt[i] & 1){
            if (cnt[i] % 4 == 1){
                cout << "WIN" << el;
                return;
            } else{
                if ((n - cnt[i]) & 1){
                    cout << "WIN" << el;
                } else{
                    cout << "LOSE" << el;
                }
                return;
            }
        }
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