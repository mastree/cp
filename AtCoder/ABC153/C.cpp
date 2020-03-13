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

const int N = 2e5 + 10;

int n, k;
int ar[N];
ll t;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> ar[i];
    }
    if (k>=n){
        cout << 0 << el;
        return 0;
    }

    sort(ar, ar + n, greater<int>());
    for (int i=k;i<n;i++){
        t+=(ll)ar[i];
    }
    cout << t << el;

    return 0;
}