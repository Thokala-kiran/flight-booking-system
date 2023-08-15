#include <iostream>
#include <string>

using namespace std;

class Flight {
public:
    string name;
    int number;
    string origin;
    string destination;
    int seatcapacity;
    int availableseats;

    Flight(string x, int y, string z, string a, int b, int c) {
        name = x;
        number = y;
        origin = z;
        destination = a;
        seatcapacity = b;
        availableseats = c;
    }
};

class Node {
public:
    Flight flight;
    Node* nextflight;

    Node(Flight h) {
        flight = h;
        nextflight = nullptr;
    }
};

class LinkedList {
public:
    Node* headnode;

    LinkedList() : headnode(nullptr) {}

    void addflight(Flight newflight) {
        Node* newnode = new Node(newflight);
        if (!headnode) {
            headnode = newnode;
        } else {
            Node* curr = headnode;
            while (curr->nextflight) {
                curr = curr->nextflight;
            }
            curr->nextflight = newnode;
        }
    }

    void search(string attribute, string value) {
        Node* curr = headnode;
        while (curr) {
            if (attribute == "number" && to_string(curr->flight.number) == value) {
                displayFlight(curr->flight);
                return;
            } else if (attribute == "name" && curr->flight.name == value) {
                displayFlight(curr->flight);
                return;
            }
            curr = curr->nextflight;
        }
        cout << "No matching flights found." << endl;
    }

    void displayflights() {
        Node* currnode = headnode;
        while (currnode) {
            if (currnode->flight.availableseats > 0) {
                displayFlight(currnode->flight);
            }
            currnode = currnode->nextflight;
        }
    }

    void bookticket(int flightNumber) {
        Node* curr = headnode;
        while (curr) {
            if (curr->flight.number == flightNumber) {
                if (curr->flight.availableseats > 0) {
                    curr->flight.availableseats--;
                    cout << "Successfully registered your ticket." << endl;
                } else {
                    cout << "Flight is full." << endl;
                }
                return;
            }
            curr = curr->nextflight;
        }
        cout << "Flight not found." << endl;
    }

private:
    void displayFlight(const Flight& flight) {
        cout << "Name: " << flight.name << endl;
        cout << "Number: " << flight.number << endl;
        cout << "Origin: " << flight.origin << endl;
        cout << "Destination: " << flight.destination << endl;
        cout << "Seat Capacity: " << flight.seatcapacity << endl;
        cout << "Available Seats: " << flight.availableseats << endl << endl;
    }
};

int main() {
    LinkedList flightList;

    Flight flight1("Flight 1", 123, "Origin 1", "Destination 1", 150, 100);
    Flight flight2("Flight 2", 456, "Origin 2", "Destination 2", 200, 50);

    flightList.addflight(flight1);
    flightList.addflight(flight2);

    string searchAttribute = "number";
    string searchValue = "123";
    flightList.search(searchAttribute, searchValue);

    // Display available flights
    flightList.displayflights();

    // Book a ticket
    int desiredFlightNumber = 123;
    flightList.bookticket(desiredFlightNumber);

    // Clean up memory (delete nodes and flights)
    // ...

    return 0;
}
