#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // Categories and Items
    string category[] = {"Tops", "Bottoms", "Accessories"};
    vector<string> tops = {"Polo", "T-Shirt", "Hoody"};
    vector<string> bottoms = {"Shorts", "Skirts", "Sweat Pants", "Denim"};
    vector<string> accessories = {"Cap", "Panyo"};
    
    // Prices and Stock for Tops
    vector<float> priceSmallTops = {100.00, 100.00, 100.00};
    vector<float> priceMediumTops = {150.00, 150.00, 150.00};
    vector<float> priceLargeTops = {200.00, 200.00, 200.00};
    vector<int> stockSmallTops = {100, 100, 100};
    vector<int> stockMediumTops = {200, 200, 200};
    vector<int> stockLargeTops = {300, 300, 300};

    // Prices and Stock for Bottoms
    vector<float> priceSmallBottoms = {100.00, 100.00, 100.00, 100.00};
    vector<float> priceMediumBottoms = {150.00, 150.00, 150.00, 150.00};
    vector<float> priceLargeBottoms = {200.00, 200.00, 200.00, 200.00};
    vector<int> stockSmallBottoms = {100, 100, 100, 100};
    vector<int> stockMediumBottoms = {200, 200, 200, 200};
    vector<int> stockLargeBottoms = {300, 300, 300, 300};

    // Prices and Stock for Accessories
    vector<float> priceSmallAccessories = {100.00, 100.00};
    vector<float> priceMediumAccessories = {150.00, 150.00};
    vector<float> priceLargeAccessories = {200.00, 200.00};
    vector<int> stockSmallAccessories = {100, 100};
    vector<int> stockMediumAccessories = {200, 200};
    vector<int> stockLargeAccessories = {300, 300};

    // Menu
    string size[] = {"Small", "Medium", "Large"};
    string selectedCategory;
    int categoryChoice, itemChoice, sizeChoice;
    bool exit = false;

    cout << "Welcome to the Store!\n";
    while (!exit) {
        cout << "\nSelect a category:\n";
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << category[i] << endl;
        }
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> categoryChoice;

        if (categoryChoice == 4) {
            exit = true;
            cout << "Thank you for shopping!\n";
            break;
        }

        switch (categoryChoice) {
            case 1:
                selectedCategory = "Tops";
                cout << "\nAvailable Tops:\n";
                for (int i = 0; i < tops.size(); i++) {
                    cout << i + 1 << ". " << tops[i] << endl;
                }
                break;
            case 2:
                selectedCategory = "Bottoms";
                cout << "\nAvailable Bottoms:\n";
                for (int i = 0; i < bottoms.size(); i++) {
                    cout << i + 1 << ". " << bottoms[i] << endl;
                }
                break;
            case 3:
                selectedCategory = "Accessories";
                cout << "\nAvailable Accessories:\n";
                for (int i = 0; i < accessories.size(); i++) {
                    cout << i + 1 << ". " << accessories[i] << endl;
                }
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                continue;
        }

        cout << "Enter the item number to select: ";
        cin >> itemChoice;

        if ((categoryChoice == 1 && itemChoice <= tops.size()) ||
            (categoryChoice == 2 && itemChoice <= bottoms.size()) ||
            (categoryChoice == 3 && itemChoice <= accessories.size())) {
            cout << "\nChoose a size:\n";
            for (int i = 0; i < 3; i++) {
                cout << i + 1 << ". " << size[i] << endl;
            }
            cout << "Enter size choice: ";
            cin >> sizeChoice;

            if (sizeChoice >= 1 && sizeChoice <= 3) {
                int stock = 0;
                float price = 0.0;

                if (selectedCategory == "Tops") {
                    if (sizeChoice == 1) {
                        stock = stockSmallTops[itemChoice - 1];
                        price = priceSmallTops[itemChoice - 1];
                    } else if (sizeChoice == 2) {
                        stock = stockMediumTops[itemChoice - 1];
                        price = priceMediumTops[itemChoice - 1];
                    } else if (sizeChoice == 3) {
                        stock = stockLargeTops[itemChoice - 1];
                        price = priceLargeTops[itemChoice - 1];
                    }
                } else if (selectedCategory == "Bottoms") {
                    if (sizeChoice == 1) {
                        stock = stockSmallBottoms[itemChoice - 1];
                        price = priceSmallBottoms[itemChoice - 1];
                    } else if (sizeChoice == 2) {
                        stock = stockMediumBottoms[itemChoice - 1];
                        price = priceMediumBottoms[itemChoice - 1];
                    } else if (sizeChoice == 3) {
                        stock = stockLargeBottoms[itemChoice - 1];
                        price = priceLargeBottoms[itemChoice - 1];
                    }
                } else if (selectedCategory == "Accessories") {
                    if (sizeChoice == 1) {
                        stock = stockSmallAccessories[itemChoice - 1];
                        price = priceSmallAccessories[itemChoice - 1];
                    } else if (sizeChoice == 2) {
                        stock = stockMediumAccessories[itemChoice - 1];
                        price = priceMediumAccessories[itemChoice - 1];
                    } else if (sizeChoice == 3) {
                        stock = stockLargeAccessories[itemChoice - 1];
                        price = priceLargeAccessories[itemChoice - 1];
                    }
                }

                if (stock > 0) {
                    cout << "Item: " << ((selectedCategory == "Tops") ? tops[itemChoice - 1] :
                                    (selectedCategory == "Bottoms") ? bottoms[itemChoice - 1] :
                                    accessories[itemChoice - 1])
                         << " | Size: " << size[sizeChoice - 1]
                         << " | Price: $" << price
                         << " | Stock: " << stock << endl;
                    cout << "Do you want to buy this item? (1 for Yes, 0 for No): ";
                    int buyChoice;
                    cin >> buyChoice;
                    if (buyChoice == 1) {
                        cout << "Purchase successful!\n";
                        // Decrease stock here
                    } else {
                        cout << "Purchase canceled.\n";
                    }
                } else {
                    cout << "Sorry, this item is out of stock.\n";
                }
            } else {
                cout << "Invalid size choice.\n";
            }
        } else {
            cout << "Invalid item choice.\n";
        }
    }

    return 0;
}
