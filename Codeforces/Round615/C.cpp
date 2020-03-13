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

int t;
int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--){
        cin >> n;

        vector <int> ans;
        bool len2 = 0;
        unordered_map <int, bool> cek;
        for (int i=2;i*i<=n;i++){
            if (n%i==0){
                ans.pb(i);
                n/=i;
                cek[i] = 1;
                if (ans.size() == 2){
                    len2=1;
                    break;
                }
            }
        }
        if (n>1 && len2 && cek[n] == 0) ans.pb(n);
        if (ans.size() == 3){
            cout << "YES" << el;
            for (auto x : ans){
                cout << x << " ";
            }
            cout << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}