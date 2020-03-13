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

int q, n;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        // cin >> n;
        cin >> s;
        n = s.length();
        s = "*" + s;

        int low = 1, high = n + 1;

        while (low < high){
            int mid = (low + high) / 2;
            bool bisa = 0;

            int last = 0;
            for (int i=1;i<=n+1;i++){
                if (last + mid >= n + 1){
                    bisa = 1;
                    break;
                }
                if (i - last > mid){
                    break;
                }
                if (s[i] == 'R'){
                    last = i;
                }
            }

            if (bisa){
                high = mid;
            } else{
                low = mid + 1;
            }
        } 

        cout << high << el;
    }

    return 0;
}