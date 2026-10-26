#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
using namespace std;

struct Personagem{
    string nome;
    string class;
    int vida;
    int mana;
    int ata;
    int def;
    int vel;
};

int main(){
    string clases[3] = {"Mago", "Guerreiro", "ladino"};
    int selec = 0, totalOpcoes = 3;
    int tecla;

    cout << "digite o nome do seu personagem: ";
    cin >> p.nome;

    do{
    system("cls");

    cout << "selecione sua classe:" << endl;
    for(int i=0;i<totalOpcoes;i++){
        if(i==selec){
            cout << ">" << clases[i]<<endl;
        }else{
            cout << clases[i]<<endl;
        }
    }
 
    tecla = getch();
      
            // subir 
            if(tecla == 72){
                selec--;
                if(selec < 0){
                    selec = totalOpcoes -1;
                }
            }
            //decer
            if (tecla == 80){
                selec++;
                if(selec >= totalOpcoes){
                    selec = 0;
                }
            }
        if(tecla == 13){
            cout << "Voce selecionou a classe: " << clases[selec] << endl;
            cin >> p.class;
        }

    }while(tecla != 13);
    status(clases[selec]);
    return 0;
}
