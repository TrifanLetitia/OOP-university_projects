//
// Created by Leti on 08.05.2022.
//
#include <cassert>
#include <iostream>
#include "MessageTests.h"
#include "../../../Domain/Message/Message.h"
#include "../../../TADList/List.h"


void testMessage(){
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
    List<Message> messages;
    messages.add(m1);
    messages.add(m2);
    messages.add(m3);
    messages.add(m4);
    messages.add(m5);
    assert(messages.Size() == 5);
    assert(messages[0] == m1);
    assert(messages[1] == m2);
    assert(messages[2] == m3);
    assert(messages[3] == m4);
    assert(messages[4] == m5);
}