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

int n;
int ar[200050];
int stree[1000000];

void constree(int low,int high,int pos){
    if (low==high){
        stree[pos]=ar[low];
        return;
    }

    int mid=(low+high)/2,left=pos*2+1;
    constree(low,mid,left);
    constree(mid+1,high,left+1);
}

void upd(int low,int high,int uid,int pos,int val){
    if (high<uid) return;
    if (low>uid) return;
    if (low==high){
        stree[pos]=val;
        return;
    }

    int mid=(low+high)/2,left=pos*2+1;

        stree[left]=max(stree[left],stree[pos]);
        stree[left+1]=max(stree[left+1],stree[pos]);
    
    stree[pos]=0;

    upd(low,mid,uid,left,val);
    upd(mid+1,high,uid,left+1,val);
}

void upall(int val){
    stree[0]=max(stree[0],val);
}

int cari(int low,int high,int pos,int id){
    if (high<id) return 0;
    if (low>id) return 0;
    if (low==high) return stree[pos];

    int mid=(low+high)/2,left=pos*2+1;
    return max(stree[pos],max(cari(low,mid,left,id),cari(mid+1,high,left+1,id)));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++) cin >> ar[i];

    int q;
    cin >> q;

    constree(0,n-1,0);
  //  for (int i=0;i<n;i++) cerr << cari(0,n-1,0,i) << " "; cerr << el;

    while (q--){
        int tipe;
        cin >> tipe;
        if (tipe==1){
            int id,val;
            cin >> id >> val;
            id--;
            upd(0,n-1,id,0,val);
        }else{
            int val;
            cin >> val;
            upall(val);
        }

    //    for (int i=0;i<n;i++) cerr << cari(0,n-1,0,i) << " "; cerr << el;
    }

    for (int i=0;i<n;i++){
        cout << cari(0,n-1,0,i) << " ";
    }
    cout << el;

    return 0;
}