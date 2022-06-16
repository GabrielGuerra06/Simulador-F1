#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//Bases de datos (declaramos toda la base de datos de manera global ya que, en cada funcion de nuestro programa las llamamos, además los valores deben actualizarse dependiendo de cada función)
string nombres[14]={"Juan","Roberto","Sergio","Neymar","Messi","Andrea","Cristano","Mbappe", "Lewis", "Max", "Laura", "Tanguy"};
int edad[14]={23,31,27,28,21,32,25,24,20,26,29,30};
string nacionalidad[14]={"México","España","Mexicano","Brasil", "Argentina","Estados Unidos","Portugal","Francia","Inglaterra","Holanda","Alemania","Zimbabue"};
string equipos[14]={"Mercedez","Red Bull","Ferrari","McClaren","Haas","Renault","Mercedez","Red Bull","Ferrari","McClaren","Haas","Renault"};
int num[14]={33,77,11,22,7,47,88,99,10,4,1,25};
//los puntos por carrera los declaramos de manera global ya que, los utilizamos para asignar nuestros ganadores con un puntaje en varias funciones
int PuntosPorCarrrera[14]={25,18,15,12,10,0,0,0,0,0,0,0,0,0};
// las carreras se usan en la funcion 5 y 6, son globales ya que, antes de entrar a nuestra funcion su valor se resta dependiendo de la cantidad de carreras de los corredores
string puntuacion[25];
int carreras[14]={5,5,5,5,5,5,5,5,5,5,5,5,5,5};
//nuestros ganadores y circuitos se les asigna un  valor dentro de la funcion, por facilidad, las declaramos globales para no volverlas a llamar cada funcion
string ganadores[15];
string circuitos[5];
//los fallos los utilizamos en más de 2 funciones, por eso, las establecemos globales 
int fallostotales[14];
//nuestros ganadores y los resultados son valores asignados y que cambian desde el incio, por ello debe de ir antes de las ultimas funciones
string ganadoresDeCarrera[5];
int resultados[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//Funciones

/////////1 BASE DE DATOS
int AltaDePilotos(){
  cout<<"Nombre"<<", "<<"Edad"<<", "<<"Nacionalidad"<<", "<<"Equipo"<<", "<<"Numero"<<"\n \n";
      for(int i=0; i<14; i++){
      cout<<nombres[i]<<", "<<edad[i]<<", "<<nacionalidad[i]<<", "<<equipos[i]<<", "<<num[i]<<"\n";
      }
      
  return 0;
}


//////////////2 SIMULACION DE CARRERA
int SimuladorDeCarrera(){
  srand(time(NULL));
  int fallas[14];
  int llantas[14], motor[14], sistema[14];
  string circuito;
  int posiciones[14];
  int repetidos[14];
  int numero;
  int errores[14];
  int contador=0;
  int c1;
  string c2;
  string c3;
  int puntajes[5]={25,18,15,12,10};
  bool huboGanadorTotal = false;

  for(int j=0; j<1; j++){

    //Checar si hay ganador
    for(int i =0; i<14 ; i++){
      if( resultados[i] >= 50){
        cout<<"\n \t \t\tEL CAMPEON ES: "<<nombres[i]<<" con: "<<resultados[i]<<"pts."<<endl;
        huboGanadorTotal = true;
      }
    }

    cout<<"Ingresa el nombre de un circuito:\n";
    cin>>circuito;
    cout<<"POSICIONES DE INICIO: \n";

    ////POSICIONES DE ARRANQUE
    for(int i = 0; i< 14 ; i++){
      repetidos[i] = 0;
      posiciones[i]= 0 ;
    }

    for(int i=0; i<10;i++){
      numero = rand() % 14 + 1; 
      if(repetidos[numero-1] == 0){
      posiciones[i] = numero-1;
      repetidos[numero-1] = 1;
      cout<<i+1<<" "<<num[posiciones[i]]<<"\n";
      cout<<"";
      }
      else{
        i--;
      }
    } 

    ////FALLOS
    for(int i=0; i<14; i++){
      llantas[i]=rand() % 100 + 1;
      motor[i]=rand() % 100 + 1;
      sistema[i]=rand() % 100 + 1;

      if(llantas[i]<=20 && motor[i]<=30){
        fallas[i]=1;
      }
      else{
        fallas[i]=0;
      }
      if(llantas[i]<=20 && sistema[i]<=40){
        fallas[i]=1;
      }
      else{
        fallas[i]=0;
      }
      if(motor[i]<=30 && sistema[i]<=40){
        fallas[i]=1;
      }
      else{
        fallas[i]=0;
      }
    }
    for(int i=0; i<14; i++){
      if(fallas[i]==1){
        cout<<"\t \t \t \t "<<nombres[i]<<" ha sido penalizado por fallas \n";
        fallostotales[i]+=1;
      }
    }
  
    cout<<"\n";
    // Marcador Final de la Carrera
    for(int i = 0; i< 14 ; i++){
      repetidos[i] = 0;
      posiciones[i]= 0 ;
    }
    cout<<"RESULTADOS: \n";
    for(int i=0; i<5;i++){
      numero = rand() % 14 + 1; 
      if(repetidos[numero-1] == 0){
      posiciones[i] = numero-1;
      repetidos[numero-1] = 1;
      cout<<i+1<<" "<<nombres[posiciones[i]]<<":"<<PuntosPorCarrrera[i]<<"\n";
      puntuacion[contador] = nombres[posiciones[i]];
      ganadoresDeCarrera[i] = nombres[posiciones[i]];

      contador++;
      }
      else{
        i--;
      }
    } 

    //Asignar resultados al arreglo global
    for(int i =0; i<14 ; i++){
      //Recorrer el arreglo de nombres de ganadores
      for(int j =0 ; j<5 ; j++){
        if(nombres[i] == ganadoresDeCarrera[j]){
          //Asignar el puntaje del corredor si se encuentra en la lista de ganadores.
          resultados[i] = resultados[i] + puntajes[j];
        }
      }
    }

  }

  while(huboGanadorTotal!= true){
    cout<<"\t \t\tEL CAMPEON ES: "<<nombres[0]<<" con: "<<resultados[0];
    huboGanadorTotal=true;
  } 
   return 0;
}
/////////////////////3 FILTRO DE PILOTOS
int FiltrarPilotos(){
int filtronum;
string filtro;
char opcion;
int contador=0;
bool encontro=false;
cout<<"Deseas buscar un valor numerico(n) o a traves de palabras(p)";
cin>>opcion;
if(opcion=='n'){
  cout<<"\n Busqueda de edad o numero. Ingresa un valor: ";
  cin>>filtronum;
}
else{
cout<<"\n Busqueda de nombre, nacionalidad o equipo.\n Ingresa la palabra a buscar: (empezando con mayuscula) ";
cin>>filtro;
}

for(int i=0; i<14;i++){
  if(filtro==nombres[i] || filtronum==edad[i] or filtro==nacionalidad[i] || filtro==equipos[i] || filtronum==num[i]){

  encontro=true;
  cout<<nombres[i]<<", "<<edad[i]<<", "<<nacionalidad[i]<<", "<<equipos[i]<<", "<<num[i]<<"\t \t Carreras competidas: ";
  cout<<carreras[i]<<"\n";
  }
}
if(encontro==false){
cout<<"ERROR, valor no encontrado en la base de datos.";
}
  return 0;
}

/////////////4 PILOTOS EN ORDEN
int PilotosOrdenados(){
  int temp;
  string temp2;
  int contador;
  char orden;
  int acomodo;
  cout<<"quieres acomodar los corredores de acuerdo a su numero(1) o su nombre(2)?";
  cin>>acomodo;
  if(acomodo==1){
    cout<<"Quieres la lista por orden ascendente(a) o descendente(d)?\n";
  cin>>orden;
  if(orden=='a'){
for(int i=0;i<14;i++){
  for(int j=i+1;j<14;j++){
    if(num[i]>num[j]){ 
  temp=num[j]; 
  num[j] = num[i]; 
  num[i] = temp; 
  }
    }
      }
    cout << endl;
    for(int i=0;i<14;i++){
    cout<<num[i]<<endl;
}
}
else if(orden=='d'){

  for(int i=0;i<14;i++){
  for(int j=i+1;j<14;j++){
    if(num[j]>num[i]){ 
  temp=num[i]; 
  num[i] = num[j]; 
  num[j] = temp; 
  }
    }
      }
    cout << endl;
    for(int i=0;i<14;i++){
    cout<<num[i]<<endl;
}
}
  }
else if(acomodo==2){
 cout<<"Quieres la lista por orden ascendente(a) o descendente(d)?\n";
  cin>>orden;
  if(orden=='a'){
for(int i=0;i<14;i++){
  for(int j=i+1;j<14;j++){
    if(nombres[i]>nombres[j]){ 
  temp2=nombres[j]; 
  nombres[j] = nombres[i]; 
  nombres[i] =temp2; 
  }
    }
      }
    cout << endl;
    for(int i=0;i<14;i++){
    cout<<nombres[i]<<endl;
}
}
else if(orden=='d'){

  for(int i=0;i<14;i++){
  for(int j=i+1;j<14;j++){
    if(nombres[j]>nombres[i]){ 
  temp2=nombres[i]; 
  nombres[i] = nombres[j]; 
  nombres[j] = temp2; 
  }
    }
      }
    cout << endl;
    for(int i=0;i<14;i++){
    cout<<nombres[i]<<endl;
}
}
}
  return 0;
}
//////////////5 DINERO GENERADO
int DineroPorEquipo(){
int comparador=0;
int contador, dinerototal=0, fallos=0, dinero=0, dinero2=0, fallos2=0, dinerototal2=0;
cout<<"Equipo "<<"\t Carreras totales \t Dinero total \n";
  for(int i=1; i<15; i++){
    int dinero=0, dinerototal=0;
    int fallos=0;
    if(equipos[comparador]==equipos[i]){
      fallos=4000*(fallostotales[i]+fallostotales[comparador]);
      dinero=(carreras[i]+carreras[comparador])*10000;
      dinerototal=dinero-fallos;
      cout<<equipos[comparador]<<"\t"<<carreras[i]+carreras[comparador]<<"\t"<<dinerototal<<"\n";
      comparador++;
    }
  }
    if(equipos[12]==equipos[13]){
      fallos=4000*(fallostotales[12]+fallostotales[13]);
      dinero=(carreras[12]+carreras[13])*10000;
      dinerototal=dinero-fallos;
    cout<<equipos[12]<<"\t"<<carreras[12]+carreras[13]<<"\t"<<dinerototal<<"\n";
    }

    else{
      fallos2=4000*(fallostotales[12]);
      dinero2=(carreras[12])*10000;
      dinerototal2=dinero2-fallos2;
      cout<<equipos[12]<<"\t"<<carreras[12]<<"\t"<<dinerototal2<<"\n";
      //Dos equipos distintos
      fallos=4000*(fallostotales[13]);
      dinero=(carreras[13])*10000;
      dinerototal=dinero-fallos;
      cout<<equipos[13]<<"\t"<<carreras[13]<<"\t"<<dinerototal<<"\n";
    }
  return 0;
}
//}////////////6 FIN
int fin(){
  int temp3, temp6;
  string temp4;
  string temp5;
  string ganador1[14];
  int winners[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  //Definición de variables
  int puntajes[25]={25,18,15,12,10,25,18,15,12,10,25,18,15,12,10,25,18,15,12,10,25,18,15,12,10};   

  cout<<"\nFinalizando...\n";
  for(int i=0; i<5;i++){
    cout<<puntuacion[i]<<"\t";
    cout<<puntajes[i]<<"\n";
    ganador1[0]=puntuacion[0];
  }
  for(int i=5; i<10;i++){
    cout<<puntuacion[i]<<"\t";
    cout<<puntajes[i]<<"\n";  
    ganador1[1]=puntuacion[5];

  }
  for(int i=10; i<15;i++){
    cout<<puntuacion[i]<<"\t";
    cout<<puntajes[i]<<"\n";
    ganador1[2]=puntuacion[10];

  }
  for(int i=15; i<20;i++){
    cout<<puntuacion[i]<<"\t";
    cout<<puntajes[i]<<"\n";
    ganador1[3]=puntuacion[15];
  }
  for(int i=20; i<25;i++){
    cout<<puntuacion[i]<<"\t";
    cout<<puntajes[i]<<"\n";
    ganador1[4]=puntuacion[20];
  }


    for(int i =0; i<14 ; i++){
      
      for(int j =0 ; j<14 ; j++){
        if(nombres[i] == ganador1[j]){
          //Asignar el puntaje del corredor si se encuentra en la lista de ganadores.
          winners[i]+= 1;
        }
      }
    }

cout<<"Nombre"<<", "<<"Equipo"<<", "<<"Puntaje"<<", "<<"Victorias"<<", "<<"Carreras competidas"<<"\n \n";
  for(int i=0;i<14;i++){
    for(int j=i+1;j<14;j++){
      if(resultados[i]<resultados[j]){ 
      temp3=resultados[j]; 
      resultados[j] = resultados[i]; 
      resultados[i] = temp3; 
      temp4=nombres[j]; 
      nombres[j] = nombres[i]; 
      nombres[i] = temp4; 

      temp5=equipos[j]; 
      equipos[j] = equipos[i]; 
      equipos[i] = temp5; 

      temp6=winners[j]; 
      winners[j] = winners[i]; 
      winners[i] = temp6; 

      }
    }
    cout<<nombres[i]<<" , "<<equipos[i]<<" , "<<resultados[i];
  cout<<"pts. , "<<winners[i]<<"V "<<"5cc"<<"\n";
  }
cout<<endl;
return 0;
}


int main() {
  srand(time(NULL));
  string nombre1, nombre2;
  int edad1, edad2;
  string nacion1, nacion2;
  string equipo1, equipo2;
  int num1, num2;
  int opc;
  char enter;
  cout<<"\nBienvenido al simulador de carreras de Diego Jimenez y Gabriel Guerra.";

      nombres[12]=nombre1;
      nombres[13]=nombre2;
      edad[12]=edad1;
      edad[13]=edad2;
      nacionalidad[12]=nacion1;
      nacionalidad[13]=nacion1;
      equipos[12]=equipo1;
      equipos[13]=equipo2;
      num[12]=num1;
      num[13]=num2;
      cout<<"Asi quedaron los equipos: ";
      cout<<"Nombre"<<", "<<"Edad"<<", "<<"Nacionalidad"<<", "<<"Equipo"<<", "<<"Numero"<<"\n \n";
      for(int i=0; i<14; i++){
      cout<<nombres[i]<<", "<<edad[i]<<", "<<nacionalidad[i]<<", "<<equipos[i]<<", "<<num[i]<<"\n";
      
      }

      while(opc!=6)
  {
  cout<<"\nAhora elige la opcion que quieras realizar (ingresa el numero) \n \n";
  cout<<"Opcion 1: Alta de pilotos \n";
  cout<<"Opcion 2: Simular carrera \n";
  cout<<"Opcion 3: Filtrar pilotos \n";
  cout<<"Opcion 4: Imprimir pilotos en orden \n";
  cout<<"Opcion 5: Dinero por equipo \n";
  cout<<"Opcion 6: Finalizar \n";
  cin>>opc;
  switch(opc){

    case 1:{
      AltaDePilotos();
  
      }  
    break;

    case 2:{
      SimuladorDeCarrera();
      }
    break;
    case 3:{
      FiltrarPilotos();
      }
    break;  
    case 4:{
      PilotosOrdenados();
      } 
    break;
    case 5:{
      DineroPorEquipo();
      }
    break;
    case 6:{
      fin();
    }
    break;
  }//switch
  cout<<"\n Escribe cualquier letra para volver al menu";
  cin>>enter;
  while (enter==' ') {
    cout<<"\n presiona enter para volver al menu";
    cin>>enter;
  }
  }//while
  }//main

