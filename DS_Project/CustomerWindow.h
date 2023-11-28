#pragma once
#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;
#include "Header.h"


bool Customerlogin(CustomerList& NewcustomerList2)
{
    Customer newcustomer2;
    cout << "\t\t\t\tEnter the name     : " << " ";
    getline(cin >> ws, newcustomer2.Name);
    cout << endl;
    cout << "\t\t\t\tEnter the username : " << " ";
    getline(cin >> ws, newcustomer2.Username);
    cout << endl;
    cout << "\t\t\t\tEnter a password   : " << " ";
    getline(cin >> ws, newcustomer2.Password);
    cout << endl;

    int var1 = NewcustomerList2.searchCustomerByPassword(newcustomer2.Password);
    int var2 = NewcustomerList2.searchCustomerByUsername(newcustomer2.Username);

    if (var1 != -1 && var2 != -1 && var1 == var2)
    {

        return true;
    }
    cout << "\t\t\t\t\tInvalid username or password\n" << endl;

    return Customerlogin(NewcustomerList2);

}

bool Customersignup(CustomerList& NewcustomerList1)
{
    Customer newcustomer1;
    cout << "\t\t\t\tEnter the name     : " << " ";
    getline(cin >> ws, newcustomer1.Name);
    cout << endl;
    cout << "\t\t\t\tEnter the username : " << " ";
    getline(cin >> ws, newcustomer1.Username);
    cout << endl;
    cout << "\t\t\t\tEnter a password   : " << " ";
    getline(cin >> ws, newcustomer1.Password);
    cout << endl;

    int var1 = NewcustomerList1.searchCustomerByPassword(newcustomer1.Password);
    if (var1 == -1)
    {
        NewcustomerList1.addCustomer(newcustomer1);
        return true;
    }
    cout << "\t\t\t\t\tPassword is already exist\n" << endl;

    return Customersignup(NewcustomerList1);

}

void Customerwindow(CustomerList& newcustomerList, BookList& storybookList, BookList& novelbookList, BookList& translatedbookList, OrderQueue& orderlist)
{
    cout << "\t\t\t\t\t1. Search Book" << endl;
    cout << "\t\t\t\t\t2. Place orders" << endl;
    cout << "\t\t\t\t\t3. Main menu" << endl;

    int choice04;
    cin >> choice04;

    system("cls");
    if (choice04 == 1)//search book
    {
        string name;
        cout << "\t\t\t\tEnter the book name : " << " ";
        getline(cin >> ws, name);
        int d = storybookList.searchBookByName(name);
        int f = novelbookList.searchBookByName(name);
        int g = translatedbookList.searchBookByName(name);
        if (d != -1 || f != -1 || g != -1)
        {
            cout << "\n\t\t\t\t\t....Book is found...." << endl;
            if (d != -1)
            {
                storybookList.checkAvailability(name);

            }
            else if (f != -1)
            {
                novelbookList.checkAvailability(name);

            }
            else if (g != -1)
            {
                translatedbookList.checkAvailability(name);
            }
        }

        else
        {
            cout << "\n\t\t\t\t\t....Book is not found...." << endl;
        }
        int s;
        cout << "\n\t\t\t\tpress 1 to go back" << endl;
        cin >> s;
        system("cls");

        if (s == 1)
            return Customerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);

    }

    else if (choice04 == 2)//place orders
    {
        string name;
        int quantity;
        string username;
        cout << "\t\t\t\tEnter the user name : " << " ";
        getline(cin >> ws, username);
        cout << endl;
        cout << "\t\t\t\tEnter the book name : " << " ";
        getline(cin >> ws, name);
        cout << endl;
        cout << "\t\t\t\tEnter the quantity  : " << " ";
        cin >> quantity;
        cout << endl;
        int a = 0;

        int d = storybookList.searchBookByName(name);
        int f = novelbookList.searchBookByName(name);
        int g = translatedbookList.searchBookByName(name);

        if (d != -1 || f != -1 || g != -1)
        {
            cout << "\n\t\t\t\t....book is found...." << endl;
            if (d != -1)
            {
                a = storybookList.placeOrder(name, quantity);

            }
            else if (f != -1)
            {
                a = novelbookList.placeOrder(name, quantity);
            }
            else if (g != -1)
            {
                a = translatedbookList.placeOrder(name, quantity);

            }

        }
        else
        {
            cout << "\n\t\t\t\t....Book is not found...." << endl;

        }
        if (a == 1)
        {
            orderlist.Placeorder(name, quantity, username);

            cout << "\t\t\t\t\t....Thank you for the order!!!!!!...." << endl;
            
            
        }
        int s;
        cout << "\n\t\t\t\tpress 1 to go back" << endl;
        cin >> s;
        system("cls");
        if (s == 1)
            return Customerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);

    }

    
    else //main menu
    {
        int s;
        cout << "\t\t\t\tpress 1 to go to main menu" << endl;
        cout << "\t\t\t\tpress 2 to go to customer window" << endl;
        cin >> s;
        if (s == 1)
        {
            return;
        }
        else
        {
            return Customerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
        }

    }
    return;


}

