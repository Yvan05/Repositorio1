/*Miguel Diaz
354292
practica 10: Curp*/

//**********************************************************************************************************************************************
//**********************************************************************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

//**********************************************************************************************************************************************
//**********************************************************************************************************************************************

#define TRUE 1
#define FALSE 0

//**********************************************************************************************************************************************
//**********************************************************************************************************************************************

void Curp(void);
void ValidaCad(char[],char[]);
void ValidaCadNum(char[],char[],int,int,int);
void ValidaNombre(char[]);
void Estados(char[]);
int ValidaNum(int,int,int);
char BuscaVocal(char[]);
char BuscaConsonante(char[]);
void ValidaPamal(char[]);

//**********************************************************************************************************************************************
//**********************************************************************************************************************************************

int main()
{
	srand(time(0));
	setlocale(LC_ALL,"spanish");
	Curp();
	return 0;
}

//**********************************************************************************************************************************************
//**********************************************************************************************************************************************

void Curp()
{
	char curp[20],appat[15],apmat[15],nom1[15],nom2[15],sexo[3],dia[3],mes[3],anio[5];
	int dMes[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},anv,mesv,sv,rep;
	
	do{
	ValidaCad(nom1,"Ingresa tu primer nombre: ");
	ValidaCad(nom2,"Ingresa tu segundo nombre: ");
	ValidaCad(appat,"Ingresa tu apellido paterno: ");
	ValidaCad(apmat,"Ingresa tu apellido materno: ");
	ValidaCadNum(anio,"Ingresa tu año de nacimiento en 4 digitos (AAAA): ",1900,2019,4);
	ValidaCadNum(mes,"Ingresa tu mes de nacimiento en 2 digitos (mm): ",1,12,2);
	anv=atoi(anio);
	mesv=atoi(mes);
	if(anv%4==0&&mesv==2)
	{
		dMes[2]=29;
	}
	ValidaCadNum(dia,"Ingresa tu dia de nacimiento en 2 digitos (dd): ",1,dMes[mesv],2);
	curp[0]=appat[0];
	curp[1]=BuscaVocal(appat);
	curp[2]=apmat[0];
	if(nom1=="MARIA"||nom1=="MA."||nom1=="MA"||nom1=="JOSE"||nom1=="J."||nom1=="J")
	  {
	  	curp[3]=nom2[0];
	  }
	 else
	  {
	  	curp[3]=nom1[0];
	  }
	curp[4]=anio[2];
	curp[5]=anio[3];
	curp[6]=mes[0];
	curp[7]=mes[1];
	curp[8]=dia[0];
	curp[9]=dia[1];
	ValidaCadNum(sexo,"Elije una opcion:\n1.-Hombre.\n2.-Mujer.\n",1,2,1);
	sv=atoi(sexo);
	if(sv==1)
	  {
	  	curp[10]='H';
	  }
	 else
	  {
	  	curp[10]='M';
	  }
	Estados(curp);
	curp[13]=BuscaConsonante(appat);
	curp[14]=BuscaConsonante(apmat);
	curp[15]=BuscaConsonante(nom1);
	if(anv>=1900&&anv<2000)
	  {
	  	curp[16]='0';
	  }
	 else
	  {
	  	curp[16]='1';
	  }
	curp[17]='1';
	ValidaPamal(curp);
	printf("\n\nTu CURP es: %s \n\n",curp);
	printf("Desea volver a crear otro CURP? \n1.-Si\n2.-No\n");
	scanf("%d",&rep);
	ValidaNum(1,2,rep);
	system("pause");
	}while(rep!=2);
}


//**********************************************************************************************************************************************
//**********************************************************************************************************************************************

void ValidaCad(char cad[],char mens[])
{
	int i;
	unsigned char letra;
	
	do{
		letra=TRUE;
		puts(mens);
		fflush(stdin);
		gets(cad);
		strupr(cad);
		for(i=0;i<strlen(cad);i++)
		   {
		   	if(cad[i]<65&&cad[i]>90||cad[0]==' ')
		   	{
		   		printf("Solo se aceptan letras. Intente denuevo.");
		   		letra=FALSE;
		   		system("pause");
			}
		   }
	  }while(letra==FALSE);
}

//**********************************************************************************************************************************************
//**********************************************************************************************************************************************

void ValidaCadNum(char cad[],char mens[],int ri, int rf,int tam)
{
	
	char cadena[20];
	int num,x,ban;
	
	do{
		ban=FALSE;
		puts(mens);
		fflush(stdin);
		gets(cad);
		num=atoi(cad);
		x=strlen(cad);
		if(num<ri||num>rf||x!=tam)
		  {
		  	printf("Dato fuera de rango. Intente denuevo.");
		  	system("pause");
		  	ban=TRUE;
		  }
	  }while(ban==TRUE);
}

//**********************************************************************************************************************************************
//**********************************************************************************************************************************************

void Estados(char curp[])
{
	int opc,x;
	
	do{
		system("cls");
		printf("**MENU DE ESTADOS**");
		printf("\nElija una opcion: ");
		printf("\n1.-Aguascalientes.");
		printf("\n2.-Baja California.");
		printf("\n3.-Baja California Sur.");
		printf("\n4.-Campeche.");
		printf("\n5.-Chiapas.");
		printf("\n6.-Chihuahua.");
		printf("\n7.-Ciudad de Mexico");
		printf("\n8.-Coahuila.");
		printf("\n9.-Colima.");
		printf("\n10.-Durango.");
		printf("\n11.-Guanajuato.");
		printf("\n12.-Guerrero.");
		printf("\n13.-Hidalgo.");
		printf("\n14.-Jalisco.");
		printf("\n15.-Mexico.");
		printf("\n16.-Michoacan.");
		printf("\n17.-Morelos.");
		printf("\n18.-Nayarit.");
		printf("\n19.-Nuevo Leon.");
		printf("\n20.-Oaxaca.");
		printf("\n21.-Puebla.");
		printf("\n22.-Queretaro.");
		printf("\n23.-Quintana Roo.");
		printf("\n24.-San Luis Potosi.");
		printf("\n25.-Sinaloa.");
		printf("\n26.-Sonora.");
		printf("\n27.-Tabasco.");
		printf("\n28.-Tamaulipas.");
		printf("\n29.-Tlaxcala.");
		printf("\n30.-Veracruz.");
		printf("\n31.-Yucatan.");
		printf("\n32.-Zacatecas.");
		printf("\n33.-Extranjero. ");
		scanf("%d",&opc);
		x=ValidaNum(1,33,opc);
	  }while(x==0);
	switch(opc)
	{
		case 1:
				curp[11]='A';
				curp[12]='G';
				break;
		case 2:
				curp[11]='B';
				curp[12]='C';
				break;
		case 3:
				curp[11]='B';
				curp[12]='S';
				break;
		case 4:
				curp[11]='C';
				curp[12]='M';
				break;
		case 5:
				curp[11]='C';
				curp[12]='S';
				break;
		case 6:
				curp[11]='C';
				curp[12]='H';
				break;
		case 7:
				curp[11]='C';
				curp[12]='X';
				break;
		case 8:
				curp[11]='C';
				curp[12]='O';
				break;
		case 9:
				curp[11]='C';
				curp[12]='L';
				break;
		case 10:
				curp[11]='D';
				curp[12]='G';
				break;
		case 11:
				curp[11]='G';
				curp[12]='T';
				break;
		case 12:
				curp[11]='G';
				curp[12]='R';
				break;
		case 13:
				curp[11]='H';
				curp[12]='G';
				break;
		case 14:
				curp[11]='J';
				curp[12]='C';
				break;
		case 15:
				curp[11]='E';
				curp[12]='M';
				break;
		case 16:
				curp[11]='M';
				curp[12]='I';
				break;
		case 17:
				curp[11]='M';
				curp[12]='O';
				break;
		case 18:
				curp[11]='N';
				curp[12]='A';
				break;
		case 19:
				curp[11]='N';
				curp[12]='L';
				break;
		case 20:
				curp[11]='O';
				curp[12]='A';
				break;
		case 21:
				curp[11]='P';
				curp[12]='U';
				break;
		case 22:
				curp[11]='Q';
				curp[12]='T';
				break;
		case 23:
				curp[11]='Q';
				curp[12]='R';
				break;
		case 24:
				curp[11]='S';
				curp[12]='L';
				break;
		case 25:
				curp[11]='S';
				curp[12]='I';
				break;
		case 26:
				curp[11]='S';
				curp[12]='O';
				break;
		case 27:
				curp[11]='T';
				curp[12]='B';
				break;
		case 28:
				curp[11]='T';
				curp[12]='M';
				break;
		case 29:
				curp[11]='T';
				curp[12]='L';
				break;
		case 30:
				curp[11]='V';
				curp[12]='E';
				break;
		case 31:
				curp[11]='Y';
				curp[12]='U';
				break;
		case 32:
				curp[11]='Z';
				curp[12]='A';
				break;
		case 33:
				curp[11]='N';
				curp[12]='E';
	}
}

//**********************************************************************************************************************************************
//**********************************************************************************************************************************************

int ValidaNum(int ri,int rf,int num)
{
	int ban;
	
	if(num>=ri&&num<=rf)
	  {
		return 1;
	  }
	 else
	  {
	 	printf("Numero fuera del rango. Ingrese otro: ");
	 	system("pause");
	 	return 0;
	  }

}

//**********************************************************************************************************************************************
//**********************************************************************************************************************************************

char BuscaVocal(char cad[])
{
	int i,x=0;
	
	for(i=1;i<strlen(cad);i++)
	   {
	   	if(cad[i]=='A'||cad[i]=='E'||cad[i]=='I'||cad[i]=='O'||cad[i]=='U')
	   	  {
	   	  	x==1;
			return cad[i];
		  }
	   }
	if(x==0)
	  {
	  	return 'X';
	  }	
}

//**********************************************************************************************************************************************
//**********************************************************************************************************************************************

char BuscaConsonante(char cad[])
{
	int i;
	
	for(i=1;i<strlen(cad);i++)
	for(i=1;i<strlen(cad);i++)
	   {
	   	if(cad[i]!='A'&&cad[i]!='E'&&cad[i]!='I'&&cad[i]!='O'&&cad[i]!='U')
	   	  {
	   	  	if(cad[i]=='Ñ')
	   	  	  {
	   	  	  	return 'X';
			  }
			return cad[i];
		  }
	   }
}

//**********************************************************************************************************************************************
//**********************************************************************************************************************************************

void ValidaPamal(char curp[])
{
	char palinc[81][5]={"BACA","BAKA","BUEI","BUEY","CACA","CACO","CAGA","CAGO","CAKA","CAKO","COGE","COGI","COJA","COJE","COJI","COJO","COLA","CULO","FALO","FETO","GETA","GUEI","GUEY","JETA","JOTO","KACA","KACO","KAGA","KAGO","KAKA","KAKO","KOGE","KOGI","KOJA","KOJE","KOJI","KOJO","KOLA","KULO","LILO","LOCA","LOCO","LOKA","LOKO","MAME","MAMO","MEAR","MEAS","MEON","MIAR","MION","MOCO","MOKO","MULA","MULO","NACA","NACO","PEDA","PEDO","PENE","PIPI","PITO","POPO","PUTA","PUTO","QULO","RATA","ROBA","ROBE","ROBO","RUIN","SENO","TETA","VACA","VAGA","VAGO","VAKA","VUEI","VUEY","WUEI","WUEY"};
	int i;
	
	for(i=0;i<81;i++)
	   {
	   	if(palinc[i][0]==curp[0]&&palinc[i][1]==curp[1]&&palinc[i][2]==curp[2]&&palinc[i][3]==curp[3])
	   	  {
	   	  	curp[1]=='X';
		  }
	   }
}


//**************************************************************************************************************************************
//**************************************************************************************************************************************