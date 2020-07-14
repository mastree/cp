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

const int N = 1e5 + 10;

int q;
int n, k;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> k;
        vector <int> pos;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            if (ar[i] == k){
                pos.pb(i);
            }
        }
        if ((int) pos.size() * 2 > n){
            cout << "yes" << el;
            continue;
        } 
        if ((int) pos.size() == 0){
            cout << "no" << el;
            continue;
        }
        int l = 1;
        int cur = 0;
        bool bisa = 0;
        for (int r=1;r<=n;r++){
            if (ar[r] >= k){
                cur++;
            }
            if (((r - l + 1) / 2) + 1 <= cur && (r - l + 1) > 1){
                bisa = 1;
                break;
            }
            while (r - l + 1 > 2){
                if (ar[l] >= k) cur--;
                l++;
            }
            if (r - l + 1 == 2){
                if (cur == 0) l = r + 1;
                else if (cur == 1 && ar[r] >= k) l++;
            } else if (r - l + 1 == 1){
                if (cur == 0) l++;
            }
        }   
        if (bisa){
            cout << "yes" << el;
        } else{
            cout << "no" << el;
        }
    }

    return 0;
}