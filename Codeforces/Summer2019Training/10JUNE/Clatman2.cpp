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

vector<int> vr,vl;
int vlen;

int binser(int a){
    int low=0,high=vlen;

    while(low<high){
        int mid=(low+high)/2;

        if (vr[mid]>a) high=mid;
        else low=mid+1;
    }

    if (vr[high]<=a) return -1;
    return high;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    bool exist[100003];
    memset(exist,0,100003);
    int ar[n];
    
    for (int i=0;i<n;i++){
        cin >> ar[i];
    }

    for (int i=0;i<n;i++){
        if (!exist[ar[i]]){
            exist[ar[i]]=1;
            vl.pb(i);
        }
    }

    memset(exist,0,100003);
    for (int i=n-1;i>=0;i--){
        if (!exist[ar[i]]){
            exist[ar[i]]=1;
            vr.pb(i);
        }
    }
    sort(vr.begin(),vr.end());
    vlen=vr.size();
    ll ans=0;
    for (int i=0;i<vlen;i++){
        int id=binser(vl[i]);
        if (id==-1) break;

        ans+=(ll)(vlen-id);
    }

    cout << ans << el;

    return 0;
}