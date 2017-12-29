#include <iostream>
#include "vqlcompiler.h"
int main(int argc, char *argv[])
{

    VqlCompiler compiler("SELECT chr, pos FROM variants");
    compiler.compile();

    return 0;
}
