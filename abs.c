// This program computes the abs value of a hvx vector

#include <hvx_hexagon_protos.h>
#include <hexagon_protos.h>
#include <hexagon_types.h>
#include <stdio.h>
#include <string.h>

#define N 128

unsigned char a[N], b[N];

int main()
{
    HVX_Vector *v1, *v2, vres;
    int i;

    for(int i=0; i<N;i++)
    {
        a[i] = i;
    }
    v1 = (HVX_Vector*) a;
    v2 = (HVX_Vector*) b;

    vres = Q6_Vb_vabs_Vb(*v1);

    *v2 = vres;

    for(i = 0; i < N; i++)
        printf("%4d: %d %d\n", i, a[i], b[i]);

    printf("Simple HVX example %p\n", b);

    return 0;
}
