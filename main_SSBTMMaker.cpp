// SSBTMMaker v2.11

#include "SSBTMMaker.hpp"
#include <stdlib.h> /* exit, EXIT_FAILURE */

int main(int argc, char* argv[]) {

    TextReader VariableListText;
    TextReader GenVariableListText;
    SSBTMMaker TreeManager;

    if (argc == 3){
        VariableListText.ReadFile(st(argv[1]));
        GenVariableListText.ReadFile(st(argv[2]));
    }
    else if(VariableListText.ReadFile("variables.config") && GenVariableListText.ReadFile("genvariables.config")){
        cout << "Reading default config files : variables.config / genvariables.config" << endl << endl;
    }
    else{
        cout << "Check argument. (./SSBTMMaker OriginalTreeVariableFile GenTreeVariableFile)" << endl << endl;
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

    exit(0);
}
