#include "customer.cpp"
#include "inventory.cpp"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
string category[] = { "T-shirt", "Hoodies", "Shorts" };
vector <string> product = {"Epok nation", "Pag-ibig na walang hanggan ni epok", "basta epok, pokpok"};
char productSize[] = {'S', 'M', 'L'};

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
    cout << "\n[ ENTER INPUT ]: ";
    while (!(cin >> choice))
    {
      cout << "Error: Number only\nEnter again: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    switch (choice)
    {
    case 1:

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
          cout << "\n[ ENTER INPUT ]: ";
          while (!(cin >> choice))
          {
            cout << "Error: Number only\nEnter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          }
          switch (choice)
          {
          case 1: addProduct();
            break;
          case 2: displayInventory ();
            break;
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
          default: cout<<"Error: Please between 1 and 7";
            
          }            


        }
      }

      break;
    }
    default:
      cout << "Error: Please between 1 and 2";
    
    }
  }
}