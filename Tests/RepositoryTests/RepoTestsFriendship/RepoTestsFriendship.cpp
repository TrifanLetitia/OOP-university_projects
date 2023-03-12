//
// Created by Leti on 21.05.2022.
//

#include <cassert>
#include "RepoTestsFriendship.h"
#include "../../../Domain/Friendship/Friendship.h"
#include "../../../Repository/RepositoryFileCSV.h"

RepositoryFileCSV<Friendship> friends(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie - Copie\RepoTestsFriends.csv)");

void runAllFriendshipRepoTests(){
    testAddFriendship();
    testDeleteFriendship();
    friends.clearfile(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\RepoTestsFriends.csv)");
}

void testAddFriendship(){
    Friendship f("maria", "ana");
    Friendship f1("ana", "andreea");
    Friendship f2("andreea", "alex");
    Friendship f3("alex", "ana");
    Friendship f4("alex", "andrei");
    friends.add(f);
    friends.add(f1);
    friends.add(f2);
    friends.add(f3);
    friends.add(f4);
    assert(friends.getSize() == 5);
    assert(friends.getAll()[0] == f);
    assert(friends.getAll()[1] == f1);;
    assert(friends.getAll()[2] == f2);
    assert(friends.getAll()[3] == f3);
    assert(friends.getAll()[4] == f4);
}

void testDeleteFriendship(){
    Friendship f("maria", "ana");
    Friendship f1("ana", "andreea");
    Friendship f2("andreea", "alex");
    Friendship f3("alex", "ana");
    Friendship f4("alex", "andrei");
    assert(friends.getSize() == 5);
    friends.deleteEl(f);
    friends.deleteEl(f1);
    friends.deleteEl(f2);
    assert(friends.getSize() == 2);
    assert(friends.getAll()[0] == f3);
    assert(friends.getAll()[1] == f4);
}