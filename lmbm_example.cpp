#include "lmbm.h"

#include <cstdio>
#include <cmath>

static int fcalls = 0;

double costFunc(void *instance,
                const double *x,
                double *g,
                const int n)
{
    double fx1 = -x[0] - x[1];
    double fx2 = x[0] * x[0] + x[1] * x[1] -
                 x[0] - x[1] - 1.0;
    double fx = fx1 > fx2 ? fx1 : fx2;
    if (g != NULL)
    {
        if (fx1 > fx2)
        {
            g[0] = -1.0;
            g[1] = -1.0;
        }
        else
        {
            g[0] = 2.0 * x[0] - 1.0;
            g[1] = 2.0 * x[1] - 1.0;
        }
    }
    fcalls++;
    return fx;
}

int main(int argc, char **argv)
{
    int n = 2;
    double x[2] = {1.0, 1.0};
    double f = INFINITY;
    lmbm::lmbm_parameter_t param;
    lmbm::lmbm_optimize(n,
                        x,
                        &f,
                        costFunc,
                        nullptr,
                        &param);
    {
        printf("-----------\n");
        printf("| Output: |\n");
        printf("-----------\n");
        printf("%-16s %f\n", "Final value:", f);
        printf("%-16s %f, %f\n", "Solution:", x[0], x[1]);
        printf("%-16s %d\n", "Func calls:", fcalls);
    }
}
