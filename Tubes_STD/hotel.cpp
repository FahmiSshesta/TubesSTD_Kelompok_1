#include "hotel.h"
#include <fstream>
#include <sstream>

HotelList::HotelList() {
    head = nullptr;
}

HotelList::~HotelList() {
    while (head) {
        Hotel* temp = head;
        head = head->next;
        delete temp;
    }
}

void HotelList::addHotel(int id, string name, int rooms) {
    Hotel* node = new Hotel{id, name, rooms, nullptr};
    if (!head) head = node;
    else {
        Hotel* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = node;
    }
}

void HotelList::displayHotels() {
    Hotel* temp = head;
    while (temp) {
        cout << temp->id << " - " << temp->name
             << " | Rooms: " << temp->rooms << endl;
        temp = temp->next;
    }
}

Hotel* HotelList::searchHotel(int id) {
    Hotel* temp = head;
    while (temp) {
        if (temp->id == id) return temp;
        temp = temp->next;
    }
    return nullptr;
}

void HotelList::loadFromCSV(string filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string id, name, rooms;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, rooms, ',');

        addHotel(stoi(id), name, stoi(rooms));
    }
    file.close();
}

void HotelList::generateCSV(string filename) {
    ofstream file(filename);
    for (int i = 1; i <= 20; i++) {
        file << i << ",Hotel_" << i << "," << (50 + i) << "\n";
    }
    file.close();
}
