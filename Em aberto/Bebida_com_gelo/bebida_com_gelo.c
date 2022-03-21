#include <stdio.h>

#define cw 4.19
#define ci 2.09
#define em 335

double mod(double x)
{
    if(x > 0) return x;
    return -x;
}

double dist0Degrees(double c, double t, double m){
    double energy = c * m * t;
    return mod(energy);
}

int main(){

    double mw, mi, tw, ti, energyToChangeState;
    double energia;
    double ew, ei, deltaE, deltaM, temp;

    scanf("%lf %lf %lf %lf", &mw, &mi, &tw, &ti);
    while(!(mw == 0 && mi == 0 && tw == 0 && ti == 0))
    {
        //energyToChangeState = ;
        ew = dist0Degrees(cw, tw, mw);
        ei = dist0Degrees(ci, ti, mi);
        
        deltaE = mod(ew - ei);
        deltaM = deltaE / em;

        // Parte do gelo vira agua (talvez)
        if(ew > ei){
            if(deltaM > mi){
                deltaE -= mi * em;
                mw = mw + mi;
                mi = 0;
                temp = deltaE / (mw*cw);
            }else{
                temp = 0;
                mw = mw + deltaM;
                mi = mi - deltaM;
            }
        } 
        // Parte da agua vira gelo
        else {
            if(deltaM > mw){
                deltaE -= mw * em;
                mi = mi + mw;
                mw = 0;
                temp = - deltaE / (mi * ci);
            }else{
                temp = 0;
                mw = mw - deltaM;
                mi = mi + deltaM;
            }
        }
        
        printf("%.1f g of ice and %.1f of water at %.1f C\n", mi, mw, temp);
        
        scanf("%lf %lf %lf %lf", &mw, &mi, &tw, &ti);
    }

    return 0;
}