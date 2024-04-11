#include <hvx_hexagon_protos.h>
#include <hexagon_protos.h>
#include <hexagon_types.h>
#include <stdio.h>
#include <string.h>

#define N 128

unsigned char a[N], b[N] __attribute__ ((aligned(128)));

int main()
{
    HVX_Vector v1, v2, *vptr;
    HVX_VectorPair v;
    int i;

    v1 = Q6_V_vzero();
    v2 = Q6_V_vzero();
    v  = Q6_W_vcombine_VV(v1, v2);

    memset(a, 0xFF, N);
    memcpy(b, a, N);

    vptr = (HVX_Vector*) b;
    *vptr = v1;

    for(i = 0; i < N; i++)
        printf("%4d: %x %x\n", i, a[i], b[i]);

    return 0;
}