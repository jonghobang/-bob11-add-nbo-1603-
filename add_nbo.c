#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <netinet/in.h>

#define BUF_SIZE 256

uint32_t my_ntohs2(uint32_t n)
{
        uint32_t n1 = (n & 0xff000000) >> 24;
        uint32_t n2 = (n & 0x00ff0000) >> 8;
        uint32_t n3 = (n & 0x0000ff00) << 8;
        uint32_t n4 = (n & 0x000000ff) << 24;
        return n1|n2|n3|n4;
}

int main(int argc, char** argv)
{
    FILE* f1 = fopen(argv[1],"rb");
    FILE* f2 = fopen(argv[2],"rb");

    uint32_t a;
    uint32_t b;

    fread(&a,sizeof(uint32_t),1,f1);
    fread(&b,sizeof(uint32_t),1,f2);

    //uint32_t* p1 = &a;
    //uint32_t n1 = my_ntohs2(*p1);

    //uint32_t n1 = htonl((*p1));

    //uint32_t* p2 = &b;
    //uint32_t n2 = my_ntohs2(*p2);
    //uint32_t n2 = htonl((*p2));
    uint32_t real_a = ntohl(a);
    uint32_t real_b = ntohl(b);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",real_a,real_a,real_b,real_b,(real_a+real_b),(real_a+real_b));
}

