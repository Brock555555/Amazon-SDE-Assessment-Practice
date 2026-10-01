#include <iostream>
#include <string>

class StarWars_Character{//class declaration
    private://cant be accessed by methods outside of the class itself, needs getter/setter methods to access these
        std::string name;
        std::string allegiance;
        unsigned int age;
    public:
        StarWars_Character(std::string name, std::string allegiance, unsigned int age){//constructor
            this->name = name;
            this->allegiance = allegiance;
            this->age = age;
        }
        /*
        can be done more optimally as
        StarWars_Character::StarWars_Character(const std::string& initialname, const std::string& initialallegiance, const unsigned int& initialage):
         name{initialname}, allegiance{initialallegiance}, age{initialage}{}
        */
        unsigned int get_age() const{
            return this->age;
        }

        /*
        Theres a couple of ways to write a functions parameters, here we do const and &
        which makes the parameter not able to change the internals outside the function through const
        but also takes away unneccesary copying via passing a reference
        
        */
        void set_age(const unsigned int& age){
            this->age = age;
        }

        std::string get_name() const{
            return this->name;
        }

        void set_name(const std::string& name){
            this->name = name;
        }

        std::string get_allegiance() const{
            return this->allegiance;
        }

        void set_allegiance(const std::string& allegiance){
            this->allegiance = allegiance;
        }

};

int main(){
    StarWars_Character Anakin("Anakin", "Republic", 20);
    std::cout << Anakin.get_age() << std::endl;
    Anakin.set_allegiance("Empire");
    Anakin.set_name("Vader");
    std::cout << Anakin.get_name() << ' ' << Anakin.get_allegiance() << ' ' << Anakin.get_age() << std::endl;
    StarWars_Character Ahsoka("Ahsoka", "Republic", 14);
    std::cout << Ahsoka.get_age() << std::endl;
    Ahsoka.set_age(15);
    std::cout << Ahsoka.get_age() << std::endl;

    return 0;
}