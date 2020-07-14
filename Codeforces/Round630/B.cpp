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

const int N = 1e3 + 10;

int q;

int n;
int ar[N];
int ans[N];

bool isPrime[1010];
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(isPrime, isPrime + 1001, 1);
    isPrime[1] = 0;
    for (int i=2;i * i<=1000;i++){
        if (!isPrime[i]) continue;
        for (int j=i * i;j<=1000;j+=i){
            isPrime[j] = 0;
        }
    }

    int cnt = 0;
    for (int i=1;i * i<=1000;i++){
        if (isPrime[i]){
            v.pb(i);
        }
    }

    cin >> q;
    while (q--){
        map <int, int> col; 
        int last = 0;
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            for (auto x : v){
                if (ar[i] % x == 0){
                    if (col[x] == 0){
                        col[x] = ++last;
                    }
                    ans[i] = col[x];
                    break;
                }
            }
        }

        cout << last << el;
        for (int i=1;i<=n;i++){
            cout << ans[i] << " ";
        }
        cout << el;

    }

    return 0;
}