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
            // delete a member
            cout << "Enter member id to delete: " << endl;
            string id;
            getline(cin, id);
            bool isFound = false;
            vector<Member *> results = memberDb.searchMember(id, isFound);
            if (isFound) {
                Member* memberToDelete = results[0]; // id is unique so there is only one result
                memberDb.deleteMember(*memberToDelete);
                cout << "Member delete successfully!";
            } else {
                cout << "Cannot find member with id " << id << " to delete!" << endl;
            }

            break;
        }
        case 3:
        {
            cout << "Enter member id to update: " << endl;
            string id;
            getline(cin, id);
            bool isFound = false;
            vector<Member *> results = memberDb.searchMember(id, isFound);
            if (isFound) {
                Member* memberToUpdate = results[0]; // id is unique so there is only one result
                memberDb.updateMember(*memberToUpdate);
                cout << "Member update successfully!";
            } else {
                cout << "Cannot find member with id " << id << " to update!" << endl;
            }
            // Update a member
            break;
        }

        case 4:
        {
            string input;
            bool isFound = false;
            cout << "Enter member info: " << endl;
            getline(cin, input);
            vector<Member *> foundMembers = memberDb.searchMember(input, isFound);
            if (isFound) {
                cout << "Found " << foundMembers.size() << " member(s): " << endl;
                for (auto &foundMember: foundMembers) {
                    cout << *foundMember << endl;
                }
            } else {
                cout << "No member found!" << endl;
            }
            break;
        }

        default: {
            cout << "Invalid choice!" << endl;
            break;
        }
    }
}

void Admin::manageMotorbike(MotorbikeDB &motorbikeDB) {

}








#endif //MOTORBIKE_RENTAL_SYSTEM_ADMIN_H

