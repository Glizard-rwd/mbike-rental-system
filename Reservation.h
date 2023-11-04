#ifndef MOTORBIKE_RENTAL_SYSTEM_RESERVATION_H
#define MOTORBIKE_RENTAL_SYSTEM_RESERVATION_H

#include <iostream>
#include <ctime>
#include <utility>
#include "Motorbike.h"

class Reservation {
    friend ostream& operator<<(ostream& os, const Reservation& rev); // display on console
    friend istream& operator>>(istream& is, Reservation& rev);
public:
    Reservation();
    ~Reservation();
    bool operator==(const Reservation& rev) const;
    [[nodiscard]] int getReservationID() const;
    [[nodiscard]] const tm& getStartDate() const;
    [[nodiscard]] const tm& getEndDate() const;
    [[nodiscard]] const string& getRevStatus() const;
    [[nodiscard]] const Motorbike& getMotorbike() const;

    void setReservationID(int reservationID);
    void setStartDate(const tm& startDate);
    void setEndDate(const tm& endDate);
    void setRevStatus(const std::string& revStatus);
    void setMotorbike(const Motorbike& motorbike);

    void setRev(int reservationID, const tm& startDate, const tm& endDate, const string& revStatus, const Motorbike& motorbike);
    void displayRev();
    double calculatePrice();

private:
    int reservationID;
    tm startDate{};
    tm endDate{};
    std::string revStatus;
    Motorbike motorbike;
};

#endif // MOTORBIKE_RENTAL_SYSTEM_RESERVATION_H

Reservation::Reservation(): reservationID(0), startDate(), endDate(), revStatus(), motorbike() {};
Reservation::~Reservation() { delete this; }

void Reservation::setRev(int reservationID, const tm& startDate, const tm& endDate, const string& revStatus, const Motorbike& motorbike) {
    this->reservationID = reservationID;
    this->startDate = startDate;
    this->endDate = endDate;
    this->revStatus = revStatus;
    this->motorbike = motorbike;
}

int Reservation::getReservationID() const {
    return reservationID;
}

const tm& Reservation::getStartDate() const {
    return startDate;
}

const tm& Reservation::getEndDate() const {
    return endDate;
}

const std::string& Reservation::getRevStatus() const {
    return revStatus;
}

const Motorbike& Reservation::getMotorbike() const {
    return motorbike;
}

void Reservation::setReservationID(int reservationID) {
    this->reservationID = reservationID;
}

void Reservation::setStartDate(const tm& startDate) {
    this->startDate = startDate;
}

void Reservation::setEndDate(const tm& endDate) {
    this->endDate = endDate;
}

void Reservation::setRevStatus(const string& revStatus) {
    this->revStatus = revStatus;
}

void Reservation::setMotorbike(const Motorbike& motorbike) {
    this->motorbike = motorbike;
}

void Reservation::displayRev() {
    cout << "Reservation ID: " << this->reservationID << endl;
    cout << "Start date: " << this->startDate.tm_mday << "/" << this->startDate.tm_mon << "/" << this->startDate.tm_year << endl;
    cout << "End date: " << this->endDate.tm_mday << "/" << this->endDate.tm_mon << "/" << this->endDate.tm_year << endl;
    cout << "Reservation status: " << this->revStatus << endl;
    cout << "Motorbike id: " << this->motorbike.getMbikeID() << endl;
}


double Reservation::calculatePrice() {
    int numberOfDays = this->endDate.tm_mday - this->startDate.tm_mday;
    return numberOfDays * this->motorbike.getPrice();
}

ostream& operator<<(ostream& os, const Reservation& rev) {
    os << "Reservation ID: " << rev.reservationID << endl;
    os << "Start date: " << rev.startDate.tm_mday << "/" << rev.startDate.tm_mon << "/" << rev.startDate.tm_year << endl;
    os << "End date: " << rev.endDate.tm_mday << "/" << rev.endDate.tm_mon << "/" << rev.endDate.tm_year << endl;
    os << "Reservation status: " << rev.revStatus << endl;
    os << "Motorbike id: " << rev.motorbike.getMbikeID() << endl;
    return os;
}

istream& operator>>(istream& is, Reservation& rev) {
    is >> rev.reservationID;
    is >> rev.startDate.tm_mday;
    is >> rev.startDate.tm_mon;
    is >> rev.startDate.tm_year;
    is >> rev.endDate.tm_mday;
    is >> rev.endDate.tm_mon;
    is >> rev.endDate.tm_year;
    is >> rev.revStatus;
    is >> rev.motorbike;
    return is;
}

bool Reservation::operator==(const Reservation &rev) const {
    return (reservationID == rev.reservationID &&
    startDate.tm_mday == rev.startDate.tm_mday &&
    startDate.tm_mon == rev.startDate.tm_mon &&
    startDate.tm_year == rev.startDate.tm_year &&
    endDate.tm_mday == rev.endDate.tm_mday &&
    endDate.tm_mon == rev.endDate.tm_mon &&
    endDate.tm_year == rev.endDate.tm_year &&
    revStatus == rev.revStatus &&
    motorbike == rev.motorbike);
}

