#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>


// A main routine that builds a std::vector<int> of random values and tests the above routines. 
// If there are more than one mode then just return any of them. That is, if the vector contains 1,5,4,6,4,8,6,4,12,6,22 
// then you could return 4 or 6 because both appear most frequently - 3 times.

int count(std::vector<int> v, int value) { // - this will return the number of times value appears in the unsorted vector v.
    int counter = 0; 
    for (int i = 0; i < v.size(); i++) { 
        if (v[i] == value) { 
            counter++;
        }
    }
    return counter; 
} 
   
int largest(std::vector<int> v) { // - this will return the largest value in vector v.
    int biggest = v[0];
    for (int i = 1; i < v.size(); i++) { 
        if (v[i] > biggest) { 
            biggest = v[i];
        }
    }
    return biggest;
} 

int mode(std::vector<int> v) { //which returns the mode of std::vector v, that is, the item that appears the most frequently.

     int most_frequent_counter = count(v, v[0]);
     int most_frequent = v[0]; 

    for (int i = 1; i < v.size(); i++) { 
        if (count(v,v[i]) > most_frequent) { 
            most_frequent_counter = count(v,v[i]);
            most_frequent = v[i];

        }
    }
    return most_frequent; 
}

//sort.cpp 
void print_vector(std::vector<int> a){
  for (int i = 0; i < a.size(); i++){
    std::cout << a[i] << ", ";
  }
  std::cout << "\n";
}


int find_min_index(std::vector<int> a,
		   int start_index,
		   int stop_index){
  int min_index = start_index;
  int i;
  for (i = start_index ; i < stop_index; i++){
    if (a[i] < a[min_index]){
      min_index = i;
    }
  }
  return min_index;
}

std::vector<int> ssort(std::vector<int> a){
  int i,min_index,j,tmp;
  int len = a.size();
  // loop through the vector from 0 to end
  for (i=0;i<len; i++){
    // find the smallest value from i to the end
    min_index = find_min_index(a,i,len);
    
    // swap it into position i
    tmp = a[i];
    a[i] = a[min_index];
    a[min_index] = tmp;
    
  }
  return a;
}

/*
  left and right are already sorted
  merged should be a new vector with all the
  elements in left and right, and result
  should be sorted
*/
std::vector<int> merge(std::vector<int> left,
		       std::vector<int> right){
  std::vector<int> merged;

  // your code here
  int l = 0;
  int r = 0;

  while (l < left.size() &&
	 r < right.size()){
    if (left[l] < right[r]){
      merged.push_back(left[l]);
      l++;
    } else {
      merged.push_back(right[r]);
      r++;
    }
  }

  // add any extra elements in left
  while (l < left.size()){
    merged.push_back(left[l]);
    l++;
  }
  

  // add any extra elements in right
  while (r < right.size()){
    merged.push_back(right[r]);
    r++;
  }
  	 
   
  return merged;
  
  
}

// Remember the outline is:

// If the list you’re sorting is less than size 2 then just return it.
// Otherwise
// Split the list into two halves (equal if the list is even length, and one off if the list odd length). Do this by copying each half into a new std::vector
// mergesort the two halves
// Use the merge we wrote in class to merge the results into a new std::vector
// return the new std::vector<int>
// The signature should be std::vector<int> msort(std::vector v)

std::vector<int> msort(std::vector<int> v) { 
    std::vector<int> first_half; 
    std::vector<int> second_half; 
    int half_index = 0; 

    if (v.size() < 2) { 
        return v; 
    }
    else { 
        
        //if v.size() is even 
        if (v.size() % 2 == 0) { 
            half_index = (v.size()/2)-1;
            std::vector<int> first_half; 

            //making 1st half vector 
            for (int i = 0; i <= half_index; i++) { 
                first_half.push_back(v[i]);
            }

            //making 2nd half vector 
            std::vector<int> second_half; 

             for (int i = half_index+1; i < v.size(); i++) { 
                second_half.push_back(v[i]);
            }

            //merge sort first half 


            //merge sort second half 
        }

        else { 
            //if v.size() is odd 
            half_index = (v.size()/2);

            //making 1st half vector 
            for (int i = 0; i <= half_index; i++) { 
                first_half.push_back(v[i]);
            }

            //making 2nd half vector 
             for (int i = half_index+1; i < v.size(); i++) { 
                second_half.push_back(v[i]);
            }


            //merge sort first half 


            //merge sort second half 
        }    
    }

    //merge both vectors 
    return merge(first_half, second_half);
}

int main() { 

    std::vector<int> v; 
    v.push_back(1);
    v.push_back(5);
    v.push_back(4);
    v.push_back(6);
    v.push_back(4);
    v.push_back(8);
    v.push_back(6);
    v.push_back(4);
    v.push_back(12);
    v.push_back(6);
    v.push_back(22);

    std::cout << "Vector contains 1,5,4,6,4,8,6,4,12,6,22\n";
    std::cout << std::endl; 
    
    //testing count 
    std::cout << "Testing count func for value 4: \n";
    int counter = count(v, 4); //should return 3 
    std::cout << counter << std::endl; 
    std::cout << "Testing count func for value 1: \n";
    int counter1 = count(v, 1); //should return 1 
    std::cout << counter1 << std::endl; 

    //testing largest 
    std::cout << "Testing largest func: \n";
    int biggest = largest(v); 
    std::cout << biggest << std::endl; //should return 22 

    //testing mode 
    std::cout << "Testing mode func: \n";
    int most_frequent = mode(v); 
    std::cout << most_frequent << std::endl; //should return 6 or 4 


}


// int main()
// {
//   int size=20;
//   int max_val=100;

//   srand(time(nullptr));
//   std::vector<int> a(size);
//   int i;
//   for (i=0;i<size; i++){
//     a[i] = rand()%max_val;
//   }
//   
//     print_vector(a);
//   std::cout << "\n";
//   a = ssort(a);
//   print_vector(a);
//   
//   std::vector<int> left = {1,2,5,6,10,15};
//   std::vector<int> right = {3,7,8,12,16,19,20};
//   print_vector(left);
//   print_vector(right);
//   std::vector<int> m = merge(left,right);
//   print_vector(m);



//   return 0;
// } 
