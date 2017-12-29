#ifndef VQLCOMPILER_H
#define VQLCOMPILER_H
#include <string>
#include <vector>
#include <iostream>
#include <map>

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
    string mWhereClause;
    string mInsideClause;

};

#endif // VQLCOMPILER_H
