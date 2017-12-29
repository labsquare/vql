#ifndef VQLCOMPILER_H
#define VQLCOMPILER_H
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "boost/spirit/home/x3.hpp"
#include "boost/fusion/include/adapt_struct.hpp"
#include "boost/fusion/adapted/std_pair.hpp"
#include <boost/fusion/sequence.hpp>
#include <boost/fusion/include/sequence.hpp>
using namespace boost::spirit;

/*
Exemple of query :
SELECT chr, pos, ref, ann.gene_name FROM variant
SELECT chr, pos, ref, sample["boby"].gt FROM variant
SELECT chr, pos, ref, ann.gene_name FROM variant WHERE pos = 3
SELECT chr, pos, ref, sample["boby"].gt FROM variant INSIDE bed

*/

using namespace std;

class VqlCompiler
{
public:
    VqlCompiler(const string& source);
    void setSource(const string& source);
    void compile();


    const string& source() const;



private:
    string mSource;
    vector<string> mSelectFields;
    map<string, vector<string>> mSampleFields;
    string mTableName;
    string mWhereClause;
    string mInsideClause;

};

#endif // VQLCOMPILER_H
