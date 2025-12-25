#include "booking.h"
#include <fstream>

BookingList::BookingList() {
    head = nullptr;
}

BookingList::~BookingList() {
    while (head) {
        Booking* temp = head;
        head = head->next;
        delete temp;
    }
}

void BookingList::addBooking(int bookingId, int customerId, int hotelId) {
    Booking* b = new Booking{bookingId, customerId, hotelId, nullptr};
    if (!head) head = b;
    else {
        Booking* t = head;
        while (t->next) t = t->next;
        t->next = b;
    }
}

void BookingList::displayBookings() {
    Booking* t = head;
    while (t) {
        cout << "Booking ID: " << t->bookingId
             << " | Customer ID: " << t->customerId
             << " | Hotel ID: " << t->hotelId << endl;
        t = t->next;
    }
}

void BookingList::exportCSV(string filename) {
    ofstream file(filename);
    Booking* t = head;
    while (t) {
        file << t->bookingId << "," << t->customerId
             << "," << t->hotelId << "\n";
        t = t->next;
    }
    file.close();
}
