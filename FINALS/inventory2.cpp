#include <bits/stdc++.h>
#include <unistd.h>  //for usleep?
#include <algorithm> //for begin() and end()
#include <string>    //for tolower
using namespace std;
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define BLACK "\033[30m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

void login(bool &isAdmin, bool &isEmployer) // authentications
{
    system("cls");
    string adminUsername = "admin";
    string adminPassword = "123";
    string emUsername = "employer";
    string emPassword = "123";

    string user;
    string pass;
    bool loginTrue = true;
    int maxAttempt = 3;
    int attempt = 0;

    while (loginTrue && attempt <= maxAttempt)
    {
        cout << BLACK << "=======================================================================\n";
        cout << "======>>>><<<<[ " << RED << "T "
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
             << BLACK << "]>>>><<<<======\n"
             << RESET;
        cout << BLACK << "=======================================================================\n\n";

        cout << BLACK << "ENTER USERNAME: " << RESET;
        getline(cin >> ws, user);

        cout << BLACK << "ENTER PASSWORD: " << RESET;
        getline(cin >> ws, pass);

        if (attempt >= maxAttempt)
        { // check attemps muna bago account checking
            cout << "\nTOO MANY ATTEMPTS. FAILED TO LOGIN. PLEASE TRY AGAIN!\n\n";
            loginTrue = false;
            cout << "PLease wait...";
            usleep(2 * 1000000);
            break;
        }
        if (adminUsername == user && adminPassword == pass) // ADMIN access
        {
            cout << GREEN << "\nLOGIN SUCCESSFULLY : (ADMIN)\n"
                 << RESET;
            loginTrue = false;
            isAdmin = true;
            cout << "PLease wait...";
            usleep(2 * 1000000);
            break;
        }
        if (emUsername == user && emPassword == pass) // EMPLOYER access
        {
            cout << GREEN << "\nLOGIN SUCCESSFULLY : (EMPLOYER)\n"
                 << RESET;
            loginTrue = false;
            isEmployer = true;
            cout << "Please wait...";
            usleep(2 * 1000000);
            break;
        }
        else
        {
            cout << RED << "\nLOGIN FAILED. PLEASE TRY AGAIN!. (ATTEMPTS # " << attempt + 1 << ")\n"
                 << RESET;
            string anything;
            cout << "\nPress any key to continue...";
            getline(cin >> ws, anything);
            attempt++;
        }
    }
}
void addProduct(bool isAdmin, string category[],
                vector<string> &t, vector<string> &b, vector<string> &a,
                vector<float> &p1, vector<float> &p2, vector<float> &p3,
                vector<int> &s1, vector<int> &s2, vector<int> &s3,
                vector<float> &p4, vector<float> &p5, vector<float> &p6,
                vector<int> &s4, vector<int> &s5, vector<int> &s6,
                vector<float> &p7, vector<int> &s7)
{
    system("cls");
    bool isSkip = 0;
    bool loopAgain = 1;
    // temporary variables
    string newProduct;
    float price1, price2, price3;
    int stock1, stock2, stock3;

    while (loopAgain)
    {

        if (isAdmin != true) // check if the user is admin or not (line 117 - 125)
        {
            cout << "You don't have an access here. Please contact your admin.";
            string anything;
            cout << "\nPress any key to continue...";
            getline(cin >> ws, anything);
            loopAgain = 0;
            break;
        }
        int choice;
        cout << "Categories:\n[1] TOPS\n[2] BOTTOMS\n[3] ACCESSORIES\n[4] BACK\n";
        cout << "Which one: ";
        while (!(cin >> choice))
        {
            cout << "\n[ERROR]: (NUMBER ONLY)\n\n[ENTER AGAIN]: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while (1 && choice != 4)
        {
            system("cls");
        una:
            cout<<"["<< category[choice - 1]<<"]\n";
            cout << "Enter new product: ";
            getline(cin >> ws, newProduct);
            // for checking duplications
            for (int i = 0; i < size(t); i++)
            {
                system("cls");
                string str1 = newProduct;
                transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
                string str2 = t[i];
                transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
                if (str1 == str2)
                {
                    cout << "[ERROR] : Duplication found!\n";
                    cout << "Please enter any keys to try again. ";
                    string a; // temp variable lang
                    cin >> a;
                    goto una;
                }
            }
            for (int i = 0; i < size(b); i++)
            {
                system("cls");
                string str1 = newProduct;
                transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
                string str2 = b[i];
                transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
                if (str1 == str2)
                {
                    cout << "[ERROR] : Duplication found!\n";
                    cout << "Please enter any keys to try again. ";
                    string a; // temp variable lang
                    cin >> a;
                    goto una;
                }
            }
            for (int i = 0; i < size(a); i++)
            {
                system("cls");
                string str1 = newProduct;
                transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
                string str2 = a[i];
                transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
                if (str1 == str2)
                {
                    cout << "[ERROR] : Duplication found!\n";
                    cout << "Please enter any keys to try again. ";
                    string a; // temp variable lang
                    cin >> a;
                    goto una;
                }
            }

            if ((choice < 3 && choice > 0)) // for tops and bottoms only
            {
                system("cls");
                cout << "[" <<category[choice - 1] << " : SMALL SIZE : " << GREEN << newProduct << RESET << "]\n";
                cout << "Set the price for \"" << GREEN << newProduct << RESET << "\" ";
                cout << "\n(" << RED << "enter 0" << RESET << " if want to skip this part): ";

                while (!(cin >> price1))
                {
                    cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the quantity for \"" << newProduct << "\"\n\n[ENTER AGAIN]: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (price1 > 0)
                {
                    cout << "[" <<category[choice - 1] << " : SMALL SIZE : " << GREEN << newProduct << RESET << "]\n";
                    cout << "Enter the number of quantity for \"" << GREEN << newProduct << RESET << "\": ";
                    while (!(cin >> stock1))
                    {
                        cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the quantity for \"" << GREEN << newProduct << RESET << "\"\n\n[ENTER AGAIN]: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                else
                {
                    stock1 = 0;
                }
                system("cls");
                cout << "[" <<category[choice - 1] << " : MEDIUM SIZE : " << GREEN << newProduct << RESET << "]\n";
                cout << "Set the number of quantity for \"" << GREEN << newProduct << RESET << "\"";
                cout << "\n(" << RED << "enter 0" << RESET << " if want to skip this part): ";
                while (!(cin >> price2))
                {
                    cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the quantity for \"" << newProduct << "\"\n\n[ENTER AGAIN]: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (price2 > 0)
                {
                    cout << "[" <<category[choice - 1] << " : MEDIUM SIZE : " << GREEN << newProduct << RESET << "]\n";
                    cout << "Enter the number of quantity for \"" << GREEN << newProduct << RESET << "\": ";
                    while (!(cin >> stock2))
                    {
                        cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the quantity for \"" << GREEN << newProduct << RESET << "\"\n\n[ENTER AGAIN]: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                else
                {
                    stock2 = 0;
                }
                system("cls");
                cout << "[" <<category[choice - 1] << " : LARGE SIZE : " << GREEN << newProduct << RESET << "]\n";
                cout << "Set the number of quantity for \"" << GREEN << newProduct << RESET << "\"";
                cout << "\n(" << RED << "enter 0" << RESET << " if want to skip this part): ";
                while (!(cin >> price3))
                {
                    cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the quantity for \"" << newProduct << "\"\n\n[ENTER AGAIN]: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (price3 > 0)
                {
                    cout << "[" <<category[choice - 1] << " : LARGE SIZE : " << GREEN << newProduct << RESET << "]\n";
                    cout << "Enter the number of quantity for \"" << GREEN << newProduct << RESET << "\": ";
                    while (!(cin >> stock3))
                    {
                        cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the quantity for \"" << GREEN << newProduct << RESET << "\"\n\n[ENTER AGAIN]: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                else
                {
                    stock3 = 0;
                }
            }
            if (choice == 3)
            { // for accessories
                system("cls");
                cout << "[ACCESORY : " << GREEN << newProduct << RESET << "]\n";
                cout << "Set the price for " << GREEN << newProduct << RESET << ": ";
                while (!(cin >> price1))
                {
                    cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the quantity for \"" << newProduct << "\"\n\n[ENTER AGAIN]: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (price1 > 0)
                {
                    cout << "[ACCESORY : " << GREEN << newProduct << RESET << "]\n";
                    cout << "Enter the number of quantity for \"" << GREEN << newProduct << RESET << "\": ";
                    while (!(cin >> stock1))
                    {
                        cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the quantity for \"" << newProduct << "\"\n\n[ENTER AGAIN]: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                else
                {
                    stock1 = 0;
                }
            }
            else
            {
                cout << "Invalid input";
            }
            break;
        }

        switch (choice) // for adding to the inventory (vectors.)
        {
        case 1: // for finalization tops
        {
            t.push_back(newProduct);
            p1.push_back(price1);
            s1.push_back(stock1);
            p2.push_back(price2);
            s2.push_back(stock2);
            p3.push_back(price3);
            s3.push_back(stock3);

            break;
        }
        case 2: // for finalization bottoms
        {
            b.push_back(newProduct);
            p4.push_back(price1);
            s4.push_back(stock1);
            p5.push_back(price2);
            s5.push_back(stock2);
            p6.push_back(price3);
            s6.push_back(stock3);

            break;
        }
        case 3: // for finalization accessories
        {
            a.push_back(newProduct);
            p7.push_back(price1);
            s7.push_back(stock1);

            break;
        }
        case 4: // to navigate back
        {
            loopAgain = 0;
            break;
        }

        default:
            break;
        }
        break;
    } // end of first loop
} // end of void function

void displayInventory( vector<string> t, vector<string> b, vector<string> a,
    
    vector<double> pxs1, vector<double> p1, vector<double> p2,
    vector<double> p3,   vector<double> px3, vector<double> pxx3,

    vector<int>& sxs1, vector<int>& s1, vector<int>& s2,
    vector<int>& s3, vector<int>& sx3, vector<int>& sxx3,

    vector<double> pxs4, vector<double> p4, vector<double> p5,
    vector<double> p6, vector<double> px6, vector<double> pxx6,
 
    vector<int>& sxs4, vector<int>& s4, vector<int>& s5,
    vector<int>& s6, vector<int>& sx6, vector<int>& sxx6,

    vector<double> p7, vector<int>& s7)
{
    system("cls");
    cout << "Display Inventory\n\n";
    cout << "Tops:" << endl;
    cout << setw(3) << left << "#" << setw(1)
         << setw(15) << left << "NAME" << setw(1)
         << setw(10) << left << "(XS)PRICE " << setw(1) << setw(15) << left << "STOCK/S" << setw(1)
         << setw(10) << left << "(S)PRICE " << setw(1) << setw(15) << left << "STOCK/S" << setw(1)
         << setw(10) << left << "(M)PRICE " << setw(1) << setw(15) << left << "STOCK/S" << setw(1)
         << setw(10) << left << "(L)PRICE " << setw(1) << setw(15) << left << "STOCK/S" << setw(1)
         << setw(10) << left << "(XL)PRICE " << setw(1) << setw(15) << left << "STOCK/S" << setw(1)
         << setw(10) << left << "(XXL)PRICE " << setw(1) << setw(10) << left << "STOCK/S" << setw(1)
         << setw(10) << left << "TOTAL OF STOCKS\n";
    for (int i = 0; i < t.size(); i++)
    {
        cout << setw(3) << left << i + 1 << setw(1)
             << setw(15) << left << t[i] << setw(1)
             << setw(10) << left << pxs1[i] << setw(1) << setw(15) << left << sxs1[i] << setw(1)
             << setw(10) << left << p1[i] << setw(1) << setw(15) << left << s1[i] << setw(1)
             << setw(10) << left << p2[i] << setw(1) << setw(15) << left << s2[i] << setw(1)
             << setw(10) << left << p3[i] << setw(1) << setw(15) << left << s3[i] << setw(1)
             << setw(10) << left << px3[i] << setw(1) << setw(15) << left << sx3[i] << setw(1)
             << setw(11) << left << pxx3[i] << setw(1) << setw(10) << left << sxx3[i] << setw(1)
             << setw(10) << left << sxs1[i] + s1[i] + s2[i] + s3[i] + sx3[i] + sxx3[i];
        cout << endl;
    }
    cout << "Bottoms:" << endl;
    cout << setw(3) << left << "#" << setw(1)
         << setw(15) << left << "NAME" << setw(1)
         << setw(10) << left << "(XS)PRICE " << setw(1) << setw(15) << left << "STOCK/S" << setw(1)
         << setw(10) << left << "(S)PRICE " << setw(1) << setw(15) << left << "STOCK/S" << setw(1)
         << setw(10) << left << "(M)PRICE " << setw(1) << setw(15) << left << "STOCK/S" << setw(1)
         << setw(10) << left << "(L)PRICE " << setw(1) << setw(15) << left << "STOCK/S" << setw(1)
         << setw(10) << left << "(XL)PRICE " << setw(1) << setw(15) << left << "STOCK/S" << setw(1)
         << setw(10) << left << "(XXL)PRICE " << setw(1) << setw(10) << left << "STOCK/S" << setw(1)
         << setw(10) << left << "TOTAL OF STOCKS\n";
    for (int i = 0; i < b.size(); i++)
    {
        cout << setw(3) << left << i + 1 << setw(1)
             << setw(15) << left << b[i] << setw(1)
             << setw(10) << left << pxs4[i] << setw(1) << setw(15) << left << sxs4[i] << setw(1)
             << setw(10) << left << p4[i] << setw(1) << setw(15) << left << s4[i] << setw(1)
             << setw(10) << left << p5[i] << setw(1) << setw(15) << left << s5[i] << setw(1)
             << setw(10) << left << p6[i] << setw(1) << setw(15) << left << s6[i] << setw(1)
             << setw(10) << left << px6[i] << setw(1) << setw(15) << left << sx6[i] << setw(1)
             << setw(11) << left << pxx6[i] << setw(1) << setw(10) << left << sxx6[i] << setw(1)
             << setw(10) << left << sxs4[i] + s4[i] + s5[i] + s6[i] + sx6[i] +sxx6[i];
        cout << endl;
    }
    cout << "Accessories:" << endl;
    cout << setw(3) << left << "#" << setw(1)
         << setw(20) << left << "NAME" << setw(1)
         << setw(15) << left << "PRICE" << setw(1)
         << setw(15) << left << "TOTAL OF STOCKS\n";
    for (int i = 0; i < a.size(); i++)
    {
        cout << setw(3) << left << i + 1 << setw(1)
             << setw(20) << left << a[i] << setw(1)
             << setw(15) << left << p7[i] << setw(1)
             << setw(15) << left << s7[i] << setw(1);
        cout << endl;
    }
    cout << endl;
    string anything;
    cout << "press any key to continue then hit enter...";
    cin >> anything;
}


// void productSales()
// {

//     cout << "product sales\n";
//     cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
//     cout << "====== [ Y O U  A R E   I N   T H E   P R O D U C T   S A L E S ] =====";
//     cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

// }

void productSales() {
    
}

void salesHistory()
{
    cout << "Sales history\n";
}


void edit(
    vector<string> t, vector<string> b, vector<string> a,
    vector<float> p1, vector<float> p2, vector<float> p3,
    vector<int> s1, vector<int> s2, vector<int> s3,
    vector<float> p4, vector<float> p5, vector<float> p6,
    vector<int> s4, vector<int> s5, vector<int> s6,
    vector<float> p7, vector<int> s7)
{
    cout<<"[1] Delete item\n[2] Update item\n[3] Back\n";
    cout<<"Enter your choice: \n";
}
