#include "customer1.cpp"
#include "inventory2.cpp"
#include <bits/stdc++.h>
using namespace std;

string category[] = {"TOPS", "BOTTOMS", "ACCESSORIES"};
// item list
vector<string> tops = {"Polo", "T-Shirt", "Hoodie"}; // choice = 1
vector<string> bottoms = {"Short", "Skirt", "Sweat Pants", "Denim"};
vector<string> accessories = {"Cap", "Handkerchief"};
// price for tops 
vector<double> priceXSmallTops =   {250.00, 150.00, 200.00};
vector<double> priceSmallTops =    {260.00, 160.00, 210.00};
vector<double> priceMediumTops =  {270.00, 170.00, 220.00};
vector<double> priceLargeTops =    {280.00, 180.00, 230.00};
vector<double> priceXLargeTops =   {290.00, 190.00, 240.00};
vector<double> priceXXLargeTops =  {300.00, 200.00, 250.00};
// stocks for tops
vector<int> stockXSmallSizeTops =  {100, 100, 100};
vector<int> stockSmallSizeTops =   {100, 100, 100};
vector<int> stockMediumSizeTops = {100, 100, 100};
vector<int> stockLargeSizeTops =   {100, 100, 100};
vector<int> stockXLargeSizeTops =  {100, 100, 100};
vector<int> stockXXLargeSizeTops = {100, 100, 100};
// price for bottoms
vector<double> priceXSmallBottoms =  {250.00, 200.00, 300.00, 250.00};
vector<double> priceSmallBottoms =   {255.00, 210.00, 310.00, 260.00};
vector<double> priceMediumBottoms = {260.00, 220.00, 320.00, 270.00};
vector<double> priceLargeBottoms =   {265.00, 230.00, 330.00, 280.00};
vector<double> priceXLargeBottoms =  {270.00, 240.00, 340.00, 290.00};
vector<double> priceXXLargeBottoms = {275.00, 250.00, 350.00, 300.00};
// stock for bottoms
vector<int> stockXSmallSizeBottoms =  {100, 100, 100, 100};
vector<int> stockSmallSizeBottoms =   {100, 100, 100, 100};
vector<int> stockMediumSizeBottoms = {100, 100, 100, 100};
vector<int> stockLargeSizeBottoms =   {100, 100, 100, 100};
vector<int> stockXLargeSizeBottoms =  {100, 100, 100, 100};
vector<int> stockXXLargeSizeBottoms = {100, 100, 100, 100};
// price for accessories
vector<double> priceAccessories = {500.00, 50.00};
vector<int> stockAccessories = {100, 100}; // isang price nalang to, since di na applicable si size

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
bool isBought = false;

//NEW FOR RESTOCKS
vector<int> originalStockXSmallSizeTops = stockXSmallSizeTops;
vector<int> originalStockSmallSizeTops = stockSmallSizeTops;
vector<int> originalStockMediumSizeTops = stockMediumSizeTops;
vector<int> originalStockLargeSizeTops = stockLargeSizeTops;
vector<int> originalStockXLargeSizeTops = stockXLargeSizeTops;
vector<int> originalStockXXLargeSizeTops = stockXXLargeSizeTops;

vector<int> originalStockXSmallSizeBottoms = stockXSmallSizeBottoms;
vector<int> originalStockSmallSizeBottoms = stockSmallSizeBottoms;
vector<int> originalStockMediumSizeBottoms = stockMediumSizeBottoms;
vector<int> originalStockLargeSizeBottoms = stockLargeSizeBottoms;
vector<int> originalStockXLargeSizeBottoms = stockXLargeSizeBottoms;
vector<int> originalStockXXLargeSizeBottoms = stockXXLargeSizeBottoms;

vector<int> originalStockAccessories = stockAccessories;


void restoreStocks() { //FOR STOCK REASSIGNMENT

    stockXSmallSizeTops = originalStockXSmallSizeTops;
    stockSmallSizeTops = originalStockSmallSizeTops;
    stockMediumSizeTops = originalStockMediumSizeTops;
    stockLargeSizeTops = originalStockLargeSizeTops;
    stockXLargeSizeTops = originalStockXLargeSizeTops;
    stockXXLargeSizeTops = originalStockXXLargeSizeTops;

    stockXSmallSizeBottoms = originalStockXSmallSizeBottoms;
    stockSmallSizeBottoms = originalStockSmallSizeBottoms;
    stockMediumSizeBottoms = originalStockMediumSizeBottoms;
    stockLargeSizeBottoms = originalStockLargeSizeBottoms;
    stockXLargeSizeBottoms = originalStockXLargeSizeBottoms;
    stockXXLargeSizeBottoms = originalStockXXLargeSizeBottoms;

    stockAccessories = originalStockAccessories;



     if (selectedItems.empty() && isBought) {
    // if(isBought){
            cout << "Your basket is already empty!\n";
            cout <<isBought <<"if\n";
        } else {
          cout<< isBought<<"else\n";
            // Restore stock and empty the basket
            for (int i = 0; i < selectedItems.size(); i++) {
                string item = selectedItems[i];
                string size = selectedSizes[i];
                int quantity = selectedQuantities[i];

                // Restore stock for tops
                if (find(tops.begin(), tops.end(), item) != tops.end()) {
                    int index = find(tops.begin(), tops.end(), item) - tops.begin();
                    if (size == "XS") stockXSmallSizeTops[index] += quantity;
                    else if (size == "S") stockSmallSizeTops[index] += quantity;
                    else if (size == "M") stockMediumSizeTops[index] += quantity;
                    else if (size == "L") stockLargeSizeTops[index] += quantity;
                    else if (size == "XL") stockXLargeSizeTops[index] += quantity;
                    else if (size == "XXL") stockXXLargeSizeTops[index] += quantity;
                }

                // Restore stock for bottoms
                else if (find(bottoms.begin(), bottoms.end(), item) != bottoms.end()) {
                    int index = find(bottoms.begin(), bottoms.end(), item) - bottoms.begin();
                    if (size == "XS") stockXSmallSizeBottoms[index] += quantity;
                    else if (size == "S") stockSmallSizeBottoms[index] += quantity;
                    else if (size == "M") stockMediumSizeBottoms[index] += quantity;
                    else if (size == "L") stockLargeSizeBottoms[index] += quantity;
                    else if (size == "XL") stockXLargeSizeBottoms[index] += quantity;
                    else if (size == "XXL") stockXXLargeSizeBottoms[index] += quantity;
                }

                // Restore stock for accessories (no size check)
                else if (find(accessories.begin(), accessories.end(), item) != accessories.end()) {
                    int index = find(accessories.begin(), accessories.end(), item) - accessories.begin();
                    stockAccessories[index] += quantity;
                }
            }

            // Clear the basket
            subTotal = 0;
            total = 0;
            selectedItems.clear();
            selectedSizes.clear();
            selectedQuantities.clear();
            selectedPrices.clear();

            

            cout << "Your basket has been emptied and stock levels restored.\n";
        }
}

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
        cout << "\n[1] PICK ITEM/S\n";     // Pipili ng items
        cout << "[2] PAY NOW\n";           // magbayad and minus stock
        cout << "[3] CHECK BASKET/CART\n"; // dito pedeng ma-edit pa yung mga napili na
        cout << "[4] BACK\n";              // Back to main menu - item/s will be stay sa cart

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
          pickItem(category, tops, bottoms, accessories,
              priceXSmallTops, priceSmallTops, priceMediumTops, priceLargeTops, priceXLargeTops, priceXXLargeTops,
              
              stockXSmallSizeTops, stockSmallSizeTops, stockMediumSizeTops, stockLargeSizeTops, stockXLargeSizeTops, stockXXLargeSizeTops,

              priceXSmallBottoms, priceSmallBottoms, priceMediumBottoms, priceLargeBottoms,
              priceXLargeBottoms, priceXXLargeBottoms,

              stockXSmallSizeBottoms, stockSmallSizeBottoms, stockMediumSizeBottoms, stockLargeSizeBottoms, stockXLargeSizeBottoms, stockXXLargeSizeBottoms,

              priceAccessories, stockAccessories,
              
              subTotal,total,
              selectedItems,selectedSizes,selectedQuantities, selectedPrices);
          break;
        }
        case 2:
          payNow(isBought, selectedItems,selectedSizes,selectedQuantities, selectedPrices);
          break;
        case 3: 
        {
          
          checkBasket(tops, bottoms, accessories,
            
            selectedItems,selectedSizes,selectedQuantities, selectedPrices,
          stockXSmallSizeTops, stockSmallSizeTops, stockMediumSizeTops, 

            stockLargeSizeTops, stockXLargeSizeTops, stockXXLargeSizeTops, 
            stockXSmallSizeBottoms, stockSmallSizeBottoms, stockMediumSizeBottoms, 

            stockLargeSizeBottoms, stockXLargeSizeBottoms, stockXXLargeSizeBottoms, 
            stockAccessories, subTotal, total);
          break;
        }
        // case 4:
        // { 
        //   restoreStocks();
        // }
        case 4:
        {
          loopAgain = false;
          break;
        }
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
        cout << "[3] EDIT INVENTORY\n";
        cout << "[4] EXIT\n";
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
         
          addProduct(isAdmin, category, tops, bottoms, accessories,
                     priceXSmallTops, priceSmallTops, priceMediumTops, 
                           priceLargeTops, priceXLargeTops, priceXXLargeTops,

                           stockXSmallSizeTops, stockSmallSizeTops, stockMediumSizeTops, 
                           stockLargeSizeTops, stockXLargeSizeTops, stockXXLargeSizeTops,

                           priceXSmallBottoms, priceSmallBottoms, priceMediumBottoms, 
                           priceLargeBottoms, priceXLargeBottoms, priceXXLargeBottoms,
                           
                           stockXSmallSizeBottoms, stockSmallSizeBottoms, stockMediumSizeBottoms, 
                           stockLargeSizeBottoms, stockXLargeSizeBottoms, stockXXLargeSizeBottoms,
                           
                           priceAccessories, stockAccessories);
          break;
        }
        case 2: // thats a lot of crap
        {
          system("cls");
          displayInventory(tops, bottoms, accessories,
                           priceXSmallTops, priceSmallTops, priceMediumTops, 
                           priceLargeTops, priceXLargeTops, priceXXLargeTops,

                           stockXSmallSizeTops, stockSmallSizeTops, stockMediumSizeTops, 
                           stockLargeSizeTops, stockXLargeSizeTops, stockXXLargeSizeTops,

                           priceXSmallBottoms, priceSmallBottoms, priceMediumBottoms, 
                           priceLargeBottoms, priceXLargeBottoms, priceXXLargeBottoms,
                           
                           stockXSmallSizeBottoms, stockSmallSizeBottoms, stockMediumSizeBottoms, 
                           stockLargeSizeBottoms, stockXLargeSizeBottoms, stockXXLargeSizeBottoms,
                           
                           priceAccessories, stockAccessories);
          break;
        }

case 3:
        {
          update(isAdmin, tops, bottoms, accessories,
                           priceXSmallTops, priceSmallTops, priceMediumTops,
                           priceLargeTops, priceXLargeTops, priceXXLargeTops,

                           stockXSmallSizeTops, stockSmallSizeTops, stockMediumSizeTops,
                           stockLargeSizeTops, stockXLargeSizeTops, stockXXLargeSizeTops,

                           priceXSmallBottoms, priceSmallBottoms, priceMediumBottoms,
                           priceLargeBottoms, priceXLargeBottoms, priceXXLargeBottoms,

                           stockXSmallSizeBottoms, stockSmallSizeBottoms, stockMediumSizeBottoms,
                           stockLargeSizeBottoms, stockXLargeSizeBottoms, stockXXLargeSizeBottoms,

                           priceAccessories, stockAccessories);
          break;
        }
        case 4:
        {
          loopAgain = false;
          isAdmin = false;
          break;
        default:
          cout << "\n[ERROR]: (PLEASE BETWEEN 1 & 7)\n";
          string anything;
          cout << "Press any key to continue...";
          getline(cin >> ws, anything);
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
      cout << "\n[ERROR]: (PLEASE BETWEEN 1 AND 3)\n\n";
      string anything;
      cout << "Press any key to continue...";
      getline(cin >> ws, anything);
    }
  }
}