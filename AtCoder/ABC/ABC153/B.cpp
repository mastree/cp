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

int a, n;
int tot;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> n;
    for (int i=0;i<n;i++){
        int tm;
        cin >> tm;
        tot+=tm;
    }
    if (tot >= a){
        cout << "Yes" << el;
    } else{
        cout << "No" << el;
    }

    return 0;
}