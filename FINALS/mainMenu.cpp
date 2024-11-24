#include "customer1.cpp"
#include "inventory2.cpp"
#include <bits/stdc++.h>
using namespace std;

string category[] = {"Tops", "Bottoms", "Accessories"};
//string size[] = {"Small", "Medium", "Large"};
vector<string> tops        = {"Polo", "T-Shirt", "Hoody"}; //choice = 1
vector<string> bottoms     = {"Shorts", "Skirts", "Sweat pants", "Denim"};
vector<string> accessories = {"Cap", "Panyo"};
//attributes for tops q
vector<float> priceSmallTops   = {100.00, 100.00, 100.00};          //priceSmallTops
vector<float> priceMediumlTops = {150.00, 150.00, 150.00};          //priceMediumlTops
vector<float> priceLargeTops   = {200.00, 200.00, 200.00};          //priceLargeSizeTops[choice] for calculation ---> qty 3    
                                                                    
vector<int> stockSmallSizeTops     = {100, 100, 100};
vector<int> stockMediumlSizeTops   = {200, 200, 200};
vector<int> stockLargeSizeTops     = {300, 300, 300};
//attributes for bottoms
vector<float> priceSmallBottoms   = {100.00, 100.00, 100.00, 100.00};
vector<float> priceMediumlBottoms = {150.00, 150.00, 150.00, 150.00};
vector<float> priceLargeBottoms   = {200.00, 200.00, 200.00, 200.00};
vector<int> stockSmallSizeBottoms     = {100, 100, 100, 100};
vector<int> stockMediumlSizeBottoms   = {200, 200, 200, 200};
vector<int> stockLargeSizeBottoms     = {300, 300, 300, 300};
//attributes for accessories
vector<float> priceSmallAccessories   = {100.00, 100.00, 100.00};
vector<float> priceMediumlAccessories = {150.00, 150.00, 150.00};
vector<float> priceLargeAccessories   = {200.00, 200.00, 200.00};
vector<int> stockSmallSizeAccessories     = {100, 100};// isang price lang ata to pero maya na to
vector<int> stockMediumlSizeAccessories   = {200, 200};// ito 
vector<int> stockLargeSizeAccessories     = {300, 300};// at ito ay di na applicable


int main()
{

  cout << "\n=========[ INVENTORY MANAGEMENT SYSTEM ]=========\n\n";
  cout << "==================[ W E L C O M E ]==================\n\n";
  while (true)
  {
    int choice;
    cout << "[1] CUSTOMER\n";
    cout << "[2] INVENTORY\n";
    cout << "[3] EXIT PROGRAM\n";
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
      while (loopAgain == true)
      {

        cout << "[1] BUY\n";
        cout << "[2] ORDER\n";
        cout << "[3] CASHIER\n";
        cout << "[4] BACK\n";

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
          buy(category, tops, bottoms, accessories, 
            priceSmallTops, priceMediumlTops, priceLargeTops, 
            stockSmallSizeTops, stockMediumlSizeTops, stockLargeSizeTops,
            priceSmallBottoms, priceMediumlBottoms, priceLargeBottoms,
            stockSmallSizeBottoms, stockMediumlSizeBottoms, stockLargeSizeBottoms,
            priceSmallAccessories,priceMediumlAccessories,priceLargeAccessories,
            stockSmallSizeAccessories,stockMediumlSizeAccessories,stockLargeSizeAccessories);
          break;
        }
        case 2:
          order();
          break;
        case 3:
          cashier(); 
          break;
        case 4:;
          break;

        default:
          cout << "\n[ERROR]: (PLEASE BETWEEN 1 AND 7)\n";
        }
      }
    }
    break;
    case 2:
    {
      bool loopAgain = true;
      while (loopAgain == true)
      {
        system("cls");
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
          case 1:
          {
            system("cls");
            addProduct();
            break;
          }
          case 2: //thats a lot of crap
          {
            system("cls");
            displayInventory(tops, bottoms, accessories, 
            priceSmallTops, priceMediumlTops, priceLargeTops, 
            stockSmallSizeTops, stockMediumlSizeTops, stockLargeSizeTops,
            priceSmallBottoms, priceMediumlBottoms, priceLargeBottoms,
            stockSmallSizeBottoms, stockMediumlSizeBottoms, stockLargeSizeBottoms,
            priceSmallAccessories,priceMediumlAccessories,priceLargeAccessories,
            stockSmallSizeAccessories,stockMediumlSizeAccessories,stockLargeSizeAccessories);
            loopAgain = false;
            break;
            
          }
          case 3:
            productSales();
            break;
          case 4:
            salesHistory();
            break;
          case 5:
            restock();
            break;
          case 6:
            editHistory();
            break;
          case 7:
            loopAgain = false;
            loopAgain = false;
            break;
          default:
            cout << "\n[ERROR]: (PLEASE BETWEEN 1 AND 7)\n";
          }
        }
      }

      break;
    }

    case 3:
    {
      cout << "Exiting program...";
      return 0;
    }
    default:
    system("cls");
      cout << "\n[ERROR]: (PLEASE BETWEEN 1 AND 3)\n\n";
    }
  }
}