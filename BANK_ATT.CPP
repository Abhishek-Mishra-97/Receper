/*
   #########
   ##     ##
   ##     ##
   #########    ####### ###### ####### ###### ####### ######
   ##  ##       ##      ##     ##      ##   # ##      ##   #
   ##    ##     ####### ##     ####### ###### ####### ######
   ##      ##   ##      ##     ##      ##     ##      ##  #
   ##        ## ####### ###### ####### ##     ####### ##   #
*/



/*
This Program is specially designed for Banks to
Add Acount Details
View Account Details
Edit Amount
*/

#include<iostream.h>
#include<ctype.h>
#include<process.h>
#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<iomanip.h>
#include<stdlib.h>
#include<stdio.h>


char acno[7],pass[50];
long float amount;
char user[20]="";
char sh[4][50]={"Developer    Abhishek Mishra","          Receper       " };
long int amt2;
int he=60,le=200,b,a,c,pro,k,i,j,l,m,n,ck=0,pe=0;
char choice,ch;
//Function decleration
void start();
void image();
void install();
void password();
void load();
void *buff1;
void write1(char []);
void edit();

void main()
{
int gd=DETECT,gm;                        //Graphics initialisation
initgraph(&gd,&gm,"C:\\TurboC3\\BGI");    //Graphics initialisation
clrscr();
setbkcolor(0);
ifstream tp("period.txt",ios::in|ios::nocreate);
pe+=1;
if(!tp)
{
ofstream create("period.txt",ios::out|ios::ate);//creates "period.txt"
create<<pe;
install();   //installation process
}
if(tp)
{
tp>>pe;  //notes no of times program is runned
remove("period.txt");
ofstream tp1("period.txt",ios::out|ios::ate);
pe+=1;
tp1<<pe;
}
clrscr();
setfillstyle(1,0);
floodfill(440,240,15);
settextstyle(4,0,4);
setcolor(15);
if(pe>1)
{
load();
}
ifstream use("user.dat",ios::in); //Inputs Username from "user.dat"
while(!use.eof())
{use>>user;
}
ifstream pas("secure.dat",ios::in);
while(!pas.eof())
{
pas>>pass;
}
clrscr();
setfillstyle(1,0);
floodfill(200,200,15);
setcolor(4);
settextstyle(4,0,4);
outtextxy(170,getmaxy()/2-50,"Welcome ");
outtextxy(300,getmaxy()/2-50,user);
delay(1000);
password();
image();
start();

getch();
}

class det1 //class to store details into file and extract data from file
{
public:    //public acces specifier
char name[30],fname[30],hno[15],lmk[30],vc[15],dit[15],state[20],sex,acno2[8];
int dob[1][3];
long int amt;
det1()       //constructor to initialize values
{
strcpy(name,"");
strcpy(fname,"");strcpy(hno,"");strcpy(lmk,"");strcpy(vc,"");strcpy(dit,"");
strcpy(state,"");
amt=0;
}//constructor

void input()       //function to input details for opening an account
{
strcpy(acno2,acno);
cout<<"\n\n\n\n";
cout<<"Acount Type -> Savings\n";
cout<<"\nName\n";
cin.getline(name,30);
cout<<"\nFathers Name\n";
cin.getline(fname,30);
cout<<"\nResidential Address :- \n";
cout<<"House No | Name\n";
cin.getline(hno,15);
cout<<"Landmark\n";
cin.getline(lmk,15);
cout<<"City | Village\n";
cin.getline(vc,15);
cout<<"District\n";
cin.getline(dit,15);

cout<<"State\n";
cin.getline(state,20);

dob:
cout<<"\nDate of Birth\n(DD MM YYYY)\n";
for(i=0;i<3;i++)
{
cin>>dob[0][i];
}
//check for invalid date of birth
if(dob[0][0]>31||(dob[0][2]>2014)||dob[0][2]<1900||(dob[0][1]==2&&dob[0][0]>28)||dob[0][1]>12||dob[0][1]<1||(dob[0][1]==4||dob[0][1]==6||dob[0][1]==9||dob[0][1]==11)&&dob[0][0]>30){cout<<"\nInvalid Date of birth\n";goto dob;}

sex:
cout<<"\nSex (M or F or O) \n";
cin>>sex;
sex=toupper(sex);
if(sex=='M'||sex=='F'||sex=='O'){}
else {goto sex;}
randomize();
cout<<"\nEnter Initial Amount\n";
cin>>amt;

cout<<"\nYour Account Number Is-> ";
for(i=0;i<8;i++)
{cout<<acno2[i];
}
getch();
}
void output() //function to display details of account
{
clrscr();
setfillstyle(1,0);
floodfill(100,200,15);
cout<<"Acount Type -> Savings\n";
cout<<"\nName\n";
cout<<name;
cout<<"\nFathers Name\n";
cout<<fname;
cout<<"\nResidential Address :- \n";
cout<<"House No | Name\n";
cout<<hno;
cout<<"\nLandmark\n";
cout<<lmk;
cout<<"\nCity | Village\n";
cout<<vc;
cout<<"\nDistrict\n";
cout<<dit;
cout<<"\nState\n";
cout<<state;
cout<<"\nDate of Birth\n";
for(i=0;i<3;i++)
{
cout<<dob[0][i]<<" ";
}
cout<<"\nSex (M or F or O) \n";
cout<<sex;
cout<<"\nInitial Amount\n";
cout<<amt;
cout<<"\nYour Account Number  ->   \n";
for(i=0;i<8;i++)
{cout<<acno2[i];
}
save_file:
cout<<"\n\nEnter 1 to save details in document file & 2 to Exit\n";
cin>>choice;
if(choice=='1'){cout<<"\nFile name detail.doc\n";
ofstream save("detail.doc",ios::out); //saves detail in .doc file
save<<"Acount Type -> Savings ";
save<<"\n\nName - ";
save<<name;
save<<"\n\nFathers Name - ";
save<<fname;
save<<"\n\nResidential Address :- \n";
save<<cout<<"House No | Name - ";
save<<hno;
save<<"\nLandmark - ";
save<<lmk;
save<<"\nCity | Village - ";
save<<vc;
save<<"\nDistrict - ";
save<<dit;
save<<"\nState - ";
save<<state;
save<<"\n\nDate of Birth - ";
for(i=0;i<3;i++)
{
save<<dob[0][i];
save<<" ";
}
save<<"\n\nSex - ";
save<<sex;
save<<"\n\nAmount  -  ";
save<<amt;
save<<"\n\nYour Account Number is -->  ";
for(i=0;i<8;i++)
{
save<<acno2[i];
}
save.close();
getch();
exit(0);
}

if(choice=='2'){exit(0);}
else {cout<<"\nWrong Selection\n";goto save_file;}
exit(0);
}

float amount(float am,char cho) //function to make changes in amount
{amt2=amt;
if(cho=='2'&&am>amt)return -1;
if(cho=='1')amt+=am;
if(cho=='2')amt-=am;
return amt;
}
}s1; //global declaration of class object


void load()                //Program loading process
{
setfillstyle(1,BLACK);
floodfill(getmaxx()/2,getmaxy()/2,15);
for(i=80;i<=83;i++)
{
setcolor(RED);
circle(getmaxx()/2,getmaxy()/2-80,i);
}
for(j=0,k=640;j<=getmaxx()/2,k>=getmaxx()/2;j++,k--)
{
setcolor(BLUE);
ellipse(j,getmaxy()/2-80,90,270,83+83,83);
ellipse(k,getmaxy()/2-80,270,90,83+83,83);
delay(4);
setcolor(BLACK);
ellipse(j,getmaxy()/2-80,90,270,95+83,84);
ellipse(k,getmaxy()/2-80,270,90,95+83,84);
}
settextstyle(4,0,10);
setcolor(GREEN);
outtextxy(270,65,"R");
setcolor(WHITE);
circle(220,260,6);
circle(250,260,6);
circle(280,260,6);
circle(310,260,6);
circle(340,260,6);
circle(370,260,6);
circle(400,260,6);
circle(430,260,6);
i=220;
c=0;
background:
setfillstyle(1,0);
bar(0,0,640,400);
setcolor(BLUE);
for(b=80;b<=83;b++)
{
setcolor(RED);
circle(getmaxx()/2,getmaxy()/2-80,b);
}
for(j=0;j<=12;j++)
{
setcolor(BLUE);
ellipse(320,getmaxy()/2-80,90,270,83+83+j,83);
ellipse(320,getmaxy()/2-80,270,90,83+83+j,83);
delay(2);
}
settextstyle(4,0,10);
setcolor(GREEN);
outtextxy(270,65,"R");
setcolor(WHITE);
circle(220,260,6);
circle(250,260,6);
circle(280,260,6);
circle(310,260,6);
circle(340,260,6);
circle(370,260,6);
circle(400,260,6);
circle(430,260,6);


while(i<=430)
{
i+=30;
setfillstyle(1,7);
floodfill(i,260,15);
settextstyle(1,0,2);
setcolor(CYAN);
outtextxy(180,280,sh[c]);
delay(500);
i+=30;
setfillstyle(1,0);
floodfill(i-30,260,15);
setfillstyle(1,7);
floodfill(i,260,15);
c+=1;
delay(500);
goto background;
}
}

void password()   //To check for Authentication
{clrscr();
setfillstyle(1,0);
floodfill(200,200,15);
  char pass1[50];
int size;
void *logo;
setbkcolor(0);
setcolor(RED);
circle(320,50,25);
circle(320,50,24);
setcolor(1);
ellipse(320,50,0,360,50,25);
ellipse(320,50,0,360,49,25);
ellipse(320,50,0,360,48,25);
ellipse(320,50,0,360,47,25);
ellipse(320,50,0,360,46,25);
settextstyle(4,0,4);
setcolor(2);
outtextxy(310,25,"R");
size=imagesize(270,25,370,75);
logo=malloc(size);
getimage(270,25,370,75,logo);
j=1;
password:

getimage(270,25,370,75,logo);
settextstyle(7,0,3);
setcolor(15);
outtextxy(160,110,"Enter Password To Continue");

if(j>1){settextstyle(1,0,1.2);outtextxy(220,198,"Character Mismatch");}

if(j==2){setcolor(4);
outtextxy(200,220,"You have 2 Chances left");}
if(j==3){
setfillstyle(1,0);
bar(150,220,525,250);
setcolor(4);
outtextxy(200,220,"You have 1 Chance left");}
setfillstyle(1,15);
bar(150,170,525,195);

for(i=0;i<strlen(pass);i++)
{
pass1[i]=getch();
setfillstyle(1,0);
bar(210,197,450,220);
settextstyle(1,0,3);
setcolor(0);
outtextxy(160+(12*i),172,"*");
if(pass1[i]==27){exit(0);}
if(pass1[i]==pass[i])continue;
else {j+=1;if(j==4){exit(0);}goto password;}

}

}

void install()   //Installation of Program during first use
{
setfillstyle(1,0);
bar(0,0,640,400);
setcolor(BLUE);
for(b=30;b<=31;b++)
{
setcolor(RED);
circle(320,240-80,b);
}
for(j=0;j<=3;j++)
{
setcolor(BLUE);
ellipse(getmaxx()/2,getmaxy()/2-80,90,270,60+j,32);
ellipse(getmaxx()/2,getmaxy()/2-80,270,90,60+j,32);

}
settextstyle(7,0,5);
setcolor(GREEN);
outtextxy(302,134,"R");
int size1;
void *buff1;
setcolor(4);
size1=imagesize(256,127,384,272);
buff1=malloc(size1);           //stores bit size image in buff1
getimage(256,127,384,272,buff1);

setfillstyle(1,0);
floodfill(320,240,15);
putimage(257,20,buff1,XOR_PUT);
setcolor(15);
rectangle(80,10,580,400);
setfillstyle(1,1);
bar(81,100,579,125);
settextstyle(1,0,2);
setcolor(4);

outtextxy(290,100,"Receper");
settextstyle(4,0,4);
setcolor(15);
settextstyle(11,0,4);
outtextxy(250,136,"Setup Is Extracting");
setcolor(14);
rectangle(130,240,530,260);
k=130;
setfillstyle(1,9);
ofstream f2("About.txt",ios::out);
char about1[125]={"                                 Record Keeper version = v.14  \n                                 Developer - Abhishek Mishra "};
for(i=0;i<125;i++)
{
f2<<about1[i];
}
settextstyle(11,0,2);
setcolor(4);
outtextxy(200,195,"C:-TurboC++-Disk-TurboC3-BIN-About.txt");
f2.close();
for(k=131;k<=230;k++)
{
bar(131,241,k,259);
delay(15);
}
setfillstyle(1,0);
bar(131,194,530,220);
outtextxy(200,195,"C:-TurboC++-Disk-TurboC3-BIN-Read Me.txt");
setfillstyle(1,9);
for(k=230;k<=330;k++)
{
bar(231,241,k,259);
delay(15);
}
char read[155]="This Software is paticularly designed for Banks to maintain their Databases :-\n Add Acount\n View Acount Details\nEdit Amount";
ofstream f3("Read Me.txt",ios::out); //Creates "readme.txt" during installation
for(i=0;i<155;i++)
{
f3<<read[i];
}
f3.close();

setfillstyle(1,0);
bar(131,194,530,220);

settextstyle(1,0,1);
setcolor(5);
outtextxy(200,280,"Press Enter To Continue");
settextstyle(11,0,2);
setcolor(15);
outtextxy(160,310,"Please Enter User Name - ");
k=0;
user:
ofstream f4("User.dat",ios::out);

while(user[k]!=13)
{
user[k]=getch(); //User name input
if(user[k]==13)break;

settextstyle(11,0,2);
outtextxy(370,310,user);
if(user[k]==8){setfillstyle(1,0);bar(370,310,520,330);for(i=0;i<k;i++){user[i]=' ';}k=0;remove("User.txt");goto user;}
f4<<user[k];
k+=1;
}
password:
ofstream pa("secure.dat",ios::out);
outtextxy(160,335,"Please Enter Password  - ");
k=0;
while(pass[k]!=13)
{
pass[k]=getch();                 //Password input
if(pass[k]==13)break;

settextstyle(11,0,2);
outtextxy(370+(k*10),335,"*");
if(pass[k]==8){setfillstyle(1,0);bar(370,335,520,370);for(i=0;i<k;i++){pass[i]=' ';}k=0;remove("secure.txt");goto password;}
pa<<pass[k];
k+=1;
}



f4.close();

settextstyle(11,0,2);
setcolor(4);

outtextxy(200,195,"C:-TurboC++-Disk-TurboC3-BIN-User.txt");
setfillstyle(1,9);

for(k=331;k<=430;k++)
{
bar(331,241,k,259);
delay(15);
}

setfillstyle(1,0);
bar(131,194,530,220);
bar(131,261,529,399);
setfillstyle(1,9);
settextstyle(11,0,3);
setcolor(15);
outtextxy(220,295,"Features");
setcolor(1);
outtextxy(205,320,"Add Account Details");
outtextxy(204,345,"View Account Details");
outtextxy(220,370,"Edit Amount");
for(k=431;k<=529;k++)
{
bar(431,241,k,259);
delay(15);
}
}

void image()
{setfillstyle(1,0);
bar(0,0,640,400);
setcolor(BLUE);
for(b=30;b<=31;b++)
{
setcolor(RED);
circle(320,240-80,b);
}
for(j=0;j<=3;j++)
{
setcolor(BLUE);
ellipse(getmaxx()/2,getmaxy()/2-80,90,270,60+j,32);
ellipse(getmaxx()/2,getmaxy()/2-80,270,90,60+j,32);
}
settextstyle(7,0,5);
setcolor(GREEN);
outtextxy(302,134,"R");
int size1;

setcolor(4);
size1=imagesize(256,127,384,272);
buff1=malloc(size1);
getimage(256,127,384,272,buff1);
}

void form1()
{  //Input details of account through class & save details in file
clrscr();
setfillstyle(1,0);
floodfill(430,240,15);
setcolor(4);
settextstyle(4,0,2);
outtextxy(250,3,"Application Form");
setcolor(1);
settextstyle(1,0,1);
outtextxy(260,25,"  Level -> 1  ");
randomize();

acno_check:
for(i=0;i<=7;i++)    //Random selection of 8 digit account number
{
acno[i]=char(48+random(10));
}
ifstream check(acno,ios::in|ios::nocreate);
if(!check){}           //check use of account no generated before
else goto acno_check;

s1.input();

ofstream f5(acno,ios::out|ios::ate);//creates binary file of generated acno
ac_write:

f5.write((char*)&s1,sizeof(s1));//writes details in file
f5.close();

start();
}

void start() //displays all tabs :- Add AccountDetails, View Account Details, Edit amount
{clrscr();
setfillstyle(1,0);
floodfill(320,240,15);
bar(0,330,640,600);
putimage(2,150,buff1,XOR_PUT);
putimage(500,150,buff1,XOR_PUT);

int r1=0,r2=0;
settextstyle(1,0,2);
setcolor(1);
outtextxy(170,55,"Bank Database Management");

settextstyle(4,0,5);
setcolor(4);
outtextxy(250,6,"Receper");

setfillstyle(1,5);
bar(180,120,450,160);
bar(180,180,450,220);
bar(180,240,450,280);
bar(180,300,450,340);
settextstyle(3,0,2);
setcolor(1);
outtextxy(250,125,"Add Account");
outtextxy(210,185,"View Account Details");
outtextxy(250,245,"Edit Amount");
outtextxy(290,305,"Exit");

selection:
char ch;
while(ch!=13)
{
ch=getch();
if(r1==1){setcolor(0);
rectangle(178,118,452,162);
}
if(r1==2){setcolor(0);
rectangle(178,178,452,222);
}
if(r1==3)
{
setcolor(0);
rectangle(178,238,452,282);
}
if(r1==4)
{setcolor(0);
rectangle(178,298,452,342);
}
if(ch==72)
{r1-=1;if(r1<1)r1=1;}
if(ch==80){r1+=1;if(r1>4)r1=4;}
if(ch==13){}
if(r1==1)
{setcolor(13);
rectangle(178,118,452,162);
}
if(r1==2)
{setcolor(13);
rectangle(178,178,452,222);
}
if(r1==3)
{
setcolor(13);
rectangle(178,238,452,282);
}
if(r1==4)
{setcolor(13);
rectangle(178,298,452,342);
}
}

if(r1==4)exit(0);
if(r1==3)edit();
if(r1==1)
{form1();}
if(r1==2)
{clrscr();
setfillstyle(1,0);
floodfill(getmaxx()/2,getmaxy()/2,15);
char acno1[8];
acnoin:
cout<<"Please Enter Account Number\nEnter 1 to go back\n";
cin>>acno1;
if(strcmp(acno1,"1")==0){start();}

ifstream acin(acno1,ios::in|ios::nocreate);
if(!acin){cout<<"\n\nAcount Number not found \nPlease Write other Acount number\n\n";
goto acnoin;
}
else{ifstream ac(acno1,ios::in);
while(!ac.eof())
{
ac.read((char*)&s1,sizeof(s1));
}
s1.output();
}
}  }

void edit() //To edit amount
{det1 s2;
char ac1[8];

clrscr();
setfillstyle(1,0);
floodfill(320,240,15);

enter_ac:
cout<<"Please Enter Acount number\n\n";
cin>>ac1;
int flag=0;
for(i=0;i<8;i++)
{
if(isupper(ac1[i])||islower(ac1[i]))flag+=1;}
if(flag>0){cout<<"Enter Valid Acount Number\n";goto enter_ac;}

fstream acno5(ac1,ios::in|ios::out|ios::nocreate);
if(!acno5){cout<<"Invalid Acount Number\nPlease enter valid Acount no\n";goto enter_ac;}

enter_ch:
cout<<"\nEnter 1 to Add Amount & 2 to Withdraw Amount\n";
cin>>ch;

add:
cout<<"\nEnter Amount \n";
cin>>amount;
float amt2;
while(!acno5.eof())
{acno5.read((char*)&s2,sizeof(s2));
acno5.read((char*)&s1,sizeof(s1));}

amt2=s2.amount(amount,ch);
if(amt2==-1){cout<<"Not enough money\n";system("pause");exit(0);}
cout<<"\nAmount Left  -->  "<<amt2<<"\n";
write1(ac1);

system("pause");
exit(0);
}

void write1(char acc[])
{det1 s4;
ifstream ac4(acc,ios::in);
while(!ac4.eof())
{ac4.read((char*)&s4,sizeof(s4));
}
s4.amount(amount,ch);
remove(acc);
fstream acno6(acc,ios::out|ios::in);
acno6.write((char*)&s4,sizeof(s4));
}
