#ifndef FUNCTION_LIMITS_H
#define FUNCTION_LIMITS_H

#include "test_functions.h"

typedef struct {
    Test_Functions function;
    Point x_limits;
    Point y_limits;
}Function_Properties;

const Function_Properties g_fproperties[] = {
    { ACKLEYS_FUNCTION, { -5, 5 }, { -5, 5 }},
    { BEALES_FUNCTION, { -4.5, 4.5 }, { -4.5, 4.5 }},
    { GOLDSTEIN_PRICE_FUNCTION, { -2, 2 }, { -2, 2 }},
    { BOOTHS_FUNCTION, { -10, 10 }, { -10, 10 }},
    { BUKIN_FUNCTION, { -15, -5 }, { -3, 3 }},
    { MATYAS_FUNCTION, { -10, 10 }, { -10, 10 }},
    { LEVI_FUNCTION, { -10, 10 }, { -10, 10 }},
    { THREE_HUMP_CAMEL, { -5, 5 }, { -5, 5 }},
    { EASOM_FUNCTION, { -100, 100 }, { -100, 100 }},
    { CROSS_IN_TRAY_FUNCTION, { -10, 10 }, { -10, 10 }},
    { EGGHOLDER_FUNCTION, { -512, 512 }, { -512, 512 }},
    { HOLDER_TABLE_FUNCTION, { -10, 10 }, { -10, 10 }},
    { MCCORMICK_FUNCTION, { -1.5, 4 }, { -3, 4 }},
    { SCHAFFER_FUNCTION_N2, { -100, 100 }, { -100, 100 }},
    { SCHAFFER_FUNCTION_N4, { -100, 100 }, { -100, 100 }},
    { SIMIONESCU_FUNCTION, { -1.25, 1.25 }, { -1.25, 1.25 }}
};

Function_Properties get_function_limits(int index){
    return g_fproperties[index];
}

#endif /* FUNCTION_LIMITS_H */