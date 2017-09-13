//
// Created by argshub on 9/5/2017.
//

#include <iostream>
#include <string>
#include "Map.h"

int main() {
    try {
        Map<std::string, int> map;
        Map<std::string, int>::Iterator iterator;

        map.put("Shazzad Hossain", 13066);
        map.put("Asik Hasan", 13044);
        map.put("Masum Billah", 13765);
        map.put("Asik Hasan", 13333);

        for (iterator = map.begin(); iterator != map.end(); ++iterator) {
            std::cout << "key: " << iterator.key() << " value: " << iterator.value() << '\n';
        }
        std::cout << map.getSize() << '\n';
        map.remove("Asik Hasan");
        std::cout << map.get("Shazzad Hossain");
    } catch (KeyNotExist keyNotExist) {
        std::cout << keyNotExist.getMessage();
    }
    return 0;
}