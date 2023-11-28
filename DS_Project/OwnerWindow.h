#pragma once
#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;
#include "Header.h"
#include "Ordersqueue.h"



int Ownerlogin()
{
    string usercd = "bms";
    string passcd = "book47";

    string usercode;
    string passcode;
    cout << "\t\t\t\t\tEnter the usercode : " << " ";
    getline(cin >> ws, usercode);
    cout << endl;
    cout << "\t\t\t\t\tEnter a passcode   : " << " ";
    getline(cin >> ws, passcode);
    cout << endl;

    if (usercode == usercd && passcode == passcd)
    {
        return -1;
    }
    cout << "\t\t\t\t\tInvalid usercode or passcode" << endl;

    return Ownerlogin();

}


void Ownerwindow(CustomerList& newcustomerList, BookList& storybookList, BookList& novelbookList, BookList& translatedbookList, OrderQueue& orderlist)
{
    system("cls");
    cout << "\n" << endl;
    cout << "\t\t\t\t\t\t1. Add New Book" << endl;
    cout << "\t\t\t\t\t\t2. Delete Book" << endl;
    cout << "\t\t\t\t\t\t3. Update Stock" << endl;
    cout << "\t\t\t\t\t\t4. Search Book by Id" << endl;
    cout << "\t\t\t\t\t\t5. Search Book by Name" << endl;
    cout << "\t\t\t\t\t\t6. View all books" << endl;
    cout << "\t\t\t\t\t\t7. Search customers by Username" << endl;
    cout << "\t\t\t\t\t\t8. View all customers" << endl;
    cout << "\t\t\t\t\t\t9. View orders and Calculate bill" << endl;  
    cout << "\t\t\t\t\t\t10. Main menu" << endl;

    int choice03;
    cin >> choice03;
    system("cls");

    if (choice03 == 1)//add new book
    {
        system("cls");
            Book book;
            cout << "\t\t\t\tEnter the book Id : " << " ";
            cin >> book.id;
            cout << endl;
            cout << "\t\t\t\tEnter the book name : " << " ";
            getline(cin >> ws, book.name);
            cout << endl;
            cout << "\t\t\t\tEnter the Author : " << " ";
            getline(cin >> ws, book.author);
            cout << endl;
            cout << "\t\t\t\tEnter the price : " << " ";
            cin >> book.price;
            cout << endl;
            cout << "\t\t\t\tEnter the stock : " << " ";
            cin >> book.stock;
            cout << endl;
            cout << "\t\t\t\tEnter the discount : " << " ";
            cin >> book.discount;
            cout << endl; 
            
            cout << "\t\t\t\t\t01. Story books" << endl;
            cout << "\t\t\t\t\t02. Novels" << endl;
            cout << "\t\t\t\t\t03. Translated books" << endl;
            cout << "\t\t\t\tEnter the book category : " << " ";           
                                    
            
            int choice04;
            cin >> choice04;
            switch (choice04)
            {
            case 01:
                storybookList.addBook(book);
                cout << "\n\t\t\t\t.....You have successfully added a new story book....." << endl;
                int a;
                cout << "\n\t\t\t\tpress 1 to go back" << endl;
                cin >> a;
                if (a == 1)
                    return Ownerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
                break;
            case 02:
                novelbookList.addBook(book);
                cout << "\n\t\t\t\t.....You have successfully added a new novel book....." << endl;
                int b;
                cout << "\n\t\t\t\tpress 1 to go back" << endl;
                cin >> b;
                if (b == 1)
                    return Ownerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
                break;
            case 03:
                translatedbookList.addBook(book);
                cout << "\n\t\t\t\t.....You have successfully added a new translated book....." << endl;
                int c;
                cout << "\n\t\t\t\tpress 1 to go back" << endl;
                cin >> c;
                if (c == 1)
                    return Ownerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
                break;
            }             
    }

    else if (choice03 == 2)//delete book
    {
        string bookname;
        cout << "\t\t\t\tEnter the book name : " << " ";
        getline(cin >> ws, bookname);
        cout << endl;        
        cout << "\t\t\t\t\t01. Story books" << endl;
        cout << "\t\t\t\t\t02. Novels" << endl;
        cout << "\t\t\t\t\t03. Translated books" << endl;
        cout << "\t\t\t\tEnter the book category : " << " ";

        int choice04;
        cin >> choice04;
        switch (choice04)
        {
        case 01:

            int var1;
            var1 = storybookList.searchBookByName(bookname);
            storybookList.deleteAt(var1);
            cout << "\n\t\t\t\t.....You have successfully deleted a story book....." << endl;
            int e;
            cout << "\n\t\t\t\tpress 1 to go back" << endl;
            cin >> e;
            if (e == 1)
                return Ownerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
            break;

        case 02:

            int var2;
            var2 = novelbookList.searchBookByName(bookname);
            novelbookList.deleteAt(var2);
            cout << "\n\t\t\t\t.....You have successfully deleted a novel book....." << endl;
            int f;
            cout << "\n\t\t\t\tpress 1 to go back" << endl;
            cin >> f;
            if (f == 1)
                return Ownerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
            break;

        case 03:

            int var3;
            var3 = translatedbookList.searchBookByName(bookname);
            translatedbookList.deleteAt(var3);
            cout << "\n\t\t\t\t.....You have successfully deleted a translated book....." << endl;
            int g;
            cout << "\n\t\t\t\tpress 1 to go back" << endl;
            cin >> g;
            if (g == 1)
                return Ownerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
            break;
        }        
    }

    else if (choice03 == 3)//update stock
    {
        string bookname;
        int stock;
        cout << "\t\t\t\tEnter the book name : " << " ";        
        getline(cin >> ws, bookname);
        cout << endl;
        cout << "\t\t\t\tEnter new stock : " << " ";
        cin >> stock;
        cout << endl;
        
        cout << "\t\t\t\t\t01. Story books" << endl;
        cout << "\t\t\t\t\t02. Novels" << endl;
        cout << "\t\t\t\t\t03. Translated books" << endl;

        int choice04;
        cout << "\t\t\t\tEnter the book category : " << " ";
        cin >> choice04;
        switch (choice04)
        {
        case 01:

            int var4;
            var4 = storybookList.searchBookByName(bookname);
            storybookList.updateStock(var4, stock);
            cout << "\n\t\t\t\t.....You have successfully updated a stock....." << endl;
            int e;
            cout << "\n\t\t\t\tpress 1 to go back" << endl;
            cin >> e;
            if (e == 1)
                return Ownerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
            break;

        case 02:

            int var5;
            var5 = novelbookList.searchBookByName(bookname);
            novelbookList.updateStock(var5, stock);
            cout << "\n\t\t\t\t.....You have successfully updated a stock....." << endl;
            int f;
            cout << "\n\t\t\t\tpress 1 to go back" << endl;
            cin >> f;
            if (f == 1)
                return Ownerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
            break;

        case 03:

            int var6;
            var6 = translatedbookList.searchBookByName(bookname);
            translatedbookList.updateStock(var6, stock);
            cout << "\n\t\t\t\t.....You have successfully updated a stock....." << endl;
            int g;
            cout << "\n\t\t\t\tpress 1 to go back" << endl;
            cin >> g;
            if (g == 1)
                return Ownerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
            break;
        }    
    }

    else if (choice03 == 4)//search book by Id
    {
        int id;       
        cout << "\t\t\t\tEnter the book Id : " << " ";
        cin >> id;
        cout << endl;
        int d = storybookList.searchBookById(id);
        int f = novelbookList.searchBookById(id);
        int g = translatedbookList.searchBookById(id);

        if (d != -1 || f != -1 || g != -1)
        {
            cout << "\t\t\t\t....Book is found...." << endl;
            if (d != -1)
            {
                storybookList.searchBookByIdtogetinfo(id);
                cout << "\t\t\t\t\tThis is a story book" << endl;

            }
            else if (f != -1)
            {
                novelbookList.searchBookByIdtogetinfo(id);
                cout << "\t\t\t\t\tThis is a novel book" << endl;
            }
            else if (g != -1)
            {
                translatedbookList.searchBookByIdtogetinfo(id);
                cout << "\t\t\t\t\tThis is a translated book" << endl;
            }            
        }

        else
        {
            cout << "\t\t\t\t....Book is not found...." << endl;
        }
        int e;
        cout << "\n\t\t\t\tpress 1 to go back" << endl;
        cin >> e;
        if (e == 1)
            return Ownerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
    }

    else if (choice03 == 5)//search book by Name
    {
    string name;
    cout << "\t\t\t\tEnter the book name : " << " ";
    getline(cin >> ws, name);
    cout << endl;
    int d = storybookList.searchBookByName(name);
    int f = novelbookList.searchBookByName(name);
    int g = translatedbookList.searchBookByName(name);

        if (d != -1 || f != -1 || g != -1)
        {
            cout << "\t\t\t\t....Book is found...." << endl; 
            
            if (d != -1)
            {
                storybookList.searchBookByNametogetinfo(name);
                cout << "\t\t\t\t\tThis is a story book" << endl;

            }
            else if (f != -1)
            {
                novelbookList.searchBookByNametogetinfo(name);
                cout << "\t\t\t\t\tThis is a novel book" << endl;
            }
            else if (g != -1)
            {
                translatedbookList.searchBookByNametogetinfo(name);
                cout << "\t\t\t\t\tThis is a translated book" << endl;

            }
        }
        else
        {
            cout << "\t\t\t\t....Book is not found...." << endl;
        }

    int e;
    cout << "\n\t\t\t\tpress 1 to go back" << endl;
    cin >> e;

    if (e == 1)
        return Ownerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
    }

    else if (choice03 == 6)//view all books
    {
    cout << "\t\t########  Story Books  ########\n" << endl;      
    storybookList.printBooks();
    cout << "\t\t########  Novels  ########\n" << endl;
    novelbookList.printBooks();
    cout << "\t\t########  Translated Books  ########\n" << endl;
    translatedbookList.printBooks();

    int e;
    cout << "press 1 to go back" << endl;
    cin >> e;

    if (e == 1)
        return Ownerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
    }
    
    else if (choice03 == 7)//search customer by Username
    {
    string name;
    cout << "\t\t\t\tEnter the Username : " << " ";
    getline(cin >> ws, name);
    cout << endl;
    int d = newcustomerList.searchCustomerByUsername(name);

    if (d != -1)
    {
        cout << "\t\t\t\t....Customer is found...." << endl;
        newcustomerList.searchCustomerByUsernametogetinfo(name);
    }
    else
    {
        cout << "\t\t\t\t....Customer is not found...." << endl;
    }
    int e;
    cout << "\n\t\t\t\tpress 1 to go back" << endl;
    cin >> e;
    if (e == 1)
        return Ownerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
    }

    else if (choice03 == 8)//view all customers
    {
    newcustomerList.printAllCustomers();
    int e;
    cout << "\n\t\t\t\tpress 1 to go back" << endl;
    cin >> e;

    if (e == 1)
        return Ownerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
    }

    else if (choice03 == 9)    //view orders and calculate bill
    {
    bool g = true;
    while (g == true)
    {
        cout << "\t\t.........Order List.........\n" << endl;
        cout << "\tusername\tbook name      \tquantity\n" << endl;
        orderlist.print();
        string usernm;
        cout << "\t\t\t\tenter the customers user name : " << " ";
        getline(cin >> ws, usernm);
        cout << endl;
        int f;

        orderlist.calculatenetbill(usernm, storybookList, novelbookList, translatedbookList);        
        
        
        cout << "\t\t\t\tDo you want to calculate another bill" << endl;
        cout << "\t\t\t\t\t\t1. yes" << endl;
        cout << "\t\t\t\t\t\t2. no" << endl;
        cin >> f;
        if (f == 1)
        {
            g = true;            
        }
        else
        {
            g = false;
        }
    }
    int e;
    cout << "\n\t\t\t\tpress 1 to go back" << endl;
    cin >> e;
    if (e == 1)
        return Ownerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);    
    
    }
    
    else if (choice03 == 10)//main menu
    {
    int s;
    cout << "\t\t\t\tpress 1 to go to main menu" << endl;
    cout << "\n\t\t\t\tpress 2 to go to owner window" << endl;
    cin >> s;
    if (s == 1)
        {
            return;
        }
        else
        {
            return Ownerwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
        }
    }
    return;

}
