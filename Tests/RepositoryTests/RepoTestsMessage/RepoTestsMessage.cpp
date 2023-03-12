//
// Created by Leti on 21.05.2022.
//

#include <cassert>
#include "RepoTestsMessage.h"
#include "../../../Repository/RepositoryFile.h"
#include "../../../Domain/Message/Message.h"
#include "../../../Repository/RepositoryFileCSV.h"

RepositoryFileCSV<Message> messages1(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\RepoTestsMessage.csv)");

void runAllRepoMessageTests(){
    testAddMessage();
    testDeleteMessage();
    messages1.clearfile(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\RepoTestsMessage.csv)");
}

void testAddMessage(){
    User u1("Ana", 20, "ana11@gmail.com", "1234");
    User u2("Maria", 18, "mariapopescu@gmail.com", "1256");
    User u3("Ioana", 20, "ioana15@gmail.com", "145");
    User u4("Andrei", 16, "andreiiomescu@yahoo.com", "123");
    User u5("Teodor", 17, "teodorPopescu@gmail.com", "467");
    Message m1(1,"Salut!", u1.getEmail(), u2.getEmail());
    Message m2(2,"Buna ziua!", u2.getEmail(), u3.getEmail());
    Message m3(3,"Ce faci?", "ana5@gmail.com", "ioana21@gmail.com");
    Message m4(4,"Buna seara!", "ana2003@gmail.com", "andrei23@gmail.com");
    Message m5(5,"La revedere!","irina2004@gmail.com", "anamaria24@gmail.com");
    messages1.add(m1);
    messages1.add(m2);
    messages1.add(m3);
    messages1.add(m4);
    messages1.add(m5);
    assert(messages1.getSize() == 5);
    assert(messages1.getAll()[0] == m1);
    assert(messages1.getAll()[1] == m2);
    assert(messages1.getAll()[2] == m3);
    assert(messages1.getAll()[3] == m4);
    assert(messages1.getAll()[4] == m5);
}

void testDeleteMessage(){
    Message m3(3,"Ce faci?", "ana5@gmail.com", "ioana21@gmail.com");
    Message m4(4,"Buna seara!", "ana2003@gmail.com", "andrei23@gmail.com");
    Message m5(5,"La revedere!","irina2004@gmail.com", "anamaria24@gmail.com");
    messages1.deleteEl(m3);
    messages1.deleteEl(m4);
    messages1.deleteEl(m5);
    assert(messages1.getSize() == 2);
}