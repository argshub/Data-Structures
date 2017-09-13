//
// Created by argshub on 9/4/2017.
//

#ifndef CPP_BITFIELD_H
#define CPP_BITFIELD_H

struct status {
    unsigned connected: 1;
    unsigned checkNumber: 1;
    unsigned preparedForDialing: 1;
    unsigned engaged: 1;
    unsigned incorrectNumber: 1;
    unsigned connectionFault: 1;
    unsigned idle: 1;
    unsigned incomingCall: 1;
};

#endif //CPP_BITFIELD_H
