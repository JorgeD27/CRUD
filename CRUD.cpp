#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include<windows.h>

using namespace std;
const char *nombre_archivo = "archivo.dat";
const char *tem= "tem.dat";
struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int elimin;
	int telefono;
};
void crear();
void leer();
void actualizar();
void Eliminar();
main(){
	leer();
	crear();
	actualizar();
	Eliminar();
}
void leer(){
		system("cls");
		FILE* archivo = fopen(nombre_archivo,"rb");	
		if (!archivo){
			archivo = fopen(nombre_archivo,"w+b");	
		}
		Estudiante estudiante;
		int id=0;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"____________________________________________"<<endl;
		cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"Telefono"<<endl;
		do{
		cout<<"____________________________________________"<<endl;
		cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;	
		}while(feof(archivo)==0);
		fclose(archivo);
		cout<<endl;
}
void actualizar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id;
	Estudiante estudiante;
	string nombre,apellido;
	cout<<"Ingres el ID que desa Modificar:";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres:";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos:";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
	
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
	leer();
}
void crear(){
	char continuar;
	FILE* archivo = fopen(nombre_archivo,"ab");
	Estudiante estudiante;
	string nombre,apellido;
	do{
		fflush(stdin);
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres:";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos:";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Dese Agregar otro Estudiante (s/n):";
		cin>>continuar;
	} while ( (continuar=='s') || (continuar=='S') );
	fclose(archivo);
	leer();
}
void Eliminar(){
	
		//char respuesta[20];
		//char elim[50];

//FILE* archivo = fopen(nombre_archivo,"r+b");
//FILE* archivo1 = fopen(tem,"r+b");
	Estudiante estudiante;
int id;
		int idd;
	ifstream salida;
	salida.open("archivo.dat", ios::in);
	
	ofstream entrada;
	entrada.open("tem.dat", ios::in);
	
	
	if(salida.fail()){
		cout<<"Hubo un error al abrir el archivo"<<endl;
	}
	else{

		cout<<"Ingrese el ID que desea Eliminar:";
		cin>>idd;
		
		salida>>estudiante.codigo;
	}
	while(!salida.eof()){
		salida>>id;
		salida>>idd;
		salida>>estudiante.codigo;
	
		if(idd==id){
			cout<<"El registro se ha eliminado";
			Sleep(1500);
			getch();
		}
		else{
			entrada<<id<<" "<<estudiante.codigo<<" "<<estudiante.nombres<<" "<<estudiante.apellidos<<" "<<estudiante.telefono<<endl;
		}
	}
	entrada.close();
	salida.close();
	
	remove("archivo.dat");
	rename("tem.dat", "archivo.dat");

}
