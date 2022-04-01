#include "Labyrinth.h"
#include <iostream>

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
   

    bool book = false; 
    bool wand = false; 
    bool potion = false; 

    bool legal = false; 

    int index = 0; 

    while (index < (int)moves.length()) { 

    //     std::cout << index << std::endl;
    //     std::cout << moves.length() << std::endl; 
    //   std::cout << moves[index] << std::endl; 
      
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
            }
            start = start->east; 
            index++; 
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

        if (wand && book && potion) { 
            legal = true;
        }
    }


    // std::cout << wand; 
    // std::cout << book; 
    // std::cout << potion; 
    // std::cout << index; 


    return legal; 
    

}



    