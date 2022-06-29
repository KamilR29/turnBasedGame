//
// Created by Kamil on 22.06.2022.
//

#ifndef PJCPROJECT1_CHARACTER_H
#define PJCPROJECT1_CHARACTER_H
using namespace std;
#include <string>
#include <vector>

/**
 * Class Character. That class provides to creat new Character. Implement methods to make action with Character.
 */
class Character {
private:
    int id;
    string name;
    char type;
    int strength;
    int skill;
    int health;
    string power;
    int exp;
public:

    /**
     * Character corntructor
     * @param id
     * @param name
     * @param type
     * @param strength
     * @param skill
     * @param health
     * @param exp
     */
    Character(int id,const string &name, char type, int strength, int skill, int health,  int exp) ;
    /**
     * Attack method. That method allows to attack another character. Make them damage which is depence of type of characters.
     * @return Character character
     */
    Character attack(Character &);
    /**
     * Chose power method. That method atributted to character theier power.
     * @param type
     * @return string power
     */
    string chosePower(char type);
    /**
     * Use power method. That method allows to use super power.
     * @param enemy
     * @return Character enemy
     */
    Character usePower(Character &enemy);
    /**
     * Level up method. That method increment to of three character sills
     * @param one
     * @param two
     */
    void level_up(int one, int two);
    /**
     * Special power (tsunami) method. Destroy enemy by setting theier health of zero.
     * @return Character character
     */
    Character tsunami(Character &);
    /**
     * Special power (med) method. Ad twenty to character health.
     */
    void med();
    /**
     * Special power (boost) method. Ad five to character strength.
     */
    void boost();
    /**
     * Special power (storm) method. Reduce enemy strength of three.
     * @return Character character
     */
    Character storm(Character &);
    /**
     * Special power (skills) method. Ad seven to character skill.
     */
    void skills();
    /**
     * Special power (flash) method. Reduce enemy skill of three.
     * @return Character character
     */
    Character flash(Character &);
    /**
     * getName
     * @return name
     */
    const string &getName() const;
    /**
     * getID
     * @return id
     */
    int getId() const;
    /**
     * getType
     * @return type
     */
    char getType() const;
    /**
     * getStrength
     * @return strength
     */
    int getStrength() const;
    /**
     * getSkill
     * @return skill
     */
    int getSkill() const;
    /**
     * getHealth
     * @return health
     */
    int getHealth() const;
    /**
     * getPower
     * @return power
     */
    const string &getPower() const;
    /**
     * getExp
     * @return exp
     */
    int getExp() const;
    /**
     * setStrength
     * @param strength
     */
    void setStrength(int strength);
    /**
     * setSkill
     * @param skill
     */
    void setSkill(int skill);
    /**
     * setHealth
     * @param health
     */
    void setHealth(int health);


};


#endif //PJCPROJECT1_CHARACTER_H
