//
// Created by Leti on 22.05.2022.
//

#include <cassert>
#include "BSTTest.h"
#include "../../Domain/User/User.h"
#include "../../BinaryTree/ABC.h"

void testBST(){
    ABC<User> users;
    User u1("Ana", 20, "ana11@gmail.com", "1234");
    User u2("Maria", 18, "mariapopescu@gmail.com", "1256");
    User u3("Ioana", 20, "ioana15@gmail.com", "145");
    User u4("Andrei", 16, "andreiiomescu@yahoo.com", "123");
    User u5("Teodor", 17, "teodorPopescu@gmail.com", "467");
    users.add(u1);
    users.add(u2);
    users.add(u3);
    users.add(u4);
    users.add(u5);
    assert(users.Size() == 5);
    assert(users.search(u1) == true);
    users.removeElem(u1);
    assert(users.Size() == 4);
}