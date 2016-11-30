SSBTreeManager::SSBTreeManager(){

    VariableBox_LorentzVector["GenPar"] = new TClonesArray("TLorentzVector");
    VariableBox_LorentzVector["GenJet"] = new TClonesArray("TLorentzVector");
    VariableBox_LorentzVector["GenTop"] = new TClonesArray("TLorentzVector");
    VariableBox_LorentzVector["Muon"] = new TClonesArray("TLorentzVector");
    VariableBox_LorentzVector["Cut_Muon"] = new TClonesArray("TLorentzVector");
    VariableBox_LorentzVector["Elec"] = new TClonesArray("TLorentzVector");
    VariableBox_LorentzVector["Cut_Elec"] = new TClonesArray("TLorentzVector");
    VariableBox_LorentzVector["Cut_Jet"] = new TClonesArray("TLorentzVector");
    VariableBox_LorentzVector["Jet"] = new TClonesArray("TLorentzVector");
    VariableBox_LorentzVector["MET"] = new TClonesArray("TLorentzVector");

}

SSBTreeManager::~SSBTreeManager(){


}

void SSBTreeManager::Book(TTree* tree){

    ssbtree = tree;
    ssbtree->Branch("Info_EventNumber", &VariableBox_Int["Info_EventNumber"], "Info_EventNumber/I");
    ssbtree->Branch("Info_Luminosity", &VariableBox_Int["Info_Luminosity"], "Info_Luminosity/I");
    ssbtree->Branch("Info_RunNumber", &VariableBox_Int["Info_RunNumber"], "Info_RunNumber/I");
    ssbtree->Branch("Info_isData", &VariableBox_Bool["Info_isData"], "Info_isData/B");
    ssbtree->Branch("Channel_Idx", &VariableBox_Int["Channel_Idx"], "Channel_Idx/I");
    ssbtree->Branch("Channel_Idx_Final", &VariableBox_Int["Channel_Idx_Final"], "Channel_Idx_Final/I");
    ssbtree->Branch("Channel_Jets", &VariableBox_Int["Channel_Jets"], "Channel_Jets/I");
    ssbtree->Branch("Channel_Jets_Abs", &VariableBox_Int["Channel_Jets_Abs"], "Channel_Jets_Abs/I");
    ssbtree->Branch("Channel_Lepton_Count", &VariableBox_Int["Channel_Lepton_Count"], "Channel_Lepton_Count/I");
    ssbtree->Branch("Channel_Lepton_Count_Final", &VariableBox_Int["Channel_Lepton_Count_Final"], "Channel_Lepton_Count_Final/I");
    ssbtree->Branch("Cut_BJet_Count", &VariableBox_Int["Cut_BJet_Count"], "Cut_BJet_Count/I");
    ssbtree->Branch("Cut_Elec", "TClonesArray", &VariableBox_LorentzVector["Cut_Elec"], 32000, 0);
    VariableBox_LorentzVector["Cut_Elec"]->BypassStreamer();
    ssbtree->Branch("Cut_Jet", "TClonesArray", &VariableBox_LorentzVector["Cut_Jet"], 32000, 0);
    VariableBox_LorentzVector["Cut_Jet"]->BypassStreamer();
    ssbtree->Branch("Cut_Jet_Count", &VariableBox_Int["Cut_Jet_Count"], "Cut_Jet_Count/I");
    ssbtree->Branch("Cut_Jet_Index", &VectorBox_Int["Cut_Jet_Index"]);
    ssbtree->Branch("Cut_Jet_bTag", &VectorBox_Bool["Cut_Jet_bTag"]);
    ssbtree->Branch("Cut_Muon", "TClonesArray", &VariableBox_LorentzVector["Cut_Muon"], 32000, 0);
    VariableBox_LorentzVector["Cut_Muon"]->BypassStreamer();
    ssbtree->Branch("Cut_ejet_ElectronVeto", &VariableBox_Bool["Cut_ejet_ElectronVeto"], "Cut_ejet_ElectronVeto/B");
    ssbtree->Branch("Cut_ejet_Lepton", &VariableBox_Bool["Cut_ejet_Lepton"], "Cut_ejet_Lepton/B");
    ssbtree->Branch("Cut_ejet_MuonVeto", &VariableBox_Bool["Cut_ejet_MuonVeto"], "Cut_ejet_MuonVeto/B");
    ssbtree->Branch("Cut_ejet_Step1", &VariableBox_Bool["Cut_ejet_Step1"], "Cut_ejet_Step1/B");
    ssbtree->Branch("Cut_ejet_Step2a", &VariableBox_Bool["Cut_ejet_Step2a"], "Cut_ejet_Step2a/B");
    ssbtree->Branch("Cut_ejet_Step2b", &VariableBox_Bool["Cut_ejet_Step2b"], "Cut_ejet_Step2b/B");
    ssbtree->Branch("Cut_ejet_Trigger", &VariableBox_Bool["Cut_ejet_Trigger"], "Cut_ejet_Trigger/B");
    ssbtree->Branch("Cut_mjet_ElectronVeto", &VariableBox_Bool["Cut_mjet_ElectronVeto"], "Cut_mjet_ElectronVeto/B");
    ssbtree->Branch("Cut_mjet_Lepton", &VariableBox_Bool["Cut_mjet_Lepton"], "Cut_mjet_Lepton/B");
    ssbtree->Branch("Cut_mjet_MuonVeto", &VariableBox_Bool["Cut_mjet_MuonVeto"], "Cut_mjet_MuonVeto/B");
    ssbtree->Branch("Cut_mjet_Step1", &VariableBox_Bool["Cut_mjet_Step1"], "Cut_mjet_Step1/B");
    ssbtree->Branch("Cut_mjet_Step2a", &VariableBox_Bool["Cut_mjet_Step2a"], "Cut_mjet_Step2a/B");
    ssbtree->Branch("Cut_mjet_Step2b", &VariableBox_Bool["Cut_mjet_Step2b"], "Cut_mjet_Step2b/B");
    ssbtree->Branch("Cut_mjet_Trigger", &VariableBox_Bool["Cut_mjet_Trigger"], "Cut_mjet_Trigger/B");
    ssbtree->Branch("Elec", "TClonesArray", &VariableBox_LorentzVector["Elec"], 32000, 0);
    VariableBox_LorentzVector["Elec"]->BypassStreamer();
    ssbtree->Branch("Elec_Charge", &VectorBox_Int["Elec_Charge"]);
    ssbtree->Branch("Elec_Conversion", &VectorBox_Bool["Elec_Conversion"]);
    ssbtree->Branch("Elec_Count", &VariableBox_Int["Elec_Count"], "Elec_Count/I");
    ssbtree->Branch("Elec_Cut_Isolated", &VectorBox_Bool["Elec_Cut_Isolated"]);
    ssbtree->Branch("Elec_Cut_Veto", &VectorBox_Bool["Elec_Cut_Veto"]);
    ssbtree->Branch("Elec_PFIsodBeta03", &VectorBox_Double["Elec_PFIsodBeta03"]);
    ssbtree->Branch("Elec_Supercluster_Eta", &VectorBox_Double["Elec_Supercluster_Eta"]);
    ssbtree->Branch("Elec_isIsoID", &VectorBox_Bool["Elec_isIsoID"]);
    ssbtree->Branch("Elec_isVetoID", &VectorBox_Bool["Elec_isVetoID"]);
    ssbtree->Branch("Elec_pdgId", &VectorBox_Int["Elec_pdgId"]);
    ssbtree->Branch("GenJet", "TClonesArray", &VariableBox_LorentzVector["GenJet"], 32000, 0);
    VariableBox_LorentzVector["GenJet"]->BypassStreamer();
    ssbtree->Branch("GenJet_Count", &VariableBox_Int["GenJet_Count"], "GenJet_Count/I");
    ssbtree->Branch("GenJet_ECalEnergy", &VectorBox_Float["GenJet_ECalEnergy"]);
    ssbtree->Branch("GenJet_HCalEnergy", &VectorBox_Float["GenJet_HCalEnergy"]);
    ssbtree->Branch("GenPar", "TClonesArray", &VariableBox_LorentzVector["GenPar"], 32000, 0);
    VariableBox_LorentzVector["GenPar"]->BypassStreamer();
    ssbtree->Branch("GenPar_Count", &VariableBox_Int["GenPar_Count"], "GenPar_Count/I");
    ssbtree->Branch("GenPar_Dau1_Idx", &VectorBox_Int["GenPar_Dau1_Idx"]);
    ssbtree->Branch("GenPar_Dau2_Idx", &VectorBox_Int["GenPar_Dau2_Idx"]);
    ssbtree->Branch("GenPar_Dau_Counter", &VectorBox_Int["GenPar_Dau_Counter"]);
    ssbtree->Branch("GenPar_Idx", &VectorBox_Int["GenPar_Idx"]);
    ssbtree->Branch("GenPar_Mom1_Idx", &VectorBox_Int["GenPar_Mom1_Idx"]);
    ssbtree->Branch("GenPar_Mom2_Idx", &VectorBox_Int["GenPar_Mom2_Idx"]);
    ssbtree->Branch("GenPar_Mom_Counter", &VectorBox_Int["GenPar_Mom_Counter"]);
    ssbtree->Branch("GenPar_Status", &VectorBox_Int["GenPar_Status"]);
    ssbtree->Branch("GenPar_pdgId", &VectorBox_Int["GenPar_pdgId"]);
    ssbtree->Branch("GenTop", "TClonesArray", &VariableBox_LorentzVector["GenTop"], 32000, 0);
    VariableBox_LorentzVector["GenTop"]->BypassStreamer();
    ssbtree->Branch("Jet", "TClonesArray", &VariableBox_LorentzVector["Jet"], 32000, 0);
    VariableBox_LorentzVector["Jet"]->BypassStreamer();
    ssbtree->Branch("Jet_Count", &VariableBox_Int["Jet_Count"], "Jet_Count/I");
    ssbtree->Branch("Jet_bDisc", &VectorBox_Double["Jet_bDisc"]);
    ssbtree->Branch("Jet_cDiscCvsB", &VectorBox_Double["Jet_cDiscCvsB"]);
    ssbtree->Branch("Jet_cDiscCvsL", &VectorBox_Double["Jet_cDiscCvsL"]);
    ssbtree->Branch("Jet_isCleanedJet", &VectorBox_Bool["Jet_isCleanedJet"]);
    ssbtree->Branch("Jet_isJetID", &VectorBox_Bool["Jet_isJetID"]);
    ssbtree->Branch("MET", "TClonesArray", &VariableBox_LorentzVector["MET"], 32000, 0);
    VariableBox_LorentzVector["MET"]->BypassStreamer();
    ssbtree->Branch("Muon", "TClonesArray", &VariableBox_LorentzVector["Muon"], 32000, 0);
    VariableBox_LorentzVector["Muon"]->BypassStreamer();
    ssbtree->Branch("Muon_Charge", &VectorBox_Int["Muon_Charge"]);
    ssbtree->Branch("Muon_Count", &VariableBox_Int["Muon_Count"], "Muon_Count/I");
    ssbtree->Branch("Muon_Cut_Isolated", &VectorBox_Bool["Muon_Cut_Isolated"]);
    ssbtree->Branch("Muon_Cut_Veto", &VectorBox_Bool["Muon_Cut_Veto"]);
    ssbtree->Branch("Muon_PFIsodBeta04", &VectorBox_Double["Muon_PFIsodBeta04"]);
    ssbtree->Branch("Muon_isIsoID", &VectorBox_Bool["Muon_isIsoID"]);
    ssbtree->Branch("Muon_isVetoID", &VectorBox_Bool["Muon_isVetoID"]);
    ssbtree->Branch("Muon_pdgId", &VectorBox_Int["Muon_pdgId"]);
    ssbtree->Branch("PV_Count", &VariableBox_Int["PV_Count"], "PV_Count/I");

}

void SSBTreeManager::InitializeVariables(){

    VariableBox_Int["Info_EventNumber"] = 0;
    VariableBox_Int["Info_Luminosity"] = 0;
    VariableBox_Int["Info_RunNumber"] = 0;
    VariableBox_Bool["Info_isData"] = false;
    VariableBox_Int["Channel_Idx"] = 0;
    VariableBox_Int["Channel_Idx_Final"] = 0;
    VariableBox_Int["Channel_Jets"] = 0;
    VariableBox_Int["Channel_Jets_Abs"] = 0;
    VariableBox_Int["Channel_Lepton_Count"] = 0;
    VariableBox_Int["Channel_Lepton_Count_Final"] = 0;
    VariableBox_Int["Cut_BJet_Count"] = 0;
    VariableBox_LorentzVector["Cut_Elec"]->Clear();
    VariableBox_LorentzVector["Cut_Jet"]->Clear();
    VariableBox_Int["Cut_Jet_Count"] = 0;
    VectorBox_Int["Cut_Jet_Index"].clear();
    VectorBox_Bool["Cut_Jet_bTag"].clear();
    VariableBox_LorentzVector["Cut_Muon"]->Clear();
    VariableBox_Bool["Cut_ejet_ElectronVeto"] = false;
    VariableBox_Bool["Cut_ejet_Lepton"] = false;
    VariableBox_Bool["Cut_ejet_MuonVeto"] = false;
    VariableBox_Bool["Cut_ejet_Step1"] = false;
    VariableBox_Bool["Cut_ejet_Step2a"] = false;
    VariableBox_Bool["Cut_ejet_Step2b"] = false;
    VariableBox_Bool["Cut_ejet_Trigger"] = false;
    VariableBox_Bool["Cut_mjet_ElectronVeto"] = false;
    VariableBox_Bool["Cut_mjet_Lepton"] = false;
    VariableBox_Bool["Cut_mjet_MuonVeto"] = false;
    VariableBox_Bool["Cut_mjet_Step1"] = false;
    VariableBox_Bool["Cut_mjet_Step2a"] = false;
    VariableBox_Bool["Cut_mjet_Step2b"] = false;
    VariableBox_Bool["Cut_mjet_Trigger"] = false;
    VariableBox_LorentzVector["Elec"]->Clear();
    VectorBox_Int["Elec_Charge"].clear();
    VectorBox_Bool["Elec_Conversion"].clear();
    VariableBox_Int["Elec_Count"] = 0;
    VectorBox_Bool["Elec_Cut_Isolated"].clear();
    VectorBox_Bool["Elec_Cut_Veto"].clear();
    VectorBox_Double["Elec_PFIsodBeta03"].clear();
    VectorBox_Double["Elec_Supercluster_Eta"].clear();
    VectorBox_Bool["Elec_isIsoID"].clear();
    VectorBox_Bool["Elec_isVetoID"].clear();
    VectorBox_Int["Elec_pdgId"].clear();
    VariableBox_LorentzVector["GenJet"]->Clear();
    VariableBox_Int["GenJet_Count"] = 0;
    VectorBox_Float["GenJet_ECalEnergy"].clear();
    VectorBox_Float["GenJet_HCalEnergy"].clear();
    VariableBox_LorentzVector["GenPar"]->Clear();
    VariableBox_Int["GenPar_Count"] = 0;
    VectorBox_Int["GenPar_Dau1_Idx"].clear();
    VectorBox_Int["GenPar_Dau2_Idx"].clear();
    VectorBox_Int["GenPar_Dau_Counter"].clear();
    VectorBox_Int["GenPar_Idx"].clear();
    VectorBox_Int["GenPar_Mom1_Idx"].clear();
    VectorBox_Int["GenPar_Mom2_Idx"].clear();
    VectorBox_Int["GenPar_Mom_Counter"].clear();
    VectorBox_Int["GenPar_Status"].clear();
    VectorBox_Int["GenPar_pdgId"].clear();
    VariableBox_LorentzVector["GenTop"]->Clear();
    VariableBox_LorentzVector["Jet"]->Clear();
    VariableBox_Int["Jet_Count"] = 0;
    VectorBox_Double["Jet_bDisc"].clear();
    VectorBox_Double["Jet_cDiscCvsB"].clear();
    VectorBox_Double["Jet_cDiscCvsL"].clear();
    VectorBox_Bool["Jet_isCleanedJet"].clear();
    VectorBox_Bool["Jet_isJetID"].clear();
    VariableBox_LorentzVector["MET"]->Clear();
    VariableBox_LorentzVector["Muon"]->Clear();
    VectorBox_Int["Muon_Charge"].clear();
    VariableBox_Int["Muon_Count"] = 0;
    VectorBox_Bool["Muon_Cut_Isolated"].clear();
    VectorBox_Bool["Muon_Cut_Veto"].clear();
    VectorBox_Double["Muon_PFIsodBeta04"].clear();
    VectorBox_Bool["Muon_isIsoID"].clear();
    VectorBox_Bool["Muon_isVetoID"].clear();
    VectorBox_Int["Muon_pdgId"].clear();
    VariableBox_Int["PV_Count"] = 0;

}

void SSBTreeManager::GenBook(TTree* tree){

    ssbtree = tree;
    ssbtree->Branch("Info_EventNumber", &VariableBox_Int["Info_EventNumber"], "Info_EventNumber/I");
    ssbtree->Branch("Info_Luminosity", &VariableBox_Int["Info_Luminosity"], "Info_Luminosity/I");
    ssbtree->Branch("Info_RunNumber", &VariableBox_Int["Info_RunNumber"], "Info_RunNumber/I");
    ssbtree->Branch("Info_isData", &VariableBox_Bool["Info_isData"], "Info_isData/B");
    ssbtree->Branch("Channel_Idx", &VariableBox_Int["Channel_Idx"], "Channel_Idx/I");
    ssbtree->Branch("Channel_Idx_Final", &VariableBox_Int["Channel_Idx_Final"], "Channel_Idx_Final/I");
    ssbtree->Branch("Channel_Jets", &VariableBox_Int["Channel_Jets"], "Channel_Jets/I");
    ssbtree->Branch("Channel_Jets_Abs", &VariableBox_Int["Channel_Jets_Abs"], "Channel_Jets_Abs/I");
    ssbtree->Branch("Channel_Lepton_Count", &VariableBox_Int["Channel_Lepton_Count"], "Channel_Lepton_Count/I");
    ssbtree->Branch("Channel_Lepton_Count_Final", &VariableBox_Int["Channel_Lepton_Count_Final"], "Channel_Lepton_Count_Final/I");
    ssbtree->Branch("GenJet", "TClonesArray", &VariableBox_LorentzVector["GenJet"], 32000, 0);
    VariableBox_LorentzVector["GenJet"]->BypassStreamer();
    ssbtree->Branch("GenJet_Count", &VariableBox_Int["GenJet_Count"], "GenJet_Count/I");
    ssbtree->Branch("GenJet_ECalEnergy", &VectorBox_Float["GenJet_ECalEnergy"]);
    ssbtree->Branch("GenJet_HCalEnergy", &VectorBox_Float["GenJet_HCalEnergy"]);
    ssbtree->Branch("GenPar", "TClonesArray", &VariableBox_LorentzVector["GenPar"], 32000, 0);
    VariableBox_LorentzVector["GenPar"]->BypassStreamer();
    ssbtree->Branch("GenPar_Count", &VariableBox_Int["GenPar_Count"], "GenPar_Count/I");
    ssbtree->Branch("GenPar_Dau1_Idx", &VectorBox_Int["GenPar_Dau1_Idx"]);
    ssbtree->Branch("GenPar_Dau2_Idx", &VectorBox_Int["GenPar_Dau2_Idx"]);
    ssbtree->Branch("GenPar_Dau_Counter", &VectorBox_Int["GenPar_Dau_Counter"]);
    ssbtree->Branch("GenPar_Idx", &VectorBox_Int["GenPar_Idx"]);
    ssbtree->Branch("GenPar_Mom1_Idx", &VectorBox_Int["GenPar_Mom1_Idx"]);
    ssbtree->Branch("GenPar_Mom2_Idx", &VectorBox_Int["GenPar_Mom2_Idx"]);
    ssbtree->Branch("GenPar_Mom_Counter", &VectorBox_Int["GenPar_Mom_Counter"]);
    ssbtree->Branch("GenPar_Status", &VectorBox_Int["GenPar_Status"]);
    ssbtree->Branch("GenPar_pdgId", &VectorBox_Int["GenPar_pdgId"]);
    ssbtree->Branch("GenTop", "TClonesArray", &VariableBox_LorentzVector["GenTop"], 32000, 0);
    VariableBox_LorentzVector["GenTop"]->BypassStreamer();

}

void SSBTreeManager::GenInitializeVariables(){

    VariableBox_Int["Info_EventNumber"] = 0;
    VariableBox_Int["Info_Luminosity"] = 0;
    VariableBox_Int["Info_RunNumber"] = 0;
    VariableBox_Bool["Info_isData"] = false;
    VariableBox_Int["Channel_Idx"] = 0;
    VariableBox_Int["Channel_Idx_Final"] = 0;
    VariableBox_Int["Channel_Jets"] = 0;
    VariableBox_Int["Channel_Jets_Abs"] = 0;
    VariableBox_Int["Channel_Lepton_Count"] = 0;
    VariableBox_Int["Channel_Lepton_Count_Final"] = 0;
    VariableBox_LorentzVector["GenJet"]->Clear();
    VariableBox_Int["GenJet_Count"] = 0;
    VectorBox_Float["GenJet_ECalEnergy"].clear();
    VectorBox_Float["GenJet_HCalEnergy"].clear();
    VariableBox_LorentzVector["GenPar"]->Clear();
    VariableBox_Int["GenPar_Count"] = 0;
    VectorBox_Int["GenPar_Dau1_Idx"].clear();
    VectorBox_Int["GenPar_Dau2_Idx"].clear();
    VectorBox_Int["GenPar_Dau_Counter"].clear();
    VectorBox_Int["GenPar_Idx"].clear();
    VectorBox_Int["GenPar_Mom1_Idx"].clear();
    VectorBox_Int["GenPar_Mom2_Idx"].clear();
    VectorBox_Int["GenPar_Mom_Counter"].clear();
    VectorBox_Int["GenPar_Status"].clear();
    VectorBox_Int["GenPar_pdgId"].clear();
    VariableBox_LorentzVector["GenTop"]->Clear();

}

