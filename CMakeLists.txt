cmake_minimum_required(VERSION 3.25)
project(motorbike_rental_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(motorbike_rental_system main.cpp Member.h Reservation.h Rating.h Person.h Account.h Motorbike.h MotorbikeDetail.h
        MemberDB.h
        MotorbikeDB.h
        Application.h
        Admin.h)
