#include <iostream>
#include <vector>
using namespace std;

vector<string> orderItems;
vector<string> orderSizes;
vector<int> orderQuantities;
vector<float> orderPrices;


void buy(string category[], vector<string> t, vector<string> b, vector<string> a,
         vector<float> pr1, vector<float> pr2, vector<float> pr3,
         vector<int> st1, vector<int> st2, vector<int> st3,
         vector<string>& orderItems, vector<string>& orderSizes, 
         vector<int>& orderQuantities, vector<float>& orderPrices) {

    string choice;
    cout << "\nAVAILABLE ITEMS: \n";
    for (int i = 0; i < 3; i++) {
        cout << "[" << i + 1 << "] " << category[i] << endl;
    }
    cout << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == "1") { // Tops
        int choice1;
        for (int j = 0; j < t.size(); j++) {
            cout << j + 1 << ". " << t[j] << endl;
        }
        cout << "Enter: ";
        cin >> choice1;

        if (choice1 > 0 && choice1 <= t.size()) {
            cout << "\nWhat size: \n\n1.Small\n2.Medium\n3.Large";
            cout << "\n\nInput: ";
            int size1;
            cin >> size1;

            int quantity;
            cout << "\nEnter Quantity: ";
            cin >> quantity;

            string sizeStr;
            float price = 0.0;

            if (size1 == 1) {
                sizeStr = "Small";
                price = pr1[choice1 - 1];
                st1[choice1 - 1] -= quantity; // Update stock
            } else if (size1 == 2) {
                sizeStr = "Medium";
                price = pr2[choice1 - 1];
                st2[choice1 - 1] -= quantity; // Update stock
            } else if (size1 == 3) {
                sizeStr = "Large";
                price = pr3[choice1 - 1];
                st3[choice1 - 1] -= quantity; // Update stock
            }

            float subTotal = price * quantity;

            // Add details to order vectors
            orderItems.push_back(t[choice1 - 1]);
            orderSizes.push_back(sizeStr);
            orderQuantities.push_back(quantity);
            orderPrices.push_back(subTotal);

            cout << "\nAdded to cart: " << t[choice1 - 1] << " | " << sizeStr
                 << " | Quantity: " << quantity << " | Price: " << subTotal << endl;
        }
    }
}


void cashier(const vector<string>& orderItems, const vector<string>& orderSizes, 
             const vector<int>& orderQuantities, const vector<float>& orderPrices) {
    cout << "---CASHIER---" << endl;
    cout << "Order Summary:\n";
    float total = 0.0;

    for (int i = 0; i < orderItems.size(); i++) {
        cout << "Item: " << orderItems[i]
             << " | Size: " << orderSizes[i]
             << " | Quantity: " << orderQuantities[i]
             << " | Total Price: " << orderPrices[i] << endl;
        total += orderPrices[i];
    }

    cout << "Total Amount: " << total << endl;
}


int main() {
    string categories[] = {"Tops", "Bottoms", "Accessories"};
    vector<string> tops = {"Shirt", "Blouse", "Jacket"};
    vector<string> bottoms = {"Jeans", "Shorts", "Skirt"};
    vector<string> accessories = {"Belt", "Hat", "Scarf"};

    vector<float> priceSmall = {100.0, 110.0, 120.0};
    vector<float> priceMedium = {150.0, 160.0, 170.0};
    vector<float> priceLarge = {200.0, 210.0, 220.0};
    vector<int> stockSmall = {10, 10, 10};
    vector<int> stockMedium = {10, 10, 10};
    vector<int> stockLarge = {10, 10, 10};

    vector<string> orderItems;
    vector<string> orderSizes;
    vector<int> orderQuantities;
    vector<float> orderPrices;

    buy(categories, tops, bottoms, accessories, priceSmall, priceMedium, priceLarge,
        stockSmall, stockMedium, stockLarge, orderItems, orderSizes, orderQuantities, orderPrices);

    cashier(orderItems, orderSizes, orderQuantities, orderPrices);

    return 0;
}

// if (size1 == 5) { // X-Large
//     if (choice1 - 1 >= prx3.size()) {
//         cout << "Error: Invalid access for X-Large price. Index out of range.\n";
//         continue;
//     }
//     sizeStr = "X-Large";
//     subTotal = prx3[choice1 - 1] * quantity;
//     stx3[choice1 - 1] -= quantity;
//     total += subTotal;
//     cout << t[choice1 - 1] << " | X-Large | Quantity: " << quantity << " | Price: " << subTotal << endl;
// }

// if (size1 == 6) { // XX-Large
//     if (choice1 - 1 >= prxx3.size()) {
//         cout << "Error: Invalid access for XX-Large price. Index out of range.\n";
//         continue;
//     }
//     sizeStr = "XX-Large";
//     subTotal = prxx3[choice1 - 1] * quantity;
//     stxx3[choice1 - 1] -= quantity;
//     total += subTotal;
//     cout << t[choice1 - 1] << " | XX-Large | Quantity: " << quantity << " | Price: " << subTotal << endl;
// }














    // // Initialize variables for analysis
    // string topProduct = "None", lowProduct = "None", noSalesProducts = "";
    // int maxSales = 0, minSales = INT_MAX;

    // // Check sales for Tops
    // for (size_t i = 0 ;i < tops.size(); i++) {
    //     if (salesTops[i] > maxSales) {
    //         maxSales = salesTops[i];
    //         topProduct = tops[i];
    //     }
    //     if (salesTops[i] > 0 && salesTops[i] < minSales) {
    //         minSales = salesTops[i];
    //         lowProduct = tops[i];
    //     }
    //     if (salesTops[i] == 0) {
    //         noSalesProducts += tops[i] + ", ";
    //     }
    // }

    // // Check sales for Bottoms
    // for (size_t i = 0; i < bottoms.size(); i++) {
    //     if (salesBottoms[i] > maxSales) {
    //         maxSales = salesBottoms[i];
    //         topProduct = bottoms[i];
    //     }
    //     if (salesBottoms[i] > 0 && salesBottoms[i] < minSales) {
    //         minSales = salesBottoms[i];
    //         lowProduct = bottoms[i];
    //     }
    //     if (salesBottoms[i] == 0) {
    //         noSalesProducts += bottoms[i] + ", ";
    //     }
    // }

    // // Check sales for Accessories
    // for (size_t i = 0; i < accessories.size(); i++) {
    //     if (salesAccessories[i] > maxSales) {
    //         maxSales = salesAccessories[i];
    //         topProduct = accessories[i];
    //     }
    //     if (salesAccessories[i] > 0 && salesAccessories[i] < minSales) {
    //         minSales = salesAccessories[i];
    //         lowProduct = accessories[i];
    //     }
    //     if (salesAccessories[i] == 0) {
    //         noSalesProducts += accessories[i] + ", ";
    //     }
    // }

    // // Display results
    // cout << "\n[ ANALYSIS ]\n";
    // cout << "Top Selling Product: " << topProduct << " (" << maxSales << " units)\n";
    // cout << "Lowest Selling Product: " << lowProduct << " (" << minSales << " units)\n";
    // cout << "Products with No Sales: " << (noSalesProducts.empty() ? "None" : noSalesProducts.substr(0, noSalesProducts.size() - 2)) << "\n";

    // cout << "\nPress any key to return to the menu...";
    // string anything;
    // getline(cin >> ws, anything);
    



    