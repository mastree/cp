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

const int N = 200;

int n, k;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    int cur = 0;
    for (int i=1;i<=n;i++){
        cur += ar[i];
        int kurang = min(8, cur);
        k -= kurang;
        cur -= kurang;
        if (k <= 0){
            cout << i << el;
            return 0;
        }
    }
    cout << -1 << el;

    return 0;
}