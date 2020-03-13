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

const int N = 100009;

int n,m;
int ar1[N], ar2[N];
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> ar1[i];
    }

    for (int i=0;i<m;i++){
        cin >> ar2[i];
    }

    sort(ar2, ar2+m);
    int id1=0, id2=0;
    for (int i=0;i<n+m;i++){
        if (id1==n){
            v.pb(ar2[id2]);
            id2++;
            continue;
        } 

        if (id2==m){
            v.pb(ar1[id1]);
            id1++;
            continue;
        }

        if (ar1[id1]<ar2[id2]){
            v.pb(ar1[id1]);
            id1++;
        } else{
            v.pb(ar2[id2]);
            id2++;
        }
    }

    for (auto x : v){
        cout << x << " ";
    }
    cout << el;

    return 0;
}