#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include "Header.h"

using namespace std;
#include "CustomerInfolinked_list.h"
#include "BookInfolinked_list.h"
#include "OwnerWindow.h"
#include "CustomerWindow.h"
#include "Ordersqueue.h"


int main()
{	
	//Owners usercode is "bms"
	//Owners passcode is "book47"
	CustomerList newcustomerList;
	BookList storybookList;
	BookList novelbookList;
	BookList translatedbookList;
	OrderQueue orderlist(1000);

	//book list
	Book book1;

	book1.id = 101; book1.name = "famous five";  book1.author = "sudath rohana"; book1.price = 500; book1.stock = 10, book1.discount = 5;
	Book book2;
	book2.id = 102; book2.name = "nensi draw";  book2.author = "jagath kumara"; book2.price = 450; book2.stock = 20, book2.discount = 3;
	Book book3;
	book3.id = 103; book3.name = "hathpana";  book3.author = "k. munidasa"; book3.price = 560; book3.stock = 15, book3.discount = 7;
	
	Book book4;
	book4.id = 104; book4.name = "wassanaya"; book4.author = "shantha soisa"; book4.price = 700; book4.stock = 10, book4.discount = 0;
	Book book5;
	book5.id = 105; book5.name = "prarthana"; book5.author = "kamal gangoda"; book5.price = 790; book5.stock = 12, book5.discount = 2;
	Book book6;
	book6.id = 106; book6.name = "bonda meedum"; book6.author = "shantha soisa"; book6.price = 600; book6.stock = 20, book6.discount = 5;
	
	Book book7;
	book7.id = 107; book7.name = "sharlokhomes"; book7.author = "chamal mendis"; book7.price = 950; book7.stock = 10, book7.discount = 10;
	Book book8;
	book8.id = 108; book8.name = "harry potter"; book8.author = "sunil gunadasa"; book8.price = 1500; book8.stock = 18, book8.discount = 4;
	Book book9;
	book9.id = 109; book9.name = "new adventure"; book9.author = "amith sirisena"; book9.price = 650; book9.stock = 25, book9.discount = 9;
	
	storybookList.addBook(book1);
	storybookList.addBook(book2);
	storybookList.addBook(book3);

	novelbookList.addBook(book4);
	novelbookList.addBook(book5);
	novelbookList.addBook(book6);

	translatedbookList.addBook(book7);
	translatedbookList.addBook(book8);
	translatedbookList.addBook(book9);

	//customer list
	Customer customer1;
	customer1.Name = "hasini"; customer1.Username = "hpm"; customer1.Password = "123";
	Customer customer2;
	customer2.Name = "rashmi"; customer2.Username = "rm"; customer2.Password = "456";
	Customer customer3;
	customer3.Name = "prasadi"; customer3.Username = "mph"; customer3.Password = "789";
	newcustomerList.addCustomer(customer1);
	newcustomerList.addCustomer(customer2);
	newcustomerList.addCustomer(customer3);
	Mainwindow(newcustomerList, storybookList, novelbookList, translatedbookList, orderlist);
	cout << "\n\n\t\t\t\t\t\t....Program ending..." << endl;
	cout << "\t\t\t\t\t\tThank You for Visiting" << endl;
	cout << "\nt\t\t\t\tPress any key to close the window" << endl;

	return 0;

}

