#include <iostream>
#include <fstream>
#include "customer.h"
#include "hotel.h"
#include "booking.h"
using namespace std;

int main() {
    CustomerList customers;
    HotelList hotels;
    BookingList bookings;

    // Generate CSV jika belum ada
    ifstream fc("customers.csv");
    if (!fc.is_open()) customers.generateCSV("customers.csv");
    fc.close();

    ifstream fh("hotels.csv");
    if (!fh.is_open()) hotels.generateCSV("hotels.csv");
    fh.close();

    customers.loadFromCSV("customers.csv");
    hotels.loadFromCSV("hotels.csv");

    int choice;
    int bookingId = 1;

    do {
        cout << "\n=== MENU HOTEL BOOKING ===\n";
        cout << "1. Lihat Customers\n";
        cout << "2. Lihat Hotels\n";
        cout << "3. Booking Hotel\n";
        cout << "4. Lihat Booking\n";
        cout << "5. Export Booking ke CSV\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        if (choice == 1) {
            customers.displayCustomers();
        }
        else if (choice == 2) {
            hotels.displayHotels();
        }
        else if (choice == 3) {
            int cid, hid;
            cout << "ID Customer: ";
            cin >> cid;
            cout << "ID Hotel: ";
            cin >> hid;

            if (customers.searchCustomer(cid) && hotels.searchHotel(hid)) {
                bookings.addBooking(bookingId++, cid, hid);
                cout << "Booking berhasil!\n";
            } else {
                cout << "Customer atau Hotel tidak ditemukan!\n";
            }
        }
        else if (choice == 4) {
            bookings.displayBookings();
        }
        else if (choice == 5) {
            bookings.exportCSV("booking.csv");
            cout << "Booking berhasil di-export ke booking.csv\n";
        }

    } while (choice != 0);

    cout << "Program selesai.\n";
    return 0;
}
