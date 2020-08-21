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

const int N = 1e6 + 10;
const int M = 23;

int n;
int ar[N];
int cnt[(1 << M)];
vector<int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        if (cnt[ar[i]] == 0){
            cnt[ar[i]] = i;
            v.pb(ar[i]);
        }
    }
    for (int i=1;i<(1 << M);i++){
        if (cnt[i]) continue;
        for (int j=0;j<23;j++){
            int bit = (1 << j);
            if (i & bit){
                if (cnt[i - bit]){
                    cnt[i] = cnt[i - bit];
                    break;
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        unsigned temp = ~ar[i];
        temp = temp % (1 << 22);
        int ans = cnt[temp];
        if (ans){
            cout << ar[ans] << " ";
        } else{
            cout << -1 << " ";
        }
    }
    cout << el;

    return 0;
}