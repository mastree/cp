// you can use includes, for example:
// #include <algorithm>
#include <bits/stdc++.h>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_map<int, bool> cek;
    for (auto& x : A) cek[x] = 1;
    for (int i=1;;i++){
        if (!cek[i]) return i;
    }
}
