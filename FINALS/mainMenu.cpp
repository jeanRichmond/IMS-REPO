#include "customer.cpp"
#include "inventory.cpp"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
vector <string> category = { "T-shirt", "Hoodies", "Shorts" };
vector <string> product = {"Epok nation", "Pag-ibig na walang hanggan ni epok", "basta epok, pokpok"};
char productSize[] = {'S', 'M', 'L'};
int main()
{





  while (true)
  {
    int choice;
    cout<<"1. Customer\n";
    cout<<"2. Inventory\n";
    cout<<"3. Exit program\n";
    cout << "Enter input: ";
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
        cout << "INVENTORY\n"<< endl;
        cout << "1. Add Product\n";
        cout << "2. Display Inventory\n";
        cout << "3. Product Sales\n";
        cout << "4. Sales history\n";
        cout << "5. Restock\n";
        cout << "6. Edit Inventory\n";
        cout << "7. Exit\n";
        while (loopAgain == true)
        {
          int choice; // local
          cout << "Enter input: ";
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