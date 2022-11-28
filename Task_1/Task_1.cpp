#include <iostream>
#include <string>
#include<sstream>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

struct Adress
{
    string city;
    string street;
    string house;
}; 

struct Product
{
    string name;
    double weight = 0;
    double price;
    int amount = 0;
};

// Кассовый чек
struct Check
{
    string companyName;
    string shopName;
    Adress adress;
    Product product;
    string specialPromo;
    Date todaysDate;
    double clientBonus;
    int checkNumber;
    int cashBoxNumber;
    string activeSale;
    string prediction;
    double bonusGathered;
    double balance;
    double totalAmount;
};

struct Device
{
    string type;
    string name;
    string fullName;
    string model;
    string brand;
    Date warrantyUpTo;
    Date saleDate;
    double price;
    Check check;
};

void PrintDevice(const Device& device);
void PrintCheck(const Check& check);
void PrintCenterText(string text, const int width);
void PrintCenterSpaceText(string text, const int width);
void PrintLeftSpaceText(string text, const int width);
void PrintLeftRightSpaceText(string textLeft, string textRight, const int width);
void PrintPromoText(string text, const int width);
void PrintText(char arr[], const int width);

int main()
{
    Device phone1;
    phone1.type = "Smartphone";
    phone1.fullName = "Samsung Galaxy Note20";
    phone1.name = "Galaxy";
    phone1.model = "Note20";
    phone1.brand = "Samsung";
    phone1.price = 22560;
    phone1.warrantyUpTo = { 15, 11, 2025 };
    phone1.saleDate = { 24, 11, 2022 };

    Check check1;

    check1.companyName = "Samsung";
    check1.shopName = "Samsung Store";
    check1.adress = { "Kyiv", "Borshagivska", "154-a" };
    check1.product.name = phone1.fullName;
    check1.product.amount = 1;
    check1.product.price = phone1.price;
    check1.specialPromo = "Sale 50% for smartphone case:\nSamsung Galaxy Note20";
    check1.todaysDate = { phone1.saleDate.day, phone1.saleDate.month, phone1.saleDate.year };
    check1.clientBonus = 93.3;
    check1.checkNumber = 2142324324;
    check1.cashBoxNumber = 3;
    check1.activeSale = "Sale: Black Friday!";
    check1.prediction = "Everything will be OK ;)";
    check1.bonusGathered = 23.9;
    check1.balance = check1.clientBonus + check1.bonusGathered;
    check1.totalAmount = check1.product.price;

    phone1.check = check1;

    PrintDevice(phone1);
    cout << "\n";
    PrintCheck(check1);
}

void PrintDevice(const Device& device)
{
    cout << "Device:\n";
    cout << "-Full name:\t" << device.fullName << "\n";
    cout << "-Type:\t\t" << device.type << "\n";
    cout << "-Brand:\t\t" << device.brand << "\n";
    cout << "-Name:\t\t" << device.name << "\n";
    cout << "-Model:\t\t" << device.model << "\n";
    cout << "-Price:\t\t" << device.price << "\n";
    cout << "-Sale date:\t" << device.saleDate.day << "." << device.saleDate.month << "." << device.saleDate.year << "\n";
    cout << "-Warranty:\t" << device.warrantyUpTo.day << "." << device.warrantyUpTo.month << "." << device.warrantyUpTo.year << "\n";
}

void PrintCheck(const Check& check)
{
    struct Pos
    {
        char upLeft = (char)218;
        char upRight = (char)191;

        char mid = (char)196;
        char midLeft = (char)195;
        char midRight = (char)180;

        char downLeft = (char)192;
        char downRight = (char)217;
        
        char space = ' ';
        char spaceLeft = (char)179;
        char spaceRight = (char)179;
    };

    const int width = 40;

    string todaysDate = to_string(check.todaysDate.day) + "." + to_string(check.todaysDate.month) + "." + to_string(check.todaysDate.year);
    string check_number = to_string(check.checkNumber);
    string cashbox_number = to_string(check.cashBoxNumber);

    string product_price;
    string client_bonus;
    string bonus_gathered;
    string balance;
    string total_amount;
    stringstream ss;
    stringstream ss2;
    stringstream ss3;
    stringstream ss4;
    stringstream ss5;
    ss.precision(2);
    ss2.precision(2);
    ss3.precision(2);
    ss4.precision(2);
    ss5.precision(2);
    ss << fixed << check.product.price;
    ss2 << fixed << check.clientBonus;
    ss3 << fixed << check.bonusGathered;
    ss4 << fixed << check.balance;
    ss5 << fixed << check.totalAmount;
    product_price = ss.str();
    client_bonus = ss2.str();
    bonus_gathered = ss3.str();
    balance = ss4.str();
    total_amount = ss5.str();

    Pos pos;

    char up[width];
    char down[width];
    char mid[width];
    char space[width];
    
    for (int i = 0; i < width; i++)
    {
        if (i == 0)
        {
            up[i] = pos.upLeft;
            down[i] = pos.downLeft;
            mid[i] = pos.midLeft;
            space[i] = pos.spaceLeft;
        }
        else if (i == width - 1)
        {
            up[i] = pos.upRight;
            down[i] = pos.downRight;
            mid[i] = pos.midRight;
            space[i] = pos.spaceRight;
        }
        else
        {
            up[i] = pos.mid;
            down[i] = pos.mid;
            mid[i] = pos.mid;
            space[i] = pos.space;
        }
    }

    PrintText(up, width);

    PrintText(space, width);

    PrintCenterText(check.companyName, width);
    PrintCenterText(check.shopName, width);
    PrintCenterSpaceText(check.adress.city, width);
    PrintCenterSpaceText(check.adress.street + ", " + check.adress.house, width);

    PrintText(space, width);

    PrintLeftSpaceText(to_string(check.product.amount) + " X", width);
    PrintLeftRightSpaceText(check.product.name, product_price, width);

    PrintText(mid, width);

    PrintPromoText(check.specialPromo, width);

    PrintText(space, width);

    PrintPromoText("For " + todaysDate + " You\nhave " + client_bonus + " bonuses", width);

    PrintText(mid, width);

    PrintPromoText("Check #" + check_number + "\nCashbox #" + cashbox_number, width);

    PrintText(mid, width);

    PrintCenterText(check.activeSale, width);

    PrintText(mid, width);

    PrintPromoText("Prediction for You:\n" + check.prediction, width);

    PrintText(mid, width);

    PrintPromoText("You gathered " + bonus_gathered + "\nnow You have " + balance, width);

    PrintText(mid, width);

    PrintLeftRightSpaceText("Total amount:", total_amount, width);

    PrintText(mid, width);

    PrintCenterText("Thanks for choosing out store!", width);

    PrintText(down, width);

    
}

void PrintCenterText(string text, const int width)
{
    int tmp = round(ceil((double)width / 2) - ceil((double)text.length() / 2));
    
    cout << (char)195;
    for (int i = 1; i < tmp; i++)
    {
        cout << (char)196;
    }
    cout << text;
    for (int i = tmp + text.length(); i < width - 1; i++)
    {
        cout << (char)196;
    }
    cout << (char)180 << "\n";
}

void PrintCenterSpaceText(string text, const int width)
{
    int tmp = round(ceil((double)width / 2) - ceil((double)text.length() / 2));

    cout << (char)179;
    for (int i = 1; i < tmp; i++)
    {
        cout << " ";
    }
    cout << text;
    for (int i = tmp + text.length(); i < width - 1; i++)
    {
        cout << " ";
    }
    cout << (char)179 << "\n";
}

void PrintLeftRightSpaceText(string textLeft, string textRight, const int width)
{
    cout << (char)179 << textLeft;
    for (int i = textLeft.length() + 1; i < width - textRight.length() - 1; i++)
    {
        cout << " ";
    }
    cout << textRight << (char)179 << "\n";
}

void PrintLeftSpaceText(string text, const int width)
{
    cout << (char)179 << text;
    for (int i = text.length() + 1; i < width - 1; i++)
    {
        cout << " ";
    }
    cout << (char)179 << "\n";
}

void PrintPromoText(string text, const int width)
{
    int tmp = 0;

    cout << (char)179;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != '\n')
        {
            cout << text[i];
        }
        else
        {
            for (int j = i; j < width - 2; j++)
            {
                cout << " ";
                tmp++;
            }
            tmp++;
            cout << (char)179 << text[i] << (char)179;
        }
    }
    for (int k = 0; k < width * 2 - 2 - text.length() - tmp; k++) // пофиксить длину
    {
        cout << " ";
    }
    cout << (char)179 << "\n";
}

void PrintText(char arr[], const int width)
{
    for (int i = 0; i < width; i++)
    {
        cout << arr[i];
    }
    cout << "\n";
}
