#include <string.h>
#include <sys/timeb.h>
#include <time.h>

#include "genetic_algorithm.h"

void calculate(Point_val*, Function_Properties);
void ga_start(int index);
void ga_start_all();
int get_input();

int main(){
    int index = 0;
    srand(time(NULL));
    
    print_test_functions();
    
    while(1){
        index = get_input();
        index == FUNCTION_COUNT + 1 ? ga_start_all() : ga_start(index - 1);
    }
    
    return 0;
}

void calculate(Point_val *population, Function_Properties fproperty){
    for (size_t i = 0; i < GENERATION; i++){
        Point_val* select = selection(population);
        int index = cross_over(population, select, fproperty);
        mutate(population, index, fproperty);
        populate(population, index, fproperty);
    }
}

void ga_start(int index){
    struct __timeb64 start, end;
    
    Function_Properties fproperty = get_function_limits(index);
    print_function_properties(fproperty);

    Point_val *population = (Point_val*) controlled_malloc(POPULATION_SIZE * sizeof(Point_val));
    create_population(population, fproperty);

    _ftime64(&start);
    calculate(population, fproperty);
    _ftime64(&end);
    
    print_pointv_details(&population[0]);
    printf("Elapsed Time: %Ld ms\n\n", (int)(1000.0 * (end.time - start.time) + (end.millitm - start.millitm)));
     
    free(population);
}

void ga_start_all(){
    for (size_t i = 0; i < FUNCTION_COUNT; i++){
        ga_start(i);
    }  
}

int get_input(){
    char* input = controlled_malloc(255 * sizeof(char));
    int index = 0;
    do
    {
        printf("Input: ");
        gets(input);

        if (strncmp(input, "exit", 4) == 0){
            exit(0);
        }

        if (strncmp(input, "clear", 5) == 0){
            system("cls");
            print_test_functions();
        }

        index = atoi(input);
    } while (index <= 0 || index > FUNCTION_COUNT + 1);

    free(input);
    return index;
}