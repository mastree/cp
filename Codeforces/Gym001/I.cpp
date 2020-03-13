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

const int N = 3e5 + 10;

int n, k;
int t[N], ar[N];

bool bisa(int bound){
    for (int i=0;i<N;i++){
        t[i] = 0;
    }
    
    int high = 1;
    for (int i=k;i<=n;i++){
        while (ar[i] - ar[high]>bound) high++;
        if (i-k < high-1){
            t[i] = t[i-1];
            continue;
        }
        if (t[i-k]>=high-1) t[i]=i;
        else t[i] = t[i-1];
    }

    return t[n]==n;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1);

    int ans = MOD;
    int low = 0, high = 1e9;
    while (low<high){
        int mid = (low + high) / 2;

        if (bisa(mid)){
            ans = mid;
            high = mid;
        } else{
            low = mid + 1;
        }
    }

    cout << ans << el;

    return 0;
}