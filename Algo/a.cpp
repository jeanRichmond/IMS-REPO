#include <iostream>
using namespace std;


int main() {


// int a,b;
// for (int i = 1; i <= 3; i++) {
// cout << "Input two positive integer: ";
// cin >> a >> b;
// if (a == b) {
//   cout << "the output is: " << (a + b) * 3 << endl;
//   continue;
// }
// cout << "the output is: " << a + b << endl;
// }


// int sub = 51;
// int n;
// cout << "enter n: ";
// cin >> n;

// if (n > sub) {
//   cout << (n - sub) * 3 << endl;
// } else {
// cout << sub - n << endl;
// }

int a, b;
int sum = 0;
cout << "enter two integers: ";
cin >> a >> b;
sum = a + b;

if ( sum == 30 || a != 30 && b == 30 ||  a == 30 && b != 30 ) {
  cout << "1";
} else {
  cout << "0";
}



return 0;





}