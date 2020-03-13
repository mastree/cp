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
int ar[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> t;
    while (t--){
        int n;
        cin >> n;

        int len = n / 2;
        vector <int> ans;
        for (int i=0;i<len;i++){
            ans.pb(1);
        }

        int sisa = n%2;
        if (sisa){
            ans[0] = 7;
        }
        for (auto x : ans){
            cout << x;
        }
        cout << el;
    }

    return 0;
}