#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>
#include "function_limits.h"

void print_pointv_details(Point_val *p_val){
    printf("x: %1.10Lf | y: %1.10Lf | func: %1.10Lf\n", p_val->point.x, p_val->point.y, p_val->val);
}

void print_population(Point_val *population){
    for (size_t i = 0; i < POPULATION_SIZE; i++){
        print_pointv_details(&population[i]);
    }
}

void print_test_functions(){
    printf("Please select the test function you want to run (type exit to exit) . . . \n");
    for (size_t i = 0; i < FUNCTION_COUNT; i++){
        printf("%d. %s\n", i+1, g_test_functions[i]);
    }
    printf("%d. ALL\n", FUNCTION_COUNT + 1);
}

void print_function_properties(Function_Properties fproperty){
    printf("Function: %s (Population: %d, Generation: %d)\n%1.2Lf <= x <= %1.2Lf\n%1.2Lf <= y <= %1.2Lf\n", 
    g_test_functions[(int)fproperty.function],
    POPULATION_SIZE,
    GENERATION, 
    fproperty.x_limits.x, 
    fproperty.x_limits.y, 
    fproperty.y_limits.x, 
    fproperty.y_limits.y);
}

#endif /* PRINT_H */