// SSBTMMaker v3.000

#ifndef SSBHistManager_h
#define SSBHistManager_h 

#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include <vector>
#include <map>
#include <iostream>
#include <TROOT.h>
#include "TFile.h"
#include "TDirectory.h"
#include "TMath.h"
#include "TH1D.h"
#include "TH2D.h"


class SSBHistManager
{

    typedef std::map<std::string, TH1D*>                 map_hist;
    typedef std::map<std::string, TH2D*>                 map_hist2;
    typedef std::map<std::string, TH1D*>::iterator       map_hist_it;
    typedef std::map<std::string, TH2D*>::iterator       map_hist2_it;

    map_hist     HistBox;
    map_hist_it  it_HistBox;
    map_hist2    HistBox2;
    map_hist2_it it_HistBox2;

public:

    SSBHistManager(std::vector<std::string>,std::vector<std::string>);
    ~SSBHistManager();

    void Book(TFileDirectory);
    void InitializeHist();

    void FillHist();

    void Fill(std::string, bool, double Weight=-1.0);
    void Fill(std::string, int, double Weight=-1.0);
    void Fill(std::string, unsigned int, double Weight=-1.0);
    void Fill(std::string, float, double Weight=-1.0);
    void Fill(std::string, double, double Weight=-1.0);
    void Fill2D(std::string, int, int, double Weight=-1.0);
    void Fill2D(std::string, unsigned int, unsigned int, double Weight=-1.0);
    void Fill2D(std::string, float, float, double Weight=-1.0);
    void Fill2D(std::string, double, double, double Weight=-1.0);

    void GetCutStep(std::string, std::map<std::string,bool>);
    void SetWeight(std::string, std::string, double)
    void CheckData(bool);

private:

    TFileDirectory ssbhist;
    std::vector<std::string> ChannelName;
    std::vector<std::string> CutStepName;
    std::vector<std::string> AllCutName;
    std::map<std::string,bool> AllCut;
    std::map<std::string,double> AllWeight;
    std::string HistName;
    bool DataCheck;

};

#endif
