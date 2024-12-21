#include <iostream>
using namespace std;
int main (){

  int arr1[1];
  int arr2[1];
  int arr3[1];
 
  
  cout << "\nEnter Your Number 1: ";
  cin >> arr1[0];

  cout << "Enter Your Number 2: ";
  cin >> arr2[0];

  cout << "Enter Your Number 3: ";
  cin >> arr3[0];

  cout << "\nOutput: " << arr1[0] << ", " << arr2[0] << ", " << arr3[0] << endl;

  if (arr1[0] == 1 && arr2[0] == 9 && arr3[0] == 9 ) {
   cout << "\nFinal Output: " << arr1[0] + 1<< ", " << arr2[0] - 9 << ", "<< arr3[0] -9  << endl << endl;
  }
  else if (arr1[0] == 2 && arr2[0] == 9 && arr3[0] == 9 ) {
  cout << "\nFinal Output: " << arr1[0] + 1<< ", " << arr2[0] - 9 << ", "<< arr3[0] -9  << endl << endl;
  }
  else if (arr1[0] == 3 && arr2[0] == 9 && arr3[0] == 9 ) {
   cout << "\nFinal Output: " << arr1[0] + 1<< ", " << arr2[0] - 9 << ", "<< arr3[0] -9  << endl << endl;
  }
  else if (arr1[0] == 4 && arr2[0] == 9 && arr3[0] == 9 ) {
   cout << "\nFinal Output: " << arr1[0] + 1<< ", " << arr2[0] - 9 << ", "<< arr3[0] -9  << endl << endl;
  }
  else if (arr1[0] == 5 && arr2[0] == 9 && arr3[0] == 9 ) { 
   cout << "\nFinal Output: " << arr1[0] + 1<< ", " << arr2[0] - 9 << ", "<< arr3[0] -9  << endl << endl;
  }
  else if (arr1[0] == 6 && arr2[0] == 9 && arr3[0] == 9 ) {
    cout << "\nFinal Output: " << arr1[0] + 1<< ", " << arr2[0] - 9 << ", "<< arr3[0] -9  << endl << endl;
  }
  else if (arr1[0] == 7 && arr2[0] == 9 && arr3[0] == 9 ) {
   cout << "\nFinal Output: " << arr1[0] + 1<< ", " << arr2[0] - 9 << ", "<< arr3[0] -9  << endl << endl;
  }
  else if (arr1[0] == 8 && arr2[0] == 9 && arr3[0] == 9 ) { 
   cout << "\nFinal Output: " << arr1[0] + 1<< ", " << arr2[0] - 9 << ", "<< arr3[0] -9  << endl << endl;
  }
  else if (arr1[0] == 9 && arr2[0] == 9 && arr3[0] == 9 ) {
    int tempoArr[1] = {1};
    cout << "\nFinal Output: " << tempoArr[0]  << ", " << arr1[0] - 9 << ", " << arr2[0] - 9 << ", "<< arr3[0] -9  << endl << endl;
  }
  else {
    cout <<  "\nFinal Output: " << arr1[0] << ", " << arr2[0] << ", " << arr3[0] + 1 << endl << endl;
}
}
