#include <iostream>
#include "Character.h"
#include <vector>
#include <fstream>

#include <windows.h>


using namespace std;

/**
 * The function is to create a character team that will be used in the game.
 * We give the id of the character and the function selects the characters from the list of possible options.
 * @param allCharacters
 * @return vector<Charcters> team
 */
static vector<Character> createTeam(vector<Character>& allCharacters);
/**
 * The function displays a graphic for the layout screen.
 */
static void start();
/**
 * The function displays all available characters along with their parameters.
 * @param allCharacters
 * @param team
 */
static void showCharacters(vector<Character>& allCharacters,vector<Character>& team);
/**
 * This function provides support for the MENU of the game. Calls other methods and functions.
 * @param allCharacters
 * @param team
 */
static void menu(vector<Character>& allCharacters,vector<Character>& team);
/**
 * The function displays help to the user by typing "-h".
 * @param allCharacters
 * @param team
 */
static void help(vector<Character>& allCharacters,vector<Character>& team);
/**
 * The function displays the members of your team.
 * @param allCharacters
 * @param team
 */
static void showTeam(vector<Character>& allCharacters,vector<Character>& team);
/**
 * The function saves the game state to a text file.
 * @param team
 * @param level
 */
static void save(vector<Character>& team, int level);
/**
 * The function reads a character vector from the saved game.
 * @param allCharacters
 * @return vector<Character> team
 */
static vector<Character> read(vector<Character>& allCharacters);
/**
 * The function reads a level from the saved game.
 * @return int lvl
 */
static int readLvl();


static void level1(Character& enemy,vector<Character> , bool& win);
static void level2(Character& enemy,vector<Character> team, bool& win);
static void level3(Character& enemy,vector<Character> team, bool& win);
static void level4(Character& enemy,vector<Character> team, bool& win);


int main() {


    //air
    Character butterfree = {1,"butterfree",'a',5,2,20,0};
    Character golbat = {2,"golbat",'a',4,3,30,0};
    Character pidgey = {3,"pidgey",'a',3,2,40,0};
    //fire
    Character charmander = {4,"charmander",'f',5,2,20,0};
    Character vulpix ={5,"vulpix",'f',4,2,30,0};
    //ground
    Character graudon = {6,"graudon",'g',5,2,20,0};
    Character marowak = {7,"marowak",'g',4,3,30,0};
    Character onix = {8,"onix",'g',3,2,40,0};
    //ice
    Character cloyster ={9,"cloyster",'i',5,2,20,0};
    Character swinub = {10,"swinub",'i',4,2,30,0};
    //steel
    Character meowth = {11,"meowth",'s',5,3,20,0};
    Character diglet = {12,"diglet",'s',4,3,30,0};
    //water
    Character psyduck = {13,"psyduck",'w',5,2,20,0};
    Character squirtle = {14,"squirtle",'w',4,3,30,0};
    Character wartortle = {15,"wartortle",'w',3,2,40,0};

    vector<Character> allCharacters = {butterfree,golbat,pidgey,charmander,vulpix, graudon,marowak,onix,cloyster,swinub,meowth,diglet,psyduck,squirtle,wartortle};

    start();
    vector<Character> team ;
    menu(allCharacters,team);




    return 0;


}
static vector<Character> createTeam(vector<Character>& allCharacters){
    cout<<"==================================="<<endl;
    cout<<"------------CREATE TEAM------------"<<endl;
    cout<<"==================================="<<endl;

    vector<Character> team;
    int id;

    cout<<"TYPE FIRST CHARACTER ID: ";
    cout<<endl;
    do {
        cin >> id;
    }while(id<1 || id>15);
    for (int i = 0; i < allCharacters.size(); ++i) {
        if(allCharacters[i].getId() == id){
            team.push_back(allCharacters[i]);
        }
    }
    cout<<"TYPE SECOND CHARACTER ID: ";
    cout<<endl;
    do {
        cin >> id;
    }while(id<1 || id>15);
    for (int i = 0; i < allCharacters.size(); ++i) {
        if(allCharacters[i].getId() == id){
            team.push_back(allCharacters[i]);
        }
    }
    cout<<"TYPE THIRD CHARACTER ID: ";
    cout<<endl;
    do {
        cin >> id;
    }while(id<1 || id>15);
    for (int i = 0; i < allCharacters.size(); ++i) {
        if(allCharacters[i].getId() == id){
            team.push_back(allCharacters[i]);
        }
    }
    cout<<"TYPE FORTH CHARACTER ID: ";
    cout<<endl;
    do {
        cin >> id;
    }while(id<1 || id>15);
    for (int i = 0; i < allCharacters.size(); ++i) {
        if(allCharacters[i].getId() == id){
            team.push_back(allCharacters[i]);
        }
    }
    cout<<"TYPE FIFTH CHARACTER ID: ";
    cout<<endl;
    do {
        cin >> id;
    }while(id<1 || id>15);
    for (int i = 0; i < allCharacters.size(); ++i) {
        if(allCharacters[i].getId() == id){
            team.push_back(allCharacters[i]);
        }
    }
    menu(allCharacters,team);
    return team;


}
static void start(){
    cout<<"------------0---------0------------"<<endl;
    cout<<"-----------0 0-------0 0-----------"<<endl;
    cout<<"----------0   0000000   0----------"<<endl;
    cout<<"----000---0   0     0   0---000----"<<endl;
    cout<<"---0   0--0      T      0--0   0---"<<endl;
    cout<<"==================================="<<endl;
    cout<<"------CAT GAME STUDIO PRESENTS-----"<<endl;
    cout<<"==================================="<<endl;

    Sleep(1000);
    cout<<"\n\n";
    cout<<"      ";

    for (int i = 0; i < 10; ++i) {

        cout<<"==";
        Sleep(500);

    }
    cout<<"\n\n";

}
static void showCharacters(vector<Character>& allCharacters,vector<Character>& team){
    cout<<"==================================="<<endl;
    cout<<"-------------CHARACTERS------------"<<endl;
    cout<<"==================================="<<endl;
    string cont;
    for (int i = 0; i < allCharacters.size(); ++i) {
        cout<<"ID: "<<allCharacters[i].getId()
            <<" NAME: "<<allCharacters[i].getName()
            <<" TYPE: "<<allCharacters[i].getType()
            <<" STRENGTH: "<<allCharacters[i].getStrength()
            <<" SKILL: "<<allCharacters[i].getSkill()
            <<" HEALTH: "<<allCharacters[i].getHealth()
            <<" POWER: "<<allCharacters[i].getPower()
            <<" EXP: "<<allCharacters[i].getExp()<<endl;
        cout<<"========================================================================================"<<endl;

    }
    cout<<"Press (anny key + enter) to continue: ";
    cin>>cont;
    menu(allCharacters,team);
}
static void menu(vector<Character>& allCharacters,vector<Character>& team){

    string option;

    cout<<"==================================="<<endl;
    cout<<"----------------MENU---------------"<<endl;
    cout<<"==================================="<<endl;
    cout<<endl;
    cout<<"OPTIONS"<<endl;
    cout<<"  -new game (1)"<<endl;
    cout<<"  -continue previous game (2)"<<endl;
    cout<<"  -show characters (3)"<<endl;
    cout<<"  -create team (4)"<<endl;
    cout<<"  -show team (5)"<<endl;
    cout<<"  -exit (6)"<<endl;
    cout<<"  -help (-h)"<<endl;
    cout<<endl;
    cout<<"TYPE NUMBER TO CHOOSE: "<<endl;


    bool correct = true;
    bool win = false;
    char saveMode;

    while (correct) {
        cin>> option;
        if (option == "1") {
            if(!(team.empty())) {
                int v = rand() % 15 + 1;
                level1(allCharacters[v], team,win);
                cout<<"SAVE (s) OR CONTINUE (c): ";
                cin>>saveMode;
                if(win && saveMode =='c') {
                    int v = rand() % 15 + 1;
                    level2(allCharacters[v], team,win);
                    cout<<"SAVE (s) OR CONTINUE (c): ";
                    cin>>saveMode;
                    if(win && saveMode =='c') {
                        int v = rand() % 15 + 1;
                        level3(allCharacters[v], team,win);
                        cout<<"SAVE (s) OR CONTINUE (c): ";
                        cin>>saveMode;
                        if(win && saveMode =='c') {
                            int v = rand() % 15 + 1;
                            level4(allCharacters[v], team,win);
                        }else if(win && saveMode =='s'){

                            save(team,3);
                            menu(allCharacters,team);

                        } else{
                            menu(allCharacters,team);

                        }
                    }else if(win && saveMode =='s'){

                        save(team,3);
                        menu(allCharacters,team);

                    } else{
                        menu(allCharacters,team);
                    }
                } else if(win && saveMode =='s'){

                    save(team,2);
                    menu(allCharacters,team);

                } else{
                    menu(allCharacters,team);
                }
                correct = false;
            } else{
                cout<<"FIRST CREATE TEAM"<<endl;
            }

        } else if (option == "2") {

            vector<Character> team2 = read(allCharacters);
            int lvl = readLvl();
            bool win2 =true;


            if(lvl == 2 ) {
                int v = rand() % 15 + 1;
                level2(allCharacters[v], team2,win2);
                if(win2 ) {
                    int v = rand() % 15 + 1;
                    level3(allCharacters[v], team2,win2);
                    if(win2) {
                        int v = rand() % 15 + 1;
                        level4(allCharacters[v], team2,win2);
                    }
                }
            }
            if(lvl == 3 ) {
                int v = rand() % 15 + 1;
                level3(allCharacters[v], team2,win2);
                if(win2 ) {
                    int v = rand() % 15 + 1;
                    level4(allCharacters[v], team2,win2);
                }
            }
            if(lvl == 4 ) {
                int v = rand() % 15 + 1;
                level4(allCharacters[v], team2,win2);
            }


            correct = false;
        } else if (option == "3") {
            showCharacters(allCharacters,team);
            correct = false;
        } else if (option == "4") {

            createTeam(allCharacters);


            correct = false;

        } else if (option == "5") {
            showTeam(allCharacters,team);
            correct = false;
        } else if (option == "6") {

            correct = false;
        } else if (option == "-h") {
            help(allCharacters,team);
            correct = false;
        } else {
            cout << "WRONG OPTION" << endl;
            cout << "DO IT AGAIN:" << endl;
        }
    }


}
static void help(vector<Character>& allCharacters,vector<Character>& team){
    string cont;
    cout<<"==================================="<<endl;
    cout<<"----------------HELP---------------"<<endl;
    cout<<"==================================="<<endl;

    cout<<"In game you have a few enemy. You can attack,\nchange your character or level up"<<endl;
    cout<<"\nGame created by Kamil Raczkowski s24513"<<endl;
    cout<<"MANUAL"<<endl;
    cout<<"-you use keys in () to use action"<<endl;
    cout<<"-if you have 10 or more exp you can use\nsuper power"<<endl;
    cout<<"-if you have 15 or more exp you can\nupgrade your character "<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"~~~~~~~~~~~~~CAT GAME STUDIO~~~~~~~~~~~~~"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"Press (anny key + enter) to continue: ";
    cin>>cont;
    menu(allCharacters,team);


}
static void showTeam(vector<Character>& allCharacters,vector<Character>& team){
    cout<<"==================================="<<endl;
    cout<<"-------------YOUR TEAM-------------"<<endl;
    cout<<"==================================="<<endl;
    string cont;
    for( int i = 0; i < team.size(); i++ )
    {
        cout << team[ i ].getName() << std::endl;
    }
    cout<<"Press (anny key + enter) to continue: ";
    cin>>cont;
    menu(allCharacters,team);

}
static void save(vector<Character>& team,int level){

    fstream file;
    file.open("save.txt", ios::out);
    file<<team[0].getId()<<endl;
    file<<team[1].getId()<<endl;
    file<<team[2].getId()<<endl;
    file<<team[3].getId()<<endl;
    file<<team[4].getId()<<endl;
    file<<level<<endl;


    file.close();



}
static vector<Character> read(vector<Character>& allCharacters){
    vector<Character> team;
    fstream file;
    int id1,id2,id3,id4,id5;
    string line;
    int lineNumber = 1;
    file.open("save.txt", ios::in);
    if(file.good()) {
        while (getline(file, line)) {
            switch (lineNumber) {
                case 1:id1= stoi(line);
                case 2:id2= stoi(line);
                case 3:id3= stoi(line);
                case 4:id4= stoi(line);
                case 5:id5= stoi(line);


            }
            lineNumber++;
        }
    }
    file.close();


    for (int i = 0; i < allCharacters.size(); ++i) {
        if(allCharacters[i].getId() == id1){
            team.push_back(allCharacters[i]);

        }
    }
    for (int i = 0; i < allCharacters.size(); ++i) {
        if(allCharacters[i].getId() == id2){
            team.push_back(allCharacters[i]);

        }
    }
    for (int i = 0; i < allCharacters.size(); ++i) {
        if(allCharacters[i].getId() == id3){
            team.push_back(allCharacters[i]);

        }
    }
    for (int i = 0; i < allCharacters.size(); ++i) {
        if(allCharacters[i].getId() == id4){
            team.push_back(allCharacters[i]);

        }
    }
    for (int i = 0; i < allCharacters.size(); ++i) {
        if(allCharacters[i].getId() == id5){
            team.push_back(allCharacters[i]);

        }
    }



    return team;


}
static int readLvl(){
    fstream file;
    int lvl;
    string line;
    int lineNumber = 1;
    file.open("save.txt", ios::in);
    if(file.good()) {
        while (getline(file, line)) {
           if(lineNumber == 6){
               lvl = stoi(line);
           }
            lineNumber++;
        }
    }
    file.close();

    return lvl;

}

static void level1(Character& enemy,vector<Character> team, bool& win){
    cout<<"==================================="<<endl;
    cout<<"---------------LEVEL1--------------"<<endl;
    cout<<"==================================="<<endl;

    bool isEnd = true;
    byte queue = 0;
    int id = 0;
    int option;
    while (isEnd){
        if(queue == 0){


            cout<<"-----------------------------------"<<endl;
            cout<<"-YOUR CHARACTER: "<<team[id].getName()<<endl;
            cout<<"-strength: "<<team[id].getStrength()<<endl;
            cout<<"-skill: "<<team[id].getSkill()<<endl;
            cout<<"-health: "<<team[id].getHealth()<<endl;
            cout<<"-power: "<<team[id].getPower()<<endl;
            cout<<"-exp: "<<team[id].getExp()<<endl;
            cout<<"-----------------------------------"<<endl;
            cout<<"CHOSE ACTION:"<<endl;
            cout<<"  -attack (1) "<<endl;
            cout<<"  -change character (2) "<<endl;
            cout<<"  -level up (3) "<<endl;
            cout<<"  -super power (4) "<<endl;
            bool isDo = true;
            while(isDo) {
                cin >> option;
                if (option == 1) {
                    if(team[id].getHealth()>0){
                        team[id].attack(enemy);
                        int myHealth =(team[id].getHealth()>0) ? team[id].getHealth() : 0;
                        int enemyHealth = (enemy.getHealth()>0) ? enemy.getHealth() : 0;

                        cout<<"|=================================|"<<endl;
                        cout<<"        "<< myHealth<<"               "<<enemyHealth<<endl;
                        cout<<"|=================================|"<<endl;
                        cout<<"|-------------------*--0--*--0--*-|"<<"  YOUR CHARACTER:"<<endl;
                        cout<<"|-----00000---------*---00000---*-|"<<"    -strength: "<< team[id].getStrength()<<endl;
                        cout<<"|---00     00------*--00     00---|"<<"    -skill: "<< team[id].getSkill()<<endl;
                        cout<<"|--0  o   o  0-------0  o   o  0--|"<<"    -health: "<< team[id].getHealth()<<endl;
                        cout<<"|-/-00     00-|>>>>>/-00     00-|-|"<<"    -power: "<<team[id].getPower()<<endl;
                        cout<<"|-----00000-------------00000-----|"<<"    -exp: "<< team[id].getExp()<<endl;
                        cout<<"|----|--- -|-----------|-- --|----|"<<endl;
                        cout<<"|=================================|"<<endl;
                        cout<<"\n\n";
                        Sleep(3000);

                        isDo = false;
                    } else{
                        cout<<"THAT CHARACTER CANT BE USE, CHANGE THE CHARACTER"<<endl;
                    }

                } else if (option == 2) {

                    cout << "CHOSE NUMBER OF CHARACTER:" << endl;
                    for (int i = 0; i < team.size(); ++i) {

                        cout << team[i].getName() << " (" << i << ")" << endl;
                    }
                    cout << "TYPE NUMBER" << endl;
                    cin >> id;

                    cout<<"|=================================|"<<endl;
                    cout<<"|---------------------------------|"<<endl;
                    cout<<"|------------------------*-----*--|"<<endl;
                    cout<<"|--------0------------------*-----|"<<endl;
                    cout<<"|===========-0----------*---*--*--|"<<endl;
                    cout<<"|               0-----------*-----|"<<endl;
                    cout<<"|===========-0----------*-----*---|"<<endl;
                    cout<<"|--------0-----------------*------|"<<endl;
                    cout<<"|=================================|"<<endl;
                    cout<<"\n\n";
                    Sleep(3000);


                    isDo = false;

                } else if (option == 3) {
                    int a = 1;
                    int b = 2;
                    cout<<"--------------------"<<endl;
                    cout<<"LEVEL UP:"<<endl;
                    cout<<"  -strength"<<endl;
                    cout<<"  -skill"<<endl;
                    cout<<"  -health"<<endl;
                    cout<<"--------------------"<<endl;
                    cout<<"TYPE FIRST NUMBER TO UPGRADE:";
                    cin>>a;
                    cout<<endl;
                    cout<<"TYPE SECOND NUMBER TO UPGRADE:";
                    cin>>b;
                    if((team[id].getExp()>=15) && (team[id].getHealth()>=0) ){
                        team[id].level_up(a,b);
                        isDo = false;
                    } else{
                        cout<<"YOUR CHARACTER HAVE NOT ENOUGH EXP OR DIE,TRY ANOTHER ACTION"<<endl;
                    }

                } else if (option == 4){

                    if((team[id].getExp()>=10) && (team[id].getHealth()>=0) ){
                    team[id].usePower(enemy);
                        isDo = false;
                    } else{
                        cout<<"YOUR CHARACTER HAVE NOT ENOUGH EXP OR DIE,TRY ANOTHER ACTION"<<endl;
                    }

                }
            }

            queue = 1;




        }else if(queue == 1){


            enemy.attack(team[id]);
            int myHealth =(team[id].getHealth()>0) ? team[id].getHealth() : 0;
            int enemyHealth = (enemy.getHealth()>0) ? enemy.getHealth() : 0;

            cout<<"|=================================|"<<endl;
            cout<<"        "<< myHealth <<"               "<<enemyHealth<<endl;
            cout<<"|=================================|"<<endl;
            cout<<"|----*--*---*----------0-----0----|"<<"  YOUR CHARACTER:"<<endl;
            cout<<"|-*---00000--*----------00000-----|"<<"    -strength: "<< team[id].getStrength()<<endl;
            cout<<"|*--00     00---*-----00     00---|"<<"    -skill: "<< team[id].getSkill()<<endl;
            cout<<"|--0  o   o  0-------0  o   o  0--|"<<"    -health: "<< team[id].getHealth()<<endl;
            cout<<"|-/-00     00-|<<<<</-00     00-|-|"<<"    -power: "<<team[id].getPower()<<endl;
            cout<<"|-----00000-------------00000-----|"<<"    -exp: "<< team[id].getExp()<<endl;
            cout<<"|----|-----|-----------|-----|----|"<<endl;
            cout<<"|=================================|"<<endl;
            cout<<"\n\n";
            Sleep(3000);

            queue = 0;
        }
        if((enemy.getHealth() <=0)){

            cout<<"|=================================|"<<endl;
            cout<<"|---------------------------------|"<<endl;
            cout<<"|---------------------------------|"<<endl;
            cout<<"|---------------------------------|"<<endl;
            cout<<"|---------------WIN---------------|"<<endl;
            cout<<"|---------------------------------|"<<endl;
            cout<<"|---------------------------------|"<<endl;
            cout<<"|---------------------------------|"<<endl;
            cout<<"|=================================|"<<endl;
            cout<<"\n\n";
            win = true;

            isEnd = false;
        } else if((team[1].getHealth()<=0)&&(team[2].getHealth()<=0)&&(team[3].getHealth()<=0)&&(team[4].getHealth()<=0)&&(team[5].getHealth()<=0)){
            cout<<"|=================================|"<<endl;
            cout<<"|---------------------------------|"<<endl;
            cout<<"|---------------------------------|"<<endl;
            cout<<"|---------------------------------|"<<endl;
            cout<<"|--------------LOSE---------------|"<<endl;
            cout<<"|---------------------------------|"<<endl;
            cout<<"|---------------------------------|"<<endl;
            cout<<"|---------------------------------|"<<endl;
            cout<<"|=================================|"<<endl;
            cout<<"\n\n";


            isEnd = false;

        }




    }





}

static void level2(Character& enemy,vector<Character> team, bool& win){
    cout<<"==================================="<<endl;
    cout<<"---------------LEVEL2--------------"<<endl;
    cout<<"==================================="<<endl;

    enemy.setSkill(enemy.getSkill()*2);
    enemy.setHealth(enemy.getHealth()*2);
    enemy.setStrength(enemy.getStrength()*2);

    bool isEnd = true;
    byte queue = 0;
    int id = 0;
    int option;
    while (isEnd) {
        if (queue == 0) {


            cout << "-----------------------------------" << endl;
            cout << "-YOUR CHARACTER: " << team[id].getName() << endl;
            cout << "-strength: " << team[id].getStrength() << endl;
            cout << "-skill: " << team[id].getSkill() << endl;
            cout << "-health: " << team[id].getHealth() << endl;
            cout << "-power: " << team[id].getPower() << endl;
            cout << "-exp: " << team[id].getExp() << endl;
            cout << "-----------------------------------" << endl;
            cout << "CHOSE ACTION:" << endl;
            cout << "  -attack (1) " << endl;
            cout << "  -change character (2) " << endl;
            cout << "  -level up (3) " << endl;
            cout << "  -super power (4) " << endl;
            bool isDo = true;
            while (isDo) {
                cin >> option;
                if (option == 1) {
                    if (team[id].getHealth() > 0) {
                        team[id].attack(enemy);
                        int myHealth = (team[id].getHealth() > 0) ? team[id].getHealth() : 0;
                        int enemyHealth = (enemy.getHealth() > 0) ? enemy.getHealth() : 0;

                        cout << "|=================================|" << endl;
                        cout << "        " << myHealth << "               " << enemyHealth <<endl;
                        cout << "|=================================|" << endl;
                        cout << "|-------------------*--0--*--0--*-|" << "  YOUR CHARACTER:" << endl;
                        cout << "|-----00000---------*---00000---*-|" << "    -strength: " << team[id].getStrength()<< endl;
                        cout << "|---00     00------*--00     00---|" << "    -skill: " << team[id].getSkill() << endl;
                        cout << "|--0  o   o  0-------0  o   o  0--|" << "    -health: " << team[id].getHealth()<< endl;
                        cout << "|-/-00     00-|>>>>>/-00     00-|-|" << "    -power: " << team[id].getPower() << endl;
                        cout << "|-----00000-------------00000-----|" << "    -exp: " << team[id].getExp() << endl;
                        cout << "|----|--- -|-----------|-- --|----|" << endl;
                        cout << "|=================================|" << endl;
                        cout<<"\n\n";
                        Sleep(3000);

                        isDo = false;
                    } else {
                        cout << "THAT CHARACTER CANT BE USE, CHANGE THE CHARACTER" << endl;
                    }

                } else if (option == 2) {

                    cout << "CHOSE NUMBER OF CHARACTER:" << endl;
                    for (int i = 0; i < team.size(); ++i) {

                        cout << team[i].getName() << " (" << i << ")" << endl;
                    }
                    cout << "TYPE NUMBER" << endl;
                    cin >> id;

                    cout << "|=================================|" << endl;
                    cout << "|---------------------------------|" << endl;
                    cout << "|------------------------*-----*--|" << endl;
                    cout << "|--------0------------------*-----|" << endl;
                    cout << "|===========-0----------*---*--*--|" << endl;
                    cout << "|               0-----------*-----|" << endl;
                    cout << "|===========-0----------*-----*---|" << endl;
                    cout << "|--------0-----------------*------|" << endl;
                    cout << "|=================================|" << endl;
                    cout<<"\n\n";
                    Sleep(3000);


                    isDo = false;

                } else if (option == 3) {
                    int a = 1;
                    int b = 2;
                    cout << "--------------------" << endl;
                    cout << "LEVEL UP:" << endl;
                    cout << "  -strength" << endl;
                    cout << "  -skill" << endl;
                    cout << "  -health" << endl;
                    cout << "--------------------" << endl;
                    cout << "TYPE FIRST NUMBER TO UPGRADE:";
                    cin >> a;
                    cout << endl;
                    cout << "TYPE SECOND NUMBER TO UPGRADE:";
                    cin >> b;
                    if ((team[id].getExp() >= 15) && (team[id].getHealth() >= 0)) {
                        team[id].level_up(a, b);
                        isDo = false;
                    } else {
                        cout << "YOUR CHARACTER HAVE NOT ENOUGH EXP OR DIE,TRY ANOTHER ACTION" << endl;
                    }

                } else if (option == 4) {

                    if ((team[id].getExp() >= 10) && (team[id].getHealth() >= 0)) {
                        team[id].usePower(enemy);
                        isDo = false;
                    } else {
                        cout << "YOUR CHARACTER HAVE NOT ENOUGH EXP OR DIE,TRY ANOTHER ACTION" << endl;
                    }

                }
            }

            queue = 1;


        } else if (queue == 1) {


            enemy.attack(team[id]);
            int myHealth = (team[id].getHealth() > 0) ? team[id].getHealth() : 0;
            int enemyHealth = (enemy.getHealth() > 0) ? enemy.getHealth() : 0;

            cout << "|=================================|" << endl;
            cout << "        " << myHealth << "               " << enemyHealth << endl;
            cout << "|=================================|" << endl;
            cout << "|----*--*---*----------0-----0----|" << "  YOUR CHARACTER:" << endl;
            cout << "|-*---00000--*----------00000-----|" << "    -strength: " << team[id].getStrength() << endl;
            cout << "|*--00     00---*-----00     00---|" << "    -skill: " << team[id].getSkill() << endl;
            cout << "|--0  o   o  0-------0  o   o  0--|" << "    -health: " << team[id].getHealth() << endl;
            cout << "|-/-00     00-|<<<<</-00     00-|-|" << "    -power: " << team[id].getPower() << endl;
            cout << "|-----00000-------------00000-----|" << "    -exp: " << team[id].getExp() << endl;
            cout << "|----|-----|-----------|-----|----|" << endl;
            cout << "|=================================|" << endl;
            cout<<"\n\n";
            Sleep(3000);

            queue = 0;
        }
        if ((enemy.getHealth() <= 0)) {

            cout << "|=================================|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------WIN---------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|=================================|" << endl;
            cout<<"\n\n";
            win = true;

            isEnd = false;
        } else if ((team[1].getHealth() <= 0) && (team[2].getHealth() <= 0) && (team[3].getHealth() <= 0) &&
                   (team[4].getHealth() <= 0) && (team[5].getHealth() <= 0)) {
            cout << "|=================================|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|--------------LOSE---------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|=================================|" << endl;
            cout<<"\n\n";

            win = false;
            isEnd = false;

        }
    }}

static void level3(Character& enemy,vector<Character> team, bool& win){
    cout<<"==================================="<<endl;
    cout<<"---------------LEVEL3--------------"<<endl;
    cout<<"==================================="<<endl;

    enemy.setSkill(enemy.getSkill()*3);
    enemy.setHealth(enemy.getHealth()*3);
    enemy.setStrength(enemy.getStrength()*3);

    bool isEnd = true;
    byte queue = 0;
    int id = 0;
    int option;
    while (isEnd) {
        if (queue == 0) {


            cout << "-----------------------------------" << endl;
            cout << "-YOUR CHARACTER: " << team[id].getName() << endl;
            cout << "-strength: " << team[id].getStrength() << endl;
            cout << "-skill: " << team[id].getSkill() << endl;
            cout << "-health: " << team[id].getHealth() << endl;
            cout << "-power: " << team[id].getPower() << endl;
            cout << "-exp: " << team[id].getExp() << endl;
            cout << "-----------------------------------" << endl;
            cout << "CHOSE ACTION:" << endl;
            cout << "  -attack (1) " << endl;
            cout << "  -change character (2) " << endl;
            cout << "  -level up (3) " << endl;
            cout << "  -super power (4) " << endl;
            bool isDo = true;
            while (isDo) {
                cin >> option;
                if (option == 1) {
                    if (team[id].getHealth() > 0) {
                        team[id].attack(enemy);
                        int myHealth = (team[id].getHealth() > 0) ? team[id].getHealth() : 0;
                        int enemyHealth = (enemy.getHealth() > 0) ? enemy.getHealth() : 0;

                        cout << "|=================================|" << endl;
                        cout << "        " << myHealth << "               " << enemyHealth << endl;
                        cout << "|=================================|" << endl;
                        cout << "|-------------------*--0--*--0--*-|" << "  YOUR CHARACTER:" << endl;
                        cout << "|-----00000---------*---00000---*-|" << "    -strength: " << team[id].getStrength()<< endl;
                        cout << "|---00     00------*--00     00---|" << "    -skill: " << team[id].getSkill() << endl;
                        cout << "|--0  o   o  0-------0  o   o  0--|" << "    -health: " << team[id].getHealth()<< endl;
                        cout << "|-/-00     00-|>>>>>/-00     00-|-|" << "    -power: " << team[id].getPower() << endl;
                        cout << "|-----00000-------------00000-----|" << "    -exp: " << team[id].getExp() << endl;
                        cout << "|----|--- -|-----------|-- --|----|" << endl;
                        cout << "|=================================|" << endl;
                        cout<<"\n\n";
                        Sleep(3000);

                        isDo = false;
                    } else {
                        cout << "THAT CHARACTER CANT BE USE, CHANGE THE CHARACTER" << endl;
                    }

                } else if (option == 2) {

                    cout << "CHOSE NUMBER OF CHARACTER:" << endl;
                    for (int i = 0; i < team.size(); ++i) {

                        cout << team[i].getName() << " (" << i << ")" << endl;
                    }
                    cout << "TYPE NUMBER" << endl;
                    cin >> id;

                    cout << "|=================================|" << endl;
                    cout << "|---------------------------------|" << endl;
                    cout << "|------------------------*-----*--|" << endl;
                    cout << "|--------0------------------*-----|" << endl;
                    cout << "|===========-0----------*---*--*--|" << endl;
                    cout << "|               0-----------*-----|" << endl;
                    cout << "|===========-0----------*-----*---|" << endl;
                    cout << "|--------0-----------------*------|" << endl;
                    cout << "|=================================|" << endl;
                    cout<<"\n\n";
                    Sleep(3000);


                    isDo = false;

                } else if (option == 3) {
                    int a = 1;
                    int b = 2;
                    cout << "--------------------" << endl;
                    cout << "LEVEL UP:" << endl;
                    cout << "  -strength" << endl;
                    cout << "  -skill" << endl;
                    cout << "  -health" << endl;
                    cout << "--------------------" << endl;
                    cout << "TYPE FIRST NUMBER TO UPGRADE:";
                    cin >> a;
                    cout << endl;
                    cout << "TYPE SECOND NUMBER TO UPGRADE:";
                    cin >> b;
                    if ((team[id].getExp() >= 15) && (team[id].getHealth() >= 0)) {
                        team[id].level_up(a, b);
                        isDo = false;
                    } else {
                        cout << "YOUR CHARACTER HAVE NOT ENOUGH EXP OR DIE,TRY ANOTHER ACTION" << endl;
                    }

                } else if (option == 4) {

                    if ((team[id].getExp() >= 10) && (team[id].getHealth() >= 0)) {
                        team[id].usePower(enemy);
                        isDo = false;
                    } else {
                        cout << "YOUR CHARACTER HAVE NOT ENOUGH EXP OR DIE,TRY ANOTHER ACTION" << endl;
                    }

                }
            }

            queue = 1;


        } else if (queue == 1) {


            enemy.attack(team[id]);
            int myHealth = (team[id].getHealth() > 0) ? team[id].getHealth() : 0;
            int enemyHealth = (enemy.getHealth() > 0) ? enemy.getHealth() : 0;

            cout << "|=================================|" << endl;
            cout << "        " << myHealth << "               " << enemyHealth << endl;
            cout << "|=================================|" << endl;
            cout << "|----*--*---*----------0-----0----|" << "  YOUR CHARACTER:" << endl;
            cout << "|-*---00000--*----------00000-----|" << "    -strength: " << team[id].getStrength() << endl;
            cout << "|*--00     00---*-----00     00---|" << "    -skill: " << team[id].getSkill() << endl;
            cout << "|--0  o   o  0-------0  o   o  0--|" << "    -health: " << team[id].getHealth() << endl;
            cout << "|-/-00     00-|<<<<</-00     00-|-|" << "    -power: " << team[id].getPower() << endl;
            cout << "|-----00000-------------00000-----|" << "    -exp: " << team[id].getExp() << endl;
            cout << "|----|-----|-----------|-----|----|" << endl;
            cout << "|=================================|" << endl;
            cout<<"\n\n";
            Sleep(3000);

            queue = 0;
        }
        if ((enemy.getHealth() <= 0)) {

            cout << "|=================================|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------WIN---------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|=================================|" << endl;
            cout<<"\n\n";
            win = true;

            isEnd = false;
        } else if ((team[1].getHealth() <= 0) && (team[2].getHealth() <= 0) && (team[3].getHealth() <= 0) &&
                   (team[4].getHealth() <= 0) && (team[5].getHealth() <= 0)) {
            cout << "|=================================|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|--------------LOSE---------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|=================================|" << endl;
            cout<<"\n\n";

            win = false;
            isEnd = false;

        }
    }}

static void level4(Character& enemy,vector<Character> team, bool& win){
    cout<<"==================================="<<endl;
    cout<<"---------------LEVEL4--------------"<<endl;
    cout<<"==================================="<<endl;

    enemy.setSkill(enemy.getSkill()*4);
    enemy.setHealth(enemy.getHealth()*4);
    enemy.setStrength(enemy.getStrength()*4);

    bool isEnd = true;
    byte queue = 0;
    int id = 0;
    int option;
    while (isEnd) {
        if (queue == 0) {


            cout << "-----------------------------------" << endl;
            cout << "-YOUR CHARACTER: " << team[id].getName() << endl;
            cout << "-strength: " << team[id].getStrength() << endl;
            cout << "-skill: " << team[id].getSkill() << endl;
            cout << "-health: " << team[id].getHealth() << endl;
            cout << "-power: " << team[id].getPower() << endl;
            cout << "-exp: " << team[id].getExp() << endl;
            cout << "-----------------------------------" << endl;
            cout << "CHOSE ACTION:" << endl;
            cout << "  -attack (1) " << endl;
            cout << "  -change character (2) " << endl;
            cout << "  -level up (3) " << endl;
            cout << "  -super power (4) " << endl;
            bool isDo = true;
            while (isDo) {
                cin >> option;
                if (option == 1) {
                    if (team[id].getHealth() > 0) {
                        team[id].attack(enemy);
                        int myHealth = (team[id].getHealth() > 0) ? team[id].getHealth() : 0;
                        int enemyHealth = (enemy.getHealth() > 0) ? enemy.getHealth() : 0;

                        cout << "|=================================|" << endl;
                        cout << "        " << myHealth << "               " << enemyHealth << endl;
                        cout << "|=================================|" << endl;
                        cout << "|-------------------*--0--*--0--*-|" << "  YOUR CHARACTER:" << endl;
                        cout << "|-----00000---------*---00000---*-|" << "    -strength: " << team[id].getStrength()<< endl;
                        cout << "|---00     00------*--00     00---|" << "    -skill: " << team[id].getSkill() << endl;
                        cout << "|--0  o   o  0-------0  o   o  0--|" << "    -health: " << team[id].getHealth()<< endl;
                        cout << "|-/-00     00-|>>>>>/-00     00-|-|" << "    -power: " << team[id].getPower() << endl;
                        cout << "|-----00000-------------00000-----|" << "    -exp: " << team[id].getExp() << endl;
                        cout << "|----|--- -|-----------|-- --|----|" << endl;
                        cout << "|=================================|" << endl;
                        cout<<"\n\n";
                        Sleep(3000);

                        isDo = false;
                    } else {
                        cout << "THAT CHARACTER CANT BE USE, CHANGE THE CHARACTER" << endl;
                    }

                } else if (option == 2) {

                    cout << "CHOSE NUMBER OF CHARACTER:" << endl;
                    for (int i = 0; i < team.size(); ++i) {

                        cout << team[i].getName() << " (" << i << ")" << endl;
                    }
                    cout << "TYPE NUMBER" << endl;
                    cin >> id;

                    cout << "|=================================|" << endl;
                    cout << "|---------------------------------|" << endl;
                    cout << "|------------------------*-----*--|" << endl;
                    cout << "|--------0------------------*-----|" << endl;
                    cout << "|===========-0----------*---*--*--|" << endl;
                    cout << "|               0-----------*-----|" << endl;
                    cout << "|===========-0----------*-----*---|" << endl;
                    cout << "|--------0-----------------*------|" << endl;
                    cout << "|=================================|" << endl;
                    cout<<"\n\n";
                    Sleep(3000);


                    isDo = false;

                } else if (option == 3) {
                    int a = 1;
                    int b = 2;
                    cout << "--------------------" << endl;
                    cout << "LEVEL UP:" << endl;
                    cout << "  -strength" << endl;
                    cout << "  -skill" << endl;
                    cout << "  -health" << endl;
                    cout << "--------------------" << endl;
                    cout << "TYPE FIRST NUMBER TO UPGRADE:";
                    cin >> a;
                    cout << endl;
                    cout << "TYPE SECOND NUMBER TO UPGRADE:";
                    cin >> b;
                    if ((team[id].getExp() >= 15) && (team[id].getHealth() >= 0)) {
                        team[id].level_up(a, b);
                        isDo = false;
                    } else {
                        cout << "YOUR CHARACTER HAVE NOT ENOUGH EXP OR DIE,TRY ANOTHER ACTION" << endl;
                    }

                } else if (option == 4) {

                    if ((team[id].getExp() >= 10) && (team[id].getHealth() >= 0)) {
                        team[id].usePower(enemy);
                        isDo = false;
                    } else {
                        cout << "YOUR CHARACTER HAVE NOT ENOUGH EXP OR DIE,TRY ANOTHER ACTION" << endl;
                    }

                }
            }

            queue = 1;


        } else if (queue == 1) {


            enemy.attack(team[id]);
            int myHealth = (team[id].getHealth() > 0) ? team[id].getHealth() : 0;
            int enemyHealth = (enemy.getHealth() > 0) ? enemy.getHealth() : 0;

            cout << "|=================================|" << endl;
            cout << "        " << myHealth << "               " << enemyHealth << endl;
            cout << "|=================================|" << endl;
            cout << "|----*--*---*----------0-----0----|" << "  YOUR CHARACTER:" << endl;
            cout << "|-*---00000--*----------00000-----|" << "    -strength: " << team[id].getStrength() << endl;
            cout << "|*--00     00---*-----00     00---|" << "    -skill: " << team[id].getSkill() << endl;
            cout << "|--0  o   o  0-------0  o   o  0--|" << "    -health: " << team[id].getHealth() << endl;
            cout << "|-/-00     00-|<<<<</-00     00-|-|" << "    -power: " << team[id].getPower() << endl;
            cout << "|-----00000-------------00000-----|" << "    -exp: " << team[id].getExp() << endl;
            cout << "|----|-----|-----------|-----|----|" << endl;
            cout << "|=================================|" << endl;
            cout<<"\n\n";
            Sleep(3000);

            queue = 0;
        }
        if ((enemy.getHealth() <= 0)) {

            cout << "|=================================|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------END---------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------WIN---------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|----------YOU ARE MASTER---------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|=================================|" << endl;
            cout<<"\n\n";
            win = true;

            isEnd = false;
        } else if ((team[1].getHealth() <= 0) && (team[2].getHealth() <= 0) && (team[3].getHealth() <= 0) &&
                   (team[4].getHealth() <= 0) && (team[5].getHealth() <= 0)) {
            cout << "|=================================|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|--------------LOSE---------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|---------------------------------|" << endl;
            cout << "|=================================|" << endl;
            cout<<"\n\n";

            win = false;
            isEnd = false;

        }
    }}
