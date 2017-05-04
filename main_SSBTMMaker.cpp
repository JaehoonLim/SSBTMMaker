// SSBTMMaker v3.00

#include "SSBTMMaker.hpp"
#include <stdlib.h> /* exit, EXIT_FAILURE */

int main(int argc, char* argv[]) {

    TextReader VariableListText;
    TextReader GenVariableListText;
    SSBTMMaker TreeManager;
    TextReader HistListText;
    SSBHMMaker HistManager;

    if (argc == 4){
        if(!VariableListText.ReadFile(st(argv[1]))){ cout << "Check OriginalTreeVariableFile" << endl; exit(EXIT_FAILURE);}
        if(!GenVariableListText.ReadFile(st(argv[2]))){ cout << "Check GenTreeVariableFile" << endl; exit(EXIT_FAILURE);}
        if(!HistListText.ReadFile(st(argv[3]))){ cout << "Check HistogramListFile" << endl; exit(EXIT_FAILURE);}
    }
    else if(VariableListText.ReadFile("variables.config") && GenVariableListText.ReadFile("genvariables.config") && HistListText.ReadFile("hist.config")){
        cout << "Reading default config files : variables.config / genvariables.config / hist.config" << endl << endl;
    }
    else{
        cout << "Check argument. (./SSBTMMaker OriginalTreeVariableFile GenTreeVariableFile HistogramListFile)" << endl << endl;
        exit(EXIT_FAILURE);
    }

    VariableListText.ReadVariables();
    VariableListText.PrintoutVariables();
    map_ss OriginalVariables;
    OriginalVariables = VariableListText.ReturnMap(OriginalVariables);
/*
    map_ss OriginalVariabless = VariableListText.ReturnMap(OriginalVariables);
    It cause error. Because ReturnMap don't know type of OriginalVariables. 
*/
    GenVariableListText.ReadVariables();
    GenVariableListText.PrintoutVariables();
    map_ss GenVariables;
    GenVariables = GenVariableListText.ReturnMap(GenVariables);

    TreeManager.Start();
    TreeManager.GetInput(OriginalVariables, GenVariables);
    TreeManager.MakeConstructor();
    TreeManager.MakeDestructor();
    TreeManager.MakeBook();
    TreeManager.MakeInitialize();
    TreeManager.MakeBook("Gen");
    TreeManager.MakeInitialize("Gen");
    TreeManager.End();

    HistListText.ReadVariables();
    HistListText.PrintoutVariables();
    map_ss HistName;
    map_sd HistValue;
    HistName  = HistListText.ReturnMap(HistName);
    HistValue = HistListText.ReturnMap(HistValue);

    HistManager.Start();
    HistManager.GetInput(HistName, HistValue);
    //HistManager.MakeConstructor();
    //HistManager.MakeDestructor();
    //HistManager.MakeBook();
    HistManager.MakeInitialize();
    HistManager.End();

    exit(0);
}
