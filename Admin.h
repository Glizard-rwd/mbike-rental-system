// Admin.h
#ifndef MOTORBIKE_RENTAL_SYSTEM_ADMIN_H
#define MOTORBIKE_RENTAL_SYSTEM_ADMIN_H

#include "Person.h"
#include "MemberDB.h"
#include "MotorbikeDB.h"

class Admin: public Person {
public:
    void manageMember(MemberDB& memberDB);
    void manageMotorbike(MotorbikeDB& motorbikeDB);
    void setAdmin(const string& fName, const string& location, const string& phone, int idNum, const string& idType, const Account& a);

};

void Admin::setAdmin(const string& fName, const string& location, const string& phone, int idNum, const string& idType, const Account& a) {
    Person::setPerson(fName, location, phone, idNum, idType, a);
}



void Admin::manageMember(MemberDB& memberDb) {
    cout << memberDb;
    cout << "----------------------------------";
    cout << "1. Insert a member" << endl;
    cout << "2. Delete a member" << endl;
    cout << "3. Update a member" << endl;
    cout << "4. Search a member" << endl;

    int choice;
    switch(choice) {
        case 1: {
            cout << "Enter member info: " << endl;
            Member aMember;
            cin >> aMember;
            memberDb.insertMember(aMember);
            break;
        }

        case 2: {

        }
        case 3:
        case 4:
            cout << "Enter member ID: " << endl;
            int memID;
            cin >> memID;


        default:
    }
}

void Admin::manageMotorbike(Motorbike& mBike);







#endif //MOTORBIKE_RENTAL_SYSTEM_ADMIN_H

