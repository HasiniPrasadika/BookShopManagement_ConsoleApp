#pragma once
#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

struct Order
{
	string bookname;
	int quanity;
	string username;
};

class OrderQueue
{
private:

	int front;
	int rear;
	int capacity;
	int size;
	Order* data;

public:

	OrderQueue(int k)
	{
		front = 0;
		rear = 0;
		capacity = k;
		size = 0;
		data = new Order[capacity];
	}

	void Placeorder(string Bookname, int Quantity, string username)
	{

		Order order;
		order.bookname = Bookname;
		order.quanity = Quantity;
		order.username = username;

		data[rear] = order;
		rear = (rear + 1) % capacity;
		size++;

	}

	int print()
	{
		if (size == 0)
		{
			cout << "Queue is empty" << endl;
			return -1;
		}
		else
		{
			int index = front;
			for (int i = 0; i < size; i++)
			{
				cout << "\t" << data[index].username << " " << "\t\t"<<  data[index].bookname << " " << "\t\t" << data[index].quanity << endl;
				index = (index + 1) % capacity;
			}
			cout << endl;
		}
	}


	void calculatenetbill(string username, BookList& storybookList, BookList& novelbookList, BookList& translatedbookList)
	{
		int amount = 0;
		int index = 0;
		int a;
		string* arr1 = new string[100];
		int* arr2 = new int[100];
		int* arr3 = new int[100];


		while (data[front].username == username)
		{

			cout << "\n\t\t\t\tDo you want to get this " << data[front].bookname << " book Order" << endl;
			int f;
			cout << "\t\t\t\t\t\t1. yes" << endl;
			cout << "\t\t\t\t\t\t2. no" << endl;
			cin >> f;

			if (f == 1)
			{
				int d = storybookList.searchBookByName(data[front].bookname);
				int f = novelbookList.searchBookByName(data[front].bookname);
				int g = translatedbookList.searchBookByName(data[front].bookname);
				if (d != -1 || f != -1 || g != -1)
				{
					if (d != -1)
					{
						a = storybookList.calculatebill(data[front].bookname, data[front].quanity);
						amount = amount + a;

					}
					else if (f != -1)
					{
						a = novelbookList.calculatebill(data[front].bookname, data[front].quanity);
						amount = amount + a;

					}
					else if (g != -1)
					{
						a = translatedbookList.calculatebill(data[front].bookname, data[front].quanity);
						amount = amount + a;

					}
				}
				arr1[index] = data[front].bookname;
				arr2[index] = data[front].quanity;
				arr3[index] = a;
				index++;


				front = (front + 1) % capacity;
				size--;

			}
			else
			{
				front = (front + 1) % capacity;
				size--;
			}
		}

		cout << "\t\tBook Name     " << "\t\t" << "Quantity" << "\t\t" << "Price" << "\n" << endl;

		for (int i = 0; i < index; i++)
		{
			cout << "\t\t" << arr1[i] << "\t\t\t" << arr2[i] << "\t\t\t" << arr3[i] << endl;
		}

		cout << "\n\t\tTotal price is : Rs." << amount << endl;
		cout << "\n\t\t......Thank you for your transaction......" << endl;
		cout << "\t\t" << "......Come Again!!!!.....\n" << endl;
	}
};



