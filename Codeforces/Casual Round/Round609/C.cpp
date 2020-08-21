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
string s;
int ar[N];
int as[N], mn[N], ans[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    cin >> s;
    for (int i=0;i<n;i++){
        int dig = (int)(s[i]-'0');
        ar[i] = dig;
        as[i] = dig;
        mn[i] = dig;
    }

    // for (int i=k;i<n;i++){
    //     ar[i] = max(ar[i], ar[i-k]);
    //     mn[i] = min(mn[i], mn[i-k]);
    // }

    // for (int i=n-k-1;i>=0;i--){
    //     ar[i] = max(ar[i], ar[i+k]);
    //     mn[i] = min(mn[i], mn[i+k]);
    // }

    for (int i=0;i<k;i++){
        ans[i] = as[i];
    }

    for (int i=k;i<n;i++){
        ans[i] = ans[i-k];
    }

    bool atas = 1;
    for (int i=0;i<n;i++){
        if (ans[i] < as[i]){
            atas = 0;
            break;
        } else if (ans[i] > as[i]){
            break;
        }
    }

    if (atas) {
        cout << n << el;
        for (int i=0;i<n;i++){
            cout << ans[i];
        }
        cout << el;
        return 0;
    }

    int per=-1;
    for (int i=k-1;i>=0;i--){
        if (ans[i] != 9){
            ans[i]++;
            per = i;
            break;
        }
    }

    if (per!=-1){
        for (int i=per+1;i<k;i++){
            ans[i]=0;
        }
    }

    for (int i=k;i<n;i++){
        ans[i] = ans[i-k];
    }

    cout << n << el;
    for (int i=0;i<n;i++){
        cout << ans[i];
    }
    cout << el;

    return 0;
}