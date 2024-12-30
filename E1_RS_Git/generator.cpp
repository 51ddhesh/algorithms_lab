#include <iostream>
using namespace std;
int main(){
    freopen("in.txt", "w", stdout);
    for(int i = 100000; i <= 5000000; i += 100000) cout << i << "\n";
    return 0;
}