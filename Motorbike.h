#ifndef MOTORBIKE_RENTAL_SYSTEM_MOTORBIKE_H
#define MOTORBIKE_RENTAL_SYSTEM_MOTORBIKE_H


#include <iostream>
#include <utility>
#include "MotorbikeDetail.h"
#include "Reservation.h"
#include "Rating.h"
#include <vector>
using namespace std;
class MotorbikeDetail;
class Rating;
class Motorbike {
    friend ostream& operator<<(ostream& os, const Motorbike& mbike); // display on console
    friend istream& operator>>(istream& is, Motorbike& mbike); // istream to console
private:
    int mbikeID;
    double price; // price per day
    float requiredScore;
    bool isAvailable; // available/unavailable for rent
    string location; // Hanoi or HCM
    MotorbikeDetail mBikeDetails;
    vector<Reservation*> requests;
    vector<Rating*> mBikeRating; // rating of the motorbike from other user.
public:
    Motorbike();
    ~Motorbike();
    bool operator==(const Motorbike& mbike) const;

    // other method
    [[nodiscard]] int getMbikeID() const;
    [[nodiscard]] double getPrice() const;
    float getRequiredScore();
    [[nodiscard]] bool getAvailableStatus() const;
    string getLocation();
    [[nodiscard]] MotorbikeDetail getMotorbikeDetail() const;
    [[nodiscard]] vector<Reservation*> getRequests() const;
    [[nodiscard]] vector<Rating*> getMBikeRating() const;
    void setMbikeID(int mbikeID);
    void setPrice(double price);
    void setRequiredScore(float requiredScore);
    void setAvailableStatus(bool isAvailable);
    void setLocation (const string& location);
    void setMotorbikeDetail(const MotorbikeDetail& mBikeDetails);
    void setRequests(const vector<Reservation *>& requests);
    void setMBikeRating(const vector<Rating *>& mBikeRating);

    void setMbike(int mbikeID, double price, float requiredScore, bool isAvailable, const string& location, const MotorbikeDetail& mBikeDetails
            , const vector<Reservation*>& requests, const vector<Rating*>& mBikeRating);

};

#endif //MOTORBIKE_RENTAL_SYSTEM_MOTORBIKE_H

Motorbike::Motorbike(): mbikeID(0), price(0), requiredScore(0), isAvailable(true), location(), mBikeDetails() {};
Motorbike::~Motorbike() {
    delete this;
}

void Motorbike::setMbike(int mbikeID, double price, float requiredScore, bool isAvailable, const string &location,
                         const MotorbikeDetail &mBikeDetails, const vector<Reservation *> &requests,
                         const vector<Rating *> &mBikeRating) {
    this->mbikeID = mbikeID;
    this->price = price;
    this->requiredScore = requiredScore;
    this->isAvailable = isAvailable;
    this->location = location;
    this->mBikeDetails = mBikeDetails;
    this->requests = requests;
    this->mBikeRating = mBikeRating;
}



int Motorbike::getMbikeID() const {
    return this->mbikeID;
}

double Motorbike::getPrice() const {
    return this->price;
}

float Motorbike::getRequiredScore() {
    return this->requiredScore;
}
bool Motorbike::getAvailableStatus() const {
    return this->isAvailable;
}

string Motorbike::getLocation() {
    return this->location;
}

void Motorbike::setMbikeID(int mbikeID) {
    this->mbikeID = mbikeID;
}

void Motorbike::setPrice(double price) {
    this->price = price;
}

void Motorbike::setRequiredScore(float requiredScore) {
    this->requiredScore = requiredScore;
}

void Motorbike::setAvailableStatus(bool isAvailable) {
    this->isAvailable = isAvailable;
}

void Motorbike::setLocation(const string& location) {
    this->location = location;
}

void Motorbike::setMotorbikeDetail(const MotorbikeDetail& mBikeDetails) {
    this->mBikeDetails = mBikeDetails;
}


MotorbikeDetail Motorbike::getMotorbikeDetail() const {
    return this->mBikeDetails;
}


void Motorbike::setRequests(const vector<Reservation *> &requests) {
    this->requests = requests;
}

void Motorbike::setMBikeRating(const vector<Rating *> &mBikeRating) {
    this->mBikeRating = mBikeRating;
}

vector<Reservation *> Motorbike::getRequests() const {
    return this->requests;
}

vector<Rating *> Motorbike::getMBikeRating() const {
    return this->mBikeRating;
}


ostream& operator<<(ostream& os, const Motorbike& mbike) {
    os << "Motorbike details: " << mbike.mBikeDetails << endl;
    os << "Motorbike ID: " << mbike.mbikeID << endl;
    os << "Price: " << mbike.price << endl;
    os << "Required score: " << mbike.requiredScore << endl;
    os << "Available status: " << mbike.isAvailable << endl;
    os << "Location: " << mbike.location << endl;
    os << "Requests: " << endl;
    for (auto& i : mbike.requests) {
        os << *i << endl;
    }
    os << "Rating: " << endl;
    for (auto& i : mbike.mBikeRating) {
        os << *i << endl;
    }

    return os;
}


istream& operator>>(istream& is, Motorbike& mbike) {
    is >> mbike.mBikeDetails;
    is >> mbike.mbikeID;
    is >> mbike.price;
    is >> mbike.requiredScore;
    is >> mbike.isAvailable;
    is >> mbike.location;
    for (auto &i : mbike.requests) {
        is >> *i;
    }
    for (auto &i : mbike.mBikeRating) {
        is >> *i;
    }
    return is;
}

bool Motorbike::operator==(const Motorbike &mbike) const {
    return (mbikeID == mbike.mbikeID && price == mbike.price && requiredScore == mbike.requiredScore && location == mbike.location);
}

