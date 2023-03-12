//
// Created by Leti on 20.05.2022.
//


#include <cassert>
#include "UserTests.h"
#include "../../../Domain/User/User.h"
void UserTests(){
    User u1("Ana", 20, "ana11@gmail.com", "1234");
    User u2("Maria", 18, "mariapopescu@gmail.com", "1256");
    User u3("Ioana", 20, "ioana15@gmail.com", "145");
    User u4("Andrei", 16, "andreiiomescu@yahoo.com", "123");
    User u5("Teodor", 17, "teodorPopescu@gmail.com", "467");
    assert(u1.getName() == "Ana");
    assert(u1.getEmail() == "ana11@gmail.com");
    assert(u1.getPassword() == "1234");
    assert(u1.getAge() == 20);
    User u6 = u2;
    assert(u6.getAge() == 18);
    assert(u6.getName() == "Maria");
    assert(u6.getEmail() == "mariapopescu@gmail.com");
    assert(u6.getPassword() == "1256");
    assert(u2 == u6);
    assert(u3 > u4);
}