//
// Created by nguye on 10/7/2023.
//

#ifndef MOTORBIKE_RENTAL_SYSTEM_MEMBER_H
#define MOTORBIKE_RENTAL_SYSTEM_MEMBER_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <memory>
#include "Person.h"
#include "Motorbike.h"
#include "Reservation.h"
#include "Rating.h"
using namespace std;
class Reservation;
class Rating;


class Member: public Person {
    friend ostream& operator<<(ostream& os, Member& mem); // display to console
    friend istream& operator>>(istream& is, Member& mem); // stream to console
public:
    // default credit of member is 20
    Member();
    ~Member() override;

    bool operator==(const Member& mem) const;

    // Member will inherit all attributes from member and person
    // other method
    int getMemberID();
    void setMemberID(int memberID);
    int getCredit() const;
    void setCredit(int score);
    Motorbike getOwnMbike();
    void setOwnMbike(const Motorbike& mbike);
    vector<Reservation*> getReservations();
    void setReservations(vector<Reservation*> reservations);
    vector<Rating*> getRatings() const;
    void setRatings(vector<Rating*> ratings);

    // other method of member
    void setMember(const string& fName, const string& location, const string& phone, int idNum, const string& idType, const Account& account, int credit);
    void requestM(const Motorbike& motorbike);
    void acceptM(const Reservation& rev);
    void returnM(const Reservation& rev);
    void payR(const Reservation& rev);
    void rate(const Member& mem);
    void rate(const Motorbike& mt);
    void topUpCredit(int credit);
    void minusCredit(int credit);



private:
    int memberID;
    int credit;
    Motorbike ownMbike; // a member has a motorbike to exchange
    vector<Reservation*> reservations; // reservation history of a member
    vector<Rating*> ratings; // rating and score has been given by another member

};
#endif //MOTORBIKE_RENTAL_SYSTEM_MEMBER_H

Member::Member(): Person(), memberID(0), credit(20), ownMbike(), reservations(), ratings() {};
Member::~Member() {
    delete this;
}

void Member::setMember(const string& fName, const string& location, const string& phone, int idNum, const string& idType, const Account& account, int credit) {
    Person::setPerson(fName, location, phone, idNum, idType, account);
    this->credit = credit;
}
int Member::getCredit() const {
    return this->credit;
}

void Member::setCredit(int credit) {
    this->credit = credit;
}

Motorbike Member::getOwnMbike() {
    return this->ownMbike;
}

void Member::setOwnMbike(const Motorbike& mbike) {
    this->ownMbike = mbike;
}

vector<Reservation*> Member::getReservations() {
    return this->reservations;
}

void Member::setReservations(vector<Reservation*> reservations) {
    this->reservations = std::move(reservations);
}

vector<Rating*> Member::getRatings() const {
    return this->ratings;
}

void Member::setRatings(vector<Rating *> ratings) {
    this->ratings = std::move(ratings);
}





void Member::requestM(const Motorbike& motorbike) {
    // does the motorbike is available?
    // does the member has enough credit?
    // if yes, then rent the motorbike
    // else, display error message

    // if the member has enough credit and the motorbike is available
    // then create a reservation
    // and wait for the owner to approve
    // then the renter can rent the motorbike
    if (!motorbike.getAvailableStatus()) {
        cout << "This motorbike is currently unavailable" << endl;
        return;
    }

    if (this->credit < motorbike.getPrice()) {
        cout << "You don't have enough credit to rent this motorbike" << endl;
        return;
    }

    Reservation* rev;
    int sD, sM, sY, fD, fM, fY;

    cout << "Enter reservation id: ";
    int id;
    cin >> id;

    cout << "Enter start date (day month year): ";
    cin >> sD >> sM >> sY;
    tm s{}, f{};
    s.tm_mday = sD;
    s.tm_mon = sM;
    s.tm_year = sM;

    cout << "Enter end date (day month year): ";
    cin >> fD >> fM >> fY;
    f.tm_mday = fD;
    f.tm_mon = fM;
    f.tm_year = fM;

    rev->setRev(id, s, f, "pending", motorbike);
    motorbike.getRequests().push_back(rev); // add the request to the request list of the motorbike

}

void Member::acceptM(const Reservation& rev) {
    // the onwer check request list of his/her motorbike
    // if the request is in the list, then accept the request
    // else, display error message
    // if the request is accepted, then the motorbike is unavailable
    // and the renter can rent the motorbike
    // else, display error message
    // if the request is accepted, then the renter will pay the price of the motorbike
    // and the owner will receive the money
    // else, display error message

    cout << "Motorbike request list: " << endl;
    for (auto &r: this->ownMbike.getRequests()) {
        r->displayRev();
    }

    cout << "Enter the reservation id you want to accept: " << endl;
    int revID;
    cin >> revID;
    for (auto &r: this->ownMbike.getRequests()) {
        if (r->getReservationID() == revID) {
            r->setRevStatus("accepted");
            r->getMotorbike().setAvailableStatus(false);
            this->reservations.push_back(r); // add the reservation to the reservation history of the renter
            this->ownMbike.getRequests().clear(); // remove all request of current motorbike
        }
    }


}

void Member::returnM(const Reservation &rev) {
    if (rev.getRevStatus() != "accepted") {
        cout << "You can't return this motorbike" << endl;
        return;
    }

    rev.setRevStatus("returned"); // the renter return the motorbike
    rev.getMotorbike().setAvailableStatus(true); // the motorbike is available again
    payR(rev); // the renter pay the price of the motorbike

    // the renter will pay the price of the motorbike

}

void Member::payR(const Reservation &rev) {
    // compare the renter credit and price of rev
    // if the renter has enough credit, then pay the price
    // else, display error message

    if (this->credit < rev.getMotorbike().getPrice()) {
        cout << "You don't have enough credit to pay for this motorbike" << endl;
        return;
    }

    this->credit -= rev.getMotorbike().getPrice(); // the renter pay the price
    rev.getMotorbike().getOwner().credit += rev.getMotorbike().getPrice(); // the owner receive the money
}

void Member::rate(const Member &mem) {
    cout << "Enter score: " << endl;
    double score;
    cin >> score;
    cout << "Enter comment: " << endl;
    string comment;
    cin >> comment;
    Rating* rating;
    rating->setRating(score, comment);
    mem.getRatings().push_back(rating);
}


void Member::rate(const Motorbike &mt) {
    cout << "Enter score: " << endl;
    double score;
    cin >> score;
    cout << "Enter comment: " << endl;
    string comment;
    cin >> comment;
    Rating* rating;
    rating->setRating(score, comment);
    mt.getMBikeRating().push_back(rating);
}



void Member::topUpCredit(int cr) {
    this->credit += cr;

}

void Member::minusCredit(int cr) {
    this->credit -= cr;
}



ostream &operator<<(ostream &os, Member &mem) {
    os << static_cast<Person&>(mem);
    os << "Member ID: " << mem.getMemberID() << endl;
    os << "Credit: " << mem.getCredit() << endl;
    os << "Own motorbike: " << endl;
    os << mem.getOwnMbike() << endl;
    os << "Reservation history: " << endl;
    for (auto &r: mem.getReservations()) {
        os << r << endl;
    }
    os << "Rating: " << endl;
    for (auto &r: mem.getRatings()) {
        os << r << endl;
    }

    return os;
}

istream &operator>>(istream &is, Member &mem) {
    is >> static_cast<Person&>(mem);
    is >> mem.memberID;
    is >> mem.credit;
    is >> mem.ownMbike;
    for (auto &r: mem.reservations) {
        is >> *r;
    }
    for (auto &r: mem.ratings) {
        is >> *r;
    }
    return is;
}


bool Member::operator==(const Member &mem) const {
    return (memberID == mem.memberID && credit == mem.credit && ownMbike == mem.ownMbike);
}










