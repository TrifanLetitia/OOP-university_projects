#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <sstream>
#include "../TADList/List.h"

using namespace std;

static List<string> split(const string &s, char delim) {
    List<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.add(item);
    }
    return result;
}

#endif