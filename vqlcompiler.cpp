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
    mSource="SELECT chr,pos FROM table";

    auto varname =  x3::rule<class varname, string>()
                 =  x3::lexeme[(x3::alpha >> *(x3::alnum|'_'|'.')) - "SELECT" - "FROM"];

    auto fieldsRule = x3::rule<class fields, vector<string>> ()
                    = "SELECT" >> varname % ",";

    auto fromRule   = x3::rule<class fromRule, string>()
                    = "FROM" >> varname;

    auto begin = mSource.begin();
    auto end   = mSource.end();

   vector<string> results;

    x3::phrase_parse(begin,end,
                     fieldsRule >> -fromRule,
                     x3::space, results);

    if (begin != end)
        cout<<"could not parse "<<endl;
    else
        cout<<"parse succes"<<endl;

    for (auto i : results)
        cout<<i<<endl;



//    cout<<"selected fields: "<<endl;
//    for (string i : mSelectFields)
//        cout<<i<<endl;

//    cout<<"table name: "<<mTableName;


}

const string &VqlCompiler::source() const
{

}

