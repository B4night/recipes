#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = { 1,1,0,0 };
    do {
        for_each(v.begin(), v.end(), [](int x) {
            cout << x << ' ';
        });
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
}