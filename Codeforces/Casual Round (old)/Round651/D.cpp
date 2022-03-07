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
const int BORD = 1e9;

int n, k;
int ar[N];

bool coba(int x){
    int cur = 1;
    bool od = 0; // true if ans in odd index
    for (int i=1;i<=n;i++){
        if (cur & 1){
            if (od){
                if (ar[i] <= x) cur++;
            } else{
                cur++;
            }
        } else{
            if (od){
                cur++;
            } else{
                if (ar[i] <= x) cur++;
            }
        }

        if (cur == k + 1) return 1;
    }
    cur = 1;
    od = 1; // true if ans in odd index
    for (int i=1;i<=n;i++){
        if (cur & 1){
            if (od){
                if (ar[i] <= x) cur++;
            } else{
                cur++;
            }
        } else{
            if (od){
                cur++;
            } else{
                if (ar[i] <= x) cur++;
            }
        }

        if (cur == k + 1) return 1;
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    int low = 1, high = BORD;
    while (low < high){
        int mid = (low + high) / 2;
        // cout << mid << el;
        if (coba(mid)){
            high = mid;
        } else{
            low = mid + 1;
        }
    }
    cout << high << el;

    return 0;
}