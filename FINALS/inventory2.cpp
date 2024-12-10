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
            usleep(1 * 1000000);
            break;
        }
        if (adminUsername == user && adminPassword == pass) // ADMIN access
        {
            cout << GREEN << "\nLOGIN SUCCESSFULLY : (ADMIN)\n"
                 << RESET;
            loginTrue = false;
            isAdmin = true;
            cout << "PLease wait...";
            usleep(1 * 1000000);
            break;
        }
        if (emUsername == user && emPassword == pass) // EMPLOYER access
        {
            cout << GREEN << "\nLOGIN SUCCESSFULLY : (EMPLOYER)\n"
                 << RESET;
            loginTrue = false;
            isEmployer = true;
            cout << "Please wait...";
            usleep(1 * 1000000);
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
                vector<double> &pxs1, vector<double> &p1, vector<double> &p2,
                vector<double> &p3, vector<double> &px3, vector<double> &pxx3,

                vector<int> &sxs1, vector<int> &s1, vector<int> &s2,
                vector<int> &s3, vector<int> &sx3, vector<int> &sxx3,

                vector<double> &pxs4, vector<double> &p4, vector<double> &p5,
                vector<double> &p6, vector<double> &px6, vector<double> &pxx6,

                vector<int> &sxs4, vector<int> &s4, vector<int> &s5,
                vector<int> &s6, vector<int> &sx6, vector<int> &sxx6,

                vector<double> &p7, vector<int> &s7)
{
    system("cls");
    bool isSkip = 0;
    bool loopAgain = 1;
    // temporary variables
    string newProduct;
    double price1, price2, price3, price4, price5, price6, price7;
    int stock1, stock2, stock3, stock4, stock5, stock6, stock7;

    while (loopAgain)
    {
        if (isAdmin != true) // check if the user is admin or not
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
        while (choice > 0 && choice < 4)
        {
            system("cls");
        una:
            cout << "[" << category[choice - 1] << "]\n";
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
                    cout << "[ERROR] : Duplication found!\n[NOTE] : You can check the inventory first to check existing items.\n";
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
                    cout << "[ERROR] : Duplication found!\n[NOTE] : You can check the inventory first to check existing items.\n";
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
                    cout << "[ERROR] : Duplication found!\n[NOTE] : You can check the inventory first to check existing items.\n";
                    cout << "Please enter any keys to try again. ";
                    string a; // temp variable lang
                    cin >> a;
                    goto una;
                }
            }

            if ((choice < 3 && choice > 0)) // for tops and bottoms only
            {
                // EXTRA SMALL
                system("cls");
                cout << "[" << category[choice - 1] << " : " << YELLOW << "EXTRA SMALL SIZE  " << RESET << ": " << GREEN << newProduct << RESET << "]\n";
                cout << "Set the price for \"" << GREEN << newProduct << RESET << "\" ";
                cout << "\n(" << RED << "enter 0" << RESET << " if want to skip this part): ";

                while (!(cin >> price1))
                {
                    system("cls");
                    cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the valid price for \"" << GREEN << newProduct << RESET << "\"\n\n[ENTER AGAIN]: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (price1 > 0)
                {
                    system("cls");
                    cout << "[" << category[choice - 1] << " : " << YELLOW << "EXTRA SMALL SIZE  " << RESET << ": " << GREEN << newProduct << RESET << "]\n";
                    cout << "Enter the number of quantity for \"" << GREEN << newProduct << RESET << "\": ";
                    while (!(cin >> stock1))
                    {
                        system("cls");
                        cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the quantity for \"" << GREEN << newProduct << RESET << "\"\n\n[ENTER AGAIN]: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                else
                {
                    stock1 = 0;
                }
                // SMALL
                system("cls");
                cout << "[" << category[choice - 1] << " : " << MAGENTA << "SMALL SIZE  " << RESET << ": " << GREEN << newProduct << RESET << "]\n";
                cout << "Set the price for \"" << GREEN << newProduct << RESET << "\" ";
                cout << "\n(" << RED << "enter 0" << RESET << " if want to skip this part): ";

                while (!(cin >> price2))
                {
                    system("cls");
                    cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the valid price for \"" << GREEN << newProduct << RESET << "\"\n\n[ENTER AGAIN]: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (price2 > 0)
                {
                    system("cls");
                    cout << "[" << category[choice - 1] << " : " << MAGENTA << "SMALL SIZE  " << RESET << ": " << GREEN << newProduct << RESET << "]\n";
                    cout << "Enter the number of quantity for \"" << GREEN << newProduct << RESET << "\": ";
                    while (!(cin >> stock2))
                    {
                        system("cls");
                        cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the quantity for \"" << GREEN << newProduct << RESET << "\"\n\n[ENTER AGAIN]: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                else
                {
                    stock2 = 0;
                }
                // MEDIUM
                system("cls");
                cout << "[" << category[choice - 1] << " : " << BLUE << "MEDIUM SIZE  " << RESET << ": " << GREEN << newProduct << RESET << "]\n";
                cout << "Set the number of quantity for \"" << GREEN << newProduct << RESET << "\"";
                cout << "\n(" << RED << "enter 0" << RESET << " if want to skip this part): ";
                while (!(cin >> price3))
                {
                    system("cls");
                    cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the valid price for \"" << GREEN << newProduct << RESET << "\"\n\n[ENTER AGAIN]: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (price3 > 0)
                {
                    system("cls");
                    cout << "[" << category[choice - 1] << " : " << BLUE << "MEDIUM SIZE  " << RESET << ": " << GREEN << newProduct << RESET << "]\n";
                    cout << "Enter the number of quantity for \"" << GREEN << newProduct << RESET << "\": ";
                    while (!(cin >> stock3))
                    {
                        system("cls");
                        cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the quantity for \"" << GREEN << newProduct << RESET << "\"\n\n[ENTER AGAIN]: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                else
                {
                    stock3 = 0;
                }
                // LARGE
                system("cls");
                cout << "[" << category[choice - 1] << " : " << CYAN << "LARGE SIZE  " << RESET << ": " << GREEN << newProduct << RESET << "]\n";
                cout << "Set the number of quantity for \"" << GREEN << newProduct << RESET << "\"";
                cout << "\n(" << RED << "enter 0" << RESET << " if want to skip this part): ";
                while (!(cin >> price4))
                {
                    system("cls");
                    cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the valid price for \"" << GREEN << newProduct << RESET << "\"\n\n[ENTER AGAIN]: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (price4 > 0)
                {
                    system("cls");
                    cout << "[" << category[choice - 1] << " : " << CYAN << "LARGE SIZE  " << RESET << ": " << GREEN << newProduct << RESET << "]\n";
                    cout << "Enter the number of quantity for \"" << GREEN << newProduct << RESET << "\": ";
                    while (!(cin >> stock4))
                    {
                        system("cls");
                        cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the quantity for \"" << GREEN << newProduct << RESET << "\"\n\n[ENTER AGAIN]: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                else
                {
                    stock4 = 0;
                }
                // XLARGE
                system("cls");
                cout << "[" << category[choice - 1] << " : " << YELLOW << "X-LARGE SIZE  " << RESET << ": " << GREEN << newProduct << RESET << "]\n";
                cout << "Set the number of quantity for \"" << GREEN << newProduct << RESET << "\"";
                cout << "\n(" << RED << "enter 0" << RESET << " if want to skip this part): ";
                while (!(cin >> price5))
                {
                    system("cls");
                    cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the valid price for \"" << GREEN << newProduct << RESET << "\"\n\n[ENTER AGAIN]: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (price5 > 0)
                {
                    system("cls");
                    cout << "[" << category[choice - 1] << " : " << YELLOW << "X-LARGE SIZE  " << RESET << ": " << GREEN << newProduct << RESET << "]\n";
                    cout << "Enter the number of quantity for \"" << GREEN << newProduct << RESET << "\": ";
                    while (!(cin >> stock5))
                    {
                        system("cls");
                        cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the quantity for \"" << GREEN << newProduct << RESET << "\"\n\n[ENTER AGAIN]: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                else
                {
                    stock5 = 0;
                }
                // XXLARGE
                system("cls");
                cout << "[" << category[choice - 1] << " : " << MAGENTA << "XX-LARGE SIZE  " << RESET << ": " << GREEN << newProduct << RESET << "]\n";
                cout << "Set the number of quantity for \"" << GREEN << newProduct << RESET << "\"";
                cout << "\n(" << RED << "enter 0" << RESET << " if want to skip this part): ";
                while (!(cin >> price6))
                {
                    system("cls");
                    cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the valid price for \"" << GREEN << newProduct << RESET << "\"\n\n[ENTER AGAIN]: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (price6 > 0)
                {
                    system("cls");
                    cout << "[" << category[choice - 1] << " : " << MAGENTA << "XX-LARGE SIZE  " << RESET << ": " << GREEN << newProduct << RESET << "]\n";
                    cout << "Enter the number of quantity for \"" << GREEN << newProduct << RESET << "\": ";
                    while (!(cin >> stock6))
                    {
                        system("cls");
                        cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the quantity for \"" << GREEN << newProduct << RESET << "\"\n\n[ENTER AGAIN]: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                else
                {
                    stock6 = 0;
                }
            }
            if (choice == 3)
            { // for accessories
                system("cls");
                cout << "[ACCESORY : " << GREEN << newProduct << RESET << "]\n";
                cout << "Set the price for " << GREEN << newProduct << RESET << ": ";
                while (!(cin >> price7))
                {
                    system("cls");
                    cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the valid price for \"" << GREEN << newProduct << RESET << "\"\n\n[ENTER AGAIN]: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (price7 > 0)
                {
                    system("cls");
                    cout << "[ACCESORY : " << GREEN << newProduct << RESET << "]\n";
                    cout << "Enter the number of quantity for \"" << GREEN << newProduct << RESET << "\": ";
                    while (!(cin >> stock7))
                    {
                        system("cls");
                        cout << RED << "\n[ERROR]" << RESET << ": PLEASE USE NUMBERS ONLY\n\nEnter the quantity for \"" << newProduct << "\"\n\n[ENTER AGAIN]: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                else
                {
                    stock7 = 0;
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
            pxs1.push_back(price1);
            sxs1.push_back(stock1);
            p1.push_back(price2);
            s1.push_back(stock2);
            p2.push_back(price3);
            s2.push_back(stock3);
            p3.push_back(price4);
            s3.push_back(stock4);
            px3.push_back(price5);
            sx3.push_back(stock5);
            pxx3.push_back(price6);
            sxx3.push_back(stock6);
            break;
        }
        case 2: // for finalization bottoms
        {
            b.push_back(newProduct);
            pxs4.push_back(price1);
            sxs4.push_back(stock1);
            p4.push_back(price2);
            s4.push_back(stock2);
            p5.push_back(price3);
            s5.push_back(stock3);
            p6.push_back(price4);
            s6.push_back(stock4);
            px6.push_back(price5);
            sx6.push_back(stock5);
            pxx6.push_back(price6);
            sxx6.push_back(stock6);
            break;
        }
        case 3: // for finalization accessories
        {
            a.push_back(newProduct);
            p7.push_back(price7);
            s7.push_back(stock7);
            break;
        }
        case 4: // to navigate back
        {
            loopAgain = 0;
            break;
        }

        default:
            cout << "PLease enter option [1 - 4] only\n\nPLease wait...";
            usleep(2 * 1000000);
            // break;
        }
        break;
    } // end of first loop
} // end of void function

void displayInventory(vector<string> &t, vector<string> &b, vector<string> &a,

                      vector<double> &pxs1, vector<double> &p1, vector<double> &p2,
                      vector<double> &p3, vector<double> &px3, vector<double> &pxx3,

                      vector<int> &sxs1, vector<int> &s1, vector<int> &s2,
                      vector<int> &s3, vector<int> &sx3, vector<int> &sxx3,

                      vector<double> &pxs4, vector<double> &p4, vector<double> &p5,
                      vector<double> &p6, vector<double> &px6, vector<double> &pxx6,

                      vector<int> &sxs4, vector<int> &s4, vector<int> &s5,
                      vector<int> &s6, vector<int> &sx6, vector<int> &sxx6,

                      vector<double> &p7, vector<int> &s7)
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
             << setw(10) << left << sxs4[i] + s4[i] + s5[i] + s6[i] + sx6[i] + sxx6[i];
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

void productSales()
{

    cout << "product sales\n";
    cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "====== [ Y O U  A R E   I N   T H E   P R O D U C T   S A L E S ] =====";
    cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
}

void salesHistory()
{
    cout << "Sales history\n";
}

void update(bool &isAdmin,
          vector<string> &t, vector<string> &b, vector<string> &a,

          vector<double> &pxs1, vector<double> &p1, vector<double> &p2,
          vector<double> &p3, vector<double> &px3, vector<double> &pxx3,

          vector<int> &sxs1, vector<int> &s1, vector<int> &s2,
          vector<int> &s3, vector<int> &sx3, vector<int> &sxx3,

          vector<double> &pxs4, vector<double> &p4, vector<double> &p5,
          vector<double> &p6, vector<double> &px6, vector<double> &pxx6,

          vector<int> &sxs4, vector<int> &s4, vector<int> &s5,
          vector<int> &s6, vector<int> &sx6, vector<int> &sxx6,

          vector<double> &p7, vector<int> &s7)
{

    bool loop = true;
    while (loop)
    {

        system("cls");
        if (isAdmin != true) // check if the user is admin or not
        {
            cout << "You don't have an access here. Please contact your admin.";
            string anything;
            cout << "\nPress any key to continue...";
            getline(cin >> ws, anything);
            loop = 0;
            break;
        }
    una:

        cout << "Update inventory\n";
        cout << "[1] DELETE ITEM\n[2] BACK\n";
        cout << "\nEnter your choice: ";
        int ch1;
        while (!(cin >> ch1))
        {
            cout << "\n[ERROR]: (INVALID/NUMBER ONLY)\n\n[ENTER AGAIN]: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (ch1)
        {
        case 1: // delete option
        {
        pan:
            system("cls");
            int ch2;
            cout << "Which Category: \n[1] TOPS\n[2] BOTTOMS\n[3] ACCESSORIES\n[4] BACK\n";
            cout << "Enter: ";
            while (!(cin >> ch2) || !(ch2 > 0 && ch2 < 5))
            {
                cout << "\n[ERROR]: (INVALID/NUMBER ONLY)\n\n[ENTER AGAIN]: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            switch (ch2)
            {
            case 1: // delete for tops
            {
            system("cls");
            if (t.empty())
            {
                cout << "[TOPS] : is currently empty. You may add items to start your business.\n";
                usleep(2000000);
                break;
            }
            del:
                system("cls");
                cout << "DELETE TAB: which action?\n";
                cout << "[1] Delete specific item\n";
                cout << "[2] Delete all item\nWhich option: ";
                int deletion;
                while (!(cin >> deletion) || !(deletion > 0 && deletion < 3))
                {
                    cout << "\n[ERROR]: (INVALID INPUT/NUMBER ONLY)\n\n[ENTER AGAIN]: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (deletion == 2) // if "delete all" option chosen
                {
                    cout << "Are you sure you want to delete all the items from [TOPS]?";
                    cout << GREEN << "\n\nPress y/Y" << RESET << " and hit enter to proceed or " << RED << "press n/N to cancel." << RESET;
                    string any;
                    getline(cin >> ws, any);
                    if (any == "n" || any == "N")
                    {
                        goto del;
                    }
                    if (any == "y" || any == "Y")
                    {
                        t.clear();
                        pxs1.clear();       sxs1.clear();                                       
                        p1.clear();         s1.clear();
                        p2.clear();         s2.clear();                      
                        p3.clear();         s3.clear();
                        px3.clear();        sx3.clear();
                        pxx3.clear();       sxx3.clear();
                        cout << "All Items in [TOPS] is cleared.";
                        usleep(2000000);
                        break;
                    }
                    else
                    {
                        cout << "[ERROR] : INVALID INPUT!\n";
                        usleep(1000000);
                        goto del;
                    }
                }
            tat:
                system("cls");
                int ch3;
                cout << "[TOPS] : Pick an item to delete\n";
                for (int i = 0; i < t.size(); i++)
                {
                    cout << "[" << i + 1 << "] " << t.at(i) << endl;
                    if (i == t.size() - 1)
                    {
                        cout << "[" << t.size() + 1 << "] BACK\n";
                    }
                }
                cout << "Enter your choice: ";
                // input validation ch3
                while (!(cin >> ch3) || !(ch3 > 0 && ch3 <= t.size() + 1))
                {
                    cout << "\n[ERROR]: (INVALID/NUMBER ONLY)\n\n[ENTER AGAIN]: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (ch3 == t.size() + 1)
                {
                    goto pan;
                }
            apa:
                cout << "Are you sure you want to delete [" << t.at(ch3 - 1) << "]?";
                cout << GREEN << "\n\nPress y/Y" << RESET << " and hit enter to proceed or " << RED << "press n/N to cancel." << RESET;
                string any;
                getline(cin >> ws, any);
                if (any == "n" || any == "N")
                {
                    goto tat;
                }
                if (any == "y" || any == "Y")
                {
                    cout << endl;
                    cout << t.at(ch3 - 1) << " is removed.";
                    for (int i = ch3; i < t.size(); i++)
                    {
                        t.at(i - 1) = t.at(i);
                        pxs1.at(i - 1) = pxs1.at(i);
                        p1.at(i - 1) = p1.at(i);
                        p2.at(i - 1) = p2.at(i);
                        p3.at(i - 1) = p3.at(i);
                        px3.at(i - 1) = px3.at(i);
                        pxx3.at(i - 1) = pxx3.at(i);

                        sxs1.at(i - 1) = sxs1.at(i);
                        s1.at(i - 1) = s1.at(i);
                        s2.at(i - 1) = s2.at(i);
                        s3.at(i - 1) = s3.at(i);
                        sx3.at(i - 1) = sx3.at(i);
                        sxx3.at(i - 1) = sxx3.at(i);
                    }
                    t.pop_back();
                    pxs1.pop_back();    sxs1.pop_back();
                    p1.pop_back();      s1.pop_back();
                    p2.pop_back();      s2.pop_back();
                    p3.pop_back();      s3.pop_back();
                    px3.pop_back();     sx3.pop_back();
                    pxx3.pop_back();    sxx3.pop_back();
                    usleep(1500000);
                }
                else
                {
                    cout << "[ERROR] : [INVALID INPUT]";
                    usleep(900000);
                    goto apa;
                }

                break;
            }
            case 2: // delete for bottoms
            {
            system("cls");
            if (b.empty())
            {
                cout << "[TOPS] : is currently empty. You may add items to start your business.\n";
                usleep(2000000);
                break;
            }
                del2:
                system("cls");
                cout << "DELETE : which action?\n";
                cout << "[1] Delete specific item\n";
                cout << "[2] Delete all item\nWhich option: ";
                int deletion;
                while (!(cin >> deletion) || !(deletion > 0 && deletion < 3))
                {
                    cout << "\n[ERROR]: (INVALID INPUT/NUMBER ONLY)\n\n[ENTER AGAIN]: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (deletion == 2) // if "delete all" option chosen
                {
                    cout << "Are you sure you want to delete all the items from [BOTTOMS]?";
                    cout << GREEN << "\n\nPress y/Y" << RESET << " and hit enter to proceed or " << RED << "press n/N to cancel." << RESET;
                    string any;
                    getline(cin >> ws, any);
                    if (any == "n" || any == "N")
                    {
                        goto del2;
                    }
                    if (any == "y" || any == "Y")
                    {
                        b.clear();
                        pxs4.clear();       sxs4.clear();
                        p4.clear();         s4.clear();
                        p5.clear();         s5.clear();
                        p6.clear();         s6.clear();
                        px6.clear();        sx6.clear();    
                        pxx6.clear();       sxx6.clear();
                        cout << "All Items in [BOTTOMS] is cleared.";
                        usleep(2000000);
                        break;
                    }
                    else
                    {   //invalid input 
                        cout << "[ERROR] : INVALID INPUT!\n";
                        usleep(1000000);
                        goto del2;
                    }
                }
                    tat2:
                        system("cls");
                        int ch3;
                        cout << "[BOTTOMS] : Pick an item to delete\n";
                        for (int i = 0; i < b.size(); i++)
                        {
                            cout << "[" << i + 1 << "] " << b.at(i) << endl;
                            if (i == b.size() - 1)
                            {
                                cout << "[" << b.size() + 1 << "] BACK\n";
                            }
                        }
                        cout << "Enter your choice: ";
                        // input validation ch3
                        while (!(cin >> ch3) || !(ch3 >= 0 && ch3 <= b.size() + 1))
                        {
                            cout << "\n[ERROR]: (INVALID/NUMBER ONLY)\n\n[ENTER AGAIN]: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        if (ch3 == b.size() + 1)
                        {
                            goto pan;
                        }
                        apa2:
                cout << "Are you sure you want to delete [" << b.at(ch3 - 1) << "]?";
                cout << GREEN << "\n\nPress y/Y" << RESET << " and hit enter to proceed or " << RED << "press n/N to cancel." << RESET;
                string any;
                getline(cin >> ws, any);
                if (any == "n" || any == "N")
                {
                    goto tat2;
                }
                if (any == "y" || any == "Y")
                {
                    cout << endl;
                    cout << b.at(ch3 - 1) << " is removed.";
                    for (int i = ch3; i < b.size(); i++)
                    {
                        b.at(i - 1) = b.at(i);
                        pxs4.at(i - 1) = pxs4.at(i);
                        p4.at(i - 1) = p4.at(i);
                        p5.at(i - 1) = p5.at(i);
                        p6.at(i - 1) = p6.at(i);
                        px6.at(i - 1) = px6.at(i);
                        pxx6.at(i - 1) = pxx6.at(i);

                        sxs4.at(i - 1) = sxs4.at(i);
                        s4.at(i - 1) = s4.at(i);
                        s5.at(i - 1) = s5.at(i);
                        s6.at(i - 1) = s6.at(i);
                        sx6.at(i - 1) = sx6.at(i);
                        sxx6.at(i - 1) = sxx6.at(i);
                    }
                    t.pop_back();
                    pxs4.pop_back();        sxs4.pop_back();       
                    p4.pop_back();          s4.pop_back();
                    p5.pop_back();          s5.pop_back();
                    p6.pop_back();          s6.pop_back();
                    px6.pop_back();         sx6.pop_back();
                    pxx6.pop_back();        sxx6.pop_back();
                    usleep(1500000);
                }
                else
                {
                    cout << "[ERROR] : [INVALID INPUT]";
                    usleep(900000);
                    goto apa2;
                }
                break;
            }
            case 3: // delete for accessories
            {
            system("cls");
            if (a.empty())
            {
                cout << "[ACCESSORIES] : is currently empty. You may add items to start your business.\n";
                usleep(2000000);
                break;
            }
            del3:
                system("cls");
                cout << "DELETE : which action?\n";
                cout << "[1] Delete specific item\n";
                cout << "[2] Delete all item\nWhich option: ";
                int deletion;
                while (!(cin >> deletion) || !(deletion > 0 && deletion < 3))
                {
                    cout << "\n[ERROR]: (INVALID INPUT/NUMBER ONLY)\n\n[ENTER AGAIN]: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (deletion == 2) // if "delete all" option chosen
                {
                    cout << "Are you sure you want to delete all the items from [ACCESSORIES]?";
                    cout << GREEN << "\n\nPress y/Y" << RESET << " and hit enter to proceed or " << RED << "press n/N to cancel." << RESET;
                    string any;
                    getline(cin >> ws, any);
                    if (any == "n" || any == "N")
                    {
                        goto del3;
                    }
                    if (any == "y" || any == "Y")
                    {
                        a.clear();
                        p7.clear();       s7.clear();                                       
                        
                        cout << "All Items in [ACCESSORIES] is cleared.";
                        usleep(2000000);
                        break;
                    }
                    else
                    {
                        cout << "[ERROR] : INVALID INPUT!\n";
                        usleep(1000000);
                        goto del3;
                    }
                }
            tat3:
                system("cls");
                int ch3;
                cout << "[TOPS] : Pick an item to delete\n";
                for (int i = 0; i < a.size(); i++)
                {
                    cout << "[" << i + 1 << "] " << a.at(i) << endl;
                    if (i == a.size() - 1)
                    {
                        cout << "[" << a.size() + 1 << "] BACK\n";
                    }
                }
                cout << "Enter your choice: ";
                // input validation ch3
                while (!(cin >> ch3) || !(ch3 >= 0 && ch3 <= a.size() + 1))
                {
                    cout << "\n[ERROR]: (INVALID/NUMBER ONLY)\n\n[ENTER AGAIN]: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (ch3 == a.size() + 1)
                {
                    goto pan;
                }
            apa3:
                cout << "Are you sure you want to delete [" << a.at(ch3 - 1) << "]?";
                cout << GREEN << "\n\nPress y/Y" << RESET << " and hit enter to proceed or " << RED << "press n/N to cancel." << RESET;
                string any;
                getline(cin >> ws, any);
                if (any == "n" || any == "N")
                {
                    goto tat;
                }
                if (any == "y" || any == "Y")
                {
                    cout << endl;
                    cout << a.at(ch3 - 1) << " is removed.";
                    for (int i = ch3; i < a.size(); i++)
                    {
                        a.at(i - 1) = a.at(i);
                        p7.at(i - 1) = p7.at(i);
                        s7.at(i - 1) = s7.at(i);
                    }
                    a.pop_back();
                    p7.pop_back();      s7.pop_back();
                    
                    usleep(1500000);
                }
                else
                {
                    cout << "[ERROR] : [INVALID INPUT]";
                    usleep(900000);
                    goto apa3;
                }
                break;
            }
            case 4: // back
            {
                break;
            }

            default:
            cout<< RED << "[ERROR] : [INVALID INPUT]" << RESET;
                break;
            }
            break;
        }
        
        case 2: // back option
        {
            loop = false;
            break;
        }

        default:
        cout<< RED << "[ERROR] : [INVALID INPUT]" << RESET;
            break;
        }
    }
}