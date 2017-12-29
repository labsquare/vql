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

    std::string input( "foo : bar ,"
    "gorp : smart ,"
    "falcou : \"crazy frenchman\" " );

    auto iter = input.begin();
    auto iter_end = input.end();

    auto name = x3::rule<class name, std::string>()
              = x3::alpha >> *x3::alnum;


    auto quote = x3::rule<class quote, std::string>()
               = '"' >> x3::lexeme[*(~x3::char_('"'))] >> '"';

    auto item  = x3::rule<class item, pair<string,string>>()
               = name >> ":" >> (quote|name);

    map<string, string> results;

    x3::phrase_parse(iter, iter_end,
                     item % ',', x3::space, results);


    cout<<results["falcou"]<<endl;

}

const string &VqlCompiler::source() const
{

}

