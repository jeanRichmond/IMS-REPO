#include "customer.cpp"
#include "inventory.cpp"
#include <bits/stdc++.h>
using namespace std;



    string category[] = { "T-shirt", "Hoodies", "Shorts" };
    string size[] = { "Small", "Medium", "Large" };
        vector <string> tshirts = {"Fila", "Adidas", "Nike"};
        vector <string> hoodies = {"GAP", "Roadster", "Campus sutra"};
        vector <string> shorts = {"Epok", "Lowoy 5 ltrs", "Tasbu"};
            vector <float> priceSmallSize = {1.00, 11.00, 111.00};
            vector <float> priceMediumlSize = {2.00, 22.00, 222.00};
            vector <float> priceLargeSize = {3.00, 33.00, 333.00};
                vector <int> stockSmallSize = {1, 11, 111};
                vector <int> stockMediumlSize = {2, 22, 222};
                vector <int> stockLargeSize = {3, 33, 333};
int main()
{ 
  cout << "\n=========[ INVENTORY MANAGEMENT SYSTEM ]=========\n\n";
  cout << "==================[ A D M I N ]==================\n\n";
  while (true)
  {
    int choice;
    cout<<"[1] CUSTOMER\n";
    cout<<"[2] INVENTORY\n";
    cout<<"[3] EXIT PROGRAM\n";
    cout << "\n[ENTER INPUT]: ";
    while (!(cin >> choice))
    {
      cout << "\n[ERROR]: (NUMBERS ONLY)\n\n{ENTER AGAIN]: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    switch (choice)
    {
    case 1:
    {
      bool loopAgain = true;
    while (loopAgain == true) {

      cout << "Buy\n";
      cout << "Order/Pre-order\n";
      cout << "Cashier\n";
      cout << "Back\n";

      int choice; // local
     cout << "\n[ENTER INPUT]: ";
     while (!(cin >> choice))
    {
      cout << "\n[ERROR]: (NUMBER ONLY)\n\n[ENTER AGAIN]: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }



    switch (choice)
    {
    case 1:
    {
    buy(category, tshirts, hoodies, shorts);
      break;
    } 
    case 2: order ();
      break;
    case 3: cashier ()  ; 
      break;
    case 4: ;
      break;

         
    default: cout<<"\n[ERROR]: (PLEASE BETWEEN 1 AND 7)\n";
      
    }   


    
    }
    }
      break;
    case 2:
    {
      bool loopAgain = true;
      while (loopAgain == true)
      {
        cout << "\n=========================================";
        cout << "\n----------[ I N V E N T O R Y ]----------\n";
        cout << "=========================================\n\n";
        cout << "[1] ADD PRODUCT\n";
        cout << "[2] DISPLAY INVENTORY\n";
        cout << "[3] PRODUCT SALES\n";
        cout << "[4] SALES HISTORY\n";
        cout << "[5] RESTOCK\n";
        cout << "[6] EDIT INVENTORY\n";
        cout << "[7] EXIT\n";
        while (loopAgain == true)
        {
          int choice; // local
          cout << "\n[ENTER INPUT]: ";
          while (!(cin >> choice))
          {
            cout << "\n[ERROR]: (NUMBER ONLY)\n\n[ENTER AGAIN]: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          }
          
          switch (choice)
          {
          case 1: addProduct();
            break;
          case 2:
           {
            int cat1 = ::tshirts.capacity(); 
            int cat2 = ::hoodies.capacity();
            int cat3 = ::shorts.capacity();
            displayInventory (cat1,cat2,cat3, category);
              break;
          }
          case 3: productSales (); 
            break;
          case 4: salesHistory ();
            break;
          case 5: restock ();
            break;
          case 6: editHistory ();
            break;
          case 7: loopAgain = false;
            break;        
          default: cout<<"\n[ERROR]: (PLEASE BETWEEN 1 AND 7)\n";
            
          }            


        }
      }

      break;
    }
    
    case 3: 
    {
      cout<<"Exiting program...";
      return 0;
    }
    default:
      cout << "\n[ERROR]: (PLEASE BETWEEN 1 AND 2)\n\n";
    
    }
  }
  cout << "HELLO JHERVIN HHAHAHAHAHAHAHAHAHAHAHA" << endl;
}