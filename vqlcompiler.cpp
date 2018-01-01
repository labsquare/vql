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
    mSource="SELECT chr,pos FROM table WHERE a=5 AND b=6 INSIDE region";

    auto varname =  x3::rule<class varname, string>()
                 =  x3::lexeme[(x3::alpha >> *(x3::alnum|'_'|'.'))];


    auto condition =  x3::lexeme[*(x3::char_ - "INSIDE")];

    auto selectRule = x3::rule<class fields, vector<string>> ()
                    = "SELECT" >> varname % ",";

    auto fromRule   = "FROM" >> varname;

    auto whereRule  = "WHERE" >> condition;

    auto insideRule = "INSIDE" >> varname;

    auto begin = mSource.begin();
    auto end   = mSource.end();


    result out;
    x3::phrase_parse(begin,end,
                     selectRule >> fromRule >> -whereRule >> -insideRule,
                     x3::space, out);



    if (begin != end)
        cout<<"could not parse "<<endl;
    else
        cout<<"parse succes"<<endl;


//    cout<<"selected fields: "<<endl;
    for (string i : out.selectData)
        cout<<i<<endl;

    cout<<"table name: "<<out.fromData<<endl;
    cout<<"where"<<out.whereData<<endl;

    cout<<"inside:"<<out.insideData<<endl;


}

const string &VqlCompiler::source() const
{

}

