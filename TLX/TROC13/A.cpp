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

int n;
int ar[N];
int cnt[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int jen = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        if (cnt[ar[i]]++ == 0) jen++;
    }
    if (jen == n || jen == 1){
        cout << jen << el;
        return 0;
    }
    cout << n - 1 << el;

    return 0;
}