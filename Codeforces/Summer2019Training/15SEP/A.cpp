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

    int a1,a2;
    cin >> a1 >> a2;

    int k1,k2;
    cin >> k1 >> k2;

    if (k2>k1){
        swap(k1,k2);
        swap(a1,a2);
    }

    int n;
    cin >> n;

    int ans1=0,ans2=0;
    int tm,aa=a1,ab=a2;
    tm=n;
    
    int tot=a1*(k1-1)+a2*(k2-1);
    ans1=max(0,n-tot);

    while (tm>=k2 && a2>0){
        tm-=k2;
        a2--;
        ans2++;
    }

    while (tm>=k1 && a1>0){
        tm-=k1;
        a1--;
        ans2++;
    }

    cout << ans1 << " " << ans2 << el;

    return 0;
}