#pragma once
#include <iostream>
#include <string>
#include "Header.h"
using namespace std;


struct Customer
{
    string Name;
    string Username;
    string Password;
};

struct Node1
{
    Customer customer;
    Node1* next;
};

class CustomerList
{
private:
    Node1* head;
    int size;

public:
    CustomerList()
    {
        head = NULL;

        size = 0;
    }

    void addCustomer(Customer customer)
    {
        Node1* newNode = new Node1;
        newNode->customer = customer;
        newNode->next = head;
        head = newNode;
        size++;
    }

    int searchCustomerByUsername(string username)//if the username found it return the index otherwise it return -1
    {
        Node1* current = head;
        for (int i = 0; i < size; i++)
        {
            if (current->customer.Username == username)
            {
                return i;
            }

            current = current->next;

        }

        return -1;
    }

    void searchCustomerByUsernametogetinfo(string username)//if the username found it return the index otherwise it return -1
    {
        Node1* current = head;
        for (int i = 0; i < size; i++)
        {
            if (current->customer.Username == username)
            {
                cout << "\n\t\t\t\t\tCustomers name is " << current->customer.Name << endl;
                cout << "\t\t\t\t\tCustomers password is " << current->customer.Password << endl;
                return;
            }

            current = current->next;
        }

        return;
    }

    int searchCustomerByPassword(string password)//if the password found it return the index otherwise it return -1
    {
        Node1* current = head;
        for (int i = 0; i < size; i++)
        {
            if (current->customer.Password == password)
            {
                return i;
            }

            current = current->next;
        }

        return -1;
    }

    void printAllCustomers()
    {
        cout << "\t\t\t.............Customer List............\n" << endl;
        cout << "\t\t\t\tName  \t\t\tUsername\n" << endl;

        Node1* current = head;
        while (current != NULL)
        {
            cout << "\t\t\t\t" << current->customer.Name << "\t\t\t" << current->customer.Username << endl;
            current = current->next;
        }
    }
    
};
