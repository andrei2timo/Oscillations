#include <iostream>
#include <cmath>
#include <graphics.h>
#include <cstdio>
#include <cstring>
using namespace std;

char *elongatie="elongatie.jpg";
char *timp="timp.jpg";
float A,A1,A2,w,phi01,phi02,phi0,pi=3.141592,T;
char sir[50];
char caracter,numar1[20],numar2[20],numar3[20],numar4[20],numar5[20],numar6[20];
int Lungimea=GetSystemMetrics(0)-(GetSystemMetrics(0)/5);
int Latimea=GetSystemMetrics(1)-(GetSystemMetrics(1)/5);
int jjj;
float rap=((11.0/Lungimea)*Latimea)/2;
int p1=1;
int p2=1;
void calcule()
{
    A=pow(A1*A1+A2*A2+2*A1*A2*cos(abs(phi01-phi02)),(1.0/2));
    phi0=atan((A1*sin(phi01)+A2*sin(phi02))/(A1*cos(phi01)+A2*cos(phi02)));
    T=2.0*pi/w;
}



void sirurare2()
{
    int ook=0;
    for(int i=strlen(sir)-1; i>=1,ook==0; i--)
        if(sir[i]=='.')
        {
            ook=1;
            sir[i+3]='\0';
        }
}
void sirurare()
{
    int ook=0;
    for(int i=strlen(sir)-1; i>=1,ook==0; i--)
        if(sir[i]!='0')
        {
            sir[i+1]='\0';
            ook=1;
            if(sir[i]=='.')
                sir[i]='\0';
            else
                sirurare2();
        }
}

void sirurare3()
{
    int ook=0;
    for(int i=strlen(sir)-1; i>=1,ook==0; i--)
        if(sir[i]!='0')
        {
            sir[i+1]='\0';
            ook=1;
            if(sir[i]=='.')
                sir[i]='\0';
        }
}

void desenare_grafic()
{
    setcolor(9);
    rectangle(-10,-10,Lungimea,Latimea);
    floodfill(20,20,9);
    setcolor(BLACK);
    for(int i=0; i<=1; i++)
    {
        line(0,Latimea/2+i,Lungimea,Latimea/2+i);
        line(80+i,0,75+i,10);
        line(80+i,0,85+i,10);
        line(Lungimea,Latimea/2+i,Lungimea-10,Latimea/2-5+i);
        line(Lungimea,Latimea/2+i,Lungimea-10,Latimea/2+5+i);
    }




    setlinestyle(1,1,1);
    for(int j=0; j<=rap; j++)
    {
        if(j<=rap-1)

            line(80,Latimea/2+j*(Lungimea/11),Lungimea,Latimea/2+j*(Lungimea/11));
        line(80,Latimea/2-j*(Lungimea/11),Lungimea,Latimea/2-j*(Lungimea/11));
        jjj=j;
    }
    jjj=jjj-1;
    for(int j=0; j<=10-1; j++)
        line(80+(j*(Lungimea/11)),0,80+(j*(Lungimea/11)),Latimea/2+jjj*(Lungimea/11));

    setlinestyle(0,1,1);
    line(80,0,80,Latimea/2+jjj*(Lungimea/11));
    line(81,0,81,Latimea/2+jjj*(Lungimea/11));

    for(int j=0; j<=10-1; j++)
        line(80+(j*(Lungimea/11)),Latimea/2-10,80+(j*(Lungimea/11)),Latimea/2+10);
    for(int j=0; j<=rap-1; j++)
    {
        line(70,Latimea/2+j*(Lungimea/11),90,Latimea/2+j*(Lungimea/11));
        line(70,Latimea/2-j*(Lungimea/11),90,Latimea/2-j*(Lungimea/11));
    }
}


void afisare_numere_pe_grafic()
{
    setcolor(COLOR(30,30,30));
    setbkcolor(WHITE);
    settextstyle(0,HORIZ_DIR,1);


    float Tprim=T;
    float Aprim=A;
    for(int i=1; i<=3; i++)
    {
        while(Tprim>1)
        {
            Tprim=Tprim/5.0;
            p1=p1*5;
        }
        for(int j=1; j<=10-1; j++)
        {
            if(T<1)
            {
                sprintf(sir,"%f",float(j*T));
                sirurare();
            }
            else
                sprintf(sir,"%d",j*p1/5);
            outtextxy(80+(j*(Lungimea/11))-(strlen(sir)*4),Latimea/2+10,sir);
        }





        while(Aprim>1)
        {
            Aprim=Aprim/2.0;
            p2=p2*2;
        }
        for(int j=1; j<=rap-1; j++)
        {
            if(A>-1 && A<1)
            {
                sprintf(sir,"-%f",float(j*A));
                sirurare();
            }
            else
                sprintf(sir,"-%d",j*p2/2);
            outtextxy(80-(strlen(sir)*8+16),Latimea/2+j*(Lungimea/11)-7,sir);
            if(A>-1 && A<1)
            {
                sprintf(sir,"%f",float(j*A));
                sirurare();
            }
            else
                sprintf(sir,"%d",j*p2/2);
            outtextxy(80-(strlen(sir)*8+16),Latimea/2-j*(Lungimea/11)-7,sir);
        }

    }
}


void afisare_ecuatie_oscilatie_compusa()
{
    char fct[100];
    strcpy(fct,"x1(t)= ");
    sprintf(sir,"%f",A1);
    sirurare();
    sirurare();
    strcat(fct,sir);
    strcat(fct,"*sin(");
    sprintf(sir,"%f",w);
    sirurare();
    sirurare();
    strcat(fct,sir);
    strcat(fct,"*t+");
    sprintf(sir,"%f",phi01);
    sirurare();
    sirurare();
    strcat(fct,sir);
    strcat(fct,")");
    settextstyle(4,HORIZ_DIR,3);
    setcolor(2);
    outtextxy(Lungimea/2*0,Latimea-90,fct);
    strcpy(fct,"x2(t)= ");
    sprintf(sir,"%f",A2);
    sirurare();
    sirurare();
    strcat(fct,sir);
    strcat(fct,"*sin(");
    sprintf(sir,"%f",w);
    sirurare();
    sirurare();
    strcat(fct,sir);
    strcat(fct,"*t+");
    sprintf(sir,"%f",phi02);
    sirurare();
    sirurare();
    strcat(fct,sir);
    strcat(fct,")");
    settextstyle(4,HORIZ_DIR,3);
    setcolor(5);
    outtextxy(Lungimea/2*1,Latimea-90,fct);
    strcpy(fct,"x(t)= ");
    sprintf(sir,"%f",A);
    sirurare();
    sirurare();
    strcat(fct,sir);
    strcat(fct,"*sin(");
    sprintf(sir,"%f",w);
    sirurare();
    sirurare();
    strcat(fct,sir);
    strcat(fct,"*t+");
    sprintf(sir,"%f",phi0);
    sirurare();
    sirurare();
    strcat(fct,sir);
    strcat(fct,")");
    settextstyle(4,HORIZ_DIR,3);
    setcolor(BLUE);
    outtextxy(Lungimea/3*1,Latimea-45,fct);
    setcolor(BLACK);
    settextstyle(0,HORIZ_DIR,1);
}

void citeste_imaginile()
{
    for(int i=1; i<=3; i++)
    {
        readimagefile(elongatie,80-2*133/(Lungimea/100),10,80-133/(Lungimea/100),543/(Lungimea/100));
        readimagefile(timp,80+(10*(Lungimea/11))-295/(Lungimea/100),Latimea/2+Lungimea/100,80+(10*(Lungimea/11)),Latimea/2+Lungimea/100+116/(Lungimea/100));
    }
}

void desenare_oscilatie_compusa()
{
    float x1x,x1y,x2x,x2y;
    float arg,arg2;
    float Lungimea_float=Lungimea;
    delay(3000);
    setcolor(2);




    if(T>=1 && A1>=1)
        for(int j=1; j<=(11*p1*(Lungimea-80))/5; j++)
        {

            arg=((j-1)/11)/(p1/5);
            arg2=((A1*sin(w*(float((j-1)/Lungimea_float))+phi01))*(Lungimea_float/11))/(p2/2);
            x1x=80+arg;
            x1y=Latimea/2-arg2;
            arg=(j/11)/(p1/5);
            arg2=((A1*sin(w*(float(j/Lungimea_float))+phi01))*(Lungimea_float/11))/(p2/2);
            x2x=80+arg;
            x2y=Latimea/2-arg2;
            line(x1x,x1y,x2x,x2y);

        }
    if(T>=1 && A1>0 && A1<1)
        for(int j=1; j<=(11*p1*(Lungimea-80))/5; j++)
        {
            arg=((j-1)/11)/(p1/5);
            arg2=((A1*sin(w*(float((j-1)/Lungimea_float))+phi01))*(Lungimea_float/11))/(float(A1));
            x1x=80+arg;
            x1y=Latimea/2-arg2;
            arg=(j/11)/(p1/5);
            arg2=((A1*sin(w*(float(j/Lungimea_float))+phi01))*(Lungimea_float/11))/(float(A1));
            x2x=80+arg;
            x2y=Latimea/2-arg2;
            line(x1x,x1y,x2x,x2y);

        }
    if(T>0 && T<1 && A1>=1)
        for(int j=1; j<=11*T*(Lungimea-80); j++)
        {

            arg=((j-1)/11)/(float(T));
            arg2=((A1*sin(w*(float((j-1)/Lungimea_float))+phi01))*(Lungimea_float/11))/(p2/2);
            x1x=80+arg;
            x1y=Latimea/2-arg2;
            arg=(j/11)/(float(T));
            arg2=((A1*sin(w*(float(j/Lungimea_float))+phi01))*(Lungimea_float/11))/(p2/2);
            x2x=80+arg;
            x2y=Latimea/2-arg2;
            line(x1x,x1y,x2x,x2y);

        }
    if(T>0 && T<1 && A1>0 && A1<1)
        for(int j=1; j<=11*T*(Lungimea-80); j++)
        {

            arg=((j-1)/11)/(float(T));
            arg2=((A1*sin(w*(float((j-1)/Lungimea_float))+phi01))*(Lungimea_float/11))/(float(A1));
            x1x=80+arg;
            x1y=Latimea/2-arg2;
            arg=(j/11)/(float(T));
            arg2=((A1*sin(w*(float(j/Lungimea_float))+phi01))*(Lungimea_float/11))/(float(A1));
            x2x=80+arg;
            x2y=Latimea/2-arg2;
            line(x1x,x1y,x2x,x2y);

        }




    setcolor(5);
    if(T>=1 && A2>=1)
        for(int j=1; j<=(11*p1*(Lungimea-80))/5; j++)
        {

            arg=((j-1)/11)/(p1/5);
            arg2=((A2*sin(w*(float((j-1)/Lungimea_float))+phi02))*(Lungimea_float/11))/(p2/2);
            x1x=80+arg;
            x1y=Latimea/2-arg2;
            arg=(j/11)/(p1/5);
            arg2=((A2*sin(w*(float(j/Lungimea_float))+phi02))*(Lungimea_float/11))/(p2/2);
            x2x=80+arg;
            x2y=Latimea/2-arg2;
            line(x1x,x1y,x2x,x2y);

        }
    if(T>=1 && A2>0 && A2<1)
        for(int j=1; j<=(11*p1*(Lungimea-80))/5; j++)
        {
            arg=((j-1)/11)/(p1/5);
            arg2=((A2*sin(w*(float((j-1)/Lungimea_float))+phi02))*(Lungimea_float/11))/(float(A2));
            x1x=80+arg;
            x1y=Latimea/2-arg2;
            arg=(j/11)/(p1/5);
            arg2=((A2*sin(w*(float(j/Lungimea_float))+phi02))*(Lungimea_float/11))/(float(A2));
            x2x=80+arg;
            x2y=Latimea/2-arg2;
            line(x1x,x1y,x2x,x2y);

        }
    if(T>0 && T<1 && A2>=1)
        for(int j=1; j<=11*T*(Lungimea-80); j++)
        {

            arg=((j-1)/11)/(float(T));
            arg2=((A2*sin(w*(float((j-1)/Lungimea_float))+phi02))*(Lungimea_float/11))/(p2/2);
            x1x=80+arg;
            x1y=Latimea/2-arg2;
            arg=(j/11)/(float(T));
            arg2=((A2*sin(w*(float(j/Lungimea_float))+phi02))*(Lungimea_float/11))/(p2/2);
            x2x=80+arg;
            x2y=Latimea/2-arg2;
            line(x1x,x1y,x2x,x2y);

        }
    if(T>0 && T<1 && A2>0 && A2<1)
        for(int j=1; j<=11*T*(Lungimea-80); j++)
        {

            arg=((j-1)/11)/(float(T));
            arg2=((A2*sin(w*(float((j-1)/Lungimea_float))+phi02))*(Lungimea_float/11))/(float(A2));
            x1x=80+arg;
            x1y=Latimea/2-arg2;
            arg=(j/11)/(float(T));
            arg2=((A2*sin(w*(float(j/Lungimea_float))+phi02))*(Lungimea_float/11))/(float(A2));
            x2x=80+arg;
            x2y=Latimea/2-arg2;
            line(x1x,x1y,x2x,x2y);

        }





    setcolor(BLUE);
    if(T>=1 && A>=1)
        for(int j=1; j<=(11*p1*(Lungimea-80))/5; j++)
        {

            arg=((j-1)/11)/(p1/5);
            arg2=((A*sin(w*(float((j-1)/Lungimea_float))+phi0))*(Lungimea_float/11))/(p2/2);
            x1x=80+arg;
            x1y=Latimea/2-arg2;
            arg=(j/11)/(p1/5);
            arg2=((A*sin(w*(float(j/Lungimea_float))+phi0))*(Lungimea_float/11))/(p2/2);
            x2x=80+arg;
            x2y=Latimea/2-arg2;
            line(x1x,x1y,x2x,x2y);
            line(x1x+1,x1y+1,x2x+1,x2y+1);

        }
    if(T>=1 && A>0 && A<1)
        for(int j=1; j<=(11*p1*(Lungimea-80))/5; j++)
        {
            arg=((j-1)/11)/(p1/5);
            arg2=((A*sin(w*(float((j-1)/Lungimea_float))+phi0))*(Lungimea_float/11))/(float(A));
            x1x=80+arg;
            x1y=Latimea/2-arg2;
            arg=(j/11)/(p1/5);
            arg2=((A*sin(w*(float(j/Lungimea_float))+phi0))*(Lungimea_float/11))/(float(A));
            x2x=80+arg;
            x2y=Latimea/2-arg2;
            line(x1x,x1y,x2x,x2y);
            line(x1x+1,x1y+1,x2x+1,x2y+1);

        }
    if(T>0 && T<1 && A>=1)
        for(int j=1; j<=11*T*(Lungimea-80); j++)
        {

            arg=((j-1)/11)/(float(T));
            arg2=((A*sin(w*(float((j-1)/Lungimea_float))+phi0))*(Lungimea_float/11))/(p2/2);
            x1x=80+arg;
            x1y=Latimea/2-arg2;
            arg=(j/11)/(float(T));
            arg2=((A*sin(w*(float(j/Lungimea_float))+phi0))*(Lungimea_float/11))/(p2/2);
            x2x=80+arg;
            x2y=Latimea/2-arg2;
            line(x1x,x1y,x2x,x2y);
            line(x1x+1,x1y+1,x2x+1,x2y+1);

        }
    if(T>0 && T<1 && A>0 && A<1)
        for(int j=1; j<=11*T*(Lungimea-80); j++)
        {

            arg=((j-1)/11)/(float(T));
            arg2=((A*sin(w*(float((j-1)/Lungimea_float))+phi0))*(Lungimea_float/11))/(float(A));
            x1x=80+arg;
            x1y=Latimea/2-arg2;
            arg=(j/11)/(float(T));
            arg2=((A*sin(w*(float(j/Lungimea_float))+phi0))*(Lungimea_float/11))/(float(A));
            x2x=80+arg;
            x2y=Latimea/2-arg2;
            line(x1x,x1y,x2x,x2y);
            line(x1x+1,x1y+1,x2x+1,x2y+1);

        }
}


void grafica()
{
    initwindow(Lungimea, Latimea, "Oscilatii", (GetSystemMetrics(0)/10), (GetSystemMetrics(1)/10));
    setcolor(9);
    rectangle(-10,-10,Lungimea,Latimea);
    floodfill(20,20,9);
    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
    settextstyle(3,HORIZ_DIR,4);
    int n00=0,x00,y00;
    outtextxy(Lungimea/2-160,Latimea-100,"CALCULEAZA");
    setbkcolor(WHITE);
    settextstyle(4,HORIZ_DIR,5);
    setcolor(2);
    outtextxy(Lungimea/18,Latimea/8,"x1(t)= ____*sin (____*t+____)");
    setcolor(5);
    outtextxy(Lungimea/18,Latimea/2,"x2(t)= ____*sin (____*t+____)");
    setcolor(BLACK);
    clearmouseclick(WM_LBUTTONDOWN);
    int ok1=1,ok2=1,ok3=1,inumar=0,ok31=1,ok4=1,inumar2=0,ok41=1,ok5=1,inumar3=0,ok51=1,ok7=1,inumar5=0,ok71=1,ok8=1,inumar6=0,ok81=1;
    int atofnr3=0;
    while(n00!=1)
    {
        getmouseclick(WM_LBUTTONDOWN, x00, y00);
        n00=0;
        if(x00>Lungimea/2-160 && x00<Lungimea/2+98 && y00>Latimea-100 && y00<Latimea-68)
            n00=2;
        if(x00>Lungimea/18+356 && x00<Lungimea/18+456 && y00>Latimea/8 && y00<Latimea/8+43)
            n00=3;
        if(x00>Lungimea/18+356 && x00<Lungimea/18+456 && y00>Latimea/2 && y00<Latimea/2+43)
            n00=4;
        if(x00>Lungimea/18+184 && x00<Lungimea/18+331 && y00>Latimea/8-8 && y00<Latimea/8+35)
            n00=5;
        if(x00>Lungimea/18+184 && x00<Lungimea/18+331 && y00>Latimea/2-8 && y00<Latimea/2+35)
            n00=6;
        if(x00>Lungimea/18+477 && x00<Lungimea/18+620 && y00>Latimea/8-8 && y00<Latimea/8+35)
            n00=7;
        if(x00>Lungimea/18+477 && x00<Lungimea/18+620 && y00>Latimea/2-8 && y00<Latimea/2+35)
            n00=8;
        if(x00>Lungimea/18+700 && x00<Lungimea/18+847 && y00>Latimea/8-8 && y00<Latimea/8+35)
            n00=9;
        if(x00>Lungimea/18+700 && x00<Lungimea/18+847 && y00>Latimea/2-8 && y00<Latimea/2+35)
            n00=10;


        if(n00==10)
        {
            ok8=1;
            while(kbhit())
                getch();
            while(ok8==1)
            {
                while(!kbhit())
                {
                    line(Lungimea/18+700,Latimea/2+35,Lungimea/18+847,Latimea/2+35);
                    delay(500);
                    setcolor(WHITE);
                    line(Lungimea/18+700,Latimea/2+35,Lungimea/18+847,Latimea/2+35);
                    delay(500);
                    setcolor(BLUE);
                }

                while(kbhit())
                    caracter=getch();
                if(int(caracter)==13)
                    ok8=2;
                if(caracter=='.' && (inumar6==1 || inumar6==2))
                {
                    if(ok81==1)
                    {
                        numar6[inumar6]=caracter;
                        inumar6++;
                    }
                    ok81=2;
                }
                if(caracter>='0' && caracter<='9' && inumar6<=3)
                {
                    if(caracter>='0' && caracter<='9' && inumar6==1)
                    {
                        if(numar6[0]!='0')
                        {
                            numar6[inumar6]=caracter;
                            inumar6++;
                        }
                    }
                    else
                    {
                        numar6[inumar6]=caracter;
                        inumar6++;
                    }
                }
                if(int(caracter)==8 && inumar6>0)
                {
                    inumar6--;
                    if(numar6[inumar6]=='.')
                        ok81=1;
                    numar6[inumar6]='\0';


                }
                numar6[4]='\0';
                setcolor(13);
                rectangle(Lungimea/18+700,Latimea/2-8,Lungimea/18+847,Latimea/2+35);
                floodfill(Lungimea/18+710,Latimea/2+2,13);
                setcolor(WHITE);
                rectangle(Lungimea/18+700,Latimea/2-8,Lungimea/18+847,Latimea/2+35);
                setcolor(BLUE);
                outtextxy(Lungimea/18+700,Latimea/2-8,numar6);
            }

            clearmouseclick(WM_LBUTTONDOWN);
        }


        if(n00==9)
        {
            ok7=1;
            while(kbhit())
                getch();
            while(ok7==1)
            {
                while(!kbhit())
                {
                    line(Lungimea/18+700,Latimea/8+35,Lungimea/18+847,Latimea/8+35);
                    delay(500);
                    setcolor(WHITE);
                    line(Lungimea/18+700,Latimea/8+35,Lungimea/18+847,Latimea/8+35);
                    delay(500);
                    setcolor(BLUE);
                }

                while(kbhit())
                    caracter=getch();
                if(int(caracter)==13)
                    ok7=2;
                if(caracter=='.' && (inumar5==1 || inumar5==2))
                {
                    if(ok71==1)
                    {
                        numar5[inumar5]=caracter;
                        inumar5++;
                    }
                    ok71=2;
                }
                if(caracter>='0' && caracter<='9' && inumar5<=3)
                {
                    if(caracter>='0' && caracter<='9' && inumar5==1)
                    {
                        if(numar5[0]!='0')
                        {
                            numar5[inumar5]=caracter;
                            inumar5++;
                        }
                    }
                    else
                    {
                        numar5[inumar5]=caracter;
                        inumar5++;
                    }
                }
                if(int(caracter)==8 && inumar5>0)
                {
                    inumar5--;
                    if(numar5[inumar5]=='.')
                        ok71=1;
                    numar5[inumar5]='\0';


                }
                numar5[4]='\0';
                setcolor(13);
                rectangle(Lungimea/18+700,Latimea/8-8,Lungimea/18+847,Latimea/8+35);
                floodfill(Lungimea/18+710,Latimea/8+2,13);
                setcolor(WHITE);
                rectangle(Lungimea/18+700,Latimea/8-8,Lungimea/18+847,Latimea/8+35);
                setcolor(BLUE);
                outtextxy(Lungimea/18+700,Latimea/8-8,numar5);
            }

            clearmouseclick(WM_LBUTTONDOWN);
        }


        if(n00==7)
        {
            ok5=1;
            while(kbhit())
                getch();
            while(ok5==1)
            {
                while(!kbhit())
                {
                    line(Lungimea/18+477,Latimea/2+35,Lungimea/18+620,Latimea/2+35);
                    line(Lungimea/18+477,Latimea/8+35,Lungimea/18+620,Latimea/8+35);
                    delay(500);
                    setcolor(WHITE);
                    line(Lungimea/18+477,Latimea/2+35,Lungimea/18+620,Latimea/2+35);
                    line(Lungimea/18+477,Latimea/8+35,Lungimea/18+620,Latimea/8+35);
                    delay(500);
                    setcolor(BLUE);
                }

                while(kbhit())
                    caracter=getch();
                if(int(caracter)==13)
                    ok5=2;
                if(caracter=='.' && (inumar3==1 || inumar3==2))
                {
                    if(ok51==1)
                    {
                        numar3[inumar3]=caracter;
                        inumar3++;
                    }
                    ok51=2;
                }
                if(caracter>='0' && caracter<='9' && inumar3<=3)
                {
                    if(caracter>='0' && caracter<='9' && inumar3==1)
                    {
                        if(numar3[0]!='0')
                        {
                            numar3[inumar3]=caracter;
                            inumar3++;
                        }
                    }
                    else
                    {
                        numar3[inumar3]=caracter;
                        inumar3++;
                    }
                }
                if(int(caracter)==8 && inumar3>0)
                {
                    inumar3--;
                    if(numar3[inumar3]=='.')
                        ok51=1;
                    numar3[inumar3]='\0';


                }
                numar3[4]='\0';
                setcolor(13);
                rectangle(Lungimea/18+477,Latimea/2-8,Lungimea/18+620,Latimea/2+35);
                floodfill(Lungimea/18+487,Latimea/2+2,13);
                rectangle(Lungimea/18+477,Latimea/8-8,Lungimea/18+620,Latimea/8+35);
                floodfill(Lungimea/18+487,Latimea/8+2,13);
                setcolor(WHITE);
                rectangle(Lungimea/18+477,Latimea/2-8,Lungimea/18+620,Latimea/2+35);
                rectangle(Lungimea/18+477,Latimea/8-8,Lungimea/18+620,Latimea/8+35);
                setcolor(BLUE);
                outtextxy(Lungimea/18+477,Latimea/8-8,numar3);
                outtextxy(Lungimea/18+477,Latimea/2-8,numar3);
                if(atof(numar3)>10)
                    atofnr3=1;
                else
                    atofnr3=0;
                if(atofnr3==1)
                    outtextxy(0,Latimea-50,"w trebuie sa fie mai mic decat 10");
                else
                {
                    setcolor(13);
                    rectangle(0,Latimea-50,Lungimea,Latimea);
                    floodfill(0,Latimea-50+2,13);
                    setcolor(WHITE);
                    rectangle(0,Latimea-50,Lungimea,Latimea);
                    setcolor(BLUE);
                }
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }

        if(n00==8)
        {
            ok5=1;
            while(kbhit())
                getch();
            while(ok5==1)
            {
                while(!kbhit())
                {
                    line(Lungimea/18+477,Latimea/8+35,Lungimea/18+620,Latimea/8+35);
                    line(Lungimea/18+477,Latimea/2+35,Lungimea/18+620,Latimea/2+35);
                    delay(500);
                    setcolor(WHITE);
                    line(Lungimea/18+477,Latimea/8+35,Lungimea/18+620,Latimea/8+35);
                    line(Lungimea/18+477,Latimea/2+35,Lungimea/18+620,Latimea/2+35);
                    delay(500);
                    setcolor(BLUE);
                }

                while(kbhit())
                    caracter=getch();
                if(int(caracter)==13)
                    ok5=2;
                if(caracter=='.' && (inumar3==1 || inumar3==2))
                {
                    if(ok51==1)
                    {
                        numar3[inumar3]=caracter;
                        inumar3++;
                    }
                    ok51=2;
                }
                if(caracter>='0' && caracter<='9' && inumar3<=3)
                {
                    if(caracter>='0' && caracter<='9' && inumar3==1)
                    {
                        if(numar3[0]!='0')
                        {
                            numar3[inumar3]=caracter;
                            inumar3++;
                        }
                    }
                    else
                    {
                        numar3[inumar3]=caracter;
                        inumar3++;
                    }
                }
                if(int(caracter)==8 && inumar3>0)
                {
                    inumar3--;
                    if(numar3[inumar3]=='.')
                        ok51=1;
                    numar3[inumar3]='\0';


                }
                numar3[4]='\0';
                setcolor(13);
                rectangle(Lungimea/18+477,Latimea/2-8,Lungimea/18+620,Latimea/2+35);
                floodfill(Lungimea/18+487,Latimea/2+2,13);
                rectangle(Lungimea/18+477,Latimea/8-8,Lungimea/18+620,Latimea/8+35);
                floodfill(Lungimea/18+487,Latimea/8+2,13);
                setcolor(WHITE);
                rectangle(Lungimea/18+477,Latimea/2-8,Lungimea/18+620,Latimea/2+35);
                rectangle(Lungimea/18+477,Latimea/8-8,Lungimea/18+620,Latimea/8+35);
                setcolor(BLUE);
                outtextxy(Lungimea/18+477,Latimea/8-8,numar3);
                outtextxy(Lungimea/18+477,Latimea/2-8,numar3);
                if(atof(numar3)>10)
                    atofnr3=1;
                else
                    atofnr3=0;
                if(atofnr3==1)
                    outtextxy(0,Latimea-50,"w trebuie sa fie mai mic decat 10");
                else
                {
                    setcolor(13);
                    rectangle(0,Latimea-50,Lungimea,Latimea);
                    floodfill(0,Latimea-50+2,13);
                    setcolor(WHITE);
                    rectangle(0,Latimea-50,Lungimea,Latimea);
                    setcolor(BLUE);
                }
            }

            clearmouseclick(WM_LBUTTONDOWN);
        }

        if(n00==5)
        {
            ok3=1;
            while(kbhit())
                getch();
            while(ok3==1)
            {
                while(!kbhit())
                {
                    line(Lungimea/18+184,Latimea/8+35,Lungimea/18+331,Latimea/8+35);
                    delay(500);
                    setcolor(WHITE);
                    line(Lungimea/18+184,Latimea/8+35,Lungimea/18+331,Latimea/8+35);
                    delay(500);
                    setcolor(BLUE);
                }

                while(kbhit())
                    caracter=getch();
                if(int(caracter)==13)
                    ok3=2;
                if(caracter=='.' && (inumar==1 || inumar==2))
                {
                    if(ok31==1)
                    {
                        numar1[inumar]=caracter;
                        inumar++;
                    }
                    ok31=2;
                }
                if(caracter>='0' && caracter<='9' && inumar<=3)
                {
                    if(caracter>='0' && caracter<='9' && inumar==1)
                    {
                        if(numar1[0]!='0')
                        {
                            numar1[inumar]=caracter;
                            inumar++;
                        }
                    }
                    else
                    {
                        numar1[inumar]=caracter;
                        inumar++;
                    }
                }
                if(int(caracter)==8 && inumar>0)
                {
                    inumar--;
                    if(numar1[inumar]=='.')
                        ok31=1;
                    numar1[inumar]='\0';


                }
                numar1[4]='\0';
                setcolor(13);
                rectangle(Lungimea/18+184,Latimea/8-8,Lungimea/18+331,Latimea/8+35);
                floodfill(Lungimea/18+194,Latimea/8+2,13);
                setcolor(WHITE);
                rectangle(Lungimea/18+184,Latimea/8-8,Lungimea/18+331,Latimea/8+35);
                setcolor(BLUE);
                outtextxy(Lungimea/18+184,Latimea/8-8,numar1);
            }

            clearmouseclick(WM_LBUTTONDOWN);
        }

        if(n00==6)
        {
            ok4=1;
            while(kbhit())
                getch();
            while(ok4==1)
            {
                while(!kbhit())
                {
                    line(Lungimea/18+184,Latimea/2+35,Lungimea/18+331,Latimea/2+35);
                    delay(500);
                    setcolor(WHITE);
                    line(Lungimea/18+184,Latimea/2+35,Lungimea/18+331,Latimea/2+35);
                    delay(500);
                    setcolor(BLUE);
                }

                while(kbhit())
                    caracter=getch();
                if(int(caracter)==13)
                    ok4=2;
                if(caracter=='.' && (inumar2==1 || inumar2==2))
                {
                    if(ok41==1)
                    {
                        numar2[inumar2]=caracter;
                        inumar2++;
                    }
                    ok41=2;
                }
                if(caracter>='0' && caracter<='9' && inumar2<=3)
                {
                    if(caracter>='0' && caracter<='9' && inumar2==1)
                    {
                        if(numar2[0]!='0')
                        {
                            numar2[inumar2]=caracter;
                            inumar2++;
                        }
                    }
                    else
                    {
                        numar2[inumar2]=caracter;
                        inumar2++;
                    }
                }
                if(int(caracter)==8 && inumar2>0)
                {
                    inumar2--;
                    if(numar2[inumar2]=='.')
                        ok41=1;
                    numar2[inumar2]='\0';


                }
                numar2[4]='\0';
                setcolor(13);
                rectangle(Lungimea/18+184,Latimea/2-8,Lungimea/18+331,Latimea/2+35);
                floodfill(Lungimea/18+194,Latimea/2+2,13);
                setcolor(WHITE);
                rectangle(Lungimea/18+184,Latimea/2-8,Lungimea/18+331,Latimea/2+35);
                setcolor(BLUE);
                outtextxy(Lungimea/18+184,Latimea/2-8,numar2);
            }

            clearmouseclick(WM_LBUTTONDOWN);
        }
        if(n00==3)
        {
            if(ok1==1)
                ok1=2;
            else
                ok1=1;
            setcolor(13);
            rectangle(Lungimea/18+356,Latimea/8,Lungimea/18+456,Latimea/8+43);
            floodfill(Lungimea/18+366,Latimea/8+10,13);
            setcolor(WHITE);
            rectangle(Lungimea/18+356,Latimea/8,Lungimea/18+456,Latimea/8+43);
            setcolor(2);
            if(ok1==1)

                outtextxy(Lungimea/18+356,Latimea/8,"sin");

            else
                outtextxy(Lungimea/18+356,Latimea/8,"cos");

            clearmouseclick(WM_LBUTTONDOWN);
        }

        if(n00==4)
        {
            if(ok2==1)
                ok2=2;
            else
                ok2=1;
            setcolor(13);
            rectangle(Lungimea/18+356,Latimea/2,Lungimea/18+456,Latimea/2+43);
            floodfill(Lungimea/18+366,Latimea/2+10,13);
            setcolor(WHITE);
            rectangle(Lungimea/18+356,Latimea/2,Lungimea/18+456,Latimea/2+43);
            setcolor(5);
            if(ok2==1)

                outtextxy(Lungimea/18+356,Latimea/2,"sin");

            else
                outtextxy(Lungimea/18+356,Latimea/2,"cos");

            clearmouseclick(WM_LBUTTONDOWN);
        }
        if(n00==2)
            if(inumar!=0 && inumar2!=0 && inumar3!=0 && inumar5!=0 && inumar6!=0 && atofnr3==0)
                n00=1;
        if(n00==1)
        {

            A1=atof(numar1);
            A2=atof(numar2);
            w=atof(numar3);
            phi01=atof(numar5);
            phi02=atof(numar6);
            A1=A1+0.001;
            A2=A2+0.001;
            w=w+0.001;
            phi01=phi01+0.001;
            phi02=phi02+0.001;
            if(ok1==2)
                phi01=phi01+1.570796;
            if(ok2==2)
                phi02=phi02+1.570796;
            calcule();

        }
    }

    desenare_grafic();
    afisare_numere_pe_grafic();
    afisare_ecuatie_oscilatie_compusa();
    citeste_imaginile();
    desenare_oscilatie_compusa();
}
int main()
{
    grafica();
    cout<<"A= "<<A<<endl<<"T= "<<T<<endl;
    cout<<A1<<endl<<A2<<endl<<phi01<<endl<<phi02;
    delay(1000000);
    return 0;
}
