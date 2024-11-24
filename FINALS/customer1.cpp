#include <iostream>
#include <vector>
using namespace std;

void buy (string category[], vector<string> t, vector<string> b, vector<string> a, 
 vector<float> p1, vector<float> p2, vector<float> p3, 
 vector<int> s1,vector<int> s2,vector<int> s3,
 vector<float> p4, vector<float> p5, vector<float> p6, 
 vector<int> s4,vector<int> s5,vector<int> s6,
 vector<float> p7, vector<float> p8, vector<float> p9, 
 vector<int> s7,vector<int> s8,vector<int> s9) {

    string choice;
    cout << "\nAVAILABLE ITEMS: \n";
        cout << endl;
    
        for (int i = 0; i < 3; i++) {
            cout << "[" << i + 1 << "]" << category[i] << ":" << endl;
        }
    cout << endl;

    while (true) {
    cout << "Enter your choice: ";
    cin >> choice;

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
                cout<<"What size: \n\n1.Small\n2.Medium\n3.Large";
                cout<<"\nInput: "; 
                int size1;
                cin >> size1;
                    
                    
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
                cout<<"What size: \n\n1.Small\n2.Medium\n3.Large";
                cout<<"\nInput: "; 
                int size2;
                cin >> size2;
                    
                    
            }
            
        }
        

    } else if (choice == "3") {
            for (int j = 0; j < a.size(); j++) {
            cout << j + 1 <<  ". " << a[j] << endl;
        }
        cout << endl;
    } else {
        cout << "\nInvalid po \n";
    }

    
}
}



void order () {
    


}
void cashier () {
    
}


