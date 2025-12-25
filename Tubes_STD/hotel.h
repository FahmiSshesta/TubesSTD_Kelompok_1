#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <string>
using namespace std;

struct Hotel {
    int id;
    string name;
    int rooms;
    Hotel* next;
};

class HotelList {
private:
    Hotel* head;

public:
    HotelList();
    ~HotelList();

    void addHotel(int id, string name, int rooms);
    void displayHotels();
    Hotel* searchHotel(int id);

    void loadFromCSV(string filename);
    void generateCSV(string filename);
};

#endif
