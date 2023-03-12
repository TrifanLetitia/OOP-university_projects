//
// Created by Leti on 21.05.2022.
//

#include <cassert>
#include "FriendshipTests.h"
#include "../../../Domain/Friendship/Friendship.h"

void testFriendship(){
    Friendship f("maria", "ana");
    Friendship f1("ana", "maria");
    Friendship f2("andreea", "alex");
    Friendship f3("alex", "andreea");
    Friendship f4("alex", "andrei");
    Friendship f6 = f;
    f2.setEmail1("andrei");
    assert(f6 == f);
    assert(f2.getEmail1() == "andrei");
    assert(f1.getEmail1() == "ana");
    assert(f1.getEmail2() == "maria");
}