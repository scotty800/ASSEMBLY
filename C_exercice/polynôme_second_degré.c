#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef enum TypeSolution
{
    UNE_SOLUTION,
    DEUX_SOLUTION,
    PAS_DE_SOLUTION
} TypeSolution;

typedef struct Equation2ndDegre
{
    float a;
    float b;
    float c;
} Equation2ndDegre;

float discriminant(Equation2ndDegre eq)
{
    return eq.b * eq.b -4 * eq.a * eq.c;
}

TypeSolution calcul_solution(Equation2ndDegre eq, float *x1, float *x2)
{
    float d = discriminant(eq);
    if (d < 0)
    {
        return PAS_DE_SOLUTION;
    }
    else if (d == 0)
    {
        *x1 = -eq.b / (2 * eq.a);
        return UNE_SOLUTION;
    }
    else
    {
        *x1 = (-eq.b + sqrt(d)) / (2 * eq.a);
        *x2 = (-eq.b - sqrt(d)) / (2 * eq.a);
        return DEUX_SOLUTION;
    }
}

int main()
{
    float x1, x2;
    Equation2ndDegre *eq;
    
    eq = malloc(sizeof(Equation2ndDegre));

    printf("Entrez a, b, c : ");
    scanf("%f %f %f", &eq->a, &eq->b, &eq->c);

    TypeSolution type = calcul_solution(*eq, &x1, &x2);

    if (type == PAS_DE_SOLUTION)
        printf("Pas de solution réelle.\n");
    else if (type == UNE_SOLUTION)
        printf("Une solution : x = %.2f\n", x1);
    else
        printf("Deux solutions : x1 = %.2f, x2 = %.2f\n", x1, x2);

        free(eq);
        return 0;
}