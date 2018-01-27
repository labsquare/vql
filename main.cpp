#include <iostream>
#include "vqlcompiler.h"
int main(int argc, char *argv[])
{

    VqlParser compiler;
    compiler.parse("SELECT chr,sample['boby ad'].gt FROM variants WHERE chr=3 INSIDE boby");

    std::cout<<compiler;


    return 0;
}
