#include <iostream>
#include <vector>
using namespace std;

void buy (string category[],vector <string> tshirts, vector <string> hoodies, vector <string> shorts) {
    cout << "AVAILABLE ITEMS: \n";
    
        for (int i = 0; i < 3; i++) {
        cout << category[i] << endl;
        
       
        if (i == 0) { 
            for (int j = 0; j < tshirts.size(); j++) {
                cout << "  " << tshirts[j] << endl;
            }
        } else if (i == 1) { 
            for (int j = 0; j < hoodies.size(); j++) {
                cout << "  " << hoodies[j] << endl;
            }
        } else if (i == 2) { 
            for (int j = 0; j < shorts.size(); j++) {
                cout << "  " << shorts[j] << endl;
            }
        }
    }

}
void order () {
    
}
void cashier () {
    
}


