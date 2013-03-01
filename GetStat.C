{
#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include <string.h>
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "RooPlot.h"
#include "RooClassFactory.h"
#include "TROOT.h"
#include "GetHist.h"
#include "DoubleErrf.C"
#include "FitHist.C"	
//                                              NbFoundHits_IT1CSideX1Sector1
//char* address = "Track/ITHitEfficiency/perSector/NbFoundHits_IT1BottomX2Sector7";
Double_t d[3];
//FitHist(d, address);
//cout<<endl<<"for "<<address<<endl<<"Shift = "<<d[0]<<endl<<"Sigma = "<<d[1]<<endl;
//}

//char* list []={"BDT_MVA","BpT","BangBd","Bvchi2","KstpT","JPsipT","KstEta","JPsiEta","Mu1mipCHI2PV","Mu2mipCHI2PV","RhopT","PippT","PimpT","Mu1pT","Mu2pT","BmipCHI2PV"};

char *tuple = "Track/ITHitEfficiency/perSector/";
char *prenom = "NbFoundHits_IT";
char *nIT [] = {"1","2","3"};
char *Side [] = {"CSide","ASide","Bottom","Top"};
char *nX [] = {"X1", "U", "V", "X2"};
char *sector = "Sector";
char *nSector []= {"1","2","3","4","5","6","7"};
for (Int_t i_nIT=0;i_nIT<sizeof(nIT)/sizeof(*nIT);i_nIT++)
{
	for (Int_t i_Side=0;i_Side<sizeof(Side)/sizeof(*Side);i_Side++)
	{
		for (Int_t i_nX=0;i_nX<sizeof(nX)/sizeof(*nX);i_nX++)
		{
			for (Int_t i_nSector=0;i_nSector<sizeof(nSector)/sizeof(*nSector);i_nSector++)
			{
				char *path = new char[strlen(prenom) + strlen(nIT[i_nIT]) + strlen(Side[i_Side]) + strlen(nX[i_nX]) + strlen(sector) + strlen(nSector[i_nSector]) +1];
				//strcat(path, tuple);
				strcat(path, prenom);
				strcat(path, nIT[i_nIT]);
				strcat(path, Side[i_Side]);
				strcat(path, nX[i_nX]);
				strcat(path, sector);
				strcat(path, nSector[i_nSector]);

				if (path != "NbFoundHits_IT1BottomX2Sector7") {


				cout<<endl<<"for "<<path<<endl;
				//cout<<path<<endl;
				char *address = new char[strlen(tuple) + strlen(path) + 1];
				strcat(address, tuple);
				strcat(address, path);
				//cout<<address<<"!!!!!"<<endl;
				FitHist(d, address);
				cout<<"Shift = "<<d[0]<<endl<<"Sigma = "<<d[1]<<endl;
			}
			}
		}
	}
}


//Double_t* d=FitHist();



}
