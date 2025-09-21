#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    int nb_floors; // number of floors
    int width; // width of the area
    int nb_rounds; // maximum number of rounds
    int exit_floor; // floor on which the exit is found
    int exit_pos; // position of the exit on its floor
    int nb_total_clones; // number of generated clones
    int nb_additional_elevators; // ignore (always zero)
    int nb_elevators; // number of elevators
    std::cin >> nb_floors >> width >> nb_rounds 
        >> exit_floor >> exit_pos >> nb_total_clones 
        >> nb_additional_elevators >> nb_elevators; std::cin.ignore();

    std::unordered_map<int, int> el;
    for (int i = 0; i < nb_elevators; i++) {
        int elevator_floor; // floor on which this elevator is found
        int elevator_pos; // position of the elevator on its floor
        std::cin >> elevator_floor >> elevator_pos; std::cin.ignore();
        el[elevator_floor] = elevator_pos;
    }

    while (1) {
        int clone_floor; // floor of the leading clone
        int clone_pos; // position of the leading clone on its floor
        std::string direction; // direction of the leading clone: LEFT or RIGHT
        std::cin >> clone_floor >> clone_pos >> direction; std::cin.ignore();

        if(clone_floor == exit_floor){
            if(clone_pos > exit_pos && direction == "RIGHT" ||
               clone_pos < exit_pos && direction == "LEFT"){
                std::cout << "BLOCK" << std::endl;
            }
            else{
                std::cout << "WAIT" << std::endl;
            }
        }
        else if(clone_pos > el[clone_floor] && direction == "RIGHT" ||
           clone_pos < el[clone_floor] && direction == "LEFT"){
            std::cout << "BLOCK" << std::endl;
        }
        else{
            std::cout << "WAIT" << std::endl;
        }
    }
}