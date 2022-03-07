#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
vector<int> vec;

int getid(int a, int b, int c){
    return a + b * 100 + c * 10000;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int temp;
        while (ss >> temp){
            vec.pb(temp);
        }
        n = vec.size();
    }
    for (int i=0;i<n;i++){
        for (int j=i + 1;j<n;j++){
            for (int k=j + 1;k<n;k++){
                if (vec[i] == vec[j] + vec[k] || vec[j] == vec[i] + vec[k] || vec[k] == vec[i] + vec[j]){
                    cout << vec[i] << " " << vec[j] << " " << vec[k] << el;
                }
            }
        }
    }
    // for (int i=0;i<n;i++){
    //     for (int j=i + 1;j<n;j++){
    //         for (int k=j + 1;k<n;k++){
    //             if (vec[j] == vec[i] + vec[k]){
    //                 cout << vec[i] << " " << vec[j] << " " << vec[k] << el;
    //             }
    //         }
    //     }
    // }
    // // for (int i=0;i<n;i++){
    // //     for (int j=i + 1;j<n;j++){
    // //         for (int k=0;k<i;k++){
    // //             if (vec[j] == vec[i] + vec[k]){
    // //                 cout << vec[k] << " " << vec[i] << " " << vec[j] << el;
    // //             }
    // //         }
    // //     }
    // // }
    // for (int j=0;j<n;j++){
    //     for (int k=j + 1;k<n;k++){
    //         for (int i=0;i<j;i++){
    //             if (vec[k] == vec[i] + vec[j]){
    //                 cout << vec[i] << " " << vec[j] << " " << vec[k] << el;
    //             }
    //         }
    //     }
    // }
    // // for (int j=0;j<n;j++){
    // //     for (int k=j + 1;k<n;k++){
    // //         for (int i=0;i<j;i++){
    // //             if (vec[i] == vec[j] + vec[k]){
    // //                 cout << vec[i] << " " << vec[j] << " " << vec[k] << el;
    // //             }
    // //         }
    // //     }
    // // }
    // for (int k=0;k<n;k++){
    //     for (int i=0;i<k;i++){
    //         for (int j=i + 1;j<k;j++){
    //             if (vec[i] == vec[j] + vec[k]){
    //                 cout << vec[i] << " " << vec[j] << " " << vec[k] << el;
    //             }
    //         }
    //     }
    // }


    // // for (int i=0;i<n;i++){
    // //     for (int j=i + 1;j<n;j++){
    // //         for (int k=j + 1;k<n;k++){
    // //             if (vec[j] == vec[i] + vec[k]){
    // //                 cout << vec[i] << " " << vec[j] << " " << vec[k] << el;
    // //             }
    // //         }
    // //     }
    // // }
    // // for (int i=0;i<n;i++){
    // //     for (int j=i + 1;j<n;j++){
    // //         for (int k=j + 1;k<n;k++){
    // //             if (vec[k] == vec[i] + vec[j]){
    // //                 cout << vec[i] << " " << vec[j] << " " << vec[k] << el;
    // //             }
    // //         }
    // //     }
    // // }
    // // for (int i=0;i<n;i++){
    // //     for (int j=i + 1;j<n;j++){
    // //         for (int k=j + 1;k<n;k++){
    // //             if (vec[i] == vec[j] + vec[k]){
    // //                 cout << vec[i] << " " << vec[j] << " " << vec[k] << el;
    // //             }
    // //         }
    // //     }
    // // }

    return 0;
}