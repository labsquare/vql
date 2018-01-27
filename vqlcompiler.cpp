#include "vqlcompiler.h"

VqlParser::VqlParser()
{

}

bool VqlParser::parse(const string &source)
{
    mSource = source;

    auto varnameRule =  x3::rule<class varname, string>()
            =  x3::lexeme[(x3::alpha >> *(x3::alnum|'_'|'.'))];


    auto columnsRule =  x3::rule<class varname, string>()
            =  x3::lexeme[*(x3::char_ - '"' - "FROM")];

    auto conditionRule =  x3::lexeme[*(x3::char_ - "INSIDE")];

    auto selectRule = x3::rule<class fields, vector<string>> ()
            = "SELECT" >> columnsRule % ",";

    auto fromRule   = "FROM" >> varnameRule;

    auto whereRule  = "WHERE" >> conditionRule;

    auto insideRule = "INSIDE" >> varnameRule;

    auto begin = mSource.begin();
    auto end   = mSource.end();


    x3::phrase_parse(begin,end,
                     selectRule >> fromRule >> -whereRule >> -insideRule,
                     x3::space, mResult);

    // parse all
    if (begin != end){
        cout<<"cannot parse "<<endl;
        return false;
    }

    return true;


}

const string &VqlParser::source() const
{

}

const string &VqlParser::tableName() const
{
    return mResult.fromData;
}

const vector<string> &VqlParser::columns() const
{
    return mResult.selectData;
}

const string &VqlParser::conditions() const
{
    return mResult.whereData;
}

const string &VqlParser::inside() const
{
    return mResult.insideData;
}


std::ostream &operator<<(std::ostream& os, VqlParser& c)
{

    os<<"table name: "<<c.tableName()<<"\n";
    os<<"columns: ";
    std::copy(c.columns().begin(), c.columns().end(), std::ostream_iterator<string>(os," "));
    os<<"\n";
    os<<"conditions: "<<c.conditions()<<"\n";
    os<<"inside: "<<c.inside()<<"\n";

    return os;
}
