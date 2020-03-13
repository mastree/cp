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

const int N = 100007;
int n;
int ar[N];
int stree[4*N];

void constree(int low, int high, int pos){
    if (low==high){
        stree[pos]=ar[low];
        return;
    }

    int left=pos*2+1, mid=(low+high)/2;
    constree(low,mid,left);
    constree(mid+1,high,left+1);

    stree[pos]=max(stree[left],stree[left+1]);
}

int ask(int qlow, int qhigh, int low, int high, int pos){
    if (qlow>high || qhigh<low){
        return -1;
    }

    if (qlow<=low && qhigh>=high){
        return stree[pos];
    }

    int left=pos*2+1, mid=(low+high)/2;
    int res1=ask(qlow,qhigh,low,mid,left);
    int res2=ask(qlow,qhigh,mid+1,high,left+1);

    return max(res1,res2);
}

int mmax(int a, int b){
    if (a<=b){
        return ask(a,b,0,n-1,0);
    } 

    return max(ask(a,n-1,0,n-1,0),ask(0,b,0,n-1,0));
}

int next(int a){
    return (a+1)%n;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int mn=MOD,mx=-1;
    for (int i=0;i<n;i++){
        cin >> ar[i];
        mn=min(mn,ar[i]);
        mx=max(mx,ar[i]);
    }
    //cout << mn << " " << mx << el;

    constree(0,n-1,0);

    int last=0, cnt=2;
    bool ulang=0;
    for (int i=0;i<n;i++){
    //    cout << "case :" << i << " " << el;
        if (mx<=mn*2){
            cout << -1 << " ";
            continue;
        }
        cnt--;
        if (cnt<=0){
            cnt=1;
            last=i;
        } 

        if (cnt<=n) ulang=0;
    //    cout << i << "--" << last << " : " << mmax(i,last) << el;
    //    cout << ulang << el;
        int tm=mmax(i,last);
        if (ulang) tm=mmax(0,n-1);
        while (tm<=ar[next(last)]*2){       
            last=next(last);
            cnt++;
            if (last==i) {
                ulang=1;
                // int tm=mmax(0,n-1);
                // while (tm<=ar[next(last)]*2){
                //     last=next(last);
                //     cnt++;
                // }
                // break;
            }
            if (ulang) tm=mmax(0,n-1);
            else tm=mmax(i,last);
        //    cout << i << "--" << last << " : " << mmax(i,last) << el;
        }

        cout << cnt << " ";

        // int low=1, high=n;
        // while (low<high){
        //     int mid=(low+high+1)/2;

        //     int st=i;
        //     int end=(st+mid-2)%n;
        //     int realend=(st+mid-1)%n;


        //     if (st<=end){
        //         int tm=ask(st,end,0,n-1,0);
        //         cout << mid << " " << tm << el;

        //         if (tm<=ar[realend]*2){
        //             low=mid;
        //         } else{
        //             high=mid-1;
        //         }
        //     } else{
        //         int tm1=ask(st,n-1,0,n-1,0);
        //         int tm2=ask(0,end,0,n-1,0);
        //         int tm=max(tm1,tm2);
        //         cout << mid << " " << tm << el;

        //         if (tm<=ar[realend]*2){
        //             low=mid;
        //         } else{
        //             high=mid-1;
        //         }
        //     }
        // }

        // cout << low << el;
    }
    cout << el;

    return 0;
}