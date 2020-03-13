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

const int N = 1e5 + 9;

int n, k;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    if (k>n/2){
        cout << -1 << el;
        return 0;
    }

    if (k == 0){
        for (int i=1;i<n;i++){
            cout << i << " ";
        }
        cout << n << el;
        return 0;
    }

    if (n % k != 0 || ((n/k) % 2 == 1)){
        cout << -1 << el;
        return 0;
    }

    bool depan = 1;

    for (int i=1;i<=n;i++){
        if (depan){
            ar[i+k] = i;
        } else{
            ar[i-k] = i;
        }

        if (i % k == 0){
            depan = !depan;
        }
    }

    for (int i=1;i<n;i++){
        cout << ar[i] << " ";
    }

    cout << ar[n] << el;

    return 0;
}