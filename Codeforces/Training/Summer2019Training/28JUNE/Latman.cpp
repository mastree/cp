#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int ar[n+1];
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    priority_queue<int>b;
    priority_queue<int,vector<int>,greater<int>> a;

    
    for (int i=1;i<=n;i++){
        if (i&1) b.push(ar[i]);
        else a.push(ar[i]);

        if (i!=1){
            while (a.top()<b.top()){
                int tm1=a.top(),tm2=b.top();
                a.pop();b.pop();
                b.push(tm1);a.push(tm2);
            }
        }

        if (i&1){
            cout << b.top(); 
        } else {
            int ans=a.top()+b.top();
            cout << ans/2;
            if (ans&1) cout << ".5";
        }

        cerr << el; 
    }

    return 0;
}