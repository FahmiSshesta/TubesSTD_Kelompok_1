#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
using namespace std;

struct Customer {
    int id;
    string name;
    string phone;
    Customer* next;
};

class CustomerList {
private:
    Customer* head;

public:
    CustomerList();
    ~CustomerList();

    void addCustomer(int id, string name, string phone);
    void displayCustomers();
    Customer* searchCustomer(int id);

    void loadFromCSV(string filename);
    void generateCSV(string filename);
};

#endif
