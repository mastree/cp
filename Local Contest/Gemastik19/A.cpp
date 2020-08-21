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


ll n,m,pmin,pmax,qmin,qmax,ans1,ans2;

int win(ll k1, ll k2, ll reg1, ll reg2){   // 1 = win, 0 = lose / draw
    if (k1 >= k2) return 1;
    if (k2>=k1*2){
        return 0;
    }
    if (k1 >= reg1){
        return win(k2-k1,k1,reg2,reg1);
    }
    
    k1+=reg1;
    swap(k1,k2);
    swap(reg1,reg2);
    if (k1 >= k2) return 1;
    if (k2>=k1*2){
        return 0;
    }
    if (k1 >= reg1){
        return win(k2-k1,k1,reg2,reg1);
    }

    return 0;

    
    // k1+=reg1;
    // swap(k1,k2);
    // swap(reg1,reg2);
    // if (k1 >= k2) return 0;
    // if (k1 > reg2) return 0;
    // if (reg1>reg2) return 0;
    // if (reg2>reg1) return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> pmin >> pmax >> qmin >> qmax;

    for (ll p=pmin;p<=pmax;p++){
        ll low=qmin,high=qmax;
        int res;

        while (low<high){
            ll mid=(low+high+1)/2;
            res=win(p,mid,n,m);
            if (res){
                low=mid;
            } else {
                high=mid-1;
            }
        }
            ans1+=low-qmin+1;
        
    }

    for (ll p=qmin;p<=qmax;p++){
        ll low=pmin,high=pmax;
        int res;

        while (low<high){
            ll mid=(low+high+1)/2;
            res=win(p,mid,m,n);
            if (res){
                low=mid;
            } else {
                high=mid-1;
            }
        }

            ans2+=low-qmin+1;
        
    }

    cout << abs(ans1) << " " << abs(ans2) << el;

    return 0;
} 