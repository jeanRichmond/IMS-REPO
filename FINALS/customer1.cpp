#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;



void pickItem(string category[], vector<string> t, vector<string> b, vector<string> a, 
 vector<double>& prx1, vector<double>& pr1, vector<double>& pr2, 
 vector<double>& pr3, vector<double>& prx3, vector<double>& prxx3, 

 vector<int>& stx1, vector<int>& st1, vector<int>& st2,vector<int>& st3,
 vector<int>& stx3,vector<int>& stxx3,

 vector<double>& prx4, vector<double>& pr4, vector<double>& pr5, vector<double>& pr6, 
 vector<double>& prx6, vector<double>& prxx6,

 vector<int>& stx4, vector<int>& st4, vector<int>& st5, vector<int>& st6,
 vector<int>& stx6, vector<int>& stxx6,

 vector<double> pr7,
 vector<int> st7,
 
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
           
           // c out << j + 1 << ". " << t[j]  << " " << "(Extra-Small: " << endl;
           
        //    Extra-Small\n2.Small\n3.Medium\n4.Large\n5.X-Large\n6.XX-Large
       cout << "TOPS:\n" << endl;
       cout << setw(3) << left << "#" << setw(1)
         << setw(20) << left << "NAME" << setw(1)
         
         << setw(10) << left << "(XS)PRICE " << setw(1) << setw(15) << left << setw(1)
         << setw(10) << left << "(S)PRICE " << setw(1) << setw(15) << left << setw(1)
         << setw(10) << left << "(M)PRICE " << setw(1) << setw(15) << left << setw(1)
         << setw(10) << left << "(L)PRICE " << setw(1) << setw(15) << left << setw(1)
         << setw(10) << left << "(XL)PRICE " << setw(1) << setw(15) << left << setw(1)
         << setw(10) << left << "(XXL)PRICE " << setw(1) << setw(15) << left;
            
          cout << endl;

           for (int j = 0; j < t.size(); j++) {
           cout << endl << setw(3) << left << j + 1 << setw(1) 
             << setw(20) << left << t[j] << setw(1)
            << setw(10) << left << prx1[j] << setw(1) << setw(10) << left  << setw(1)
             << setw(10) << left << pr1[j] << setw(1) << setw(15) << left << setw(1)
             << setw(10) << left << pr2[j] << setw(1) << setw(15) << left << setw(1)
             << setw(10) << left << pr3[j] << setw(1) << setw(15) << left << setw(1)
            
             << setw(10) << left << prx3[j] << setw(1) << setw(15) << left << setw(1)
             << setw(10) << left << prxx3[j] << setw(1) << setw(15) << left  << setw(1);
             
             cout << endl;
            }


        
        cout << endl;

        cout << "Enter: ";
        cin >> choice1;
        
        for(int i = 0; i < t.size(); i++){
            if((choice1 - 1) == i){
               
                cout<<"\nWhat size: \n\n1.Extra-Small\n2.Small\n3.Medium\n4.Large\n5.X-Large\n6.XX-Large";
                cout<<"\n\nInput: "; 
                int size1;
                cin >> size1;

                int quantity;
                cout << "\nEnter Quantity: ";
                cin >> quantity;

                string sizeStr;
                
                if (size1 == 1) { //for xtra-small
                    if (quantity > stx1[choice1 -1]) {
                        cout << "Not enough stocks.\n";
                    } else if (quantity <= 0) {
                        cout << "Invalid input...\n";
                    } else {
                    sizeStr = "Extra-Small";
                    subTotal = (prx1[choice1 - 1] * quantity);
                    (stx1[choice1 -1] -= quantity); 
                    total += subTotal;
                    cout << t[choice1 -1] << " | " << "Extra-Small" << " | " << "Quantity: "<< quantity << " |" << " Price: " << subTotal <<endl;
            selectedItems.push_back(t[choice1 - 1]);
            selectedSizes.push_back(sizeStr);
            selectedQuantities.push_back(quantity);
            selectedPrices.push_back(subTotal);                    
                    }
                } 
                if (size1 == 2) { //for small
                    if (quantity > st1[choice1 -1]) {
                        cout << "Not enough stocks.\n";
                    } else if (quantity <= 0) {
                        cout << "Invalid input...\n";
                    } else {                
                    sizeStr = "Small";
                    subTotal = (pr1[choice1 - 1] * quantity);
                    (st1[choice1 -1] -= quantity); 
                    total += subTotal;
                    cout << t[choice1 -1] << " | " << "Small" << " | " << "Quantity: "<< quantity << " |" << " Price: " << subTotal <<endl;
            selectedItems.push_back(t[choice1 - 1]);
            selectedSizes.push_back(sizeStr);
            selectedQuantities.push_back(quantity);
            selectedPrices.push_back(subTotal);                    
                    }
                } 
                if (size1 == 3) { //for medium
                    if (quantity > st2[choice1 -1]) {
                        cout << "Not enough stocks.\n";
                    } else if (quantity <= 0) {
                        cout << "Invalid input...\n";
                    } else {                
                    sizeStr = "Medium";
                    subTotal = (pr2[choice1 - 1] * quantity);
                    (st2[choice1 -1] -= quantity);   
                    total += subTotal;
                    cout << t[choice1 -1] << " | " << "Medium" << " | " << "Quantity: "<< quantity << " |" << " Price: " << subTotal <<endl; 
            selectedItems.push_back(t[choice1 - 1]);
            selectedSizes.push_back(sizeStr);
            selectedQuantities.push_back(quantity);
            selectedPrices.push_back(subTotal);                    
                    }
                }
                if (size1 == 4) { // for large
                    if (quantity > st3[choice1 -1]) {
                        cout << "Not enough stocks.\n";
                    } else if (quantity <= 0) {
                        cout << "Invalid input...\n";
                    } else {                
                   sizeStr = "Large";
                   subTotal = (pr3[choice1 - 1] * quantity);       
                   (st3[choice1 -1] -= quantity);        
                   total += subTotal;
                   cout << t[choice1 -1] << " | " << "Large" << " | " << "Quantity: " << quantity << " |" << " Price: " << subTotal <<endl;
            selectedItems.push_back(t[choice1 - 1]);
            selectedSizes.push_back(sizeStr);
            selectedQuantities.push_back(quantity);
            selectedPrices.push_back(subTotal);                   
                   }                    
                }
                if (size1 == 5) { // for Xlarge
                    if (quantity > stx3[choice1 -1]) {
                        cout << "Not enough stocks.\n";
                    } else if (quantity <= 0) {
                        cout << "Invalid input...\n";
                    } else {                
                   sizeStr = "X-Large";
                   subTotal = prx3[choice1 - 1] * quantity;       
                   (stx3[choice1 -1] -= quantity);       
                   total += subTotal;
                   cout << t[choice1 -1] << " | " << "X-Large" << " | " << "Quantity: " << quantity << " |" << " Price: " << subTotal <<endl; 
            selectedItems.push_back(t[choice1 - 1]);
            selectedSizes.push_back(sizeStr);
            selectedQuantities.push_back(quantity);
            selectedPrices.push_back(subTotal);                   
                   }                   
                }
                   if (size1 == 6) { // for XXlarge
                    if (quantity > stxx3[choice1 -1]) {
                        cout << "Not enough stocks.\n";
                    } else if (quantity <= 0) {
                        cout << "Invalid input...\n";
                    } else {                   
                   sizeStr = "XX-Large";
                   subTotal = prxx3[choice1 - 1] * quantity;       
                   (stxx3[choice1 -1] -= quantity);       
                   total += subTotal;
                   cout << t[choice1 -1] << " | " << "XX-Large" << " | " << "Quantity: " << quantity << " |" << " Price: " << subTotal <<endl;
            selectedItems.push_back(t[choice1 - 1]);
            selectedSizes.push_back(sizeStr);
            selectedQuantities.push_back(quantity);
            selectedPrices.push_back(subTotal);                   
                   }             
                }      

                



            }
        
            
        }
    

    
    } else if (choice == "2") { // bottoms
        int choice2;

        cout << "BOTTOMS:\n" << endl;
       cout << setw(3) << left << "#" << setw(1)
         << setw(20) << left << "NAME" << setw(1)
         
         << setw(10) << left << "(XS)PRICE " << setw(1) << setw(15) << left << setw(1)
         << setw(10) << left << "(S)PRICE " << setw(1) << setw(15) << left << setw(1)
         << setw(10) << left << "(M)PRICE " << setw(1) << setw(15) << left << setw(1)
         << setw(10) << left << "(L)PRICE " << setw(1) << setw(15) << left << setw(1)
         << setw(10) << left << "(XL)PRICE " << setw(1) << setw(15) << left << setw(1)
         << setw(10) << left << "(XXL)PRICE " << setw(1) << setw(15) << left;
            
          cout << endl;

            for (int j = 0; j < b.size(); j++) {
            cout << endl << setw(3) << left << j + 1 << setw(1) 
             << setw(20) << left << b[j] << setw(1)
            << setw(10) << left << prx4[j] << setw(1) << setw(15) << left  << setw(1)
             << setw(10) << left << pr4[j] << setw(1) << setw(15) << left << setw(1)
             << setw(10) << left << pr5[j] << setw(1) << setw(15) << left << setw(1)
             << setw(10) << left << pr6[j] << setw(1) << setw(15) << left << setw(1)
            
             << setw(10) << left << prx6[j] << setw(1) << setw(15) << left << setw(1)
             << setw(10) << left << prxx6[j] << setw(1) << setw(15) << left  << setw(1);
             
             cout << endl;
        } 

        cout << endl;
        
        cout << "Enter: ";
        cin >> choice2;
        
        for(int i = 0; i < b.size(); i++){
            if((choice2 - 1) == i){
                cout<<"\nWhat size: \n\n1.Extra-Small\n2.Small\n3.Medium\n4.Large\n5.X-Large\n6.XX-Large";
                cout<<"\n\nInput: "; 
                int size2;
                cin >> size2;

                int quantity;
                cout << "\nEnter Quantity: ";
                cin >> quantity;
                  string sizeStr;
                
                if (size2 == 1) { //for small
                    if (quantity > stx4[choice2 -1]) {
                        cout << "Not enough stocks.\n";
                    } else if (quantity <= 0) {
                        cout << "Invalid input...\n";
                    } else {                
                    sizeStr = "Extra-Small";
                    subTotal = (prx4[choice2 -1] * quantity);
                    (stx4[choice2 -1] -= quantity); 
                    total += subTotal;
                    cout << b[choice2 -1] << " | " << "Extra-Small" << " | " << "Quantity: "<< quantity << " |" << " Price: " << subTotal <<endl;
            selectedItems.push_back(b[choice2 - 1]);
            selectedSizes.push_back(sizeStr);
            selectedQuantities.push_back(quantity);
            selectedPrices.push_back(subTotal);                    
                    }
                }
                if (size2 == 2) { //for small
                    if (quantity > st4[choice2 -1]) {
                        cout << "Not enough stocks.\n";
                    } else if (quantity <= 0) {
                        cout << "Invalid input...\n";
                    } else {                                
                    sizeStr = "Small";
                    subTotal = (pr4[choice2 -1] * quantity);
                    (st4[choice2 -1] -= quantity); 
                    total += subTotal;
                    cout << b[choice2 -1] << " | " << "Small" << " | " << "Quantity: "<< quantity << " |" << " Price: " << subTotal <<endl;
            selectedItems.push_back(b[choice2 - 1]);
            selectedSizes.push_back(sizeStr);
            selectedQuantities.push_back(quantity);
            selectedPrices.push_back(subTotal);                    
                    }
                } 
                if (size2 == 3) {
                    if (quantity > st5[choice2 -1]) {
                        cout << "Not enough stocks.\n";
                    } else if (quantity <= 0) {
                        cout << "Invalid input...\n";
                    } else {                
                    sizeStr = "Medium";
                    subTotal = (pr5[choice2 -1] * quantity);
                    (st5[choice2 -1] -= quantity); 
                    total += subTotal;
                    cout << b[choice2 -1] << " | " << "Medium" << " | " << "Quantity: "<< quantity << " |" << " Price: " << subTotal <<endl;
            selectedItems.push_back(b[choice2 - 1]);
            selectedSizes.push_back(sizeStr);
            selectedQuantities.push_back(quantity);
            selectedPrices.push_back(subTotal);                    
                    }                   
                }
                if (size2 == 4) {
                    if (quantity > st6[choice2 -1]) {
                        cout << "Not enough stocks.\n";
                    } else if (quantity <= 0) {
                        cout << "Invalid input...\n";
                    } else {                
                    sizeStr = "Large";
                    subTotal = (pr6[choice2 -1] * quantity);
                    (st6[choice2 -1] -= quantity); 
                    total += subTotal;
                    cout << b[choice2 -1] << " | " << "Large" << " | " << "Quantity: "<< quantity << " |" << " Price: " << subTotal <<endl;
            selectedItems.push_back(b[choice2 - 1]);
            selectedSizes.push_back(sizeStr);
            selectedQuantities.push_back(quantity);
            selectedPrices.push_back(subTotal);                    
                    }                   
                }
                if (size2 == 5) {
                    if (quantity > stx6[choice2 -1]) {
                        cout << "Not enough stocks.\n";
                    } else if (quantity <= 0) {
                        cout << "Invalid input...\n";
                    } else {                
                    sizeStr = "X-Large";
                    subTotal = (prx6[choice2 -1] * quantity);
                    (stx6[choice2 -1] -= quantity); 
                    total += subTotal;
                    cout << b[choice2 -1] << " | " << "X-Large" << " | " << "Quantity: "<< quantity << " |" << " Price: " << subTotal <<endl;
            selectedItems.push_back(b[choice2 - 1]);
            selectedSizes.push_back(sizeStr);
            selectedQuantities.push_back(quantity);
            selectedPrices.push_back(subTotal);                    
                    }                   
                }
                if (size2 == 6) {
                    if (quantity > stxx6[choice2 -1]) {
                        cout << "Not enough stocks.\n";
                    } else if (quantity <= 0) {
                        cout << "Invalid input...\n";
                    } else {                
                    sizeStr = "XX-Large";
                    subTotal = prxx6[choice2 - 1] * quantity;  
                    (stxx6[choice2 -1] -= quantity); 
                    total += subTotal;
                    cout << b[choice2 -1] << " | " << "XX-Large" << " | " << "Quantity: "<< quantity << " |" << " Price: " << subTotal <<endl;
            selectedItems.push_back(b[choice2 - 1]);
            selectedSizes.push_back(sizeStr);
            selectedQuantities.push_back(quantity);
            selectedPrices.push_back(subTotal);                    
                    }             
                }

            }
            }
            
        
        

    } else if (choice == "3") {
        int choice3;

        cout << "Accessories:\n" << endl;
    cout << setw(3) << left << "#" << setw(1)
         << setw(20) << left << "NAME" << setw(1)
         << setw(15) << left << "PRICE" << setw(1) << endl;

            for (int j = 0; j < a.size(); j++) {
            cout << setw(3) << left << j + 1 << setw(1)
             << setw(20) << left << a[j] << setw(1)
             << setw(15) << left << pr7[j] << setw(1) << endl;
        }
        cout << endl;

        cout << "Enter: ";
        cin >> choice3;
        
        for(int i = 0; i < a.size(); i++){
            if((choice3 - 1) == i){
                // cout<<"\nWhat size: \n\n1.Small\n2.Medium\n3.Large";
                // cout<<"\n\nInput: "; 
                // int size3;
                // cin >> size3;

                int quantity;
                cout << "\nEnter Quantity: ";
                cin >> quantity;
                string sizeStr;
                

                // if (size3 == 1) { 
                     if (quantity > st7[choice3 -1]) {
                        cout << "Not enough stocks.\n";
                    } else if (quantity <= 0) {
                        cout << "Invalid input...\n";
                    } else { 
                    sizeStr = "N/A";
                    subTotal = (pr7[choice3 -1] * quantity);
                    (st7[choice3 -1] -= quantity); 
                    total += subTotal;
                    cout << t[choice3 -1] << " | " << "Small" << " | " << "Quantity: "<< quantity << " |" << " Price: " << subTotal <<endl;
                    }
                // } 

            selectedItems.push_back(a[choice3 - 1]);
            selectedSizes.push_back(sizeStr);
            selectedQuantities.push_back(quantity);
            selectedPrices.push_back(subTotal);
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





void payNow (vector<string>& selectedItems,  
             vector<string>& selectedSizes, 
             vector<int>& selectedQuantities,  
             vector<double>& selectedPrices) {

    cout << "\n---CASHIER---" << endl;
    cout << "Order Summary:\n";
    double total = 0.0;

    if(selectedItems.empty()){
        cout<<"The basket is Empty.";
        
    } else {
  cout << left << setw(20) << "ITEM" 
         << setw(15) << "SIZE" 
         << setw(15) << "PRICE"
         << setw(15) << "QUANTITY" 
         << setw(15) << "SUBTOTAL" 
         << endl;
         cout << endl;
    //rinig ba ko 
    // Loop through the selected items and display their details
    for (int i = 0; i < selectedItems.size(); i++) {
        cout << left << setw(20) << selectedItems[i] 
             << setw(15) << selectedSizes[i]
             << setw(15) << selectedPrices[i] / selectedQuantities[i]
             << setw(15) << selectedQuantities[i]
             << setw(15) << fixed << setprecision(2) << selectedPrices[i] 
             << endl;
             total += selectedPrices[i];
    }   
             
             cout << "\nTotal Amount: " << total << endl;
        double money;
        
        while (true) {
             cout << "Enter Your Money: ";
             cin >> money;
             if (money <= 0) {
                cout << "\nInvalid input...\n";
             } else if (money < total) {
                cout << "\nInsufficient Money! You need " <<  total - money << " more.\n";
             } else if (money == total) {
                cout << "You have no change, Thanks for purchasing.\n\n";
                break;
             } else {
                cout << "Your change is: " << money - total <<", Thanks for purchasing."<< endl<<endl;
                break;
             }
        }
   
    }

}


void checkBasket (vector<string>& selectedItems,  
             vector<string>& selectedSizes, 
             vector<int>& selectedQuantities) {

    cout << "\n---BASKET---\n" << endl;

    string basketChoice;

    cout << "\n[1] SHOW ITEM/S\n";
    cout << "[2] CANCEL / EMPTY BASKET\n";

    if (basketChoice == "1") {

   if (selectedItems.empty()) {
        cout << "Your basket is Empty!!\n";
    } else {
               for (int i = 0; i < selectedItems.size(); i++) {
        cout << "Item: " << selectedItems.at(i) 
             << " | Size: " << selectedSizes.at(i)
             << " | Quantity: " << selectedQuantities.at(i) << endl;
     }
    }

    } else if (basketChoice == "2") {
   
}
    

}




