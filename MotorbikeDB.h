#ifndef MOTORBIKE_RENTAL_SYSTEM_MOTORBIKEDB_H
#define MOTORBIKE_RENTAL_SYSTEM_MOTORBIKEDB_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Motorbike.h"
class Motorbike;
class MotorbikeDB {
public:
    MotorbikeDB();
    ~MotorbikeDB();
    void insertMotorbike(Motorbike& motorbike);
    void deleteMotorbike(Motorbike& motorbike);
    void updateMotorbike(Motorbike& motorbike);
    bool searchMotorbike(Motorbike& motorbike);
    void readMotorbikeDB();
    void writeMotorbikeDB();
    friend ostream& operator<<(ostream& os, const MotorbikeDB& motorbikeDB); // display to console
    friend istream& operator>>(istream& is, MotorbikeDB& motorbikeDB); // get from console
private:
    fstream db;
    string fileName;
    std::vector<Motorbike *> motorbikeList;
};

MotorbikeDB::MotorbikeDB(): motorbikeList() {};
MotorbikeDB::~MotorbikeDB() {
    for (auto & i : motorbikeList) {
        delete i;
    }
}

void MotorbikeDB::insertMotorbike(Motorbike& motorbike) {
    motorbikeList.push_back(&motorbike);
}

void MotorbikeDB::deleteMotorbike(Motorbike& motorbike) {
    for (auto i = motorbikeList.begin(); i != motorbikeList.end(); i++) {
        if (*i == &motorbike) {
            motorbikeList.erase(i);
            break;
        }
    }
}


void MotorbikeDB::updateMotorbike(Motorbike& motorbike) {
    if (!searchMotorbike(motorbike)) {
        cout << "Motorbike not found!" << endl;
        return;
    }

    cout << "Enter field to update: " << endl;
    cout << "1. Motorbike ID" << endl;
    cout << "2. Price" << endl;
    cout << "3. Required Score" << endl;
    cout << "4. Availability" << endl;
    cout << "5. Location" << endl;
    cout << "6. Motorbike Detail" << endl;

    int choice;
    cin >> choice;
    cin.ignore(); // Consume the newline character left in the stream

    switch(choice) {
        case 1: {
            cout << "Enter new motorbike ID: ";
            int motorbikeID;
            cin >> motorbikeID;
            motorbike.setMbikeID(motorbikeID);
            break;
        }

        case 2: {
            cout << "Enter new price: ";
            double price;
            cin >> price;
            motorbike.setPrice(price);
            break;
        }

        case 3: {
            cout << "Enter new required score: ";
            float requiredScore;
            cin >> requiredScore;
            motorbike.setRequiredScore(requiredScore);
            break;
        }

        case 4: {
            cout << "Enter new availability: ";
            bool isAvailable;
            cin >> isAvailable;
            motorbike.setAvailableStatus(isAvailable);
            break;
        }

        case 5: {
            cout << "Enter new location: ";
            string location;
            cin.ignore(); // Consume the newline character left in the stream
            getline(cin, location);
            motorbike.setLocation(location);
            break;
        }

        case 6: {
            cout << "Enter new motorbike detail: " << endl;
            MotorbikeDetail motorbikeDetail;
            cin >> motorbikeDetail;
            motorbike.setMotorbikeDetail(motorbikeDetail);
            break;
        }
    }
}

bool MotorbikeDB::searchMotorbike(Motorbike& motorbike) {
    for (auto &i: motorbikeList)
        if (*i == motorbike) {
            return true;
        }

    return false;
}

void MotorbikeDB::readMotorbikeDB() {
    db.open("motorbikeDB.txt", ios::in);
    if (!db) {
        cout << "Error opening file!" << endl;
        return;
    }

    string motorbikeLine;
    while(getline(db, motorbikeLine)) {
        stringstream ss(motorbikeLine);
        auto *motorbike = new Motorbike;
        if (!(ss >> *motorbike)) {
            cout << "Cannot read motorbike!" << endl;
            delete motorbike;
            continue;
        }
        motorbikeList.push_back(motorbike);
    }
    db.close();
}

void MotorbikeDB::writeMotorbikeDB() {
    db.open("motorbikeDB.txt", ios::out);
    if (!db) {
        cout << "Cannot open file!" << endl;
        return;
    }
    for (auto &i: motorbikeList) {
        db << *i << endl; // write to file
    }
    db.close();
}

ostream &operator<<(ostream &os, const MotorbikeDB &motorbikeDB) {
    for (auto &i: motorbikeDB.motorbikeList) {
        os << *i << endl;
    }
    return os;
}

istream &operator>>(istream &is, MotorbikeDB &motorbikeDB) {
    for (auto &i: motorbikeDB.motorbikeList) {
        is >> *i;
    }
    return is;
}

#endif //MOTORBIKE_RENTAL_SYSTEM_MOTORBIKEDB_H
