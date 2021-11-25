#include<bits/stdc++.h>
using namespace std;
#include<windows.h>
#include<conio.h>

void tieude();
int gety();
void gotoxy(int x, int y);
void dangnhap();
void input(char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101], char msv[][15], char email[][30], char tenlop[], int &size);
void menu();
void quanly(char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101], char msv[][15], char email[][30], char tenlop[], int &size);
void themsinhvien(char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101], int &size, bool &cm, bool &sx, bool &em);
void nhap(int n, char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101]);
void sapxepten(char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101], char msv[][15], char email[][30], bool &sx, int size);
void hoandoi(int i, int j, char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101], char msv[][15], char email[][30]);
void xoasinhvien(char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101], char msv[][15], char email[][30],bool cm, int &size);
void gan(int i, int j, char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101]);
void timsinhvien(char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101], char msv[][15], char email[][30], bool cm, int size);
void capmasinhvien(char msv[][15], bool sx, bool &cm, int size);
void capemail(char msv[][15], char email[][30], bool cm, bool &em, int size);
void in(char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101], char msv[][15], char email[][30], char tenlop[], int size, bool sx, bool cm, bool em);
void output(char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101], char msv[][15], char email[][30], char tenlop[], int size);

int main(){	
	
	char holot[101][30];
	char ten[101][20];
	char ngaysinh[101][20];
	char gioitinh[101][10];
	char diachi[101][101];
	char msv[101][15];
	char email[101][30];
	char tenlop[101];
	int size = 0;
	strcpy(msv[0],"102190345");
	tieude();
	dangnhap();
	input(holot,ten,ngaysinh,gioitinh,diachi,msv,email,tenlop,size);
	menu();
	quanly(holot,ten,ngaysinh,gioitinh,diachi,msv,email,tenlop,size);
	output(holot,ten,ngaysinh,gioitinh,diachi,msv,email,tenlop,size);	
	
	return 0;
}

void tieude(){
	cout<<"**********************************************************************************************************************"<<endl;
	cout<<"*                                                   DO AN CO SO A                                                    *"<<endl;
	cout<<"*                                DE TAI: XAY DUNG UNG DUNG QUAN LY DANH SACH SINH VIEN                               *"<<endl;
	cout<<"*                                      GIANG VIEN HUONG DAN: TRAN HO THUY TIEN                                       *"<<endl;
	cout<<"*                                  SINH VIEN THUC HIEN: PHAM NGOC HIEU-19TCLCNHAT2                                   *"<<endl;
	cout<<"*                                                       HO THI HIEU-19TCLCNHAT2                                      *"<<endl;                                                                                                    
	cout<<"**********************************************************************************************************************"<<endl;
	cout<<endl;
}

int gety() { 
CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
       GetConsoleScreenBufferInfo(h,&csbi);
    return csbi.dwCursorPosition.Y;
}

void gotoxy(int x, int y) {
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void dangnhap(){
	char username[25];
	char password[25];
	int i=0,j,X,Y;
	
	char c;
	strcpy(username,"admin");
	strcpy(password,"123456");	
	char tendangnhap[25];
	char matkhau[25];	
		cout<<"Ten dang nhap: ";
		cin>>tendangnhap;
		i = 0;
		X=0;
		cout<<"Mat khau: ";
		do {
			c = getch();
			if(c!=8&&c!=13) {
				cout<<"*";	
				matkhau[i] = c;
				i++;
				X++;
			}
			if(c==8){
				if(i>0) {
					Y = gety();
					gotoxy(10+X-1,Y);
					cout<<" ";
					gotoxy(10+X-1,Y);
					matkhau[i-1] = 0;
					i--;
					X--;
				}
			}	
	 	} while(c!=13);
	
	while((strcmp(tendangnhap,username)!=0)||(strcmp(matkhau,password)!=0)){
		system("cls");
		tieude();
		cout<<"Sai ten dang nhap hoac mat khau!\n";
		cout<<"Ten dang nhap: ";
		cin>>tendangnhap;
		i = 0;
		X=0;
		memset(matkhau,0,sizeof(matkhau));
		cout<<"Mat khau: ";
		do {
			c = getch();
			if(c!=8&&c!=13) {
				cout<<"*";	
				matkhau[i] = c;
				i++;
				X++;
			}
			if(c==8){
				if(i>0) {
					Y = gety();
					gotoxy(10+X-1,Y);
					cout<<" ";
					gotoxy(10+X-1,Y);
					matkhau[i-1] = 0;
					i--;
					X--;
				}
			}	
	 	} while(c!=13);	
	}
	cout<<endl;
	cout<<endl;
}

void input(char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101], char msv[][15], char email[][30], char tenlop[], int &size){	
	char tenlop1[101],tenlop2[101];
	FILE *f;
	int k;
	do {
		cout<<"Nhap ten lop : ";
		fflush(stdin);
		fgets(tenlop1,sizeof(tenlop1),stdin);
		k = strlen(tenlop1);
		tenlop1[k-1] = 0;
		strcpy(tenlop2,"C:\\Users\\Admin\\Desktop\\C\\");
		strcat(tenlop2,tenlop1);
		strcat(tenlop2,".txt");
		f = fopen(tenlop2,"rt");
		if(f==NULL) {
			system("cls");
			tieude();
			cout<<"Lop khong ton tai!"<<endl;	
		}
	} while(f==NULL);
	strcpy(tenlop,tenlop1);
	int i,j;
	i = 0;
	char tam;
	while (1){
		tam = getc(f);
		if(tam==10||tam==EOF) {
			break;
		} 	
	}
	bool c = feof(f);
	while(!c){
		i++;
		fgets(msv[i],10*sizeof(char),f);
		fgetc(f);
		fgets(holot[i],23*sizeof(char),f);
		fgetc(f);
		fgets(ten[i],9*sizeof(char),f);
		fgetc(f);
		fgets(ngaysinh[i],11*sizeof(char),f);
		fgetc(f);
		fgets(gioitinh[i],10*sizeof(char),f);
		fgetc(f);
		fgets(email[i],24*sizeof(char),f);
		fgetc(f);
		fgets(diachi[i],sizeof(diachi[i]),f);
		j = strlen(diachi[i]);
		if(diachi[i][j-1]==10||diachi[i][j-1]==13) diachi[i][j-1] = 0;
		c = feof(f);			
	}
	
	size = i;
	cout<<endl;
	system("cls");
	tieude();		
	fclose(f);
	return ;
}

void menu(){
	
	cout<<"                                                         MENU                                                         "<<endl;
	cout<<"**********************************************************************************************************************"<<endl;
	cout<<"*      1-Them sinh vien.    2-Sap xep danh sach.    3-Xoa sinh vien.    4-Tim sinh vien.    5-Cap ma sinh vien.      *"<<endl;
	cout<<"*                                   6.Cap email.    7-In ra danh sach.    8-Thoat.                                   *"<<endl;
	cout<<"**********************************************************************************************************************"<<endl;    
}

void quanly(char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101], char msv[][15], char email[][30], char tenlop[], int &size){
	bool sx,cm,em;
	sx = cm = em = true;
	char c;
	do {
		cout<<"Nhap lua chon: ";
		fflush(stdin);
		cin>>c;
		cout<<endl;
		
		while(c<'1'||c>'8') {
		cout<<"Nhap lai: ";
		fflush(stdin);
		cin>>c;
		cout<<endl;
		}
		
		if(c=='1') themsinhvien(holot,ten,ngaysinh,gioitinh,diachi,size,cm,sx,em);
		if(c=='2') sapxepten(holot,ten,ngaysinh,gioitinh,diachi,msv,email,sx,size);
		if(c=='3') xoasinhvien(holot,ten,ngaysinh,gioitinh,diachi,msv,email,cm,size);
		if(c=='4') timsinhvien(holot,ten,ngaysinh,gioitinh,diachi,msv,email,cm,size);
		if(c=='5') capmasinhvien(msv,sx,cm,size);
		if(c=='6') capemail(msv,email,cm,em, size);
		if(c=='7') in(holot,ten,ngaysinh,gioitinh,diachi,msv,email,tenlop,size,sx,cm,em);	
	}
	while(c!='8');
	cout<<"Ket thuc chuong trinh !";
	return;
}

void themsinhvien(char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101], int &size, bool &cm, bool &sx, bool &em){
	sx = false;
	cm = false;
	em = false;
	
	if(size>=100) {
		cout<<"Danh sach da day !"<<endl;
	}
	else {
		size++;
		nhap(size,holot,ten,ngaysinh,gioitinh,diachi);
	}
	cout<<"Bam phim bat ky de tiep tuc: ";
	getch();
	system("cls");
	tieude();
	menu();
	return;	
}

void nhap(int n, char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101]){
	int j,i;
	cout<<"Ho lot: ";
	fflush(stdin);
	fgets(holot[n],sizeof(holot[n]),stdin);
	j = strlen(holot[n]);
	for(i=j-1;i<=21;i++) holot[n][i] = ' ';
	strupr(holot[n]);
	
	cout<<"Ten: ";
	fflush(stdin);
	fgets(ten[n],sizeof(ten[n]),stdin);
	j = strlen(ten[n]);
	for(i=j-1;i<=7;i++) ten[n][i] = ' ';
	strupr(ten[n]);
	
	do {
		cout<<"Ngay sinh: ";
		fflush(stdin);
		fgets(ngaysinh[n],sizeof(ngaysinh[n]),stdin);
		j = strlen(ngaysinh[n]);
		ngaysinh[n][j-1]=0;
	} while(j!=11||ngaysinh[n][2]!='/'||ngaysinh[n][5]!='/'||ngaysinh[n][0]<48||ngaysinh[n][0]>57||ngaysinh[n][1]<48||ngaysinh[n][1]>57||ngaysinh[n][3]<48||ngaysinh[n][3]>57||ngaysinh[n][4]<48||ngaysinh[n][4]>57||ngaysinh[n][6]<48||ngaysinh[n][6]>57||ngaysinh[n][7]<48||ngaysinh[n][7]>57||ngaysinh[n][8]<48||ngaysinh[n][8]>57||ngaysinh[n][9]<48||ngaysinh[n][9]>57);
	
	do {
		cout<<"Gioi tinh: ";
		fflush(stdin);
		fgets(gioitinh[n],sizeof(gioitinh[n]),stdin);
		j = strlen(gioitinh[n]);
		for(i=(j-1);i<=8;i++) gioitinh[n][i] = ' ';
	} while(strcmp(gioitinh[n],"Nam      ")!=0&&strcmp(gioitinh[n],"Nu       ")!=0&&strcmp(gioitinh[n],"Khac     ")!=0);
	
	cout<<"Dia chi: ";
	fflush(stdin);
	fgets(diachi[n],sizeof(diachi[n]),stdin);
	j = strlen(diachi[n]);
	diachi[n][j-1] = 0;
	cout<<endl;
}

void sapxepten(char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101], char msv[][15], char email[][30], bool &sx, int size){
	if(size==0) {
		cout<<"Danh sach sinh vien trong!"<<endl;
		cout<<endl;
		cout<<"Bam phim bat ky de tiep tuc: ";
		getch();
		system("cls");
		tieude();
		menu();
		return;
	}
	
	int i,j,l;
	int tam,dem,tam1;
	for(i=1;i<size;i++){
		tam = i;
		for(j=i+1;j<=size;j++){
			if(strcmp(ten[tam],ten[j])>0) {
				tam = j;
			}
		}
		hoandoi(i,tam,holot,ten,ngaysinh,gioitinh,diachi,msv,email);
	}
	
	for(i=1;i<size;i++){
		if(!strcmp(ten[i],ten[i+1])){
			tam1 = i;
			while(!strcmp(ten[i],ten[i+1])&&(i<size)){
			i++;
			}
			for(j=tam1;j<i;j++){
				tam = j;
				for(l=j+1;l<=i;l++){					
					if(strcmp(holot[tam],holot[l])>0) {
					tam = l;
					}					
				}
				hoandoi(tam,j,holot,ten,ngaysinh,gioitinh,diachi,msv,email);
			}
		}		
	}
	sx = true;
	cout<<"Da sap xep danh sach!"<<endl;
	cout<<endl;
	cout<<"Bam phim bat ky de tiep tuc: ";
	getch();
	system("cls");
	tieude();
	menu();
	return;
}

void hoandoi(int i, int j, char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101], char msv[][15], char email[][30]){
	char holot1[30];
	char ten1[20];
	char ngaysinh1[20];
	char gioitinh1[10];
	char diachi1[101];
	char email1[30];
	char msv1[15];
	
	strcpy(holot1,holot[i]);
	strcpy(ten1,ten[i]);
	strcpy(ngaysinh1,ngaysinh[i]);
	strcpy(gioitinh1,gioitinh[i]);
	strcpy(diachi1,diachi[i]);
	strcpy(email1,email[i]);
	strcpy(msv1,msv[i]);
	
	strcpy(holot[i],holot[j]);
	strcpy(ten[i],ten[j]);
	strcpy(ngaysinh[i],ngaysinh[j]);
	strcpy(gioitinh[i],gioitinh[j]);
	strcpy(diachi[i],diachi[j]);
	strcpy(email[i],email[j]);
	strcpy(msv[i],msv[j]);
	
	strcpy(holot[j],holot1);
	strcpy(ten[j],ten1);
	strcpy(ngaysinh[j],ngaysinh1);
	strcpy(gioitinh[j],gioitinh1);
	strcpy(diachi[j],diachi1);
	strcpy(email[j],email1);
	strcpy(msv[j],msv1);	
}

void xoasinhvien(char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101], char msv[][15], char email[][30],bool cm, int &size){
	if(size==0) {
		cout<<"Danh sach sinh vien trong!"<<endl;
		cout<<endl;
		cout<<"Bam phim bat ky de tiep tuc: ";
		getch();
		system("cls");
		tieude();
		menu();
		return;
	}
	
	if(!cm) {
		cout<<"Chua cap ma so sinh vien !"<<endl;
		cout<<endl;
		cout<<"Bam phim bat ky de tiep tuc: ";
		getch();
		system("cls");
		tieude();
		menu();
		return ;
	}
	
	cout<<"Nhap ma so sinh vien can xoa: ";
	char ms[15];
	int i,j,k;
	fflush(stdin);
	fgets(ms,sizeof(ms),stdin);
	j = strlen(ms);
	ms[j-1] = 0;
	cout<<endl;
	
	for(i=1;i<=size;i++){
		if(!strcmp(ms,msv[i])){
			cout<<"Da xoa sinh vien co ma so "<<ms<<" trong danh sach lop!"<<endl;
			cout<<"STT | MSV       | Ho Lot                 | Ten      | Ngay Sinh  | Gioi Tinh | Email                   | Dia Chi"<<endl;
			printf("%-3d | ",i);
			printf("%9s | ",msv[i]);
			cout<<holot[i]<<" | ";
			cout<<ten[i]<<" | ";
			cout<<ngaysinh[i]<<" | ";
			cout<<gioitinh[i]<<" | ";
			printf("%23s | ",email[i]);
			cout<<diachi[i];
			cout<<endl;
			cout<<endl;
			
			for(j=i;j<size;j++){
				gan(j,j+1,holot,ten,ngaysinh,gioitinh,diachi);
			}
				
			k = size;
			size--;
			memset(holot[k],0,sizeof(holot[k]));
			memset(ten[k],0,sizeof(ten[k]));
			memset(ngaysinh[k],0,sizeof(ngaysinh[k]));
			memset(gioitinh[k],0,sizeof(gioitinh[k]));
			memset(diachi[k],0,sizeof(diachi[k]));
			memset(msv[k],0,sizeof(msv[k]));
			memset(email[k],0,sizeof(email[k]));
			cout<<"Bam phim bat ky de tiep tuc: ";
			getch();
			system("cls");
			tieude();
			menu();	
			return ;
		}
	}
	cout<<"Khong co sinh vien co ma so "<<ms<<" trong danh sach lop!"<<endl;
	cout<<endl;
	cout<<"Bam phim bat ky de tiep tuc: ";
	getch();
	system("cls");
	tieude();
	menu();
	return;
}

void gan(int i, int j, char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101]){
	strcpy(holot[i],holot[j]);
	strcpy(ten[i],ten[j]);
	strcpy(ngaysinh[i],ngaysinh[j]);
	strcpy(gioitinh[i],gioitinh[j]);
	strcpy(diachi[i],diachi[j]);
}

void timsinhvien(char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101], char msv[][15], char email[][30], bool cm, int size){	

	if(size==0) {
		cout<<"Danh sach sinh vien trong!"<<endl;
		cout<<endl;
		cout<<"Bam phim bat ky de tiep tuc: ";
		getch();
		system("cls");
		tieude();
		menu();
		return;
	}
	
	if(!cm) {
		cout<<"Chua cap ma sinh vien !"<<endl;
		cout<<endl;
		cout<<"Bam phim bat ky de tiep tuc: ";
		getch();
		system("cls");
		tieude();
		menu();
		return ;
	}
	
	int i,j;
	char ms[15];
	cout<<"Nhap ma sinh vien can tim : ";
	fflush(stdin);
	fgets(ms,sizeof(ms),stdin);
	j = strlen(ms);
	ms[j-1] = 0;
	cout<<endl;
	
	for(i=1;i<=size;i++){
		if(!strcmp(ms,msv[i])) {
			cout<<"Tim thay sinh vien co ma so "<<ms<<" !"<<endl;
			cout<<endl;
			cout<<"STT | MSV       | Ho Lot                 | Ten      | Ngay Sinh  | Gioi Tinh | Email                   | Dia Chi"<<endl;
			printf("%-3d | ",i);
			printf("%9s | ",msv[i]);
			cout<<holot[i]<<" | ";
			cout<<ten[i]<<" | ";
			cout<<ngaysinh[i]<<" | ";
			cout<<gioitinh[i]<<" | ";
			printf("%23s | ",email[i]);
			cout<<diachi[i];
			cout<<endl;
			cout<<endl;
			cout<<"Bam phim bat ky de tiep tuc: ";
			getch();
			system("cls");
			tieude();
			menu();
			return ;
		}	
	}
	cout<<"Khong tim thay sinh vien co ma so "<<ms<<" !"<<endl;
	cout<<endl;
	cout<<"Bam phim bat ky de tiep tuc: ";
	getch();
	system("cls");
	tieude();
	menu();
	return ;
}

void capmasinhvien(char msv[][15], bool sx, bool &cm, int size){	
	if(size==0) {
		cout<<"Danh sach sinh vien trong!"<<endl;
		cout<<endl;
		cout<<"Bam phim bat ky de tiep tuc: ";
		getch();
		system("cls");
		tieude();
		menu();
		return;
	}
	
	if(!sx) {
		cout<<"Chua sap xep!"<<endl;
		cout<<endl;
		cout<<"Bam phim bat ky de tiep tuc: ";
		getch();
		system("cls");
		tieude();
		menu();
		return ;
	}
	int i,j,k;
	
	for(i=1;i<=size;i++){
		j = 8;
		while(msv[i-1][j]=='9') j--;
		strcpy(msv[i],msv[i-1]);
		msv[i][j] = msv[i-1][j] + 1;
		for(k=j+1;k<=8;k++) msv[i][k] = '0';		
	}
	
	cm = true;
	cout<<"Da cap xong ma sinh vien! "<<endl;
	cout<<endl;
	cout<<"Bam phim bat ky de tiep tuc: ";
	getch();
	system("cls");
	tieude();
	menu();
}

void capemail(char msv[][15], char email[][30], bool cm, bool &em, int size){
	if(size==0) {
		cout<<"Danh sach sinh vien trong!"<<endl;
		cout<<endl;
		cout<<"Bam phim bat ky de tiep tuc: ";
		getch();
		system("cls");
		tieude();
		menu();
		return;
	}
	
	if(!cm) {
		cout<<"Chua cap ma sinh vien !"<<endl;
		cout<<endl;
		cout<<"Bam phim bat ky de tiep tuc: ";
		getch();
		system("cls");
		tieude();
		menu();
		return;
	}
	
	int i,j,k;
	for(i=1;i<=size;i++){
		strcpy(email[i],msv[i]);
		strcat(email[i],"@sv.dut.edu.vn");
	}		
	em = true;
	cout<<"Da cap xong email! "<<endl;
	cout<<endl;
	cout<<"Bam phim bat ky de tiep tuc: ";
	getch();
	system("cls");
	tieude();
	menu();
}

void in(char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101], char msv[][15], char email[][30], char tenlop[], int size, bool sx, bool cm, bool em){
	if(size==0) {
		cout<<"Lop khong co sinh vien! "<<endl;
		cout<<endl;
		cout<<"Bam phim bat ky de tiep tuc: ";
		getch();
		system("cls");
		tieude();
		menu();
		return;
	}
	if(!sx) {
		cout<<"Chua sap xep danh sach!"<<endl;
		cout<<endl;
		cout<<"Bam phim bat ky de tiep tuc: ";
		getch();
		system("cls");
		tieude();
		menu();
		return;
	}
	if(!cm) {
		cout<<"Chua cap ma sinh vien!"<<endl;
		cout<<endl;
		cout<<"Bam phim bat ky de tiep tuc: ";
		getch();
		system("cls");
		tieude();
		menu();
		return;
	}
	if(!em){
		cout<<"Chua cap email!"<<endl;
		cout<<endl;
		cout<<"Bam phim bat ky de tiep tuc: ";
		getch();
		system("cls");
		tieude();
		menu();
		return;
	}
	cout<<"                                         Danh sach sinh vien lop "<<tenlop<<":                                       "<<endl;
	cout<<endl;
	cout<<"STT | MSV       | Ho Lot                 | Ten      | Ngay Sinh  | Gioi Tinh | Email                   | Dia Chi"<<endl;
	int i=1;
	while(i<=size){
		printf("%-3d | ",i);
		printf("%9s | ",msv[i]);
		cout<<holot[i]<<" | ";
		cout<<ten[i]<<" | ";
		cout<<ngaysinh[i]<<" | ";
		cout<<gioitinh[i]<<" | ";
		printf("%23s | ",email[i]);
		cout<<diachi[i];
		cout<<endl;
		i++;
	}
	cout<<endl;
	cout<<"Bam phim bat ky de tiep tuc: ";
	getch();
	system("cls");
	tieude();
	menu();
}

void output(char holot[][30], char ten[][20], char ngaysinh[][20], char gioitinh[][10], char diachi[][101], char msv[][15], char email[][30], char tenlop[], int size){
	FILE *f;
	char tenlop1[101];
	strcpy(tenlop1,"C:\\Users\\Admin\\Desktop\\C\\");
	strcat(tenlop1,tenlop);
	strcat(tenlop1,".txt");
	f = fopen(tenlop1,"wt");
	int i;
	fprintf(f,"MSV       Ho Lot                 Ten      Ngay Sinh  Gioi Tinh Email                   Dia Chi","");
	for(i=1;i<=size;i++){
		if(i==1) fprintf(f,"\n","");
		fprintf(f,"%9s ",msv[i]);
		fprintf(f,"%s ",holot[i]);
		fprintf(f,"%s ",ten[i]);
		fprintf(f,"%s ",ngaysinh[i]);
		fprintf(f,"%s ",gioitinh[i]);
		fprintf(f,"%23s ",email[i]);
		if(i!=size) {
			fprintf(f,"%s\n",diachi[i]);
		}
		else fprintf(f,"%s",diachi[i]);
	}
	fclose(f);
	return ;
}

