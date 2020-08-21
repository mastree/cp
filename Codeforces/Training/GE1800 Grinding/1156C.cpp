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

int n, d;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1);

    int low = 0, high = n / 2;
    while (low < high){
        int mid = (low + high + 1) / 2;

        int l = 1, r = n - mid + 1;
        bool bisa = 1;
        for (int i=0;i<mid;i++){
            if (ar[r + i] - ar[l + i] < d){
                bisa = 0;
                break;
            }
        }
        if (bisa){
            low = mid;
        } else{
            high = mid - 1;
        }
    }
    cout << low << el;

    return 0;
}