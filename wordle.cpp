#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
string wrds[9999],chn[9999],line;
string user,sys,trans,gsd;
int i,j,k,th=0,life=6;
int c;bool reset=true;
ifstream ifile("dictionary7.txt");
HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
char tc(int inte){return inte;}
void play();
int search(string arr[],int sise,string targ){
	for(k=0;k<=sise;k++){
		if(arr[k]==targ){return k;}
	}
    return -1;
}
void color(string clr){
	if(clr=="white"){
		SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);
	}
	else if(clr=="yellow"){
		SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED);
	}
	else if(clr=="cyan"){
		SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
	}
	else if(clr=="green"){
		SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	}
	else if(clr=="red"){
		SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED);
	}
}
void cons(){
	int sise;
	while(getline(ifile,line)){
		sise=line.size();
		for(i=0;i<sise;i++){
			if(line[i]!=' '){
				wrds[th]+=line[i];
			}
			else{break;}
		}
		chn[th]=line.substr(i+1,sise-i-1);
		//cout<<wrds[th]<<"\n";
		th++;
	}
}
void end(string ver){
	if(ver=="win"){
		color("yellow");
		cout<<"You guessed out the word!\n";
		color("cyan");
		cout<<sys<<" "<<trans<<"\n";
	}
	else if(ver=="lose"){
		color("red");
		cout<<"You used up the times.\n";
		color("white");
		cout<<"the word is ";color("cyan");
		cout<<sys;color("white");cout<<".\n";color("cyan");
		cout<<sys<<" "<<trans<<"\n";
	}
	else{
		color("red");cout<<"You choose to restart.\n";
		color("white");
		cout<<"the word is ";color("cyan");
		cout<<sys;color("white");cout<<".\n";color("cyan");
		cout<<sys<<" "<<trans<<"\n";reset=true;play();
	}
	color("white");
	cout<<"Wanna play again?[Y/N]\n";
	char choice;
	cin>>choice;
	if(choice=='Y'){
		reset=true;play();
	}
	else if(choice=='N'){exit(0);}
}
void play(){
	if(reset){
		th=rand()%1078;
		sys=wrds[th];trans=chn[th];reset=false;user="";
		life=6;gsd="";
	}
	//cout<<th<<wrds[th]<<"\n";
	L:color("white");cout<<"_ _ _ _ _";
	for(i=0;i<9;i++){cout<<'\b';}
	user="";
	for(i=0;i<5;i++){
		c=getch();
		if(c==224){exit(0);}
		if(c!=8 && isalpha(tc(c)) || c=='-'){
			cout<<tc(c)<<" ";
			user+=tc(c);
		}
		else if(i!=0 && c==8){
			cout<<"\b\b";
			cout<<"_ _";
			cout<<"\b\b\b";
			user.erase(user.end()-1);
			i-=2;
		}
		else{i--;}
	}
	for(i=0;i<10;i++){cout<<'\b';}
	if(user=="rstrt"){end("restart");}
	if(search(wrds,1778,user)==-1){
		color("red");Sleep(500);
		cout<<"You sure the word is legal?";
		Sleep(1500);
		for(j=0;j<54;j++){cout<<"\b \b";}
		user="";goto L;
	}
	if(gsd.find(user)!=gsd.npos && gsd.find(user)%5==0){
		color("cyan");Sleep(500);
		cout<<"You've guessed this word.";Sleep(1500);
		for(j=0;j<50;j++){cout<<"\b \b";}
		user="";goto L;
	}
	gsd+=user;
	for(i=0;i<5;i++){
		if(user[i]==sys[i]){
			color("green");
			cout<<user[i]<<" ";
			continue;
		}
		if(sys.find(user[i])!=sys.npos){
			color("yellow");
			cout<<user[i]<<" ";
		}
		else{color("white");cout<<user[i]<<" ";}
	}
	cout<<"\n";
	if(sys==user){end("win");}
	if(life==1){end("lose");}
	life--;user="";
	play();
}
int main(){
	srand((unsigned)time(NULL));
	cons();
	SetConsoleTitle("Wordle");
	reset=true;play();
	return 0;
}
