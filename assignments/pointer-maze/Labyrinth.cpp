#include "Labyrinth.h"
#include <iostream>

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    /* TODO: Delete this comment and the remaining lines, then implement this function. */

    bool book = false; 
    bool wand = false; 
    bool potion = false; 

    bool legal = true; 

    int index = 0; 

    while (index < (int)moves.length()) { 
        std::cout << index << std::endl;
        std::cout << moves.length() << std::endl; 
      std::cout << moves[index] << std::endl; 
        if (moves[index] == 'N') { 
            if (start->north != nullptr) { 
                if (start->whatsHere == Item::SPELLBOOK) { 
                    book = true; 
                }
                else if (start->whatsHere == Item::WAND) { 
                    wand = true; 
                }
                if (start->whatsHere == Item::POTION) { 
                    potion = true; 
                }
            }
            else { 
                
                legal = false;  
                break; 
            }
            start = start->north; 
            index++; 
        }
        
        else if (moves[index] == 'S') { 
            if (start->south != nullptr) { 
                if (start->whatsHere == Item::SPELLBOOK) { 
                    book = true; 
                }
                else if (start->whatsHere == Item::WAND) { 
                    wand = true; 
                }
                if (start->whatsHere == Item::POTION) { 
                    potion = true; 
                }
            }
            else { 
                legal = false; 
                break;  
            }
            start = start->south; 
            index++; 
        }
        else if (moves[index] == 'E') { 
            if (start->east != nullptr) { 
                if (start->whatsHere == Item::SPELLBOOK) { 
                    book = true; 
                }
                else if (start->whatsHere == Item::WAND) { 
                    wand = true; 
                }
                if (start->whatsHere == Item::POTION) { 
                    potion = true; 
                }
            }
            else { 
                legal = false; 
                break; 
            
            start = start->east; 
            index++; 
            }
        }
        if (moves[index] == 'W') { 
            if (start->west != nullptr) { 
                if (start->whatsHere == Item::SPELLBOOK) { 
                    book = true; 
                }
                else if (start->whatsHere == Item::WAND) { 
                    wand = true; 
                }
                if (start->whatsHere == Item::POTION) { 
                    potion = true; 
                }
            }
            else { 
                legal = false; 
                break; 
            }
            
            start = start->west; 
            index++; 
        }

    }

    std::cout << wand; 
    std::cout << book; 
    std::cout << potion; 
    std::cout << index; 


    return legal; 
    

}



    