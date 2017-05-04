// SSBTMMaker v3.00

#include "SSBTreeManager.h"

void SSBTreeManager::FillNtuple(){
   ssbtree->Fill();
}

void SSBTreeManager::Fill(st VariableName, double pt, double eta, double phi, double e, int index){
    if ((it_VariableBox_LorentzVector = VariableBox_LorentzVector.find(VariableName.c_str())) != VariableBox_LorentzVector.end()){
	new ((*VariableBox_LorentzVector[VariableName.c_str()])[index]) TLorentzVector();
	( (TLorentzVector*)VariableBox_LorentzVector[VariableName.c_str()]->At(index) )->SetPtEtaPhiE(pt, eta, phi, e);
    }
    else {
	std::cout << "Fill_LV_Int Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, double pt, double eta, double phi, double e, unsigned int index){
    if ((it_VariableBox_LorentzVector = VariableBox_LorentzVector.find(VariableName.c_str())) != VariableBox_LorentzVector.end()){
	new ((*VariableBox_LorentzVector[VariableName.c_str()])[index]) TLorentzVector();
	( (TLorentzVector*)VariableBox_LorentzVector[VariableName.c_str()]->At(index) )->SetPtEtaPhiE(pt, eta, phi, e);
    }
    else {
	std::cout << "Fill_LV_UInt Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, bool VariableBool){
    if ((it_VariableBox_Bool = VariableBox_Bool.find(VariableName.c_str())) != VariableBox_Bool.end()){
	VariableBox_Bool[VariableName.c_str()] = VariableBool;
	//std::cout << "Val : " << VariableBool << " == " << it_VariableBox_Bool->second << std::endl;
    }
    else if ((it_VectorBox_Bool = VectorBox_Bool.find(VariableName.c_str())) != VectorBox_Bool.end()){
        (it_VectorBox_Bool->second).push_back(VariableBool);
	//std::cout << "Vec : " << VariableBool << " == " << (it_VectorBox_Bool->second).back() << std::endl;
    }
    else {
	std::cout << "Fill_Bool Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, int VariableInt){
    if ((it_VariableBox_Int = VariableBox_Int.find(VariableName.c_str())) != VariableBox_Int.end()){
	VariableBox_Int[VariableName.c_str()] = VariableInt;
	//std::cout << "Val : " << VariableInt << " == " << it_VariableBox_Int->second << std::endl;
    }
    else if ((it_VectorBox_Int = VectorBox_Int.find(VariableName.c_str())) != VectorBox_Int.end()){
        (it_VectorBox_Int->second).push_back(VariableInt);
	//std::cout << "Vec : " << VariableInt << " == " << (it_VectorBox_Int->second).back() << std::endl;
    }
    else {
	std::cout << "Fill_Int Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, unsigned int VariableUInt){
    if ((it_VariableBox_UInt = VariableBox_UInt.find(VariableName.c_str())) != VariableBox_UInt.end()){
	VariableBox_UInt[VariableName.c_str()] = VariableUInt;
	//std::cout << "Val : " << VariableUInt << " == " << it_VariableBox_UInt->second << std::endl;
    }
    else if ((it_VectorBox_UInt = VectorBox_UInt.find(VariableName.c_str())) != VectorBox_UInt.end()){
        (it_VectorBox_UInt->second).push_back(VariableUInt);
	//std::cout << "Vec : " << VariableUInt << " == " << (it_VectorBox_UInt->second).back() << std::endl;
    }
    else {
	std::cout << "Fill_UInt Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, float VariableFloat){
    if ((it_VariableBox_Float = VariableBox_Float.find(VariableName.c_str())) != VariableBox_Float.end()){
	VariableBox_Float[VariableName.c_str()] = VariableFloat;
	//std::cout << "Val : " << VariableFloat << " == " << it_VariableBox_Float->second << std::endl;
    }
    else if ((it_VectorBox_Float = VectorBox_Float.find(VariableName.c_str())) != VectorBox_Float.end()){
        (it_VectorBox_Float->second).push_back(VariableFloat);
	//std::cout << "Vec : " << VariableFloat << " == " << (it_VectorBox_Float->second).back() << std::endl;
    }
    else {
	std::cout << "Fill_Float Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, double VariableDouble){
    if ((it_VariableBox_Double = VariableBox_Double.find(VariableName.c_str())) != VariableBox_Double.end()){
	VariableBox_Double[VariableName.c_str()] = VariableDouble;
	//std::cout << "Val : " << VariableDouble << " == " << it_VariableBox_Double->second << std::endl;
    }
    else if ((it_VectorBox_Double = VectorBox_Double.find(VariableName.c_str())) != VectorBox_Double.end()){
        (it_VectorBox_Double->second).push_back(VariableDouble);
	//std::cout << "Vec : " << VariableDouble << " == " << (it_VectorBox_Double->second).back() << std::endl;
    }
    else {
	std::cout << "Fill_Double Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, st VariableString){
    if ((it_VariableBox_String = VariableBox_String.find(VariableName.c_str())) != VariableBox_String.end()){
	VariableBox_String[VariableName.c_str()] = VariableString;
	//std::cout << "Val : " << VariableString << " == " << it_VariableBox_String->second << std::endl;
    }
    else if ((it_VectorBox_String = VectorBox_String.find(VariableName.c_str())) != VectorBox_String.end()){
        (it_VectorBox_String->second).push_back(VariableString);
	//std::cout << "Vec : " << VariableString << " == " << (it_VectorBox_String->second).back() << std::endl;
    }
    else {
	std::cout << "Fill_String Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, vec_b VectorBool){
    if ((it_VectorBox_Bool = VectorBox_Bool.find(VariableName.c_str())) != VectorBox_Bool.end()){
        (it_VectorBox_Bool->second) = VectorBool;
    }
    else {
	std::cout << "Fill_VectorBool Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, vec_i VectorInt){
    if ((it_VectorBox_Int = VectorBox_Int.find(VariableName.c_str())) != VectorBox_Int.end()){
        (it_VectorBox_Int->second) = VectorInt;
    }
    else {
	std::cout << "Fill_VectorInt Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, vec_ui VectorUInt){
    if ((it_VectorBox_UInt = VectorBox_UInt.find(VariableName.c_str())) != VectorBox_UInt.end()){
        (it_VectorBox_UInt->second) = VectorUInt;
    }
    else {
	std::cout << "Fill_VectorUInt Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, vec_f VectorFloat){
    if ((it_VectorBox_Float = VectorBox_Float.find(VariableName.c_str())) != VectorBox_Float.end()){
        (it_VectorBox_Float->second) = VectorFloat;
    }
    else {
	std::cout << "Fill_VectorFloat Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, vec_d VectorDouble){
    if ((it_VectorBox_Double = VectorBox_Double.find(VariableName.c_str())) != VectorBox_Double.end()){
        (it_VectorBox_Double->second) = VectorDouble;
    }
    else {
	std::cout << "Fill_VectorDouble Error : " << VariableName << std::endl;
    }
}

void SSBTreeManager::Fill(st VariableName, vec_s VectorString){
    if ((it_VectorBox_String = VectorBox_String.find(VariableName.c_str())) != VectorBox_String.end()){
        (it_VectorBox_String->second) = VectorString;
    }
    else {
	std::cout << "Fill_VectorString Error : " << VariableName << std::endl;
    }
}

