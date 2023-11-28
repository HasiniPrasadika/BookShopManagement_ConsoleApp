#pragma once
#include <iostream>
#include <string>
#include "Header.h"
using namespace std;



struct Book
{
	int id;
	string name;
	string author;
	float price;
	int stock;
	int discount;
};

struct Node2
{
	Book book;
	Node2* next;
};

class BookList
{
public:

	Node2* head;
	int size;

public:

	BookList()
	{
		head = NULL;
		size = 0;
	}

	void addBook(Book book)
	{
		Node2* newNode = new Node2;
		newNode->book = book;
		newNode->next = head;
		head = newNode;
		size++;
	}

	void deleteFirstbook()
	{
		if (head == NULL)
		{
			cout << "Book list is empty" << endl;
		}
		else
		{
			Node2* temp = head;
			if (size == 1)
			{
				delete temp;
				head = NULL;
				size = 0;
			}
			else
			{
				head = head->next;
				delete temp;
				size--;
			}
		}
	}

	void deleteLastbook()
	{
		if (head == NULL)
		{
			cout << "Book list is empty" << endl;
		}
		else
		{
			if (size == 1)
			{
				Node2* temp = head;
				delete temp;
				head = NULL;
				size = 0;
			}
			else
			{
				Node2* current = head;
				for (int i = 0; i < size - 1; i++)
				{
					current = current->next;
				}
				current->next = NULL;
				delete current;

				size--;
			}
		}
	}

	void deleteAt(int pos)
	{
		if (pos < 0 || pos > size)
		{
			cout << "Invalid Index" << endl;
		}
		else if (pos == 0)
		{
			deleteFirstbook();
		}
		else if (pos == size)
		{
			deleteLastbook();
		}
		else
		{
			Node2* current = head;
			for (int i = 0; i < pos - 1; i++)
			{
				current = current->next;
			}
			Node2* temp = current->next;
			current->next = temp->next;

			delete temp;
			size--;

		}
	}


	int searchBookById(int id)
	{
		Node2* current = head;
		for (int i = 0; i < size; i++)
		{
			if (current->book.id == id)
			{
				return i;				
			}
			current = current->next;
		}

		return -1;
	}

	void searchBookByIdtogetinfo(int id)
	{
		Node2* current = head;
		for (int i = 0; i < size; i++)
		{
			if (current->book.id == id)
			{
				cout << "\n\t\t\t\t\tBook name is " << current->book.name << endl;
				cout << "\t\t\t\t\tAuthor is " << current->book.author << endl;
				cout << "\t\t\t\t\tAvailable stock is " << current->book.stock << endl;
				cout << "\t\t\t\t\tPrice is Rs." << current->book.price << endl;
				return;
			}

			current = current->next;
		}

		return;
	}

	void searchBookByNametogetinfo(string name)
	{
		Node2* current = head;
		for (int i = 0; i < size; i++)
		{
			if (current->book.name == name)
			{
				cout << "\n\t\t\t\t\tBook id is " << current->book.id << endl;
				cout << "\t\t\t\t\tAuthor is " << current->book.author << endl;
				cout << "\t\t\t\t\tAvailable stock is " << current->book.stock << endl;
				cout << "\t\t\t\t\tPrice is Rs." << current->book.price << endl;
				return;

			}

			current = current->next;

		}
		return;
	}

	int searchBookByName(string name)
	{
		Node2* current = head;
		for (int i = 0; i < size; i++)
		{
			if (current->book.name == name)
			{
				return i;
			}
			current = current->next;
		}

		return -1;
	}

	void checkAvailability(string name)
	{
		Node2* current = head;
		int i;
		for (i = 0; i < size; i++)
		{
			if (current->book.name == name)
			{
				if (current->book.stock > 0)
				{
					cout <<  " \n\t\t\t\t\t\tThis book is Available" << endl;
					cout << "\t\t\t\t\t\tPrice is Rs." << current->book.price << endl;
					if (current->book.discount > 0)
					{
						cout << "\t\t\t\t\t\tDiscount is " << current->book.discount << "%" << endl;
						int d = (current->book.price) - (((current->book.price) * (current->book.discount)) / 100);
						cout << "\t\t\t\t\t\tGross amount is Rs. " << d << endl;
						return;
					}
					else
					{
						cout << "\t\t\t\t\t\tNo discount" << endl;
						return;
					}
				}

				else
				{
					cout << "\t\t\t\t" << "This book is not Available" << endl;
					return;
				}
			}

			else
			{
				current = current->next;
			}
		}
	}

	int placeOrder(string name, int quantity)
	{
		Node2* current = head;
		int i;
		for (i = 0; i < size; i++)
		{
			if (current->book.name == name)
			{
				if (current->book.stock >= quantity)
				{
					cout << "\t\t\t\tYou can order this book" << endl;
					cout << "\n\t\t\t\t\t\tPrice is Rs." << (current->book.price) * quantity << endl;

					if (current->book.discount > 0)
					{
						cout << "\t\t\t\t\t\tDiscount is " << current->book.discount << "%" << endl;
						int d = ((current->book.price) - (((current->book.price) * (current->book.discount)) / 100)) * quantity;
						cout << "\n\t\t\t\t\t\tGross amount is Rs." << d << endl;
					}

					else
					{
						cout << "\t\t\t\t\t\tNo discount" << endl;
						int d = ((current->book.price) - (((current->book.price) * (current->book.discount)) / 100)) * quantity;
						cout << "\n\t\t\t\t\t\tGross amount is Rs." << d << endl;
					}

					int f;
					cout << "\n\t\t\t\t\tDo you want to place this order" << endl;
					cout << "\t\t\t\t\t\t\t01. Yes" << endl;
					cout << "\t\t\t\t\t\t\t02. No" << endl;
					cin >> f;
					if (f == 1)
					{
						return 1;
					}
					else
					{
						return -1;
					}

				}
				else
				{
					cout << " \t\t\t\t\t\tStock is not enough" << endl;
					return -1;
				}

			}
			else
			{
				current = current->next;
			}
		}
		return -1;
	}

	int calculatebill(string bookname, int quantity)
	{
		Node2* current = head;
		int i;
		int d;
		for (int i = 0; i < size; i++)
		{
			if (current->book.name == bookname)
			{
				d = ((current->book.price) - (((current->book.price) * (current->book.discount)) / 100)) * quantity;
			}
			current = current->next;
		}
		return d;

	}


	void updateStock(int index, int stock)
	{
		Node2* current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		current->book.stock = stock;
	}

	void printBooks()
	{
		cout << "ID\t Title\t\t\tAuthor\t\t\t\tPrice\t\tStock" << endl;
		cout << "\n" << endl;
		Node2* temp = head;
		while (temp != NULL)
		{
			cout << temp->book.id << "\t" << temp->book.name << "\t\t " << temp->book.author << "\t\t\t" << temp->book.price << "\t\t" << temp->book.stock << endl;
			temp = temp->next;
		}
		cout << "          " << endl;
		cout << "          " << endl;
		cout << "          " << endl;

	}

};
