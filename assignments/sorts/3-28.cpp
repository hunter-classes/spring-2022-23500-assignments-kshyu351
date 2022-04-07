std::vector<int> qsort(std::vector<int> list) { //quick sort 


    

    //return list if size is less than 2 
    if(list.size() <= 1) { 
        return list; 
    }

    //select a pivot value, for now j pick list[0] 

    int pivot = list[0]; 

    //make 2 new vectors 
    std::vector<int> lower, higher; 

    //copy all the values < pivot value to lower 
    //copy all values >= pivot to higher 

    for (int i = 0; i < list.size(); i++) { 
        if (list[i] < pivot) { 
            lower.pushback(list[i]);
        }
        else if(list[i] >= pivot) {
            higher.pushback(list[i]);

        }
    }

    //zmans way (also on github) 
    for (i = 0; i < lower.size(); i++) { 
        liat[i] = lower[i];
    }
    list[i] = pivot; 
    i++; 

    for(int j = 0; j < higher.size(); j++) { 
        list[i] = higher[j];
        i++; 

    }

    // lower | pivot | higher 

    lower = qsort(lower); 
    higher = qsort(higher); 

    //copy everything back in.to the list 
    std::vector<int> copy; 

    for (int i = 0; i < lower.size(); i++) { 
        copy.pushback(lower[i]); 
    }

    copy.pushback(pivot); 

    for (int i = 0; i < higher.size(); i++) { 
        copy.pushback(higher[i]);
    }

    for(int i = 0; i < copy.size(); i++) { 
        list[i] = copy[i]; 
    }


    //return the sorted list 
    return list; 

    }

}