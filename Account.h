//
// Created by nguye on 10/7/2023.
//

#ifndef MOTORBIKE_RENTAL_SYSTEM_ACCOUNT_H
#define MOTORBIKE_RENTAL_SYSTEM_ACCOUNT_H
#include <iostream>
#include <utility>
using namespace std;
class Account {
    friend ostream& operator<<(ostream& os, const Account& acc); // write account info to file
    friend istream& operator>>(istream& is, Account& acc); // read account info from a file
public:
    Account();
    ~Account();
    bool operator==(const Account& acc) const;
    // other method
    [[nodiscard]] string getUsername() const;
    void setUsername(const string& username);
    string getPassword();
    void setPassword(const string& password);
    string getAccType();
    void setAccType(const string& accType);
    void setAccount(const string& username, const string& password, const string& accType);
    bool login(const string& username, const string& password);

private:
    string username;
    string password;
    string accType;

    // getter and setter

};
#endif //MOTORBIKE_RENTAL_SYSTEM_ACCOUNT_H

Account::Account(): username(), password(), accType() {};
Account::~Account() {
    delete this;
}

void Account::setAccount(const string& username, const string& password, const string& accType) {
    this->username = username;
    this->password = password;
    this->accType = accType;
}

string Account::getUsername() const {
    return this->username;
}

void Account::setUsername(const string& username) {
    this->username = username;
}

string Account::getPassword() {
    return this->password;
}

void Account::setPassword(const string& password) {
    this->password = password;
}

string Account::getAccType() {
    return this->accType;
}

void Account::setAccType(const string& accType) {
    this->accType = accType;
}

bool Account::login(const string& username, const string& password) {
    if (this->username == username && this->password == password) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const Account& acc) {
    os << acc.username << endl;
    os << acc.password << endl;
    os << acc.accType << endl;
    return os;
}

istream& operator>>(istream& is, Account& acc) {
    getline(is, acc.username);
    getline(is, acc.password);
    getline(is, acc.accType);
    return is;
}

bool Account::operator==(const Account &acc) const {
    return (this->username == acc.username && this->password == acc.password && this->accType == acc.accType);
}


