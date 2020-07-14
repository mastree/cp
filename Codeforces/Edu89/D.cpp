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

const int N = 5e5 + 10;
const int M = 1e7;

int n;
int ar[N];
int fac[M + 10];
pii ans[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=2;i * i<=M;i++){
        if (fac[i]) continue;
        for (int j=i * i;j<=M;j+=i){
            fac[j] = i;
        }
    }
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        int a = fac[ar[i]], b;
        if (a <= 1){
            ans[i] = mp(-1, -1);
            continue;
        }
        int temp = ar[i];
        while (temp % a == 0){
            temp /= a;
        }
        a = ar[i] / temp;
        b = temp;
        if (a == 1 || b == 1){
            ans[i] = mp(-1, -1);
            continue;
        }
        ans[i] = mp(a, b);
    }
    for (int i=1;i<=n;i++){
        cout << ans[i].fi << " ";
    }
    cout << el;
    for (int i=1;i<=n;i++){
        cout << ans[i].se << " ";
    }
    cout << el;

    return 0;
}