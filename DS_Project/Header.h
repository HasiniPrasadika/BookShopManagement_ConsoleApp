#pragma once
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;
#include "CustomerInfolinked_list.h"
#include "BookInfolinked_list.h"
#include "OwnerWindow.h"
#include "CustomerWindow.h"
#include "Ordersqueue.h"



void Mainwindow(CustomerList& newcustomerList, BookList& storybookList, BookList& novelbookList, BookList& translatedbookList, OrderQueue& orderlist)
{
    system("cls");
    
    cout << "\t\t\t\t\t.........KURULU BookShop............\n" << endl;
    cout << "\t\t\t############## Welcome to the bookshop management system ################\n" << endl; 
    
    int choice01;
    cout << "\t\t\t\t\t\t1. Login" << endl;//owner and customer can log into the system using their usernames and passwords
    cout << "\t\t\t\t\t\t2. Sign Up" << endl;//new customer can sign up to the system giving username and password.Then that customer is directed to log into the system.
    cout << "\t\t\t\t\t\t3. Quit" << endl;//program will end
    cin >> choice01;

    bool q = true;//while q is true, main window will be executed.when we choose quit option, q is made to false and program will end.

    while (q)
    {
        
        system("cls");
        if (choice01 == 1)//Log in
        {
            int choice02;
            cout << "\t\t\t\t\t\t01. Login as the owner" << endl;
            cout << "\t\t\t\t\t\t02. Login as a customer" << endl;
            cout << "\t\t\t\t\t\t03. Main Menu" << endl;
            cin >> choice02;

            system("cls");

            if (choice02 == 01)//log in as the owner
            {
                int a = Ownerlogin();
                if (a == -1)
                {
                    ////////////////functions for the owner///////////////////////
                    system("cls");
                    cout << "\t\t\t....you have successfully logged in to the system....\n" << endl;
                    Ownerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
                    return Mainwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);

                }

            }

            else if (choice02 == 02)//log in as the customer
            {
                bool b = Customerlogin(newcustomerList);
                if (b == true)
                {
                    ///////////////////functions for the customer/////////////////
                    system("cls");
                    cout << "\t\t\t....you have successfully logged in to the system....\n" << endl;
                    Customerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
                    return Mainwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
                }
            }

            else if (choice02 == 03)//Main window
            {
                return Mainwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
            }

            else
            {                
                return Mainwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
            }
        }

        else if (choice01 == 2)//Sign up
        {

            bool a = Customersignup(newcustomerList);

            if (a == true)
            {

                cout << "\n\t\t\t\t\t......You have successfully signed up.......\n" << endl;
                cout << "\t\t\t\t\tpress 1 to go to the main menu" << endl;
                int c;
                cin >> c;
                if (c == 1)
                {
                    return Mainwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
                }
            }            
        }

        else if (choice01 == 3)//Quit
        {
            q = false;
        }
        else
        {
            return Mainwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
        }
    }

    return;
}

