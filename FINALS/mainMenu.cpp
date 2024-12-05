#include "customer1.cpp"
#include "inventory2.cpp"
#include <bits/stdc++.h>
using namespace std;

string category[] = {"TOPS", "BOTTOMS", "ACCESSORIES"};
// item list
vector<string> tops = {"Polo", "T-Shirt", "Hoody"}; // choice = 1
vector<string> bottoms = {"Short", "Skirt", "Sweat pant", "Denim"};
vector<string> accessories = {"Cap", "Handkerchief"};
// price for tops 
vector<double> priceXSmallTops   = {250.00, 250.00, 250.00};
vector<double> priceSmallTops    = {300.00, 300.00, 300.00};
vector<double> priceMediumlTops  = {350.00, 350.00, 350.00};
vector<double> priceLargeTops    = {400.00, 400.00, 400.00};
vector<double> priceXLargeTops   = {500.00, 500.00, 500.00};
vector<double> priceXXLargeTops  = {700.00, 700.00, 700.00};
// stocks for tops
vector<int> stockXSmallSizeTops   = {100, 100, 100};
vector<int> stockSmallSizeTops    = {100, 100, 100};
vector<int> stockMediumlSizeTops  = {200, 200, 200};
vector<int> stockLargeSizeTops    = {300, 300, 300};
vector<int> stockXLargeSizeTops   = {300, 300, 300};
vector<int> stockXXLargeSizeTops  = {300, 300, 300};
// price for bottoms
vector<double> priceXSmallBottoms   = {250.00, 250.00, 250.00, 250.00};
vector<double> priceSmallBottoms    = {300.00, 300.00, 300.00, 300.00};
vector<double> priceMediumlBottoms  = {350.00, 350.00, 350.00, 350.00};
vector<double> priceLargeBottoms    = {400.00, 400.00, 400.00, 400.00};
vector<double> priceXLargeBottoms   = {500.00, 500.00, 500.00, 500.00};
vector<double> priceXXLargeBottoms  = {700.00, 700.00, 700.00, 700.00};
// stock for bottoms
vector<int> stockXSmallSizeBottoms  = {100, 100, 100, 100};
vector<int> stockSmallSizeBottoms   = {100, 100, 100, 100};
vector<int> stockMediumlSizeBottoms = {200, 200, 200, 200};
vector<int> stockLargeSizeBottoms   = {300, 300, 300, 300};
vector<int> stockXLargeSizeBottoms  = {300, 300, 300, 300};
vector<int> stockXXLargeSizeBottoms = {300, 300, 300, 300};
// price for accessories
vector<double> priceAccessories = {500.00, 50.00};
vector<int> stockAccessories    = {100, 100}; // isang price nalang to, since di na applicable si size

//vectors for storing new elements
vector<string> selectedItems;
vector<string> selectedSizes;
vector<int> selectedQuantities;
vector<double> selectedPrices;
//
double subTotal = 0;
double total = 0;
// bools
bool isAdmin = false;
bool isEmployer = false;

int main()
{
  while (true)
  {
    system("cls");
    cout << "\n=========[ " << RED << "I N V E N T O R Y  " << BLUE << "M A N A G E M E N T  " << MAGENTA << "S Y S T E M" << RESET << " ]=========\n\n";
    cout << "==================[ " << YELLOW << "W E L C O M E" << RESET << " ]==================\n\n";

    int choice;
    cout << "[1] CUSTOMER\n";
    cout << "[2] INVENTORY\n";
    cout << "[3] EXIT PROGRAM\n";
    cout << "\n[ENTER INPUT]: ";
    while (!(cin >> choice))
    {
      cout << "\n[ERROR]: (NUMBERS ONLY)\n\n[ENTER AGAIN]: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    switch (choice)
    {
    case 1:
    {
      system("cls");
      bool loopAgain = true;
      while (loopAgain == true)
      {
        cout << "\n[1] BUY\n";
        cout << "[2] CASHIER\n";
        cout << "[3] BACK\n";

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
              priceXSmallTops, priceSmallTops, priceMediumlTops, priceLargeTops, priceXLargeTops, priceXXLargeTops,
              
              stockXSmallSizeTops, stockSmallSizeTops, stockMediumlSizeTops, stockLargeSizeTops, stockXLargeSizeTops, stockXXLargeSizeTops,

              priceXSmallBottoms, priceSmallBottoms, priceMediumlBottoms, priceLargeBottoms,
              priceXLargeBottoms, priceXXLargeBottoms,

              stockXSmallSizeBottoms, stockSmallSizeBottoms, stockMediumlSizeBottoms, stockLargeSizeBottoms, stockXLargeSizeBottoms, stockXXLargeSizeBottoms,

              priceAccessories, stockAccessories,
              
              subTotal,total,
              selectedItems,selectedSizes,selectedQuantities, selectedPrices);
          break;
        }
        case 2:
          cashier(selectedItems,selectedSizes,selectedQuantities, selectedPrices);
          break;
        case 3:
          loopAgain = false;
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
      bool loopAgain1 = true;
      login(isAdmin, isEmployer);
      if (isAdmin == false && isEmployer == false)
      {
        string anything;
        cout << "Press any key to continue...";
        getline(cin >> ws, anything);
        break;
      }
      while (loopAgain == true)
      {
        system("cls");
        cout << "=========================================";
        cout << "----------[ I N V E N T O R Y ]----------\n";
        cout << "=========================================\n\n";
        cout << "[1] ADD PRODUCT\n";
        cout << "[2] DISPLAY INVENTORY\n";
        cout << "[3] PRODUCT SALES\n";
        cout << "[4] SALES HISTORY\n";
        cout << "[5] RE-STOCK/ADD STOCK\n";
        cout << "[6] EDIT INVENTORY\n";
        cout << "[7] EXIT\n";
        // while (loopAgain == true)
        cout << "\n[ENTER INPUT]: ";
        //{
        int choice; // local
        while (!(cin >> choice))
        {
          cout << "\n[ERROR]: (NUMBER ONLY)\n\n[ENTER AGAIN]: ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (choice) // for inventory
        {
        case 1:
        {
          // system("cls");
          // addProduct(isAdmin, category, tops, bottoms, accessories,
          //            priceSmallTops, priceMediumlTops, priceLargeTops,
          //            stockSmallSizeTops, stockMediumlSizeTops, stockLargeSizeTops,
          //            priceSmallBottoms, priceMediumlBottoms, priceLargeBottoms,
          //            stockSmallSizeBottoms, stockMediumlSizeBottoms, stockLargeSizeBottoms,
          //            priceAccessories, stockAccessories);
          // break;
        }
        case 2: // thats a lot of crap
        {
          system("cls");
          displayInventory(tops, bottoms, accessories,
                           priceXSmallTops, priceSmallTops, priceMediumlTops, 
                           priceLargeTops, priceXLargeTops, priceXXLargeTops,

                           stockXSmallSizeTops, stockSmallSizeTops, stockMediumlSizeTops, 
                           stockLargeSizeTops, stockXLargeSizeTops, stockXXLargeSizeTops,

                           priceXSmallBottoms, priceSmallBottoms, priceMediumlBottoms, 
                           priceLargeBottoms, priceXLargeBottoms, priceXXLargeBottoms,
                           
                           stockXSmallSizeBottoms, stockSmallSizeBottoms, stockMediumlSizeBottoms, 
                           stockLargeSizeBottoms, stockXLargeSizeBottoms, stockXXLargeSizeBottoms,
                           
                           priceAccessories, stockAccessories);
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
        {
          // edit(tops, bottoms, accessories,
          //      priceSmallTops, priceMediumlTops, priceLargeTops,
          //      stockSmallSizeTops, stockMediumlSizeTops, stockLargeSizeTops,
          //      priceSmallBottoms, priceMediumlBottoms, priceLargeBottoms,
          //      stockSmallSizeBottoms, stockMediumlSizeBottoms, stockLargeSizeBottoms,
          //      priceAccessories, stockAccessories);
          // break;
        }
          
        case 7: // this also serves as logout
          loopAgain = false;
          isAdmin = false;
          break;
        default:
          cout << "\n[ERROR]: (PLEASE BETWEEN 1 AND 7)\n";
          string anything;
          cout << "Press any key to continue...";
          getline(cin >> ws, anything);
        }
        //}
      }

      break;
    }
    case 3:
    {
      cout << "Exiting program...";
      return 0;
    }
    default:
      cout << "\n[ERROR]: (PLEASE BETWEEN 1 AND 3)\n\n";
      string anything;
      cout << "Press any key to continue...";
      getline(cin >> ws, anything);
    }
  }
}