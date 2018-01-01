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


    auto condition =  x3::rule<class condition, string>()
                   =  x3::lexeme[*(x3::char_ - "INSIDE")];

    auto selectRule = x3::rule<class fields, vector<string>> ()
                    = "SELECT" >> varname % ",";

    auto fromRule   = x3::rule<class fromRule, string>()
                    = "FROM" >> varname;

    auto whereRule  = x3::rule<class whereRule, vector<string>>()
                    = "WHERE" >> condition % " AND ";

    auto insideRule = x3::rule<class insideRule, string>()
                    = "INSIDE" >> varname;

    auto begin = mSource.begin();
    auto end   = mSource.end();

   vector<string> results;

   // How to fill
   vector<string> selectData;
   string fromData;
   string whereData;
   string insideData;


    x3::phrase_parse(begin,end,
                     selectRule >> fromRule >> -whereRule >> -insideRule,
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

