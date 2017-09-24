//
// Created by argshub on 9/24/2017.
//

#include <iostream>
#include <string>
#include "ParallelArray.h"

int main() {
    try {

        ParallelArray<int, std::string, std::string> parallelArray;
        parallelArray.insert(110, "Shazzad Hossain", "Joypurhat");
        parallelArray.insert(111, "Masum Billah", "Dinajpur");
        parallelArray.insert(112, "Asik Hasan", "Thakurgaon");
        parallelArray.insert(113, "Ahsan Khan", "Dinajpur");
        parallelArray.insert(114, "Krisna Ghosh", "Madaripur");
        parallelArray.insert(115, "Mintu Plabon", "Pabna");
        parallelArray.insert(116, "Rasel Ahmed", "Sherpur");
        parallelArray.insert(117, "Sharwar Ahmed", "Chapainawabgonj");

        parallelArray.echo();

    } catch (ArrayOverflow arrayOverflow) {
        std::cout << arrayOverflow.why() << " capacity: " << arrayOverflow.getCapacity();
    }
    return 0;
}