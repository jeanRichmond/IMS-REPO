#include <iostream>
#include <vector>
using namespace std;



void buy (string category[], vector<string> t, vector<string> b, vector<string> a, 
 vector<float> pr1, vector<float> pr2, vector<float> pr3, 
 vector<int> st1,vector<int> st2,vector<int> st3,
 vector<float> pr4, vector<float> pr5, vector<float> pr6, 
 vector<int> st4,vector<int> st5,vector<int> st6,
 vector<float> pr7, vector<float> pr8, vector<float> pr9, 
 vector<int> st7,vector<int> st8,vector<int> st9, 
 
        double &subTotal, double &total, 
         vector<string>& selectedItems,
         vector<string>& selectedSizes,
         vector<int>& selectedQuantities,
         vector<double>& selectedPrices) {

    bool exitBool = false;
    // string exit; //for you

    string choice;
   

    while (!exitBool) {
        cout << "\nAVAILABLE ITEMS: \n";
        cout << endl;
    
        for (int i = 0; i < 3; i++) {
            cout << "[" << i + 1 << "]" << " " << category[i] << endl;
        }
         cout << "[4] BACK\n";
    cout << endl;

    cout << "Enter your choice: ";
   
    cin >> choice;
    cout << endl;

    if (choice == "1" ) { //tops
        int choice1;
            for (int j = 0; j < t.size(); j++) {
            cout << j + 1 << ". " << t[j] << endl;
        }
        cout << endl;
        // if (choice1 == 1) {
            
        // }
        cout << "Enter: ";
        cin >> choice1;
        
        for(int i = 0; i < t.size(); i++){
            if((choice1 - 1) == i){
               
                cout<<"\nWhat size: \n\n1.Small\n2.Medium\n3.Large";
                cout<<"\n\nInput: "; 
                int size1;
                cin >> size1;

                int quantity;
                cout << "\nEnter Quantity: ";
                cin >> quantity;

                string sizeStr;
                

                if (size1 == 1) { //for small
                    sizeStr = "Small";
                    subTotal = (pr1[size1 -1] * quantity);
                    (st1[size1 -1] - quantity); 
                    total += subTotal;
                    cout << t[choice1 -1] << " | " << "Small" << " | " << "Quantity: "<< quantity << " |" << " Price: " << subTotal <<endl;

                    
                } 
                if (size1 == 2) { //for medium
                    sizeStr = "Medium";
                    subTotal = (pr2[size1 -1] * quantity);
                    (st2[size1 -1] - quantity);   
                    total += subTotal;
                    cout << t[choice1 -1] << " | " << "Medium" << " | " << "Quantity: "<< quantity << " |" << " Price: " << subTotal <<endl; 
                }
                if (size1 == 3) { // for large
                   sizeStr = "Large";
                   subTotal = (pr3[size1 -1] * quantity);       
                   (st3[size1 -1] - quantity);       
                   total += subTotal;
                   cout << t[choice1 -1] << " | " << "Large" << " | " << "Quantity: " << quantity << " |" << " Price: " << subTotal <<endl;                    
                }

            selectedItems.push_back(t[choice1 - 1]);
            selectedSizes.push_back(sizeStr);
            selectedQuantities.push_back(quantity);
            selectedPrices.push_back(subTotal);

            }
            
        }


    } else if (choice == "2") { // bottoms
        int choice2;
            for (int j = 0; j < b.size(); j++) {
            cout << j + 1 << ". " << b[j] << endl;
        } 
        cout << endl;
        
        cout << "Enter: ";
        cin >> choice2;
        
        for(int i = 0; i < t.size(); i++){
            if((choice2 - 1) == i){
                cout<<"\nWhat size: \n\n1.Small\n2.Medium\n3.Large";
                cout<<"\n\nInput: "; 
                int size2;
                cin >> size2;

                int quantity;
                cout << "\nEnter Quantity: ";
                cin >> quantity;
                

                if (size2 == 1) { //for small
                    subTotal = (pr4[size2 -1] * quantity);
                    (st4[size2 -1] - quantity); 
                    total += subTotal;
                    cout << t[choice2 -1] << " | " << "Small" << " | " << "Quantity: "<< quantity << " |" << " Price: " << subTotal <<endl;
                } 
                if (size2 == 2) {
                    subTotal = (pr5[size2 -1] * quantity);
                    (st5[size2 -1] - quantity); 
                    total += subTotal;
                    cout << t[choice2 -1] << " | " << "Medium" << " | " << "Quantity: "<< quantity << " |" << " Price: " << subTotal <<endl;                   
                }
                if (size2 == 3) {
                    subTotal = (pr6[size2 -1] * quantity);
                    (st6[size2 -1] - quantity); 
                    total += subTotal;
                    cout << t[choice2 -1] << " | " << "Large" << " | " << "Quantity: "<< quantity << " |" << " Price: " << subTotal <<endl;                   
                }
            }
            }
            
        
        

    } else if (choice == "3") {
        int choice3;
            for (int j = 0; j < a.size(); j++) {
            cout << j + 1 <<  ". " << a[j] << endl;
        }
        cout << endl;

        cout << "Enter: ";
        cin >> choice3;
        
        for(int i = 0; i < t.size(); i++){
            if((choice3 - 1) == i){
                cout<<"\nWhat size: \n\n1.Small\n2.Medium\n3.Large";
                cout<<"\n\nInput: "; 
                int size3;
                cin >> size3;

                int quantity;
                cout << "\nEnter Quantity: ";
                cin >> quantity;
                

                if (size3 == 1) { //for small
                    subTotal = (pr7[size3 -1] * quantity);
                    (st7[size3 -1] - quantity); 
                    total += subTotal;
                    cout << t[choice3 -1] << " | " << "Small" << " | " << "Quantity: "<< quantity << " |" << " Price: " << subTotal <<endl;
                } 
                if (size3 == 2) {
                    subTotal = (pr8[size3 -1] * quantity);
                    (st8[size3 -1] - quantity); 
                    total += subTotal;
                    cout << t[choice3 -1] << " | " << "Medium" << " | " << "Quantity: "<< quantity << " |" << " Price: " << subTotal <<endl;                   
                }
                if (size3 == 3) {
                    subTotal = (pr9[size3 -1] * quantity);
                    (st9[size3 -1] - quantity); 
                    total += subTotal;
                    cout << t[choice3 -1] << " | " << "Large" << " | " << "Quantity: "<< quantity << " |" << " Price: " << subTotal <<endl;
                    // cout <<  "--" << total << "--" << endl;                
                }
            }
        }
    } else if (choice == "4") {
        exitBool = true;
        break;
    } else {
        cout << "\nInvalid po \n";
    }

    
}
}



void order () {
    cout << "---CASHIER---";
    cout << "Order Area" << endl;

}




void cashier (vector<string>& selectedItems,  
             vector<string>& selectedSizes, 
             vector<int>& selectedQuantities,  
             vector<double>& selectedPrices) {

    cout << "---CASHIER---" << endl;
    cout << "Order Summary:\n";
    double total = 0.0;

    for (int i = 0; i < selectedItems.size(); i++) {
        cout << "Item: " << selectedItems.at(i)
             << " | Size: " << selectedSizes.at(i)
             << " | Quantity: " << selectedQuantities.at(i)
             << " | Total Price: " << selectedPrices.at(i) << endl;
        total += selectedPrices[i];
    }

    cout << "Total Amount: " << total << endl;
}

