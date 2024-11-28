#include <bits/stdc++.h>
using namespace std;
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define BLACK "\033[30m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

void login() // authentications
{ 
    string adminUsername = "123";
    string adminPassword = "123";
    string emUsername = "456";
    string emPassword = "456";

    string user;
    string pass;
    bool loginTrue = true;
    int maxAttempt = 3;
    int attempt = 0;

    while (loginTrue && attempt <= maxAttempt){
    cout << BLACK <<"=======================================================================\n";
    cout << "======>>>><<<<[ "<< RED << "T "
     << GREEN << "H " 
     << BLUE << "R " 
     << YELLOW << "I " 
     << MAGENTA << "F "
     << CYAN << "T  "
     << BLACK << "C "
     << RED << "L "
     << GREEN << "O "
     << BLUE << "T " 
     << YELLOW << "H "
     << MAGENTA << "I "
     << CYAN << "N "
     << BLACK << "G  "
     << RED << "S " 
     << GREEN << "T "
     << BLUE << "O "
     << YELLOW << "R "
     << MAGENTA "E " 
     << BLACK << "]>>>><<<<======\n" << RESET;
    cout << BLACK << "=======================================================================\n\n";

    cout << BLACK << "ENTER USERNAME: " << RESET;
    getline(cin >> ws, user);

    cout << BLACK << "ENTER PASSWORD: " << RESET;
    getline(cin >> ws,pass);  

   
    if (adminUsername == user && adminPassword == pass) { //admin access
        cout << GREEN << "\nLOGIN SUCCESSFULLY\n" << RESET;
        loginTrue = false;
    } else {    
        cout << RED << "\nLOGIN FAILED. PLEASE TRY AGAIN!. (ATTEMPTS # " << attempt + 1 << ")\n" << RESET;
        attempt++;
    }  
    
     if (attempt >= maxAttempt){
        cout << "\nTOO MANY ATTEMPTS. FAILED TO LOGIN. PLEASE TRY AGAIN!\n\n";
        loginTrue = false;
        exit(0);
        
    }
    }
}
void addProduct()
{
    string adminPass = "123";
    string pass;   
    cout << "addProduct\n";
    while(1){
        cout<<"Enter password: ";
        cin>> pass;

    if(pass != adminPass){
        cout<< "Wrong password";
        break;
    }
    }
    
    
    while(1){
        int choice;
        cout<<"Which category: "; 
        cout<<"[1] TOPS\n[2] BOTTOMS\n[3]ACCESSORIES\n[4]BACK\n";
        cout<<"[ENTER INPUT]";
            while (!(cin >> choice))
            {
            cout << "\n[ERROR]: (INPUT NUMBER ONLY AND 1-4 ONLY)\n\n{ENTER AGAIN]: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        switch(choice){
            case 1: {

            }
            case 2: {
                
            }
            case 3: {
                
            }
            case 4: {
                
            }
            default: cout << "\n[ERROR]: (1-4 ONLY)\n";
        }            
    }
}

void displayInventory( //done... atleast for now
 vector<string> t, vector<string> b, vector<string> a, 
 vector<float> p1, vector<float> p2, vector<float> p3, 
 vector<int> s1,vector<int> s2,vector<int> s3,
 vector<float> p4, vector<float> p5, vector<float> p6, 
 vector<int> s4,vector<int> s5,vector<int> s6,
 vector<float> p7, vector<float> p8, vector<float> p9, 
 vector<int> s7,vector<int> s8,vector<int> s9)         
{
    system("cls");
    cout << "Display Inventory\n\n";
    cout<<"Tops:"<<endl;
    cout<<setw(3) << left << "#"  << setw(1)
    << setw(20) << left << "NAME" << setw(1)
    << setw(10) << left << "SMALL"  << setw(1) << setw(15) << left << "STOCK/S"  << setw(1)
    << setw(10) << left << "MEDIUM" << setw(1) << setw(15) << left << "STOCK/S"  << setw(1)
    << setw(10) << left << "LARGE"  << setw(1) << setw(15) << left << "STOCK/S"  << setw(1)
    << setw(10) << left << "TOTAL OF STOCKS\n";
    for (int i = 0; i < t.size() ; i++)
    {
       cout<<setw(3) << left << i + 1 << setw(1)
       << setw(20) << left << t[i] << setw(1)
       << setw(10) << left << p1[i] << setw(1) << setw(15) << left << s1[i] << setw(1)
       << setw(10) << left << p2[i] << setw(1) << setw(15) << left << s2[i] << setw(1)
       << setw(10) << left << p3[i] << setw(1) << setw(15) << left << s3[i] << setw(1)
       << setw(10) << left << s1[i] + s2[i] + s3[i];
       cout<<endl;
    }
    cout<<"Bottoms:"<<endl;
    cout<<setw(3) << left << "#"  << setw(1)
    << setw(20) << left << "NAME" << setw(1)
    << setw(10) << left << "SMALL"  << setw(1) << setw(15) << left << "STOCK/S"  << setw(1)
    << setw(10) << left << "MEDIUM" << setw(1) << setw(15) << left << "STOCK/S"  << setw(1)
    << setw(10) << left << "LARGE"  << setw(1) << setw(15) << left << "STOCK/S"  << setw(1)
    << setw(10) << left << "TOTAL OF STOCKS\n";
    for (int i = 0; i < b.size() ; i++)
    {
        cout<<setw(3) << left << i + 1 << setw(1)
        << setw(20) << left << b[i] << setw(1)
        << setw(10) << left << p4[i] << setw(1) << setw(15) << left << s4[i] << setw(1)
        << setw(10) << left << p5[i] << setw(1) << setw(15) << left << s5[i] << setw(1)
        << setw(10) << left << p6[i] << setw(1) << setw(15) << left << s6[i] << setw(1)
        << setw(10) << left << s4[i] + s5[i] + s6[i];
        cout<<endl;
    }
    cout<<"Accessories:"<<endl;
    cout<<setw(3) << left << "#"  << setw(1)
    << setw(20) << left << "NAME" << setw(1)
    << setw(10) << left << "SMALL"  << setw(1) << setw(15) << left << "STOCK/S"  << setw(1)
    << setw(10) << left << "MEDIUM" << setw(1) << setw(15) << left << "STOCK/S"  << setw(1)
    << setw(10) << left << "LARGE"  << setw(1) << setw(15) << left << "STOCK/S"  << setw(1)
    << setw(10) << left << "TOTAL OF STOCKS\n";
    for (int i = 0; i < a.size() ; i++)
    {
        cout<<setw(3) << left << i + 1 << setw(1)
        << setw(20) << left << a[i] << setw(1)
        << setw(10) << left << p7[i] << setw(1) << setw(15) << left << s7[i] << setw(1)
        << setw(10) << left << p8[i] << setw(1) << setw(15) << left << s9[i] << setw(1)
        << setw(10) << left << p9[i] << setw(1) << setw(15) << left << s9[i] << setw(1)
        << setw(10) << left << s7[i] + s8[i] + s9[i];
        cout<<endl;
    }
    cout<<endl;
    string anything;
    cout<<"press any key to continue then hit enter..."; 
    cin>> anything; 
}

void productSales()
{
    cout << "product sales\n";
}

void salesHistory()
{
    cout << "Sales history\n";
}

void restock()
{
    cout << "restock\n";
}

void editHistory()
{
    cout << "edit history\n";
}
