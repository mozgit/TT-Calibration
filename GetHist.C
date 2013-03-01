{
	
TFile* f1 = new TFile("~/Documents/TT-Calibration/STTrackMonitor-HitEfficiency-D0-2012-Window_0_3mm-NbRes_NoCut-SingleHitPerSector_0_5mm-Edges_2mm-ITExp_6-TTExp_2-GhostProb_0_3-P_NoCut_HIGHSTAT.root");
TH1D* hist = (TH1D*)f1->Get("Track/ITHitEfficiency/perSector/NbFoundHits_IT1CSideX1Sector1");

}