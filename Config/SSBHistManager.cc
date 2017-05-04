// SSBTMMaker v3.00

#include "SSBHistManager.h"

void SSBHistManager::GetCutStep(std::string input_Channel, std::map<std::string,bool> input_CutStep){
    for(unsigned int i_CutStep=0;i_CutStep<CutStepName.size();++i_CutStep){
        AllCut[input_Channel+"_"+CutStepName[i_CutStep]] = input_CutStep[CutStepName[i_CutStep]];
    }
}

void SSBHistManager::SetWeight(std::string input_Channel, std::string input_Cutstep, double Weight){
    AllWeight[input_Channel+"_"+input_Cutstep] = Weight;
}

void SSBHistManager::CheckData(bool isData){
    DataCheck = isData;
}

void SSBHistManager::Fill(std::string VariableName, bool VariableBool, double Weight ){
    if(DataCheck) Weight = 1.0;
    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistName = VariableName+"_"+AllCutName[i_hist];
        if((it_HistBox = HistBox.find(HistName.c_str())) != HistBox.end()){
            if(AllCut[AllCutName[i_hist]]){
                if(Weight == -1.0){
                    ( HistBox[HistName] )->Fill(VariableBool, AllWeight[AllCutName[i_hist]]);
                else {
                    ( HistBox[HistName] )->Fill(VariableBool, Weight);
                }
            }
        }
        else {
            std::cout << "Fill_Bool Error : " << HistName << std::endl;
        }
    }
}

void SSBHistManager::Fill(std::string VariableName, int VariableInt, double Weight ){
    if(DataCheck) Weight = 1.0;
    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistName = VariableName+"_"+AllCutName[i_hist];
        if ((it_HistBox = HistBox.find(HistName.c_str())) != HistBox.end()){
            if(AllCut[AllCutName[i_hist]]){
                if(Weight == -1.0){
                    ( HistBox[HistName] )->Fill(VariableInt, AllWeight[AllCutName[i_hist]]);
                else {
                    ( HistBox[HistName] )->Fill(VariableInt, Weight);
                }
            }
        }
        else {
            std::cout << "Fill_Int Error : " << HistName << std::endl;
        }
    }
}

void SSBHistManager::Fill(std::string VariableName, unsigned int VariableUInt, double Weight ){
    if(DataCheck) Weight = 1.0;
    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistName = VariableName+"_"+AllCutName[i_hist];
        if ((it_HistBox = HistBox.find(HistName.c_str())) != HistBox.end()){
            if(AllCut[AllCutName[i_hist]]){
                if(Weight == -1.0){
                    ( HistBox[HistName] )->Fill(VariableUInt, AllWeight[AllCutName[i_hist]]);
                else {
                    ( HistBox[HistName] )->Fill(VariableUInt, Weight);
                }
            }
        }
        else {
            std::cout << "Fill_UInt Error : " << HistName << std::endl;
        }
    }
}

void SSBHistManager::Fill(std::string VariableName, float VariableFloat, double Weight ){
    if(DataCheck) Weight = 1.0;
    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistName = VariableName+"_"+AllCutName[i_hist];
        if ((it_HistBox = HistBox.find(HistName.c_str())) != HistBox.end()){
            if(AllCut[AllCutName[i_hist]]){
                if(Weight == -1.0){
                    ( HistBox[HistName] )->Fill(VariableFloat, AllWeight[AllCutName[i_hist]]);
                else {
                    ( HistBox[HistName] )->Fill(VariableFloat, Weight);
                }
            }
        }
        else {
            std::cout << "Fill_Float Error : " << HistName << std::endl;
        }
    }
}

void SSBHistManager::Fill(std::string VariableName, double VariableDouble, double Weight ){
    if(DataCheck) Weight = 1.0;
    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistName = VariableName+"_"+AllCutName[i_hist];
        if ((it_HistBox = HistBox.find(HistName.c_str())) != HistBox.end()){
            if(AllCut[AllCutName[i_hist]]){
                if(Weight == -1.0){
                    ( HistBox[HistName] )->Fill(VariableDouble, AllWeight[AllCutName[i_hist]]);
                else {
                    ( HistBox[HistName] )->Fill(VariableDouble, Weight);
                }
            }
        }
        else {
            std::cout << "Fill_Double Error : " << HistName << std::endl;
        }
    }
}

void SSBHistManager::Fill2D(std::string VariableName, int VariableIntX, int VariableIntY, double Weight ){
    if(DataCheck) Weight = 1.0;
    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistName = VariableName+"_"+AllCutName[i_hist];
        if ((it_HistBox2 = HistBox2.find(HistName.c_str())) != HistBox2.end()){
            if(AllCut[AllCutName[i_hist]]){
                if(Weight == -1.0){
                    ( HistBox2[HistName] )->Fill(VariableIntX, VariableIntY, AllWeight[AllCutName[i_hist]]);
                else {
                    ( HistBox2[HistName] )->Fill(VariableIntX, VariableIntY, Weight);
                }
            }
        }
        else {
            std::cout << "Fill_2D_Int Error : " << HistName << std::endl;
        }
    }
}

void SSBHistManager::Fill2D(std::string VariableName, unsigned int VariableUIntX, unsigned int VariableUIntY, double Weight ){
    if(DataCheck) Weight = 1.0;
    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistName = VariableName+"_"+AllCutName[i_hist];
        if ((it_HistBox2 = HistBox2.find(HistName.c_str())) != HistBox2.end()){
            if(AllCut[AllCutName[i_hist]]){
                if(Weight == -1.0){
                    ( HistBox2[HistName] )->Fill(VariableUIntX, VariableUIntY, AllWeight[AllCutName[i_hist]]);
                else {
                    ( HistBox2[HistName] )->Fill(VariableUIntX, VariableUIntY, Weight);
                }
            }
        }
        else {
            std::cout << "Fill_2D_UInt Error : " << HistName << std::endl;
        }
    }
}

void SSBHistManager::Fill2D(std::string VariableName, float VariableFloatX, int VariableFloatY, double Weight ){
    if(DataCheck) Weight = 1.0;
    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistName = VariableName+"_"+AllCutName[i_hist];
        if ((it_HistBox2 = HistBox2.find(HistName.c_str())) != HistBox2.end()){
            if(AllCut[AllCutName[i_hist]]){
                if(Weight == -1.0){
                    ( HistBox2[HistName] )->Fill(VariableFloatX, VariableFloatY, AllWeight[AllCutName[i_hist]]);
                else {
                    ( HistBox2[HistName] )->Fill(VariableFloatX, VariableFloatY, Weight);
                }
            }
        }
        else {
            std::cout << "Fill_2D_Float Error : " << HistName << std::endl;
        }
    }
}

void SSBHistManager::Fill2D(std::string VariableName, double VariableDoubleX, double VariableDoubleY, double Weight ){
    if(DataCheck) Weight = 1.0;
    for(unsigned int i_hist=0;i_hist<AllCutName.size();++i_hist){
        HistName = VariableName+"_"+AllCutName[i_hist];
        if ((it_HistBox2 = HistBox2.find(HistName.c_str())) != HistBox2.end()){
            if(AllCut[AllCutName[i_hist]]){
                if(Weight == -1.0){
                    ( HistBox2[HistName] )->Fill(VariableDoubleX, VariableDoubleY, AllWeight[AllCutName[i_hist]]);
                else {
                    ( HistBox2[HistName] )->Fill(VariableDoubleX, VariableDoubleY, Weight);
                }
            }
        }
        else {
            std::cout << "Fill_2D_Double Error : " << HistName << std::endl;
        }
    }
}

SSBHistManager::SSBHistManager(std::vector<std::string> Channel, std::vector<std::string> CutStep){

    ChannelName = Channel;
    CutStepName = CutStep;
    AllCutName.clear();
    AllCut.clear();
    AllWeight.clear();
    HistName = "";
    for(unsigned int CutChannelInit=0;CutChannelInit<ChannelName.size();++CutChannelInit){
        for(unsigned int CutStepInit=0;CutStepInit<CutStepName.size();++CutStepInit){
            HistName = ChannelName[CutChannelInit]+"_"+CutStepName[CutStepInit];
            AllCutName.push_back(HistName);
            AllCut[HistName] = false;
        }
    }
    

}

SSBHistManager::~SSBHistManager(){

}

void SSBHistManager::Book(TFileDirectory histdir){

    ssbhist = histdir;

}

