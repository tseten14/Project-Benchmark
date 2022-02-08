//Vector Container
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono>

//Function for Printing
void print_vec(std:: vector <int> vec){
    std:: vector <int>:: iterator it;
    for (it= vec.begin(); it!=vec.end(); it++){ //Loop for printing
	    std::cout<< *it<< " ";
	}
	std:: cout<< std::endl;
    
    
}
//Function for Append
int Append(std:: vector <int> vec){
    int input;
    std::cout << "Enter any integer to add at the end of the vector." << std::endl;
	std::cin >> input;     //Input by user
	
	//Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
	vec.push_back(input); //Appending value to the end of vector
	//End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
    print_vec(vec); 
    
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();
}

int Prepend(std:: vector <int> vec){
    int input;
    std::cout << "Enter any integer to add at the beginning of the vector." << std::endl;
	std::cin >> input;     //Input by user
	
	//Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
	vec.insert(vec.begin(), input);  //Prepending value to the beginning of vector
	
	//End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	print_vec(vec);
    
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();	
}
int Remove_from_end(std:: vector <int> vec){
    
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
    vec.pop_back(); //removing the last element
    
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
    print_vec(vec);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();	
}

int Remove_from_beginning(std:: vector <int> vec){
    
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
    vec.erase(vec.begin());  //removing the first element
    
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
    print_vec(vec);
    
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();	
}

int Swap(std:: vector <int> vec){
    
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
    std:: iter_swap(vec.begin(), vec.end()-1); //swapping first and last element
    
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
    print_vec(vec);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();	
}

int Empty(std:: vector <int> vec){
    
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
    vec.clear();    //deleting every element on array
    
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
    print_vec(vec);
    
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();	
}

int Insert(std:: vector <int> vec){
    int pos;
    int input;
    std::cout << "At what position would you like to add your integer?" << std::endl;
	std::cin >> pos;     //Input position by user
    std::cout << "Enter any integer to add at the given position of the vector." << std::endl;
	std::cin >> input;     //Input by user
	
	//Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
	vec.insert(vec.begin() + (pos-1), input);   //Inserting input in the position given by user
	
	//End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
	print_vec(vec);
	std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();	
}

int Remove_duplicate(std:: vector <int> vec){

    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
    for (int i= 0; i< vec.size(); i++){ //loop for removing duplicates
        
        for (int j= i+1; j< vec.size(); j++){
            if (vec[j]==vec[i]){
            vec.erase(vec.begin()+ j);
            }
        }
        
    }
    
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
    print_vec(vec);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();	
}

int Reverse(std:: vector <int> vec) {
    
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
    std:: reverse(vec.begin(), vec.end()); //reversing the vector
    
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
    print_vec(vec);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();	
    
}
  
int main()
{
    
    std:: vector <int> vec1; //initializing vector
    
    int var1=5;
    
    std:: ofstream file_1;           //Declaring a file of ofstream type
	std:: string name_file= "vector.csv" ; //Keeping the name of file
	
	file_1.open(name_file.c_str());     //File opening
	file_1 <<" Container Size, Append, Prepend, Remove from end, Remove from beginning, Swap, Empty, Insert, Remove duplicates, Reverse \n";  //Labelling run time for each function

    for (int i = 0; i < 40; i = i + 5) { //loop for creating different vector sizes

		for (int j = i; j < i + 5; j++) { //loop for inserting values to each different array sizes
			vec1.push_back(var1);
			var1 += 5;
		}

	
		//Calling functions and inserting run time in the .csv file
       	
       	std::cout<<"Append: \n";
       	file_1 << i+5 << ", " << Append (vec1) ;		
       	std::cout<<"Prepend: \n";
		file_1 << ", " << Prepend (vec1);		
		std::cout<<"Remove_from_end: \n";
		file_1 << ", " << Remove_from_end (vec1);	
		std::cout<<"Remove_from_beginning: \n";
		file_1 << ", " << Remove_from_beginning (vec1);	
		std::cout<<"Swap: \n";
		file_1 << ", " << Swap(vec1);	
		std::cout<<"Empty: \n";
		file_1 << ", " << Empty (vec1);		
		std::cout<<"Insert: \n";
		file_1 << ", " << Insert (vec1);		
		std::cout<<"Remove_Duplicate: \n";
		file_1 << ", " << Remove_duplicate (vec1);	
		std::cout<<"Reverse: \n";
		file_1 << ", " << Reverse (vec1) << std::endl;	
	
    }
    return 0;
}
