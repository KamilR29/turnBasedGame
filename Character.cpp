#include <iostream>
#include "Character.h"
#include <string>
#include <windows.h>
using namespace std;


Character::Character(int id, const string &name, char type, int strength, int skill, int health,  int exp){

    this->id = id;
    this->name = name;
    this->type = type;
    this->strength = strength;
    this->skill = skill;
    this->health = health;
    this->power = chosePower(type);
    this->exp = exp;
}

Character Character::attack(Character &character) {

    if(this->type=='w') {
        if (character.type == 'w') {
            character.health = character.health - (this->strength / 2);
            this->exp += 2;
        } else if ((character.type == 'g') || (character.type == 'f')) {
            character.health = character.health - (this->strength * 2);
            this->exp +=3;
        } else {
            character.health = character.health - (this->strength);
            this->exp +=4;
        }
    } else if(this->type=='g'){
            if(character.type =='a'){
                character.health = character.health - (this->strength/2);
                this->exp += 2;
            }else if((character.type == 'f')||(character.type == 'i')||(character.type == 's')){
                character.health = character.health - (this->strength*2);
                this->exp +=3;
            } else{
                character.health = character.health - (this->strength);
                this->exp +=4;
            }
    } else if(this->type=='a'){
            if((character.type =='g')||(character.type == 's')){
                character.health = character.health - (this->strength/2);
                this->exp += 2;
            }else if((character.type == 'i')){
                character.health = character.health - (this->strength*2);
                this->exp +=3;
            } else{
                character.health = character.health - (this->strength);
                this->exp +=4;
            }

    } else if(this->type=='f'){
            if((character.type =='w')||(character.type == 'g')){
                character.health = character.health - (this->strength/2);
                this->exp += 2;
            }else if((character.type == 'i')||(character.type == 's')){
                character.health = character.health - (this->strength*2);
                this->exp +=3;
            } else{
                character.health = character.health - (this->strength);
                this->exp +=4;
            }
    } else if(this->type=='i'){
            if((character.type =='w')||(character.type == 'f')||(character.type == 'i')){
                character.health = character.health - (this->strength/2);
                this->exp += 2;
            }else if((character.type == 'g')){
                character.health = character.health - (this->strength*2);
                this->exp +=3;
            } else{
                character.health = character.health - (this->strength);
                this->exp +=4;
            }
    } else if(this->type=='s'){
            if((character.type =='f')||(character.type == 's')){
                character.health = character.health - (this->strength/2);
                this->exp++;
            }else if((character.type == 'w')||(character.type == 'a')){
                character.health = character.health - (this->strength*2);
                this->exp +=3;
            } else{
                character.health = character.health - (this->strength);
                this->exp +=4;
            }

    }

    return character;

}

string Character::chosePower(char type) {


    switch (type) {
        case 'w':
            power = "tsunami";


            break;
        case 'g':
            power = "med";
            break;
        case 'a':
            power = "boost";
            break;
        case 'f':
            power = "storm";
            break;
        case 'i':
            power = "skill";
            break;
        case 's':
            power = "flash";
            break;
        default:
            break;

    }
    return power;

}

void Character ::level_up(int one, int two) {


        if (one == 1 ||  two == 1){
            this->strength ++;
        }
        if (one == 2 ||  two == 2){
            this->skill ++;
        }
        if (one == 3 ||  two ==3){
            this->health ++;
        }
    this->exp -= 15;


    cout<<"|=================================|"<<endl;
    cout<<"|---------------------------------|"<<endl;
    cout<<"|---------------------------------|"<<endl;
    cout<<"|---------------------------------|"<<endl;
    cout<<"|-------------LEVEL UP------------|"<<endl;
    cout<<"|---------------------------------|"<<endl;
    cout<<"|---------------------------------|"<<endl;
    cout<<"|---------------------------------|"<<endl;
    cout<<"|=================================|"<<endl;
    Sleep(3000);

}
Character Character::tsunami(Character &character) {

    character.health = 0;
    this->exp -= 10;
    cout<<"|=================================|"<<endl;
    cout<<"|---------------TSUNAMI-----------|"<<endl;
    cout<<"|---------------------------------|"<<endl;
    cout<<"|-----------------000000000000----|"<<endl;
    cout<<"|------------00000---------0--*---|"<<endl;
    cout<<"|--------0000----------000--*-*---|"<<endl;
    cout<<"|-----0000-----------00-----------|"<<endl;
    cout<<"|--000---------------000000-------|"<<endl;
    cout<<"|=================================|"<<endl;
    Sleep(3000);

    return character;
}
void Character::med() {

    this->health += 20;
    this->exp -= 10;
    cout<<"|=================================|"<<endl;
    cout<<"|----------------MED--------------|"<<endl;
    cout<<"|---------------------------------|"<<endl;
    cout<<"|----------____(TTT)___-----------|"<<endl;
    cout<<"|---------|    __|__   |----------|"<<endl;
    cout<<"|---------|      |     |----------|"<<endl;
    cout<<"|---------|____________|----------|"<<endl;
    cout<<"|---------------------------------|"<<endl;
    cout<<"|=================================|"<<endl;
    Sleep(3000);



}
void Character::boost() {
    this->strength += 5;
    this->exp -= 10;
    cout<<"|=================================|"<<endl;
    cout<<"|---------------BOOST-------------|"<<endl;
    cout<<"|---------------------------------|"<<endl;
    cout<<"|---------------------------------|"<<endl;
    cout<<"|---------------00000-------------|"<<endl;
    cout<<"|--------------|  *  |------------|"<<endl;
    cout<<"|--------------| * * |------------|"<<endl;
    cout<<"|--------------|_____|------------|"<<endl;
    cout<<"|=================================|"<<endl;
    Sleep(3000);

}
Character Character::storm(Character &character) {

    character.strength -=3;
    this->exp -= 10;
    cout<<"|=================================|"<<endl;
    cout<<"|---------------STORM-------------|"<<endl;
    cout<<"|---------------------------------|"<<endl;
    cout<<"|--------------00000000-----------|"<<endl;
    cout<<"|----------0000--------00---------|"<<endl;
    cout<<"|-------00---------------0--------|"<<endl;
    cout<<"|-----*--0000000000000000--*------|"<<endl;
    cout<<"|--------*---*-------*------*-----|"<<endl;
    cout<<"|=================================|"<<endl;
    Sleep(3000);

    return character;
}
void Character::skills() {
    this->skill +=7;
    this->exp -= 10;
    cout<<"|=================================|"<<endl;
    cout<<"|--------------SKILL--------------|"<<endl;
    cout<<"|----------------0----------------|"<<endl;
    cout<<"|--------------0 | 0--------------|"<<endl;
    cout<<"|--------------0 | 0--------------|"<<endl;
    cout<<"|--------------0 | 0--------------|"<<endl;
    cout<<"|-----------====0 0====-----------|"<<endl;
    cout<<"|---------------0 0---------------|"<<endl;
    cout<<"|=================================|"<<endl;
    Sleep(3000);

}
Character Character::flash(Character &character){

    character.skill -=3;
    this->exp -= 10;
    cout<<"|=================================|"<<endl;
    cout<<"|---------------FLASH-------------|"<<endl;
    cout<<"|-----------------/---------------|"<<endl;
    cout<<"|----------------/----------------|"<<endl;
    cout<<"|---------------/-//--------------|"<<endl;
    cout<<"|--------------//-/---------------|"<<endl;
    cout<<"|----------------/----------------|"<<endl;
    cout<<"|---------------/-----------------|"<<endl;
    cout<<"|=================================|"<<endl;
    Sleep(3000);

    return character;

}
const string &Character::getName() const {
    return name;
}

int Character::getId() const {
    return id;
}

char Character::getType() const {
    return type;
}

int Character::getStrength() const {
    return strength;
}

int Character::getSkill() const {
    return skill;
}

int Character::getHealth() const {
    return health;
}

const string &Character::getPower() const {
    return power;
}

int Character::getExp() const {
    return exp;
}

Character Character::usePower(Character &enemy) {

    if(this->type == 'w') {
        this->tsunami(enemy);
    }else if(this->type == 'g'){
        this->med();
    }else if(this->type == 'a'){
        this->boost();
    }else if(this->type == 'f'){
        this->storm(enemy);
    }else if(this->type == 'i'){
        this->skills();
    }else if(this->type == 's'){
        this->flash(enemy);

    }
    return enemy;




}

void Character::setStrength(int strength) {
    Character::strength = strength;
}

void Character::setSkill(int skill) {
    Character::skill = skill;
}

void Character::setHealth(int health) {
    Character::health = health;
}





