//Array Container
#include <stdio.h>
#include <iostream>
#include <array>
#include <fstream>
#include <chrono>
#include <iterator>
#include <ctime>

//Function for Append
int Append(int length, std::array<int, 100> arr) {
	int input;
	std::cout << "Enter any integer to add at the end of the array." << std::endl;
	std::cin >> input;     //Input by user
	
	//Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
	arr[length++] = input;  //Appending the input value in array
	
	//End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
	for (int i = 0; i < length; i++) //print loop
			std::cout << arr[i] << " ";
		std::cout<< std::endl;
	
	std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();
}

//Function for Prepend
int Prepend(int length, std::array<int, 100> arr) {
	int input;
	std::cout << "Enter any integer to add at the beginning of the array ." << std::endl;
	std::cin >> input;     //Input by user
    length++;
    
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
	for (int i = length; i >= 1; i--) {   //loop used to shift the elements one step forward to insert a new element at the beginning
		arr[i] = arr[i - 1];  
	}
	arr[0] = input;   //Prepending the input
	
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
	for (int i = 0; i < length; i++) //print loop
		std::cout << arr[i] << " ";
	
	std::cout<< std::endl;
	std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();	
}

//Function for Remove_from_end
int Remove_from_end(int length, std:: array<int, 100> arr) {
    
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
    arr[length-1]=0; //removing last element of array
    
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    
    for (int i = 0; i < length; i++) //print loop
		std::cout << arr[i] << " ";
		
	std::cout<< std::endl;
	
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();	
}

//Function for Remove_from_beginning
int Remove_from_beginning(int length, std:: array<int,100> arr){
    
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
    for (int i = 0; i <= length; i++) { //loop for removing first element of array
		arr[i] = arr[i + 1];
	}
	
	//End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    for (int i = 0; i < length-1; i++) //print loop
		std::cout << arr[i] << " ";
		std::cout<< std::endl;
	
	 std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();
}

//Function for Swap
int Swap(int length, std:: array<int,100> arr){
    int pos1, pos2; 
    int val;
    std::cout<<"Enter 2 positions of integers you want swapped"<<std::endl;
    std::cin>>pos1>>pos2;     //Input 2 positions by user
    
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    
    val= arr[pos1-1];           //Initializing variable with first data
    arr[pos1-1]= arr[pos2-1];   //Changing data for swap
    arr[pos2-1]= val;           //Using val variable for swap
    
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
    for (int i = 0; i < length; i++)   //print loop
		std::cout << arr[i] << " ";
	std::cout<< std::endl;
    std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();
}
//Function for Empty
int Empty(int length, std:: array<int,100> arr){   
    
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
    arr.fill(0);  //Emptying the array by filling 0 in each index of array
    
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
    for (int i = 0; i < length; i++)   //print loop
		std::cout << arr[i] << " ";
	std::cout<< std::endl;
		
	std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();
}

//Function for Insert
int Insert(int length, std::array<int, 100> arr) {
	int input;
	int pos;
	std::cout << "At what position would you like to add your integer?" << std::endl;
	std::cin >> pos;     //Input position by user
	std::cout << "Enter any integer to add at the input position of the array ." << std::endl;
	std::cin >> input;   //Input integer by user
    length++;
    
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
		for (int i = length; i >= pos; i--) {   //loop for pulling the elements one step backwards
	    	arr[i] = arr[i - 1];
	}
	arr[pos-1] = input;    //inserting value in given input position

    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

	    for (int i = 0; i < length; i++) //print loop
	    	std::cout << arr[i] << " ";
	std::cout<< std::endl;
	
	std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();
}

//Function for Remove_Duplicate
int Remove_Duplicate(int length, std:: array<int, 100> arr){
    
    int var2= 5;
    for (int i= length; i<length+5;i++){
        arr[i]= var2;
        var2= var2+ 5;
    }
    length= length + 5;
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
    for (int i=0; i< length; i++){  //loop for removing duplicate
        for (int j=i+1; j< length; j++){
            if (arr[i]==arr[j]){
                for (int k= j; k<length; k++){
                    arr[k] = arr[k+1];
                 }
        }
    }
    }
    
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
    for (int i = 0; i < length; i++) //print loop
	    std::cout << arr[i] << " ";
	std::cout<< std::endl;
	
		std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();
}
//Function for Reverse
int Reverse(int length, std::array<int, 100> arr) {
    std:: array<int, 100> arr2;  //Creating another array
    int index = 0;
    
    //Initiate timing
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
    for (int i=length-1; i>=0; i--){ //Initializing values to array 2 in reverse order
        arr2[index]= arr[i];
        index++;
    }
    for (int i=0; i<length; i++){  //Copying same reversed value from array 2 to 1
        arr[i]= arr2[i];
    }
    
    //End timing
	std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
	
	//Finding runtime 
	std::chrono::nanoseconds runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
   for (int i = 0; i < length; i++) //Print Loop
		std::cout << arr[i] << " ";
	std::cout<< std::endl;
	std::cout << "\nThe function takes " << runtime.count() << " nanoseconds \n";
	
	return runtime.count();	
		
}


int main()
{
	std::array<int, 100> arr1;      //Initializing an array
	int var1 = 5;
	std:: ofstream file_1;           //Declaring a file of ofstream type
	std:: string name_file= "array.csv" ; //Keeping the name of file
	
	file_1.open(name_file.c_str());     //File opening
	file_1 <<" Container Size, Append, Prepend, Remove from end, Remove from beginning, Empty, Insert, Remove duplicates, Reverse \n";  //Labelling run time for each function


	for (int i = 0; i < 40; i = i + 5) {  //loop for creating different array sizes

		for (int j = i; j < i + 5; j++) {  //loop for inserting values to one array size
			arr1[j] = var1;
			var1 += 5;
		}
		
		//Calling functions and inserting run time in the .csv file
       	
       	std::cout<<"Append: \n";
       	file_1 << i+5 << ", " << Append (i+5, arr1) ;		
       	std::cout<<"Prepend: \n";
		file_1 << ", " << Prepend (i+5, arr1);		
		std::cout<<"Remove_from_end: \n";
		file_1 << ", " << Remove_from_end (i+5, arr1);	
		std::cout<<"Remove_from_beginning: \n";
		file_1 << ", " << Remove_from_beginning (i+5,arr1);	
		std::cout<<"Swap: \n";
		file_1 << ", " << Swap(i+5,arr1);	
		std::cout<<"Empty: \n";
		file_1 << ", " << Empty (i+5, arr1);		
		std::cout<<"Insert: \n";
		file_1 << ", " << Insert (i+5, arr1);		
		std::cout<<"Remove_Duplicate: \n";
		file_1 << ", " << Remove_Duplicate (i+5, arr1);	
		std::cout<<"Reverse: \n";
		file_1 << ", " << Reverse (i+5, arr1) << std::endl;	
	    
	}
    return 0;
}