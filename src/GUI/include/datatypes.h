#ifndef DATATYPES_H
#define DATATYPES_H
enum Input {
    IN_UP = 0,
    IN_DOWN = 1,
    IN_RIGHT = 2,
    IN_LEFT = 3,
    IN_NULL = -1
};
enum State {
    ST_LG_CARD = 1,
    ST_SM_LFT = 0,
    ST_SM_MID = 2,
    ST_SM_RGT = 3
};
#endif // DATATYPES_H
