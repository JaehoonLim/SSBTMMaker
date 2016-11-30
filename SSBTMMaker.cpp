// SSBTMMaker v2.11

#include "SSBTMMaker.hpp"

SSBTMMaker::SSBTMMaker() {
}

SSBTMMaker::~SSBTMMaker() {
}

void SSBTMMaker::Start() {

    // Make files
    ofstream HeaderFile;
    HeaderFile.open ("SSBTreeManager.h");
    CPPFile.open ("SSBTreeManager.cc");

    // Read Base files
    ifstream HeaderBaseFile ("HEADER_BASE.h");
    ifstream CPPBaseFile ("CPP_BASE.cc");

    // Base to Output files
    st Base_Line;
    while (getline(HeaderBaseFile,Base_Line)){
	HeaderFile << Base_Line << '\n';
    }
    while (getline(CPPBaseFile,Base_Line)){
	CPPFile << Base_Line << '\n';
    }

    // Close files
    HeaderFile.close();
    HeaderBaseFile.close();
    CPPBaseFile.close();

}

void SSBTMMaker::End() {
    CPPFile.close();
}

void SSBTMMaker::GetInput(map_ss OriginalVariables, map_ss GenVariables) {
    Variable_List = OriginalVariables;
    GenVariable_List = GenVariables;
}

void SSBTMMaker::MakeConstructor() {
    CPPFile << "SSBTreeManager::SSBTreeManager(){" << '\n' << '\n';
    Variable_List_it = Variable_List.find("TLorentzVector");
    GenVariable_List_it = GenVariable_List.find("TLorentzVector");
    for (Vector_it = (Variable_List_it->second).begin(); Vector_it != (Variable_List_it->second).end(); ++Vector_it) {
	CPPFile << "    VariableBox_LorentzVector[\"" << *Vector_it << "\"] = new TClonesArray(\"TLorentzVector\");" << '\n'; 
    }
    for (GenVector_it = (GenVariable_List_it->second).begin(); GenVector_it != (GenVariable_List_it->second).end(); ++GenVector_it) {
	if (find((Variable_List_it->second).begin(), (Variable_List_it->second).end(), *GenVector_it) == (Variable_List_it->second).end()) {
	    CPPFile << "    VariableBox_LorentzVector[\"" << *GenVector_it << "\"] = new TClonesArray(\"TLorentzVector\");" << '\n';
	}
    }
    CPPFile << '\n' << "}" << '\n' << '\n';
}

void SSBTMMaker::MakeDestructor() {
    CPPFile << "SSBTreeManager::~SSBTreeManager(){" << '\n' << '\n';
/*    Variable_List_it = Variable_List.find("TLorentzVector");
    GenVariable_List_it = GenVariable_List.find("TLorentzVector");
    for (Vector_it = (Variable_List_it->second).begin(); Vector_it != (Variable_List_it->second).end(); ++Vector_it) {
	CPPFile << "    delete VariableBox_LorentzVector[\"" << *Vector_it << "\"];" << '\n'; 
    }
    for (GenVector_it = (GenVariable_List_it->second).begin(); GenVector_it != (GenVariable_List_it->second).end(); ++GenVector_it) {
	if (find((Variable_List_it->second).begin(), (Variable_List_it->second).end(), *GenVector_it) == (Variable_List_it->second).end()) {
	CPPFile << "    delete VariableBox_LorentzVector[\"" << *GenVector_it << "\"];" << '\n'; 
	}
    }
*/    CPPFile << '\n' << "}" << '\n' << '\n';
}

void SSBTMMaker::MakeBook(std::string FuncName) {
    map_s Sorted_Variable;
    Sorted_Variable.clear();
    if (FuncName == "Gen") {
	for (GenVariable_List_it = GenVariable_List.begin(); GenVariable_List_it != GenVariable_List.end(); ++GenVariable_List_it){
	    for (GenVector_it = (GenVariable_List_it->second).begin(); GenVector_it != (GenVariable_List_it->second).end(); ++GenVector_it) {
		Sorted_Variable[*GenVector_it] = GenVariable_List_it->first;
	    }
	}
    }
    else {
	for (Variable_List_it = Variable_List.begin(); Variable_List_it != Variable_List.end(); ++Variable_List_it){
	    for (Vector_it = (Variable_List_it->second).begin(); Vector_it != (Variable_List_it->second).end(); ++Vector_it) {
		Sorted_Variable[*Vector_it] = Variable_List_it->first;
	    }
	}
    }

    CPPFile << "void SSBTreeManager::" << FuncName << "Book(TTree* tree){" << '\n' << '\n';
    CPPFile << "    ssbtree = tree;" << '\n';
    bool StartWithInfoVariable = true;
    for (map_s_it Sorted_Variable_it = Sorted_Variable.begin();
	 (Sorted_Variable_it != Sorted_Variable.end()) || (StartWithInfoVariable == true);
	 ++Sorted_Variable_it){
	if ((Sorted_Variable_it == Sorted_Variable.end()) && (StartWithInfoVariable == true)){
	    Sorted_Variable_it = Sorted_Variable.begin();
	    StartWithInfoVariable = false;
	}
	if (!(Sorted_Variable_it->first).find("Info_") ^ StartWithInfoVariable) {continue;}
        CPPFile << "    ssbtree->Branch(\"" << Sorted_Variable_it->first << "\", ";
	if (Sorted_Variable_it->second == "BOOL"){
	    CPPFile << "&VariableBox_Bool[\"" << Sorted_Variable_it->first << "\"], \"" << Sorted_Variable_it->first << "/B\");" << '\n';
	}
	if (Sorted_Variable_it->second == "INT"){
	    CPPFile << "&VariableBox_Int[\"" << Sorted_Variable_it->first << "\"], \"" << Sorted_Variable_it->first << "/I\");" << '\n';
	}
	if (Sorted_Variable_it->second == "UINT"){
	    CPPFile << "&VariableBox_UInt[\"" << Sorted_Variable_it->first << "\"], \"" << Sorted_Variable_it->first << "/i\");" << '\n';
	}
	if (Sorted_Variable_it->second == "FLOAT"){
	    CPPFile << "&VariableBox_Float[\"" << Sorted_Variable_it->first << "\"], \"" << Sorted_Variable_it->first << "/F\");" << '\n';
	}
	if (Sorted_Variable_it->second == "DOUBLE"){
	    CPPFile << "&VariableBox_Double[\"" << Sorted_Variable_it->first << "\"], \"" << Sorted_Variable_it->first << "/D\");" << '\n';
	}
	if (Sorted_Variable_it->second == "STRING"){
	    CPPFile << "&VariableBox_String[\"" << Sorted_Variable_it->first << "\"]);" << '\n';
	}
	if (Sorted_Variable_it->second == "TLorentzVector"){
	    CPPFile << "\"TClonesArray\", &VariableBox_LorentzVector[\"" << Sorted_Variable_it->first << "\"], 32000, 0);" << '\n';
	    CPPFile << "    VariableBox_LorentzVector[\"" << Sorted_Variable_it->first << "\"]->BypassStreamer();" << '\n';
	}
	if (Sorted_Variable_it->second == "BOOL_VECTOR"){
	    CPPFile << "&VectorBox_Bool[\"" << Sorted_Variable_it->first << "\"]);" << '\n';
	}
	if (Sorted_Variable_it->second == "INT_VECTOR"){
	    CPPFile << "&VectorBox_Int[\"" << Sorted_Variable_it->first << "\"]);" << '\n';
	}
	if (Sorted_Variable_it->second == "UINT_VECTOR"){
	    CPPFile << "&VectorBox_UInt[\"" << Sorted_Variable_it->first << "\"]);" << '\n';
	}
	if (Sorted_Variable_it->second == "FLOAT_VECTOR"){
	    CPPFile << "&VectorBox_Float[\"" << Sorted_Variable_it->first << "\"]);" << '\n';
	}
	if (Sorted_Variable_it->second == "DOUBLE_VECTOR"){
	    CPPFile << "&VectorBox_Double[\"" << Sorted_Variable_it->first << "\"]);" << '\n';
	}
	if (Sorted_Variable_it->second == "STRING_VECTOR"){
	    CPPFile << "&VectorBox_String[\"" << Sorted_Variable_it->first << "\"]);" << '\n';
	}
    }
    CPPFile << '\n' << "}" << '\n' << '\n';
}

void SSBTMMaker::MakeInitialize(std::string FuncName) {
    map_s Sorted_Variable;
    Sorted_Variable.clear();
    if (FuncName == "Gen") {
	for (GenVariable_List_it = GenVariable_List.begin(); GenVariable_List_it != GenVariable_List.end(); ++GenVariable_List_it){
	    for (GenVector_it = (GenVariable_List_it->second).begin(); GenVector_it != (GenVariable_List_it->second).end(); ++GenVector_it) {
		Sorted_Variable[*GenVector_it] = GenVariable_List_it->first;
	    }
	}
    }
    else {
	for (Variable_List_it = Variable_List.begin(); Variable_List_it != Variable_List.end(); ++Variable_List_it){
	    for (Vector_it = (Variable_List_it->second).begin(); Vector_it != (Variable_List_it->second).end(); ++Vector_it) {
		Sorted_Variable[*Vector_it] = Variable_List_it->first;
	    }
	}
    }

    CPPFile << "void SSBTreeManager::" << FuncName << "InitializeVariables(){" << '\n' << '\n';
    bool StartWithInfoVariable = true;
    for (map_s_it Sorted_Variable_it = Sorted_Variable.begin();
	 (Sorted_Variable_it != Sorted_Variable.end()) || (StartWithInfoVariable == true);
	 ++Sorted_Variable_it){
	if ((Sorted_Variable_it == Sorted_Variable.end()) && (StartWithInfoVariable == true)){
	    Sorted_Variable_it = Sorted_Variable.begin();
	    StartWithInfoVariable = false;
	}
	if (!(Sorted_Variable_it->first).find("Info_") ^ StartWithInfoVariable) {continue;}
	if (Sorted_Variable_it->second == "BOOL"){
	    CPPFile << "    VariableBox_Bool[\"" << Sorted_Variable_it->first << "\"] = false;" << '\n';
	}
	if (Sorted_Variable_it->second == "INT"){
	    CPPFile << "    VariableBox_Int[\"" << Sorted_Variable_it->first << "\"] = 0;" << '\n';
	}
	if (Sorted_Variable_it->second == "UINT"){
	    CPPFile << "    VariableBox_UInt[\"" << Sorted_Variable_it->first << "\"] = 0;" << '\n';
	}
	if (Sorted_Variable_it->second == "FLOAT"){
	    CPPFile << "    VariableBox_Float[\"" << Sorted_Variable_it->first << "\"] = 0;" << '\n';
	}
	if (Sorted_Variable_it->second == "DOUBLE"){
	    CPPFile << "    VariableBox_Double[\"" << Sorted_Variable_it->first << "\"] = 0;" << '\n';
	}
	if (Sorted_Variable_it->second == "STRING"){
	    CPPFile << "    VariableBox_String[\"" << Sorted_Variable_it->first << "\"] = \"\"" << '\n';
	}
	if (Sorted_Variable_it->second == "TLorentzVector"){
	    CPPFile << "    VariableBox_LorentzVector[\"" << Sorted_Variable_it->first << "\"]->Clear();" << '\n';
	}
	if (Sorted_Variable_it->second == "BOOL_VECTOR"){
	    CPPFile << "    VectorBox_Bool[\"" << Sorted_Variable_it->first << "\"].clear();" << '\n';
	}
	if (Sorted_Variable_it->second == "INT_VECTOR"){
	    CPPFile << "    VectorBox_Int[\"" << Sorted_Variable_it->first << "\"].clear();" << '\n';
	}
	if (Sorted_Variable_it->second == "UINT_VECTOR"){
	    CPPFile << "    VectorBox_UInt[\"" << Sorted_Variable_it->first << "\"].clear();" << '\n';
	}
	if (Sorted_Variable_it->second == "FLOAT_VECTOR"){
	    CPPFile << "    VectorBox_Float[\"" << Sorted_Variable_it->first << "\"].clear();" << '\n';
	}
	if (Sorted_Variable_it->second == "DOUBLE_VECTOR"){
	    CPPFile << "    VectorBox_Double[\"" << Sorted_Variable_it->first << "\"].clear();" << '\n';
	}
	if (Sorted_Variable_it->second == "STRING_VECTOR"){
	    CPPFile << "    VectorBox_String[\"" << Sorted_Variable_it->first << "\"].clear();" << '\n';
	}
    }
    CPPFile << '\n' << "}" << '\n' << '\n';
}
