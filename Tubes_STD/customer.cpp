#include "customer.h"
#include <fstream>
#include <sstream>

CustomerList::CustomerList() {
    head = nullptr;
}

CustomerList::~CustomerList() {
    while (head) {
        Customer* temp = head;
        head = head->next;
        delete temp;
    }
}

void CustomerList::addCustomer(int id, string name, string phone) {
    Customer* node = new Customer{id, name, phone, nullptr};
    if (!head) head = node;
    else {
        Customer* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = node;
    }
}

void CustomerList::displayCustomers() {
    Customer* temp = head;
    while (temp) {
        cout << temp->id << " - " << temp->name
             << " | Phone: " << temp->phone << endl;
        temp = temp->next;
    }
}

Customer* CustomerList::searchCustomer(int id) {
    Customer* temp = head;
    while (temp) {
        if (temp->id == id) return temp;
        temp = temp->next;
    }
    return nullptr;
}

void CustomerList::loadFromCSV(string filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string id, name, phone;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, phone, ',');

        addCustomer(stoi(id), name, phone);
    }
    file.close();
}

void CustomerList::generateCSV(string filename) {
    ofstream file(filename);
    for (int i = 1; i <= 20; i++) {
        file << i << ",Customer_" << i << ",0812" << (100000 + i) << "\n";
    }
    file.close();
}
