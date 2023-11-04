//
// Created by nguye on 21-Oct-23.
//

#ifndef MOTORBIKE_RENTAL_SYSTEM_MEMBERDB_H
#define MOTORBIKE_RENTAL_SYSTEM_MEMBERDB_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Member.h"
using namespace std;
class MemberDB {
    friend ostream& operator<<(ostream& os, const MemberDB& memberDB); // display to console
    friend istream& operator>>(istream& is, MemberDB& memberDB); // get from console

public:
    MemberDB();
    ~MemberDB();

    void readMemberDB();
    void writeMemberDB();

    void insertMember(Member& member);
    void deleteMember(Member& member);
    void updateMember(Member& member);
    vector<Member *> searchMember(const string& input, bool& found);

    vector<Member *> getMemberList() const {
        return memberList;
    }

    void setMemberList(const vector<Member *> &ml) {
        MemberDB::memberList = ml;
    }


private:
    fstream db;
    string fileName;
    vector<Member *> memberList;
};

MemberDB::MemberDB(): memberList() {};
MemberDB::~MemberDB() {
    for (auto & i : memberList) {
        delete i;
    }
}

ostream& operator<<(ostream& os, const MemberDB& memberDB) {
    for (auto &i: memberDB.memberList) {
        os << *i << endl;
    }
    return os;
}

istream& operator>>(istream& is, MemberDB& memberDB) {
    for (auto &i: memberDB.memberList) {
        is >> *i;
    }
    return is;
}

void MemberDB::readMemberDB() {
    db.open("MemberDB.txt", ios::in);
    if (!db) {
        cout << "Cannot open file!" << endl;
        return;
    }
    string memberLine; // each line is a member record
    while(getline(db, memberLine)) {
        stringstream ss(memberLine); // convert string to stream
        auto* member = new Member;
        if (!(ss >> *member)) {
            cout << "Cannot read member!" << endl;
            delete member;
            continue;
        }
        memberList.push_back(member);
    }
    db.close();
}

void MemberDB::writeMemberDB() {
    db.open("MemberDB.txt", ios::app); // append to file rather than rewrite to file
    if (!db) {
        cout << "Cannot open file!" << endl;
        return;
    }
    for (auto &i: memberList) {
        db << *i << endl; // write to file
    }
    db.close();
}


vector<Member *> searchMember(const string& input, bool& found) {
    // search member by id, name, and location
    // return a list of members that match the input
}

void MemberDB::insertMember(Member &member) {
    memberList.push_back(&member);
}

void MemberDB::deleteMember(Member &member) {
    for (auto it = memberList.begin(); it != memberList.end(); ++it) {
        if (*it == &member) {
            memberList.erase(it);
            break;
        }
    }
}

void MemberDB::updateMember(Member &member) {
    cout << "Enter field to update:" << endl;
    cout << "1. Name" << endl;
    cout << "2. Location" << endl;
    cout << "3. Phone" << endl;
    cout << "4. ID number" << endl;
    cout << "5. ID type" << endl;
    cout << "6. Account" << endl;
    cout << "7. Own Motorbike" << endl;

    int choice;
    cin >> choice;
    cin.ignore(); // Consume the newline character left in the stream

    switch (choice) {
        case 1: {
            cout << "Enter new name: ";
            string name;
            getline(cin, name);
            member.setFname(name);
            break;
        }
        case 2: {
            cout << "Enter new location: ";
            string location;
            getline(cin, location);
            member.setLocation(location);
            break;
        }
        case 3: {
            cout << "Enter new phone: ";
            string phone;
            getline(cin, phone);
            member.setPhone(phone);
            break;
        }
        case 4: {
            cout << "Enter new ID number: ";
            int idNum;
            cin >> idNum;
            member.setIdNum(idNum);
            break;
        }
        case 5: {
            cout << "Enter new ID type: ";
            string idType;
            cin.ignore(); // Consume the newline character left in the stream
            getline(cin, idType);
            member.setIdType(idType);
            break;
        }
        case 6: {
            cout << "Choose account field to update:" << endl;
            cout << "1. Username" << endl;
            cout << "2. Password" << endl;
            cout << "3. Role" << endl;

            int accChoice;
            cin >> accChoice;
            cin.ignore(); // Consume the newline character left in the stream
            switch (accChoice) {
                case 1: {
                    cout << "Enter new username: ";
                    string username;
                    getline(cin, username);
                    member.getAccount().setUsername(username);
                    break;
                }
                case 2: {
                    cout << "Enter new password: ";
                    string password;
                    getline(cin, password);
                    member.getAccount().setPassword(password);
                    break;
                }
                case 3: {
                    cout << "Enter new role: ";
                    string role;
                    getline(cin, role);
                    member.getAccount().setAccType(role);
                    break;
                }
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }
            break;
        }
        case 7: {
            cout << "Choose motorbike field to update:" << endl;
            cout << "1. Model" << endl;
            cout << "2. Description" << endl;
            cout << "3. Year made" << endl;
            cout << "4. Transmission mode" << endl;
            cout << "5. Engine size" << endl;
            cout << "6. Color" << endl;
            cout << "7. Price" << endl;
            cout << "8. Required score" << endl;
            cout << "9. Available status" << endl;
            cout << "10. Location" << endl;

            int mbChoice;
            cin >> mbChoice;
            cin.ignore(); // Consume the newline character left in the stream

            switch (mbChoice) {
                case 1: {
                    cout << "Enter new model: ";
                    string model;
                    getline(cin, model);
                    member.getOwnMbike().getMotorbikeDetail().setUmodel(model);
                    break;
                }

                case 2: {
                    cout << "Enter new description: ";
                    string description;
                    getline(cin, description);
                    member.getOwnMbike().getMotorbikeDetail().setDescription(description);
                    break;
                }

                case 3: {
                    cout << "Enter new year made: ";
                    int year;
                    cin >> year;
                    member.getOwnMbike().getMotorbikeDetail().setYearMade(year);
                    break;
                }

                case 4: {
                    cout << "Enter new transmission mode: ";
                    string transmissionMode;
                    getline(cin, transmissionMode);
                    member.getOwnMbike().getMotorbikeDetail().setTransmissionMode(transmissionMode);
                    break;
                }
                case 5: {
                    cout << "Enter new engine size: ";
                    int engineSize;
                    cin >> engineSize;
                    member.getOwnMbike().getMotorbikeDetail().setEngineSize(engineSize);
                    break; }

                case 6: {
                    cout << "Enter new color: ";
                    string color;
                    getline(cin, color);
                    member.getOwnMbike().getMotorbikeDetail().setColor(color);
                }

                case 7: {
                    cout << "Enter new price: ";
                    double price;
                    cin >> price;
                    member.getOwnMbike().setPrice(price);
                    break;
                }

                case 8: {
                    cout << "Enter new required score: ";
                    float requiredScore;
                    cin >> requiredScore;
                    member.getOwnMbike().setRequiredScore(requiredScore);
                    break;
                }

                case 9: {
                    cout << "Enter new available status: ";
                    bool availableStatus;
                    cin >> availableStatus;
                    member.getOwnMbike().setAvailableStatus(availableStatus);
                    break;
                }

                case 10: {
                    cout << "Enter new location: ";
                    string location;
                    getline(cin, location);
                    member.getOwnMbike().setLocation(location);
                    break;
                }

                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }

        }

        default:
            cout << "Invalid choice!" << endl;
            break;

    }
    writeMemberDB(); // update to file
}




#endif //MOTORBIKE_RENTAL_SYSTEM_MEMBERDB_H
