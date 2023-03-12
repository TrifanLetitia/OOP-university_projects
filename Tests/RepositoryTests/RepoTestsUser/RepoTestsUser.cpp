//
// Created by Leti on 11.05.2022.
//

#include <cassert>
#include "RepoTestsUser.h"
#include "../../../Repository/RepositoryFile.h"
#include "../../../Domain/User/User.h"
#include "../../../Repository/RepositoryFileCSV.h"

RepositoryFileCSV<User> users(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\RepoTestsUser.csv)");

void runAllRepoUserTests(){
    testAddUser();
    testDeleteUser();
    testGetAll();
    users.clearfile(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\RepoTestsUser.csv)");
}

void testAddUser(){

    User u1("Ana", 20, "ana11@gmail.com", "1234");
    User u2("Maria", 18, "mariapopescu@gmail.com", "23435");
    User u3("Ioana", 20, "ioana15@gmail.com", "43567");
    User u4("Andrei", 16, "andreiiomescu@yahoo.com", "ertyu");
    User u5("Teodor", 17, "teodorPopescu@gmail.com", "aertr4");
    users.add(u1);
    users.add(u2);
    users.add(u3);
    users.add(u4);
    users.add(u5);
    assert(users.getSize() == 5);
    assert(users.getAll()[0] == u1);
    assert(users.getAll()[1] == u2);
    assert(users.getAll()[2] == u3);
    assert(users.getAll()[3] == u4);
    assert(users.getAll()[4] == u5);
}

void testDeleteUser(){
    User u1("Ana", 20, "ana11@gmail.com", "1234");
    User u2("Maria", 18, "mariapopescu@gmail.com", "23435");
    User u3("Ioana", 20, "ioana15@gmail.com", "43567");
    User u4("Andrei", 16, "andreiiomescu@yahoo.com", "ertyu");
    User u5("Teodor", 17, "teodorPopescu@gmail.com", "aertr4");
    assert(users.getSize() == 5);
    users.deleteEl(u1);
    users.deleteEl(u2);
    users.deleteEl(u3);
    assert(users.getSize() == 2);
}

void testGetAll(){
    assert(users.getSize() == 2);
    User u4("Andrei", 16, "andreiiomescu@yahoo.com", "ertyu");
    User u5("Teodor", 17, "teodorPopescu@gmail.com", "aertr4");
    assert(users.getAll()[0] == u4);
    assert(users.getAll()[1] == u5);
}