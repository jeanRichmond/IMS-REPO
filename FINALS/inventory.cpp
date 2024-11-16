#include <iostream>
using namespace std;

void addProduct () {
    cout<<"addProduct\n";


    
}


    void displayInventory (int cat1, int cat2, int cat3, string catergory[]) {
    cout<<"Display Inventory\n\n";
    cout<<"#\tCategory\tName\tSize\tPrice\tStock\n";
    int i = 0;
    for(; i < (cat1);i++){
        for (int j = 0; j < 1; j++){
            cout<< i +1 << "\t"<< catergory[j];
        }
        cout<<endl;
        
        
    }
    
        

}

void productSales () {
    cout<<"product sales\n";
    
}

void salesHistory () {
    cout<<"Sales history\n";
}

void restock () {
    cout<<"restock\n";
}

void editHistory () {
    cout<<"edit history\n";
}

