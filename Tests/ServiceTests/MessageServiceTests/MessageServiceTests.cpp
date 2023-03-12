//
// Created by Leti on 21.05.2022.
//

#include <cassert>
#include "MessageServiceTests.h"
#include "../../../Repository/RepositoryFileCSV.h"
#include "../../../Domain/Message/Message.h"
#include "../../../Service/MessageService/MessageService.h"

RepositoryFileCSV<Message> messages2(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\MessageServiceTests.csv)");
RepositoryFileCSV<User> users2(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\UserServiceTests.csv)");
UserValidator vd1;
UserService serviceUs(users2, vd1);
MessageValidator ms(serviceUs);
MessageService serviceM(messages2, ms);

void runAllMessageServiceTests(){
    User u1("Ana", 20, "ana11@gmail.com", "1234");
    User u2("Maria", 18, "mariapopescu@gmail.com", "1256");
    User u3("Ioana", 20, "ioana15@gmail.com", "145");
    User u4("Andrei", 16, "andreiiomescu@yahoo.com", "123");
    User u5("Teodor", 17, "teodorPopescu@gmail.com", "467");
    serviceUs.addUser(u1);
    serviceUs.addUser(u2);
    serviceUs.addUser(u3);
    serviceUs.addUser(u4);
    serviceUs.addUser(u5);
    testAddMessageS();
    testDeleteMessageS();
    messages2.clearfile(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\MessageServiceTests.csv)");
    users2.clearfile(R"(C:\Users\Leti\OneDrive\Desktop\Trifan_Ionica_Letitia_316\ProiectSDA - Copie - Copie\UserServiceTests.csv)");
}

void testAddMessageS(){
    User u1("Ana", 20, "ana11@gmail.com", "1234");
    User u2("Maria", 18, "mariapopescu@gmail.com", "1256");
    User u3("Ioana", 20, "ioana15@gmail.com", "145");
    User u4("Andrei", 16, "andreiiomescu@yahoo.com", "123");
    User u5("Teodor", 17, "teodorPopescu@gmail.com", "467");
    Message m1(1,"Salut!", "ana11@gmail.com", "mariapopescu@gmail.com");
    Message m2(2,"Buna ziua!", "mariapopescu@gmail.com", "ana11@gmail.com");
    Message m3(3,"Ce faci?", "ioana15@gmail.com", "andreiiomescu@yahoo.com");
    Message m4(4,"Buna seara!", "ioana15@gmail.com", "teodorPopescu@gmail.com");
    Message m5(5,"La revedere!","andreiiomescu@yahoo.com", "ioana15@gmail.com");
    serviceM.addMessage(m1);
    serviceM.addMessage(m2);
    serviceM.addMessage(m3);
    serviceM.addMessage(m4);
    serviceM.addMessage(m5);
    assert(serviceM.getSize() == 5);
}

void testDeleteMessageS(){
    User u1("Ana", 20, "ana11@gmail.com", "1234");
    User u2("Maria", 18, "mariapopescu@gmail.com", "1256");
    User u3("Ioana", 20, "ioana15@gmail.com", "145");
    User u4("Andrei", 16, "andreiiomescu@yahoo.com", "123");
    User u5("Teodor", 17, "teodorPopescu@gmail.com", "467");
    Message m1(1,"Salut!", "ana11@gmail.com", "mariapopescu@gmail.com");
    Message m2(2,"Buna ziua!", "mariapopescu@gmail.com", "ana11@gmail.com");
    Message m3(3,"Ce faci?", "ioana15@gmail.com", "andreiiomescu@yahoo.com");
    Message m4(4,"Buna seara!", "ioana15@gmail.com", "teodorPopescu@gmail.com");
    Message m5(5,"La revedere!","andreiiomescu@yahoo.com", "ioana15@gmail.com");
    assert(serviceM.getSize() == 5);
    serviceM.deleteMessage(m1);
    serviceM.deleteMessage(m2);
    assert(serviceM.getSize() == 3);
}