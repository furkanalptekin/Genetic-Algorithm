#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

#include <math.h>
#include "main.h"

typedef enum {
    ACKLEYS_FUNCTION = 0,
    BEALES_FUNCTION,
    GOLDSTEIN_PRICE_FUNCTION,
    BOOTHS_FUNCTION,
    BUKIN_FUNCTION,
    MATYAS_FUNCTION,
    LEVI_FUNCTION,
    THREE_HUMP_CAMEL,
    EASOM_FUNCTION,
    CROSS_IN_TRAY_FUNCTION,
    EGGHOLDER_FUNCTION,
    HOLDER_TABLE_FUNCTION,
    MCCORMICK_FUNCTION,
    SCHAFFER_FUNCTION_N2,
    SCHAFFER_FUNCTION_N4,
    SIMIONESCU_FUNCTION,
    FUNCTION_COUNT
}Test_Functions;

const char* g_test_functions[] = {
    "ACKLEYS_FUNCTION",
    "BEALES_FUNCTION",
    "GOLDSTEIN_PRICE_FUNCTION",
    "BOOTHS_FUNCTION",
    "BUKIN_FUNCTION",
    "MATYAS_FUNCTION",
    "LEVI_FUNCTION",
    "THREE_HUMP_CAMEL",
    "EASOM_FUNCTION",
    "CROSS_IN_TRAY_FUNCTION",
    "EGGHOLDER_FUNCTION",
    "HOLDER_TABLE_FUNCTION",
    "MCCORMICK_FUNCTION",
    "SCHAFFER_FUNCTION_N2",
    "SCHAFFER_FUNCTION_N4",
    "SIMIONESCU_FUNCTION"
};

void ackleys_function(Point_val *p_val){
    p_val->val = -20 * exp(-0.2 * sqrt(0.5 * (pow(p_val->point.x, 2) + pow(p_val->point.y, 2)))) - exp(0.5 * (cos(2 * PI * p_val->point.x) + cos(2 * PI * p_val->point.y))) + E + 20;
}

void beales_function(Point_val *p_val){
    p_val->val = pow(1.5 - p_val->point.x + p_val->point.x * p_val->point.y, 2) + pow(2.25 - p_val->point.x + p_val->point.x * pow(p_val->point.y, 2), 2) + pow(2.625 - p_val->point.x + p_val->point.x * pow(p_val->point.y, 3), 2);
}

void goldstein_price_function(Point_val *p_val){
    p_val->val = (1 + pow(p_val->point.x + p_val->point.y + 1, 2) * (19 - 14 * p_val->point.x + 3 * pow(p_val->point.x, 2) - 14 * p_val->point.y + 6 * p_val->point.x * p_val->point.y + 3 * pow(p_val->point.y, 2))) * (30 + pow(2 * p_val->point.x - 3 * p_val->point.y, 2) * (18 - 32 * p_val->point.x + 12 * pow(p_val->point.x, 2) + 48 * p_val->point.y - 36 * p_val->point.x * p_val->point.y + 27 * pow(p_val->point.y, 2)));
}

void booths_function(Point_val *p_val){
    p_val->val = pow(p_val->point.x + 2 * p_val->point.y - 7, 2) + pow(2 * p_val->point.x + p_val->point.y - 5, 2);
}

void bukin_function(Point_val *p_val){
    p_val->val = 100 * sqrt(fabs(p_val->point.y - 0.01 * pow(p_val->point.x, 2))) + 0.01 * fabs(p_val->point.x + 10);
}

void matyas_function(Point_val *p_val){
    p_val->val = 0.26 * (pow(p_val->point.x, 2) + pow(p_val->point.y, 2)) - 0.48 * p_val->point.x * p_val->point.y;
}

void levi_function(Point_val *p_val){
    p_val->val = pow(sin(3 * PI * p_val->point.x), 2) + pow(p_val->point.x - 1, 2) * (1 + pow(sin(3 * PI * p_val->point.y), 2)) + pow(p_val->point.y - 1, 2) * (1 + pow(sin(2 * PI * p_val->point.y), 2));
}

void three_hump_camel(Point_val *p_val){
    p_val->val = 2 * pow(p_val->point.x, 2) - 1.05 * pow(p_val->point.x, 4) + pow(p_val->point.x, 6) / 6 + p_val->point.x * p_val->point.y + pow(p_val->point.y, 2);
}

void easom_function(Point_val *p_val){
    p_val->val = -1 * cos(p_val->point.x) * cos(p_val->point.y) * exp(-(pow(p_val->point.x - PI, 2) + pow(p_val->point.y - PI, 2)));
}

void cross_in_tray_function(Point_val *p_val){
    p_val->val = -0.0001 * pow(fabs(sin(p_val->point.x) * sin(p_val->point.y) * exp(fabs(100 - sqrt(pow(p_val->point.x, 2) + pow(p_val->point.y, 2)) / PI))) + 1, 0.1);
}

void eggholder_function(Point_val *p_val){
    p_val->val = -1 * (p_val->point.y + 47) * sin(sqrt(fabs(p_val->point.x / 2 + (p_val->point.y + 47)))) - p_val->point.x * sin(sqrt(fabs(p_val->point.x - (p_val->point.y + 47))));
}

void holder_table_function(Point_val *p_val){
    p_val->val = -1 * fabs(sin(p_val->point.x) * cos(p_val->point.y) * exp(fabs(1 - sqrt(pow(p_val->point.x, 2) + pow(p_val->point.y, 2)) / PI)));
}

void mccormick_function(Point_val *p_val){
    p_val->val = sin(p_val->point.x + p_val->point.y) + pow(p_val->point.x - p_val->point.y, 2) - 1.5 * p_val->point.x + 2.5 * p_val->point.y + 1;
}

void schaffer_function_n2(Point_val *p_val){
    p_val->val = 0.5 + (pow(sin(pow(p_val->point.x, 2) - pow(p_val->point.y, 2)), 2) - 0.5) / pow(1 + 0.001 * (pow(p_val->point.x, 2) + pow(p_val->point.y, 2)), 2);
}

void schaffer_function_n4(Point_val *p_val){
    p_val->val = 0.5 + (pow(cos(sin(fabs(pow(p_val->point.x, 2) - pow(p_val->point.y, 2)))), 2) - 0.5) / pow(1 + 0.001 * (pow(p_val->point.x, 2) + pow(p_val->point.y, 2)), 2);
}

void simionescu_function(Point_val *p_val){
    double rT = 1.0, rS = 0.2, n = 8.0;
    if (pow(p_val->point.x, 2) + pow(p_val->point.y, 2) <= pow(rT + rS * cos(n * atan(p_val->point.x / p_val->point.y)), 2.0))
        p_val->val = 0.1 * p_val->point.x * p_val->point.y;
    else
        p_val->val = SHRT_MAX * 1.0;
}

void (*calculate_test_function[]) (Point_val *p_val) = {
    &ackleys_function,
    &beales_function,
    &goldstein_price_function,
    &booths_function,
    &bukin_function,
    &matyas_function,
    &levi_function,
    &three_hump_camel,
    &easom_function,
    &cross_in_tray_function,
    &eggholder_function,
    &holder_table_function,
    &mccormick_function,
    &schaffer_function_n2,
    &schaffer_function_n4,
    &simionescu_function
};

#endif /* TEST_FUNCTIONS_H */