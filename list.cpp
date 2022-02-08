//List Container
#include <stdio.h>
#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
#include <chrono>


void print_list(std:: list <int> list_name){
    std:: list <int>:: iterator it;
    for (it= list_name.begin(); it!=list_name.end(); it++){
	    std::cout<< *it<< " ";
	}
	std:: cout<< std::endl;
    
    
}
int Append(std:: list <int> list_name){
    int input;
	std::cout << "Enter any integer to add at the end of the list." << std::endl;
	std::cin >> input;     //Input by user
	
	//Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
    list_name.push_back(input);
    
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
    print_list(list_name);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();
    
}

int Prepend(std:: list <int> list_name){
    int input;
	std::cout << "Enter any integer to add at the end of the list." << std::endl;
	std::cin >> input;     //Input by user
	
	//Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
    list_name.push_front(input);
    
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    
    print_list(list_name);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();
}

int Remove_from_end(std:: list <int> list_name){
    
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    list_name.pop_back();
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    
    print_list(list_name);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();
}

int Remove_from_beginning(std:: list <int> list_name){
    
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
	
    list_name.pop_front();
    
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
    print_list(list_name);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();
}

int Swap(std:: list <int> list_name) {
    std:: list<int>::iterator it;
    it=list_name.begin();
    int pos1, pos2; 
    std::cout<<"Enter 2 positions of integers you want swapped"<<std::endl;
    std::cin>>pos1>>pos2;     //Input 2 positions by user
    
    //keeps value for swapping data
    int val1=0, val2=0;
    
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
    for (int i=0; i< pos1-1; i++){
        ++it;
    }
    val1 = *it;
    
    it=list_name.begin();
    for (int i=0; i< pos2-1; i++){
        ++it;
    }
    val2= *it;
    *it= val1;
    
    it= list_name.begin();
    for (int i=0; i< pos1-1; i++){
        ++it;
    }
    *it= val2;
    
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
    print_list(list_name);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();
}
int Empty(std:: list <int> list_name){
    
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
    list_name.clear();
    
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
    print_list(list_name);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();
}
int Insert(std:: list <int> list_name){
    std::list<int>::iterator it;
    it= list_name.begin();
    int pos;
    int input;
    std::cout << "At what position would you like to add your integer?" << std::endl;
	std::cin >> pos;     //Input position by user
    std::cout << "Enter any integer to add at the given position of the list." << std::endl;
	std::cin >> input;     //Input by user
	
	for (int i=0; i< pos-1; i++){
	    ++it;
	}
	//Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	list_name.insert(it, input);
	
	//End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
	print_list(list_name);
	std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();
    
}

int Remove_duplicate(std:: list <int> list_name){
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    
    list_name.unique();
    
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
    print_list(list_name);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();
}

int Reverse(std:: list <int> list_name){
    
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
    list_name.reverse();
    
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
    print_list(list_name);
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();
    
}
 
int main(){

  std:: list <int> sherpa_list;
  
  int var1 = 5;

  std:: ofstream file_1;           //Declaring a file of ofstream type
	std:: string name_file= "list.csv" ; //Keeping the name of file
	
	file_1.open(name_file.c_str());     //File opening
	file_1 <<" Container Size, Append, Prepend, Remove from end, Remove from beginning, Swap, Empty, Insert, Remove duplicates, Reverse \n";  //Labelling run time for each function

	for (int i = 0; i < 40; i = i + 5) {

		for (int j = i; j < i + 5; j++) {
			sherpa_list.push_back(var1);
			var1 += 5;
		}
    
    //Calling functions and inserting run time in the .csv file
       	
       	std::cout<<"Append: \n";
       	file_1 << i+5 << ", " << Append (sherpa_list) ;		
       	std::cout<<"Prepend: \n";
		file_1 << ", " << Prepend (sherpa_list);		
		std::cout<<"Remove_from_end: \n";
		file_1 << ", " << Remove_from_end (sherpa_list);	
		std::cout<<"Remove_from_beginning: \n";
		file_1 << ", " << Remove_from_beginning (sherpa_list);	
		std::cout<<"Swap: \n";
		file_1 << ", " << Swap(sherpa_list);	
		std::cout<<"Empty: \n";
		file_1 << ", " << Empty (sherpa_list);		
		std::cout<<"Insert: \n";
		file_1 << ", " << Insert (sherpa_list);		
		std::cout<<"Remove_Duplicate: \n";
		file_1 << ", " << Remove_duplicate (sherpa_list);	
		std::cout<<"Reverse: \n";
		file_1 << ", " << Reverse (sherpa_list) << std::endl;	
    
    
	}
    return 0;
}
