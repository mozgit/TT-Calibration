void FitHist(Double_t * d, char * path)
{

TH1D* hist = GetHist(path);
if (hist == NULL )
	{
		d[0]=-1;
	    d[1]=-1;
		d[2]=-1;
		return;
	}
TF1 *func = new TF1 ("fit",DoubleErrf,hist->GetXaxis()->GetXmin(),hist->GetXaxis()->GetXmax(),3);
func->SetParameters(0.,0.1,hist->GetEntries());
func->SetParNames ("Mean_value","Sigma","N");
hist->Fit("fit","Q");
//Double_t d[2];
d[0]=func->GetParameter(0);
d[1]=func->GetParameter(1);
d[2]=func->GetParameter(2);
//return d;
//cout<<endl<<"for "<<path<<endl<<"mean = "<<func->GetParameter(0)<<endl<<"sigma = "<<func->GetParameter(1)<<endl;
}