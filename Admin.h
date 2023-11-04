// Admin.h
#ifndef MOTORBIKE_RENTAL_SYSTEM_ADMIN_H
#define MOTORBIKE_RENTAL_SYSTEM_ADMIN_H

#include "Person.h"
#include "MemberDB.h"
#include "MotorbikeDB.h"

class Admin : public Person {
public:
    Admin();
    ~Admin();

    void manageMember(MemberDB& memberDB);
    void manageMotorbike(MotorbikeDB& motorbikeDB);
    void setAdmin(const string& fName, const string& location, const string& phone, int idNum, const string& idType, const Account& a);

};

#endif //MOTORBIKE_RENTAL_SYSTEM_ADMIN_H

