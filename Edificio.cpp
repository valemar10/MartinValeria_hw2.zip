#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
using namespace std;
void leapfrog(float inicial, float finali, float dt);

void otro1(float inicial, float finali, float dt, float omega);

void otro2(float inicial, float finali, float dt, float omega);

void otro3(float inicial, float finali, float dt, float omega);

void otro4(float inicial, float finali, float dt, float omega);

void bono_masas(float inicial, float finali, float dt);

void bono_gammas(float inicial, float finali, float dt, float omega);


void bono_masas3(float inicial, float finali, float dt);

void bono_gammas2(float inicial, float finali, float dt, float omega);

void bono_gammas3(float inicial, float finali, float dt, float omega);

void bono_masas2(float inicial, float finali, float dt);

int main()
{
    float omega2=0.402837;
    float omega1=3.72267;
    float omega3= 3.92266;
    float omega4=2.32274;
    leapfrog(0.0, 100.0, 0.1);
    otro1(0.0, 100.0, 0.1, omega1);
    otro2(0.0, 100.0, 0.1, omega2);
    otro3(0.0, 100.0, 0.1, omega3);
    otro4(0.0, 100.0, 0.1, omega4);
    bono_masas(0.0, 100.0, 0.1);
    bono_gammas(0.0, 100.0, 0.1, omega2);
    bono_gammas2(0.0, 100.0, 0.1, omega2);
    bono_gammas3(0.0, 100.0, 0.1, omega2);
    bono_masas2(0.0, 100.0, 0.1);
    bono_masas3(0.0, 100.0, 0.1);
    return(0);   
}

void leapfrog(float inicial, float finali, float dt)
{
    float V1nuevo=0;
    float U1nuevo=0;
    float V2nuevo=0;
    float U2nuevo=0;
    float V3nuevo=0;
    float U3nuevo=0;
    float m=1000;
    float gammas=0;
    float k=2000;
    float omega= 1*sqrt(k/m);
    float V1viejo;
    float U1viejo;
    float V2viejo;
    float U2viejo;
    float V3viejo;
    float U3viejo;
    ofstream outfile;
    outfile.open("datoslp.dat");
    while (inicial<finali)
    {
        V1viejo=V1nuevo;
        U1viejo=U1nuevo;
        V2viejo=V2nuevo;
        U2viejo=U2nuevo;
        V3viejo=V3nuevo;
        U3viejo=U3nuevo;
        outfile << U1nuevo <<" "<< U2nuevo <<" "<< U3nuevo <<" "<< inicial <<endl;
        V1viejo= V1viejo-(dt/2)*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        V1nuevo= V1viejo+dt*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        U1nuevo= U1viejo+V1nuevo*dt;
        V2viejo= V2viejo-(dt/2)*(1/m)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        V2nuevo=V2viejo+dt*(1/m)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        U2nuevo=U2viejo+V2nuevo*dt;
        V3viejo= V3viejo-(dt/2)*(1/m)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
        V3nuevo= V3viejo+dt*(1/m)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
        U3nuevo=U3viejo+V3nuevo*dt;
        inicial= inicial+dt;
          
    }
    outfile.close();
    // arreglo de omegas
    float contador=0;
    float omegas[100];
    float arreglo[100];
    float valor_inicial=0.2;
    arreglo[0]=0.2;
    float valor=0; 
    float espacio=((3-0.2)/(99));
    for(int i=1; i<100; i++)
    {
        valor=valor_inicial+(espacio);
        arreglo[i]=valor;
        valor_inicial=valor;
        
        
        
    }
    
    for(int i=0;i<100;i++)
    {
        omegas[i]=arreglo[i]*sqrt(k/m);
    }
    float posicion1[100];
    float posicion2[100];
    float posicion3[100];
    int j=0;
    int contador2=0;
    while(j<9900)  
        {
            if(j%100==0)
            {
                contador2=contador2+1;
            }


                V1viejo=V1nuevo;
                U1viejo=U1nuevo;
                V2viejo=V2nuevo;
                U2viejo=U2nuevo;
                V3viejo=V3nuevo;
                U3viejo=U3nuevo;
                V1viejo= V1viejo-(dt/2)*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omegas[contador2]*inicial));
              
                V1nuevo= V1viejo+dt*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omegas[contador2]*inicial));
                U1nuevo= U1viejo+V1nuevo*dt;
        
                if(abs(U1nuevo)>abs(U1viejo))
                {
                    posicion1[contador2]=abs(U1nuevo);
                }
                V2viejo= V2viejo-(dt/2)*(1/m)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
                V2nuevo=V2viejo+dt*(1/m)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
                U2nuevo=U2viejo+V2nuevo*dt;
                if(abs(U2nuevo)>abs(U2viejo))
                {
                    posicion2[contador2]=abs(U2nuevo);
                }
                V3viejo= V3viejo-(dt/2)*(1/m)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
                V3nuevo= V3viejo+dt*(1/m)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
                U3nuevo=U3viejo+V3nuevo*dt;
                if(abs(U3nuevo)>abs(U3viejo))
                {
                    posicion3[contador2]=abs(U3nuevo);
                }
                j=j+1;
            }
            
           
        
        
    outfile.open("datos_omega.dat");
    for(int i=1; i<100; i++)
    {
          outfile <<posicion1[i] <<" "<< posicion2[i] <<" "<< posicion3[i] <<" "<< omegas[i] <<endl;   
    
    }
    outfile.close();

}

void otro1(float inicial, float finali, float dt, float omega)
{
    float V1nuevo=0;
    float U1nuevo=0;
    float V2nuevo=0;
    float U2nuevo=0;
    float V3nuevo=0;
    float U3nuevo=0;
    float m=1000;
    float gammas=0;
    float k=2000;
    float V1viejo;
    float U1viejo;
    float V2viejo;
    float U2viejo;
    float V3viejo;
    float U3viejo;
    ofstream outfile;
    outfile.open("datoslp1.dat");
    while (inicial<finali)
    {
        V1viejo=V1nuevo;
        U1viejo=U1nuevo;
        V2viejo=V2nuevo;
        U2viejo=U2nuevo;
        V3viejo=V3nuevo;
        U3viejo=U3nuevo;
        outfile << U1nuevo <<" "<< U2nuevo <<" "<< U3nuevo <<" "<< inicial <<endl;
        V1viejo= V1viejo-(dt/2)*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        V1nuevo= V1viejo+dt*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        U1nuevo= U1viejo+V1nuevo*dt;
        V2viejo= V2viejo-(dt/2)*(1/m)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        V2nuevo=V2viejo+dt*(1/m)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        U2nuevo=U2viejo+V2nuevo*dt;
        V3viejo= V3viejo-(dt/2)*(1/m)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
        V3nuevo= V3viejo+dt*(1/m)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
        U3nuevo=U3viejo+V3nuevo*dt;
        inicial= inicial+dt;
          
    }
    outfile.close();
}

void otro2(float inicial, float finali, float dt, float omega)
{
    float V1nuevo=0;
    float U1nuevo=0;
    float V2nuevo=0;
    float U2nuevo=0;
    float V3nuevo=0;
    float U3nuevo=0;
    float m=1000;
    float gammas=0;
    float k=2000;
    float V1viejo;
    float U1viejo;
    float V2viejo;
    float U2viejo;
    float V3viejo;
    float U3viejo;
    ofstream outfile;
    outfile.open("datoslp2.dat");
    while (inicial<finali)
    {
        V1viejo=V1nuevo;
        U1viejo=U1nuevo;
        V2viejo=V2nuevo;
        U2viejo=U2nuevo;
        V3viejo=V3nuevo;
        U3viejo=U3nuevo;
        outfile << U1nuevo <<" "<< U2nuevo <<" "<< U3nuevo <<" "<< inicial <<endl;
        V1viejo= V1viejo-(dt/2)*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        V1nuevo= V1viejo+dt*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        U1nuevo= U1viejo+V1nuevo*dt;
        V2viejo= V2viejo-(dt/2)*(1/m)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        V2nuevo=V2viejo+dt*(1/m)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        U2nuevo=U2viejo+V2nuevo*dt;
        V3viejo= V3viejo-(dt/2)*(1/m)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
        V3nuevo= V3viejo+dt*(1/m)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
        U3nuevo=U3viejo+V3nuevo*dt;
        inicial= inicial+dt;
          
    }
    outfile.close();
}

void otro3(float inicial, float finali, float dt, float omega)
{
    float V1nuevo=0;
    float U1nuevo=0;
    float V2nuevo=0;
    float U2nuevo=0;
    float V3nuevo=0;
    float U3nuevo=0;
    float m=1000;
    float gammas=0;
    float k=2000;
    float V1viejo;
    float U1viejo;
    float V2viejo;
    float U2viejo;
    float V3viejo;
    float U3viejo;
    ofstream outfile;
    outfile.open("datoslp3.dat");
    while (inicial<finali)
    {
        V1viejo=V1nuevo;
        U1viejo=U1nuevo;
        V2viejo=V2nuevo;
        U2viejo=U2nuevo;
        V3viejo=V3nuevo;
        U3viejo=U3nuevo;
        outfile << U1nuevo <<" "<< U2nuevo <<" "<< U3nuevo <<" "<< inicial <<endl;
        V1viejo= V1viejo-(dt/2)*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        V1nuevo= V1viejo+dt*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        U1nuevo= U1viejo+V1nuevo*dt;
        V2viejo= V2viejo-(dt/2)*(1/m)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        V2nuevo=V2viejo+dt*(1/m)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        U2nuevo=U2viejo+V2nuevo*dt;
        V3viejo= V3viejo-(dt/2)*(1/m)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
        V3nuevo= V3viejo+dt*(1/m)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
        U3nuevo=U3viejo+V3nuevo*dt;
        inicial= inicial+dt;
          
    }
    outfile.close();
}

void otro4(float inicial, float finali, float dt, float omega)
{
    float V1nuevo=0;
    float U1nuevo=0;
    float V2nuevo=0;
    float U2nuevo=0;
    float V3nuevo=0;
    float U3nuevo=0;
    float m=1000;
    float gammas=0;
    float k=2000;
    float V1viejo;
    float U1viejo;
    float V2viejo;
    float U2viejo;
    float V3viejo;
    float U3viejo;
    ofstream outfile;
    outfile.open("datoslp4.dat");
    while (inicial<finali)
    {
        V1viejo=V1nuevo;
        U1viejo=U1nuevo;
        V2viejo=V2nuevo;
        U2viejo=U2nuevo;
        V3viejo=V3nuevo;
        U3viejo=U3nuevo;
        outfile << U1nuevo <<" "<< U2nuevo <<" "<< U3nuevo <<" "<< inicial <<endl;
        V1viejo= V1viejo-(dt/2)*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        V1nuevo= V1viejo+dt*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        U1nuevo= U1viejo+V1nuevo*dt;
        V2viejo= V2viejo-(dt/2)*(1/m)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        V2nuevo=V2viejo+dt*(1/m)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        U2nuevo=U2viejo+V2nuevo*dt;
        V3viejo= V3viejo-(dt/2)*(1/m)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
        V3nuevo= V3viejo+dt*(1/m)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
        U3nuevo=U3viejo+V3nuevo*dt;
        inicial= inicial+dt;
          
    }
    outfile.close();
}
void bono_masas(float inicial, float finali, float dt)
{
    float V1nuevo=0;
    float U1nuevo=0;
    float V2nuevo=0;
    float U2nuevo=0;
    float V3nuevo=0;
    float U3nuevo=0;
    float m=5000;
    float gammas=0;
    float k=2000;
    float omega=1*sqrt(k/m);
    float V1viejo;
    float U1viejo;
    float V2viejo;
    float U2viejo;
    float V3viejo;
    float U3viejo;
    ofstream outfile;
    outfile.open("masa.dat");
    while (inicial<finali)
    {
        V1viejo=V1nuevo;
        U1viejo=U1nuevo;
        V2viejo=V2nuevo;
        U2viejo=U2nuevo;
        V3viejo=V3nuevo;
        U3viejo=U3nuevo;
        outfile << U1nuevo <<" "<< U2nuevo <<" "<< U3nuevo <<" "<< inicial <<endl;
        V1viejo= V1viejo-(dt/2)*(1/5000)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        V1nuevo= V1viejo+dt*(1/5000)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        U1nuevo= U1viejo+V1nuevo*dt;
        V2viejo= V2viejo-(dt/2)*(1/5000)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        V2nuevo=V2viejo+dt*(1/5000)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        U2nuevo=U2viejo+V2nuevo*dt;
        V3viejo= V3viejo-(dt/2)*(1/5000)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
        V3nuevo= V3viejo+dt*(1/5000)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
        U3nuevo=U3viejo+V3nuevo*dt;
        inicial= inicial+dt;
          
    }
    outfile.close();
}
void bono_masas2(float inicial, float finali, float dt)
{
    float V1nuevo=0;
    float U1nuevo=0;
    float V2nuevo=0;
    float U2nuevo=0;
    float V3nuevo=0;
    float U3nuevo=0;
    float m=500;
    float gammas=0;
    float k=2000;
    float omega=1*sqrt(k/m);
    float V1viejo;
    float U1viejo;
    float V2viejo;
    float U2viejo;
    float V3viejo;
    float U3viejo;
    ofstream outfile;
    outfile.open("masa1.dat");
    while (inicial<finali)
    {
        V1viejo=V1nuevo;
        U1viejo=U1nuevo;
        V2viejo=V2nuevo;
        U2viejo=U2nuevo;
        V3viejo=V3nuevo;
        U3viejo=U3nuevo;
        outfile << U1nuevo <<" "<< U2nuevo <<" "<< U3nuevo <<" "<< inicial <<endl;
        V1viejo= V1viejo-(dt/2)*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        V1nuevo= V1viejo+dt*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        U1nuevo= U1viejo+V1nuevo*dt;
        V2viejo= V2viejo-(dt/2)*(1/m)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        V2nuevo=V2viejo+dt*(1/m)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        U2nuevo=U2viejo+V2nuevo*dt;
        V3viejo= V3viejo-(dt/2)*(1/m)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
        V3nuevo= V3viejo+dt*(1/m)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
        U3nuevo=U3viejo+V3nuevo*dt;
        inicial= inicial+dt;
          
    }
    outfile.close();
}

void bono_masas3(float inicial, float finali, float dt)
{
    float V1nuevo=0;
    float U1nuevo=0;
    float V2nuevo=0;
    float U2nuevo=0;
    float V3nuevo=0;
    float U3nuevo=0;
    float m=2000;
    float gammas=0;
    float k=2000;
    float omega=1*sqrt(k/m);
    float V1viejo;
    float U1viejo;
    float V2viejo;
    float U2viejo;
    float V3viejo;
    float U3viejo;
    ofstream outfile;
    outfile.open("masa2.dat");
    while (inicial<finali)
    {
        V1viejo=V1nuevo;
        U1viejo=U1nuevo;
        V2viejo=V2nuevo;
        U2viejo=U2nuevo;
        V3viejo=V3nuevo;
        U3viejo=U3nuevo;
        outfile << U1nuevo <<" "<< U2nuevo <<" "<< U3nuevo <<" "<< inicial <<endl;
        V1viejo= V1viejo-(dt/2)*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        V1nuevo= V1viejo+dt*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        U1nuevo= U1viejo+V1nuevo*dt;
        V2viejo= V2viejo-(dt/2)*(1/m)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        V2nuevo=V2viejo+dt*(1/m)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        U2nuevo=U2viejo+V2nuevo*dt;
        V3viejo= V3viejo-(dt/2)*(1/m)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
        V3nuevo= V3viejo+dt*(1/m)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
        U3nuevo=U3viejo+V3nuevo*dt;
        inicial= inicial+dt;
          
    }
    outfile.close();
}


void bono_gammas(float inicial, float finali, float dt, float omega)
{
    float V1nuevo=0;
    float U1nuevo=0;
    float V2nuevo=0;
    float U2nuevo=0;
    float V3nuevo=0;
    float U3nuevo=0;
    float gammas=0.41;
    float k=2000;
    float m=1000;
    float V1viejo;
    float U1viejo;
    float V2viejo;
    float U2viejo;
    float V3viejo;
    float U3viejo;
    ofstream outfile;
    outfile.open("gamma.dat");
    while (inicial<finali)
    {
        V1viejo=V1nuevo;
        U1viejo=U1nuevo;
        V2viejo=V2nuevo;
        U2viejo=U2nuevo;
        V3viejo=V3nuevo;
        U3viejo=U3nuevo;
        outfile << U1nuevo <<" "<< U2nuevo <<" "<< U3nuevo <<" "<< inicial <<endl;
        V1viejo= V1viejo-(dt/2)*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        V1nuevo= V1viejo+dt*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        U1nuevo= U1viejo+V1nuevo*dt;
        V2viejo= V2viejo-(dt/2)*(1/m)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        V2nuevo=V2viejo+dt*(1/m)*((-gammas*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        U2nuevo=U2viejo+V2nuevo*dt;
        V3viejo= V3viejo-(dt/2)*(1/m)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
        V3nuevo= V3viejo+dt*(1/m)*((-gammas*V3viejo)+(k*U2viejo)-(k*U3viejo));
        U3nuevo=U3viejo+V3nuevo*dt;
        inicial= inicial+dt;
          
    }
    outfile.close();
}

void bono_gammas2(float inicial, float finali, float dt, float omega)
{
    float V1nuevo=0;
    float U1nuevo=0;
    float V2nuevo=0;
    float U2nuevo=0;
    float V3nuevo=0;
    float U3nuevo=0;
    float gammas=0.7;
    float gammas2=0.4;
    float gammas3=0.37;
    float k=2000;
    float m=1000;
    float V1viejo;
    float U1viejo;
    float V2viejo;
    float U2viejo;
    float V3viejo;
    float U3viejo;
    ofstream outfile;
    outfile.open("gamma2.dat");
    while (inicial<finali)
    {
        V1viejo=V1nuevo;
        U1viejo=U1nuevo;
        V2viejo=V2nuevo;
        U2viejo=U2nuevo;
        V3viejo=V3nuevo;
        U3viejo=U3nuevo;
        outfile << U1nuevo <<" "<< U2nuevo <<" "<< U3nuevo <<" "<< inicial <<endl;
        V1viejo= V1viejo-(dt/2)*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        V1nuevo= V1viejo+dt*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        U1nuevo= U1viejo+V1nuevo*dt;
        V2viejo= V2viejo-(dt/2)*(1/m)*((-gammas2*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        V2nuevo=V2viejo+dt*(1/m)*((-gammas2*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        U2nuevo=U2viejo+V2nuevo*dt;
        V3viejo= V3viejo-(dt/2)*(1/m)*((-gammas3*V3viejo)+(k*U2viejo)-(k*U3viejo));
        V3nuevo= V3viejo+dt*(1/m)*((-gammas3*V3viejo)+(k*U2viejo)-(k*U3viejo));
        U3nuevo=U3viejo+V3nuevo*dt;
        inicial= inicial+dt;
          
    }
    outfile.close();
}


void bono_gammas3(float inicial, float finali, float dt, float omega)
{
    float V1nuevo=0;
    float U1nuevo=0;
    float V2nuevo=0;
    float U2nuevo=0;
    float V3nuevo=0;
    float U3nuevo=0;
    float gammas=0.37;
    float gammas2=0.4;
    float gammas3=0.7;
    float k=2000;
    float m=1000;
    float V1viejo;
    float U1viejo;
    float V2viejo;
    float U2viejo;
    float V3viejo;
    float U3viejo;
    ofstream outfile;
    outfile.open("gamma3.dat");
    while (inicial<finali)
    {
        V1viejo=V1nuevo;
        U1viejo=U1nuevo;
        V2viejo=V2nuevo;
        U2viejo=U2nuevo;
        V3viejo=V3nuevo;
        U3viejo=U3nuevo;
        outfile << U1nuevo <<" "<< U2nuevo <<" "<< U3nuevo <<" "<< inicial <<endl;
        V1viejo= V1viejo-(dt/2)*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        V1nuevo= V1viejo+dt*(1/m)*((-gammas*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        U1nuevo= U1viejo+V1nuevo*dt;
        V2viejo= V2viejo-(dt/2)*(1/m)*((-gammas2*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        V2nuevo=V2viejo+dt*(1/m)*((-gammas2*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        U2nuevo=U2viejo+V2nuevo*dt;
        V3viejo= V3viejo-(dt/2)*(1/m)*((-gammas3*V3viejo)+(k*U2viejo)-(k*U3viejo));
        V3nuevo= V3viejo+dt*(1/m)*((-gammas3*V3viejo)+(k*U2viejo)-(k*U3viejo));
        U3nuevo=U3viejo+V3nuevo*dt;
        inicial= inicial+dt;
          
    }
    outfile.close();
}