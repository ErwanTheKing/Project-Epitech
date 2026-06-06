#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UPPER_BOUND 5000.0
#define N_INTERVALS 10000
#define H           (UPPER_BOUND / N_INTERVALS)
#define PI          3.14159265358979323846

static double product_for_x(double x, const double *inv_d, int n)
{
    double product = 1.0;

    for (int k = 0; k <= n; k++) {
        double t = (x * inv_d[k]);
        product *= (sin(t) / t);
    }
    return product;
}

static void compute(int n, double *mid_out, double *trap_out)
{
    double *inv_d = malloc((n + 1) * sizeof(double));
    for (int k = 0; k <= n; k++)
        inv_d[k] = (1.0 / (2.0 * k + 1.0));

    double mid_sum  = 0.0;
    double trap_sum = 0.0;

    for (int i = 0; i < N_INTERVALS; i++) {
        double xm = ((i + 0.5) * H);
        double xt = ((i + 1)   * H);
        double pm = product_for_x(xm, inv_d, n);
        double pt = product_for_x(xt, inv_d, n);
        mid_sum  += pm;
        trap_sum += pt;
    }

    double trap_last = product_for_x((N_INTERVALS * H), inv_d, n);
    free(inv_d);
    *mid_out  = (mid_sum * H);
    *trap_out = ((1.0 + (2.0 * trap_sum) - trap_last) * H / 2.0);
}

static void print_result(const char *method, double value, int n)
{
    double diff = (value - (PI / 2.0));
    if (diff < 0.0) diff = -diff;
    printf("%s:\nI%d = %.10f\ndiff = %.10f\n", method, n, value, diff);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        fprintf(stderr, "USAGE\n\t./110borwein n\n\nDESCRIPTION\n\tn\tconstant defining the integral to be computed\n");
        return 84;
    }
    if (strcmp(av[1], "-h") == 0) {
        printf("USAGE\n\t./110borwein n\n\nDESCRIPTION\n\tn\tconstant defining the integral to be computed\n");
        return 0;
    }
    char *end;
    int n = (int)strtol(av[1], &end, 10);
    if (*end != '\0' || n < 0) {
        fprintf(stderr, "Error: invalid argument '%s'\n", av[1]);
        return 84;
    }
    double mid, trap, simp;
    compute(n, &mid, &trap);
    simp = ((2.0 * mid + trap) / 3.0);
    print_result("Midpoint",    mid,  n);
    printf("\n");
    print_result("Trapezoidal", trap, n);
    printf("\n");
    print_result("Simpson",     simp, n);
    return 0;
}