#ifndef MAIN_H
#define MAIN_H

#define POPULATION_SIZE 2000
#define GENERATION 400
#define MUTATION_RATE 0.001

#define PI 3.14159265358979323846
#define E 2.7182818284590451

typedef struct {
    double x;
    double y;
}Point;

typedef struct {
    Point point;
    double val;
}Point_val;

double get_random(double min, double max){
    return ((double)rand() / 0x7FFF) * (max - min) + min;
}

void* controlled_malloc(size_t size){
    void* memory = malloc(size);
    if (memory == NULL){
        printf("malloc failed.");
        system("pause");
        exit(0);
    }
    return memory;
}

#endif /* MAIN_H */