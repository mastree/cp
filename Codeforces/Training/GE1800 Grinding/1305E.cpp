#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e3 + 10;

int n, m;
vector<int> ar;
int mx;

int cnt[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cnt[i] = (i - 1) / 2;
        mx += (i - 1) / 2;
    }
    if (m > mx){
        cout << -1 << el;
        return 0;
    }
    
    int sisa = m;
    for (int i=1;i<=n;i++){
        if (sisa > cnt[i]){
            sisa -= cnt[i];
            ar.pb(i);
        } else{
            int ni = i;
            while (sisa < cnt[i]){
                ni += 2;
                cnt[i]--;
            }
            ar.pb(ni);
            break;
        }
    }
    for (int i=0;i<(int)ar.size();i++) ar[i] <<= 1; 
    int del = 20000;
    while ((int)ar.size() < n){
        if (ar.back() & 1){
            ar.pb(ar.back() + del);
        } else{
            ar.pb(ar.back() + del + 1);
        }
    }
    for (auto x : ar){
        cout << x << " ";
    }
    cout << el;

    return 0;
}