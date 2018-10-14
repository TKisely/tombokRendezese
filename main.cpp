#include <iostream>
#define TOMBMERET 10
using namespace std;

int tomb[TOMBMERET];

void feltoltIndexekkel(){
    for (int index = 0; index < TOMBMERET; ++index) {
        tomb[index]=index;
    }
}

bool tombKetElemenekFelcserelese(int egyikIndex, int masikIndex){
    if(egyikIndex<<TOMBMERET&&masikIndex<<TOMBMERET){
        //Azert van ra szukseg, mert ha az egyik elemet
        //rogton egyenlove tennem a masikkal, akkor
        //az elso eredeti erteket mar nem tudnam kiolvasni, elveszne
        int ideiglenes = tomb[egyikIndex];

        //Ekkor az elso indexen talalhato elem erteke lecserelodik
        //a masodik indexen talalhatoeval
        //Ha nem mentettem volna ki elore az erteket, akkor elveszett volna
        tomb[egyikIndex]=tomb[masikIndex];

        //Vegul mivel nem hagytam elveszni, igy
        //betolthetem az erteket az uj helyere
        tomb[masikIndex]=ideiglenes;

        return true;

    }
    return false;
}


bool konzolrolFeltoltes(){
    for (int index = 0; index < TOMBMERET; ++index) {
        cout<<"Kerem adja meg a tomb ["<<index<<"] elemet: "<<endl;
        cin>>tomb[index];
        cout<<endl;
    }
    return true;
}

void buborekRendezesNovekvo(){
    //Mindig kivalasztunk egy szamot
    // (jelen eseteben megyunk szepen sorban)
    //majd osszemerjuk a mellette elhelyezkedovel
    // (jelen esetben az eggyel nagyobb indexuvel)

    //Utolso elemet nem tudjuk az utolso utanival osszemerni
    //ezert megyunk az utolso elotti elemig
    for (int i = 0; i < TOMBMERET - 1; ++i) {
        for (int j = 0; j < TOMBMERET - i - 1; ++j) {
            //A rendezessel mindig garantaljuk, hogy az utolso i elem
            // mar jo helyen all
            //Gondoljuk vegig miert!

            if(tomb[j]>tomb[j+1]){
                tombKetElemenekFelcserelese(j,j+1);
            }
        }
    }
}

void buborekRendezesCsokkeno(){
//TODO:Buborekrendezes megforditasa
}

void feltoltRandomSzamokkal(int alsoHatar, int felsoHatar){
    for (int i = 0; i < TOMBMERET; ++i) {
        //Random szamok generalasanak egyik tipusa
        tomb[i] = rand() % (felsoHatar-alsoHatar) + alsoHatar;
    }

}

void konzolraKiirjaATombot(){
    for (int index = 0; index < TOMBMERET; ++index) {
        cout<<"A tomb ["<<index<<"] eleme = "<<tomb[index]<<endl;
    }
}

void elvalasztoAKonzolra(){
    cout<<"-----||-----"<<endl;
}

int main() {
    //Kiirjuk az ures tombot
    konzolraKiirjaATombot();
    elvalasztoAKonzolra();

    //Feltoltjuk a tombot az indexeivel
    feltoltIndexekkel();
    konzolraKiirjaATombot();
    elvalasztoAKonzolra();

    //Vegrehajtunk egy tetszoleges cseret
    tombKetElemenekFelcserelese(5,8);
    konzolraKiirjaATombot();
    elvalasztoAKonzolra();

    //Konzolrol toltjuk fel a tombot
//    konzolrolFeltoltes();
//    konzolraKiirjaATombot();
//    elvalasztoAKonzolra();

    //Random szamokkal valo feltoltes
    feltoltRandomSzamokkal(1000,9999);
    konzolraKiirjaATombot();
    elvalasztoAKonzolra();

    //Buborekrendezes novekvo sorrendbe
    buborekRendezesNovekvo();
    konzolraKiirjaATombot();
    elvalasztoAKonzolra();

    //Buborekrendezes csokkeno sorrendbe
    buborekRendezesCsokkeno();
    konzolraKiirjaATombot();
    elvalasztoAKonzolra();

    //A kod vege
    //-----||-----
    elvalasztoAKonzolra();
    std::cout << "Lefutottam!" << std::endl;
    return 0;
}