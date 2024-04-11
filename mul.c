// This program adds two hvx vectors

#include <hvx_hexagon_protos.h>
#include <hexagon_protos.h>
#include <hexagon_types.h>
#include <stdio.h>
#include <string.h>

#define N 128

unsigned char a[N], b[N];

int main()
{
    HVX_Vector *v1, *v3, vres;
    HEXAGON_Vect32 v2 = 3;
    int i;

    for(int i=0; i<N;i++)
    {
        a[i] = i;
    }
    v1 = (HVX_Vector*) a;
    v3 = (HVX_Vector*) b;

    vres =  Q6_Vh_vdmpy_VubRb(*v1, v2);

    *v3 = vres;

    for(i = 0; i < N; i++)
        printf("%4d: %d %d\n", i, a[i], b[i]);

    printf("Simple HVX example %p\n", b);

    return 0;
}