//
// Created by argshub on 9/6/2017.
//

#include <iostream>
#include <string>
#include "MultiMap.h"

int main() {
    try {
        MultiMap<std::string, int> multiMap;
        MultiMap<std::string, int>::Iterator iterator;

        multiMap.put("Shazzad Hossain", 1);
        multiMap.put("Ahsan Khan", 2);
        multiMap.put("Masum Billah", 3);
        multiMap.put("Rasel Ahmed", 4);
        multiMap.put("Krisna Ghosh", 5);
        multiMap.put("Shazzad Hossain", 6);
        multiMap.put("Ahsan Khan", 7);
        multiMap.put("Rasel Ahmed", 8);

        multiMap.removeAll("Shazzad Hossain");

        for (iterator = multiMap.begin(); iterator != multiMap.end(); ++iterator) {
            std::cout << "key: " << iterator.key() << " value : " << iterator.value() << '\n';
        }
    } catch (KeyNotExist keyNotExist) {
        std::cout << keyNotExist.getMessage();
    }
    return 0;
}