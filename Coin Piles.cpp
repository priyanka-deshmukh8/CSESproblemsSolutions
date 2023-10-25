#include <iostream>
using namespace std;
#define ll long long

int main() {
   int t = 1;
   cin >> t;
   while (t--) {
       int a, b;
       cin >> a >> b;
       if (a > b) swap(a, b);
       string ans = "";
       if (a * 2 < b) ans = "NO";
       else {
           a %= 3;
           b %= 3;
           if (a > b) swap(a, b);
           if ((a == 0 && b == 0) || (a == 1 && b == 2)) {
               ans = "YES";
           } else {
               ans = "NO";
           }
       }
       cout << ans << endl;  // This line should be inside the while loop.
   }
   return 0;
}
