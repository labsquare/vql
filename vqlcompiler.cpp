#include "vqlcompiler.h"

VqlCompiler::VqlCompiler(const string &source)
    :mSource(source)
{

}
void VqlCompiler::setSource(const string &source)
{
    mSource = source;
}

void VqlCompiler::compile()
{


    cout<<"Select fields:\n";
    for (string field: mSelectFields)
        cout<<field<<endl;

}

const string &VqlCompiler::source() const
{

}

