//
// Created by Leti on 21.05.2022.
//

#include <cassert>
#include "EventTests.h"
#include "../../../Domain/Event/Event.h"

void testEvent(){
    User u1("Ana", 20, "ana11@gmail.com", "1234");
    User u2("Maria", 18, "mariapopescu@gmail.com", "1256");
    User u3("Ioana", 20, "ioana15@gmail.com", "145");
    User u4("Andrei", 16, "andreiiomescu@yahoo.com", "123");
    User u5("Teodor", 17, "teodorPopescu@gmail.com", "467");
    List<string>l;
    Event e(1, u1, "Posh Peony Event", "Monday 12/09/2022", l);
    Event e1(2, u2, "Event at the sea", "Friday",l);
    Event e2(3, u3, "Event ss", "asd",l);
    Event e3(4, u4, "Summer festival", "Saturday",l);
    Event e4(5, u5, "Winter festival", "12/12/2022",l);
    assert(e.getId() == 1);
    assert(e.getEventName() == "Posh Peony Event");
    assert(e.getDetails() == "Monday 12/09/2022");
    assert(e1.getId() == 2);
    assert(e1.getEventName() == "Event at the sea");
    assert(e1.getDetails() == "Friday");
    assert(e2.getId() == 3);
    assert(e2.getEventName() == "Event ss");
    assert(e2.getDetails() == "asd");
    assert(e3.getId() == 4);
    assert(e3.getEventName() == "Summer festival");
    assert(e3.getDetails() == "Saturday");
}