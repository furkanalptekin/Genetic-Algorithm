#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include <stdlib.h>
#include "print.h"

void create_point_val(Point_val *func, Function_Properties fproperties){
    func->point.x = get_random(fproperties.x_limits.x, fproperties.x_limits.y);
    func->point.y = get_random(fproperties.y_limits.x, fproperties.y_limits.y);
    calculate_test_function[(int)fproperties.function](func);
}

void create_population(Point_val *population, Function_Properties fproperties){
    for (size_t i = 0; i < POPULATION_SIZE; i++){
        create_point_val(&population[i], fproperties);
    }
}

int point_val_cmp(const void *p1, const void *p2){
    Point_val point1 = *(const Point_val*)p1;
    Point_val point2 = *(const Point_val*)p2;

    if (point1.val < point2.val)
        return -1;

    if (point1.val > point2.val)
        return 1;

    return 0;
}

Point_val* selection(Point_val *population){
    qsort(population, POPULATION_SIZE, sizeof(Point_val), point_val_cmp);
    Point_val *selection = (Point_val*) controlled_malloc(POPULATION_SIZE / 2 * sizeof(Point_val));
    
    for (size_t i = 0; i < POPULATION_SIZE / 2; i++){
        selection[i] = population[i];
    }

    return selection;
}

int cross_over(Point_val *population, Point_val *selection, Function_Properties fproperty){
    int selection_size = POPULATION_SIZE / 2;
    int index = 0;
    int *randomvalues = (int*) controlled_malloc(selection_size / 2 * sizeof(int));

    for (size_t i = 0; i < selection_size / 2; i++){
        randomvalues[i] = (int)ceil(get_random(0, 1) * selection_size / 2);
    }

    for (index = 0; index < selection_size / 4; index++){
        population[index] = selection[index];
    }

    for (size_t i = 0; i < selection_size / 2 - 1; i += 2){
        double beta = get_random(0, 1);
        Point_val *children = (Point_val*) controlled_malloc(2 * sizeof(Point_val));
        for (size_t j = 0; j < 2; j++){
            children[j].point.x = selection[randomvalues[i]].point.x - beta * (selection[randomvalues[i]].point.x - selection[randomvalues[i + 1]].point.x);
            children[j].point.y = selection[randomvalues[i]].point.y - beta * (selection[randomvalues[i]].point.y - selection[randomvalues[i + 1]].point.y);
            calculate_test_function[(int)fproperty.function](&children[j]);

            population[index++] = children[j];
        }
        free(children);
    }
    free(randomvalues);
    free(selection);
    return index; 
}

void mutate(Point_val *population, int count, Function_Properties fproperty){
    for (int i = 0; i < count; i++){
        if (get_random(0, 1) < MUTATION_RATE){
            create_point_val(&population[i], fproperty);
        }
    }
}

void populate(Point_val *population, int count, Function_Properties fproperty){
    for (int i = count; i < POPULATION_SIZE; i++){
        create_point_val(&population[i], fproperty);
    }
}

#endif /* GENETIC_ALGORITHM_H */