//
// Created by Leti on 21.05.2022.
//

#include <cassert>
#include "UserServiceTests.h"
#include "../../../Service/UserService/UserService.h"

RepositoryFileCSV<User> users1(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\UserServiceTests.csv)");
UserValidator vd;
UserService service(users1, vd);

void runAllUserServiceTests(){
    testAddUserS();
    testDeleteUserS();
    users1.clearfile(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\UserServiceTests.csv)");
}

void testAddUserS(){
    User u1("Ana", 20, "ana11@gmail.com", "1234");
    User u2("Maria", 18, "mariapopescu@gmail.com", "23435");
    User u3("Ioana", 20, "ioana15@gmail.com", "43567");
    User u4("Andrei", 16, "andreiiomescu@yahoo.com", "ertyu");
    User u5("Teodor", 17, "teodorPopescu@gmail.com", "aertr4");
    service.addUser(u1);
    service.addUser(u2);
    service.addUser(u3);
    service.addUser(u4);
    service.addUser(u5);
    assert(service.getSize() == 5);
    assert(service.getAll()[0] == u1);
    assert(service.getAll()[1] == u2);
    assert(service.getAll()[2] == u3);
    assert(service.getAll()[3] == u4);
    assert(service.getAll()[4] == u5);
}

void testDeleteUserS(){
    User u1("Ana", 20, "ana11@gmail.com", "1234");
    User u2("Maria", 18, "mariapopescu@gmail.com", "23435");
    User u3("Ioana", 20, "ioana15@gmail.com", "43567");
    User u4("Andrei", 16, "andreiiomescu@yahoo.com", "ertyu");
    User u5("Teodor", 17, "teodorPopescu@gmail.com", "aertr4");
    assert(service.getSize() == 5);
    service.deleteUser(u1);
    service.deleteUser(u2);
    service.deleteUser(u3);
    assert(service.getSize() == 2);
    assert(service.getAll()[0] == u4);
    assert(service.getAll()[1] == u5);
    service.addUser(u1);
    service.addUser(u2);
    service.addUser(u3);
}