//
// Created by nguye on 22-Oct-23.
//

#ifndef MOTORBIKE_RENTAL_SYSTEM_APPLICATION_H
#define MOTORBIKE_RENTAL_SYSTEM_APPLICATION_H

#include "MemberDB.h"

class Application {
public:
    Application();
    ~Application();
    void run();
    void menu();
    void option();

private:
    MemberDB memberDB;
};

Application::Application() = default;

Application::~Application() = default;

void Application::run() {
    menu();
}

void Application::menu() {
    cout << "MOTORBIKE RENTAL SYSTEM" << endl;
    cout << "Name: Glizard" << endl;
    cout << "Date: 22-Oct-23" << endl;

}


void Application::option() {
    cout << "Use the app as 1.Guest 2.Member 3.Admin: " << endl;
    int choice;
    cin >> choice;
//    switch (choice) {
//        // choice should replace by enum
//        case 1: {
//            guestOption();
//            break;
//        }
//        case 2: {
//            memberOption();
//            break;
//        }
//        case 3: {
//            adminOption();
//            break;
//        }
//
//    }

}



#endif //MOTORBIKE_RENTAL_SYSTEM_APPLICATION_H
