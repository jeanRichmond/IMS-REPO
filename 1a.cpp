#include <iostream>
#include <string>

using namespace std;


int main ()
{
  int n; // for generating input number of item
  int price; //
  double totalPrice = 0;
  bool isPremium = false;
  double discount;
  double discountAmount = 0;
  double finalPrice = 0;

  cout << "\t\nSIMPLE DISCOUNT SYSTEM \n\n";
  cout << "INPUT NUMBER OF ITEMS: ";
  cin >> n;
  cout << endl;

  try {

    if (n <= 0) {
      throw string ("INVALID NUMBER OF ITEMS");
      
      }
      for (int i = 1; i <= n; i++) {
        cout << "INPUT PRICE OF THE ITEM: ";
        cin >> price;

        if (price <= 0){
          throw string ("INVALID PRICE");
        }
        else {
          totalPrice += price;
        }
        if (price > 100) {
          isPremium = true;
           cout << "ITO AY ISANG PREMIUM (GOOD ITEM SARAP)" << endl;
        }
       

       if (n > 10){
          discount = 0.20;
          discountAmount = totalPrice * discount;
        
            if (isPremium && discountAmount > 15){
               discountAmount = 15.0;
               finalPrice = totalPrice - discountAmount;
            }
            else{
              finalPrice = totalPrice - discountAmount;

            } 
           
            }

            if (n > 5 ){
          discount = 0.20;
          discountAmount = totalPrice * discount;
        
            if (isPremium && discountAmount > 15){
               discountAmount = 15.0;
               finalPrice = totalPrice - discountAmount;
            }
            else{
              finalPrice = totalPrice - discountAmount;

            } 
            }

            else {
          discount = 0.0;
          discountAmount = totalPrice * discount;
          
            if (isPremium && discountAmount > 15){
               discountAmount = 15.0;
               finalPrice = totalPrice - discountAmount;
            }
            else {
              finalPrice = totalPrice - discountAmount;
            }
           
            }
      }
              
        cout << "TOTAL PRICE IS: " << finalPrice << endl;

    }  catch (string e) {
      cout << "ERROR: " << e << endl;
  }

}
  
