
#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

int victoria();
int comprobarver();
int comprobarhor();
int comprobartiktak();
int introducir();
void imprimir_act(int numact);
void turnos();


int matrizj[3][3] = {{0,9,0}, {9,0,9}, {9,0,9}};
char matrizact[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
int jugG = 1,numJugadas = 0;

int main() {
 
    int x = 10;

	cout<< "Welcome to the game! \nPLEASE use the assigned numbers to play correctly :3" << endl;
    cout<< "_1_|_2_|_3_" <<endl<<"_4_|_5_|_6_"<<endl<<" 7 | 8 | 9 "<<endl<<"Enter to start!!!!";
    cin.get();
    cout<< "_ _|_ _|_ _" <<endl<<"_ _|_ _|_ _"<<endl<<"   |   |   "<<endl;
    
    while(victoria() != 1){
        cout<<"Turn of the player: "<< jugG << endl; 
        x = introducir();
        imprimir_act(x);
        numJugadas++;
    }
	cout<<"GAME OVER"<<endl;
    return 0;

}

//Print the actual table of the game and put all the numbers into the arrays
void imprimir_act(int numact){
    char varAct;
    int intAct;
    if (jugG == 1)
    {
        varAct = 'X';
        intAct = 1;
    }else{
        intAct = 2;
        varAct = 'O';
    }
    
    switch (numact)
    {
    case 1:{
        if (matrizact[0] == ' ')
        {
            matrizact[0] = varAct;
            matrizj[0][0] = intAct;
        }else{
            cout<<"OCCUPIED BOX PLEASE USE ANOTHER [1-9]: ";
            return;
        }
        break;
    }
    case 2:
        if (matrizact[1] == ' ')
        {
            matrizact[1] = varAct;
            matrizj[0][1] = intAct;
        }else{
            cout<<"OCCUPIED BOX PLEASE USE ANOTHER [1-9]:  ";
            return;
        }
        break;
    case 3:
        if (matrizact[2] == ' ')
        {
            matrizact[2] = varAct;
            matrizj[0][2] = intAct;
        }else{
            cout<<"OCCUPIED BOX PLEASE USE ANOTHER [1-9]:  ";
            return;
        }
        break;
    case 4:
        if (matrizact[3] == ' ')
        {
            matrizact[3] = varAct;
            matrizj[1][0] = intAct;
        }else{
            cout<<"OCCUPIED BOX PLEASE USE ANOTHER [1-9]:  ";
            return;
        }
        break;
    case 5:
        if (matrizact[4] == ' ')
        {
            matrizact[4] = varAct;
            matrizj[1][1] = intAct;
        }else{
            cout<<"OCCUPIED BOX PLEASE USE ANOTHER [1-9]:  ";
            return;
        }
        break;
    case 6:
        if (matrizact[5] == ' ')
        {
            matrizact[5] = varAct;
            matrizj[1][2] = intAct;
        }else{
            cout<<"OCCUPIED BOX PLEASE USE ANOTHER [1-9]:  ";
            return;
        }
        break;
    case 7:
        if (matrizact[6] == ' ')
        {
            matrizact[6] = varAct;
            matrizj[2][0] = intAct;
        }else{
            cout<<"OCCUPIED BOX PLEASE USE ANOTHER [1-9]:  ";
            return;
        }
        break;
    case 8:
        if (matrizact[7] == ' ')
        {
            matrizact[7] = varAct;
            matrizj[2][1] = intAct;
        }else{
            cout<<"OCCUPIED BOX PLEASE USE ANOTHER [1-9]:  ";
            return;
        }
        break;
    case 9:
        if (matrizact[8] == ' ')
        {
            matrizact[8] = varAct;
            matrizj[2][2] = intAct;
        }else{
            cout<<"OCCUPIED BOX PLEASE USE ANOTHER [1-9]:  ";
            return;
        }
        break;
    default:
        break;
    }

    printf("_%c_|_%c_|_%c_\n",matrizact[0],matrizact[1],matrizact[2]);
    printf("_%c_|_%c_|_%c_\n",matrizact[3],matrizact[4],matrizact[5]);
    printf(" %c | %c | %c \n",matrizact[6],matrizact[7],matrizact[8]);
    
    turnos();

    return;
}

//This function is only to enter the plays
int introducir(){
    int y = -1;
    
    cin>>y;
        
    while (y < 1 || y > 9)
        {
            cout<<"INVALID NUMBER, please enter another [1-9]\n";
            cin>>y;
        }
    return y;
}

//Function to change turns
void turnos(){

    if (jugG == 1)
    {
        jugG++;
        return;
    }
    jugG--;
    return;
}

/*FROM HERE to the final all the functions works together to check if there is a winner
  'comprobarver' check vertically, first if the current number have a coincidence with the next one, keeps going, otherwise go down to repeat the process
  'comprobarhor' check horizontally, like the other function but upside down, check if is equal to the number below, otherwise go to the next and repeat
  'comprobartiktak' just check the diagonals with if-else 
*/
int comprobarver(){
    int aux = 0, numi = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (aux<2 && matrizj[i][j+1] == matrizj[i][j])
            {
                aux++;
            }else j+=2;
        }
        if (aux == 2)
        {
            numi = matrizj[i][0];
            return numi;
        }else aux = 0;
    }
    return 0;
}

int comprobarhor(){
    int aux = 0, numi = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (aux<2 && matrizj[j+1][i] == matrizj[j][i])
            {
                aux++;
            }else j+=2;
        }
        if (aux == 2)
        {
            numi = matrizj[0][i];
            return numi;
        }else aux = 0;
    }
    return 0;
}


int comprobartiktak(){
    if (matrizj[1][1] == matrizj[0][0] && matrizj[1][1] == matrizj[2][2])
    {
        return 1;
    }else if(matrizj[1][1] == matrizj[0][2] && matrizj[1][1] == matrizj[2][0]){
        return 2;
    }
    return 0;
}

int victoria(){
    if (comprobarver() > 0 || comprobarhor() > 0 || comprobartiktak() > 0)
    {
        turnos();
        cout<<"THE PLAYER "<<jugG<<" WINS!!!!"<<endl;
        return 1;
    }else if(numJugadas == 9){
        cout<<"TIE -_-"<<endl;
        return 1;
    }
    return 0;
}
