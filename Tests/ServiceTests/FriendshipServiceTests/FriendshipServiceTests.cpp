//
// Created by Leti on 21.05.2022.
//

#include <cassert>
#include "FriendshipServiceTests.h"
#include "../../../Domain/Friendship/Friendship.h"
#include "../../../Repository/RepositoryFileCSV.h"
#include "../../../Service/FriendshipService/FriendshipService.h"

RepositoryFileCSV<Friendship> friends2(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\FriendshipServiceTests.csv)");
RepositoryFileCSV<User> users3(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\UserServiceTests.csv)");
UserValidator vd2;
UserService serviceU(users3, vd2);
FriendshipValidator fv(serviceU);
FriendshipService frfriends(friends2);

void runAllFriendshipServiceTests(){
    User u1("Ana", 20, "ana11@gmail.com", "1234");
    User u2("Maria", 18, "mariapopescu@gmail.com", "23435");
    User u3("Ioana", 20, "ioana15@gmail.com", "43567");
    User u4("Andrei", 16, "andreiiomescu@yahoo.com", "ertyu");
    User u5("Teodor", 17, "teodorPopescu@gmail.com", "aertr4");
    serviceU.addUser(u1);
    serviceU.addUser(u2);
    serviceU.addUser(u3);
    serviceU.addUser(u4);
    serviceU.addUser(u5);
    testAddFriendshipS();
    testDeleteFriendshipS();
    friends2.clearfile(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\FriendshipServiceTests.csv)");
    users3.clearfile(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\UserServiceTests.csv)");
}

void testAddFriendshipS(){
    Friendship f("maria", "ana");
    Friendship f1("ana", "andreea");
    Friendship f2("andreea", "alex");
    Friendship f3("alex", "ana");
    Friendship f4("alex", "andrei");
    frfriends.addFriendship(f);
    frfriends.addFriendship(f1);
    frfriends.addFriendship(f2);
    frfriends.addFriendship(f3);
    frfriends.addFriendship(f4);
    assert(frfriends.getSize() == 10);
    assert(frfriends.getAll()[0] == f);
    assert(frfriends.getAll()[2] == f1);
    assert(frfriends.getAll()[4] == f2);
}

void testDeleteFriendshipS(){
    Friendship f("maria", "ana");
    Friendship f1("ana", "andreea");
    Friendship f2("andreea", "alex");
    Friendship f3("alex", "ana");
    Friendship f4("alex", "andrei");
    assert(frfriends.getSize() == 10);
    frfriends.deleteFriend(f);
    frfriends.deleteFriend(f1);
    frfriends.deleteFriend(f2);
    assert(frfriends.getSize() == 4);
    assert(frfriends.getAll()[0] == f3);
    assert(frfriends.getAll()[2] == f4);
}