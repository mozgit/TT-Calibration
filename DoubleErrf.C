Double_t DoubleErrf(Double_t *y, Double_t *par) 
{
  mu=par[0];
  sigma=par[1];
  x=y[0];
  Double_t pi=acos(-1);
  Double_t a=-8*(pi-3)/(3*pi*(pi-4));
  Double_t t1 = (x-mu)/sqrt(2*sigma);
  Double_t t2 = (x+mu)/sqrt(2*sigma);
  return par[2]*0.5*(tanh(77*t1/75+116/25*tanh(147*t1/73-76/7*tanh(51*t1/278)))+tanh(77*t2/75+116/25*tanh(147*t2/73-76/7*tanh(51*t2/278))));
 } 