// SSBTMMaker v2.11
// TextReader v2.11

#ifndef __SSBTMMaker_hpp_Inclueded__
#define __SSBTMMaker_hpp_Inclueded__

#include "./TextReader/TextReader.hpp"
#include <algorithm> // std::find
#include <iostream>
#include <fstream>

using namespace std;

class SSBTMMaker {

public:

    SSBTMMaker();
    ~SSBTMMaker();

    void Start();
    void End();
    void GetInput(map_ss, map_ss);
    void MakeConstructor();
    void MakeDestructor();
    void MakeBook(std::string FuncName = "");
    void MakeInitialize(std::string FuncName = "");

private:

    ofstream HeaderFile;
    ofstream CPPFile;

    map_ss 	Variable_List;
    map_ss_it 	Variable_List_it;
    vec_s_it 	Vector_it;

    map_ss 	GenVariable_List;
    map_ss_it 	GenVariable_List_it;
    vec_s_it 	GenVector_it;

};

/////////////////////////////////
// SSB Histogram Manager Maker //
/////////////////////////////////

class SSBHMMaker {

public:

    SSBHMMaker();
    ~SSBHMMaker();

    void Start();
    void End();
    void GetInput(map_ss, map_sd);
    void MakeConstructor();
    void MakeDestructor();
    void MakeBook();
    void MakeInitialize();

private:

    ofstream HeaderFile;
    ofstream CPPFile;

    map_sd 	Variable_List;
    map_sd_it 	Variable_List_it;
    map_ss 	Name_List;
    map_ss_it 	Name_List_it;
    vec_s_it 	Name_it;

};

#endif // __SSBTMMaker_hpp_Inclueded__
