#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <string>
using namespace std;

struct Booking {
    int bookingId;
    int customerId;
    int hotelId;
    Booking* next;
};

class BookingList {
private:
    Booking* head;

public:
    BookingList();
    ~BookingList();

    void addBooking(int bookingId, int customerId, int hotelId);
    void displayBookings();
    void exportCSV(string filename);
};

#endif
