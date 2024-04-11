// This program adds two hvx vectors

#include <hvx_hexagon_protos.h>
#include <hexagon_protos.h>
#include <hexagon_types.h>
#include <stdio.h>
#include <string.h>

#define N 128

unsigned char a[N], b[N], c[N];

int main()
{
    HVX_Vector *v1, *v2, *v3, vres;
    int i;

    for(int i=0; i<N;i++)
    {
        a[i] = i;
        b[i] = i+1;
    }
    v1 = (HVX_Vector*) a;
    v2 = (HVX_Vector*) b;
    v3 = (HVX_Vector*) c;

    vres =  Q6_Vb_vsub_VbVb(*v1, *v2);

    *v3 = vres;

    for(i = 0; i < N; i++)
        printf("%4d: %d %d %d\n", i, a[i], b[i], c[i]);

    printf("Simple HVX example %p\n", b);

    return 0;
}