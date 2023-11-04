//
// Created by nguye on 10/7/2023.
//

#ifndef MOTORBIKE_RENTAL_SYSTEM_PERSON_H
#define MOTORBIKE_RENTAL_SYSTEM_PERSON_H
#include <iostream>
#include "Account.h"
using namespace std;
class Person {
    friend ostream& operator<<(ostream& os, const Person& person); // display to console
    friend istream& operator>>(istream& is, Person& person); // get from console
public:
    Person();
    virtual ~Person();
    bool operator==(const Person& p) const;


    // other method

    string getFname();
    string getLocation();
    string getPhone();
    int getIdNum() const;
    string getIdType();
    Account getAccount();
    void setFname(const string& fName);
    void setLocation(const string& location);
    void setPhone(const string& phone);
    void setIdNum(int idNum);
    void setIdType(const string& idType);
    void setAccount(const Account& account);

    void setPerson(const string& fname, const string& location, const string& phone, int idNum, const string& idType, const Account& a);

private:
    string fName;
    string location;
    string phone;
    int idNum;
    string idType;
    Account account;
};
#endif //MOTORBIKE_RENTAL_SYSTEM_PERSON_H

Person::Person():fName(), location(), phone(), idNum(0), idType() , account() {};
Person::~Person() {
    delete this;
}



string Person::getFname() {
    return this->fName;
}

string Person::getLocation() {
    return this->location;
}

string Person::getPhone() {
    return this->phone;
}

int Person::getIdNum() const {
    return this->idNum;
}

string Person::getIdType() {
    return this->idType;
}

Account Person::getAccount() {
    return this->account;
}

void Person::setFname(const string& fName) {
    this->fName = fName;
}

void Person::setLocation(const string& location) {
    this->location = location;
}

void Person::setPhone(const string& phone) {
    this->phone = phone;
}

void Person::setIdNum(int idNum) {
    this->idNum = idNum;
}

void Person::setIdType(const string& idType) {
    this->idType = idType;
}

void Person::setAccount(const Account& account) {
    this->account = account;
}

void Person::setPerson(const string& fname, const string& location, const string& phone, int idNum, const string& idType, const Account& a) {
    this->fName = fname;
    this->location = location;
    this->phone = phone;
    this->idNum = idNum;
    this->idType = idType;
    this->account = a;
}

ostream &operator<<(ostream &os, const Person &person) {
    cout << "Name: " << person.fName << endl;
    cout << "Location: " << person.location << endl;
    cout << "Phone: " << person.phone << endl;
    cout << "ID Number: " << person.idNum << endl;
    cout << "ID Type: " << person.idType << endl;
    cout << "Account: " << person.account.getUsername() << endl;
    return os;
}

istream &operator>>(istream &is, Person &person) {
    is >> person.fName;
    is >> person.location;
    is >> person.phone;
    is >> person.idNum;
    is >> person.idType;
    is >> person.account;
    return is;
}

bool Person::operator==(const Person &p) const {
    return (fName == p.fName && location == p.location && phone == p.phone && idNum == p.idNum && idType == p.idType);
}



