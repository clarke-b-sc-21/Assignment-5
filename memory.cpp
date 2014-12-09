#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include "Memory.h"


/*
Author: Logan Clarke
Memory: Assignment # 5
Purpose: The purpose of this program is to simulate computer memory.
It contains functions to store and retrieve ints to and from memory
locations as well as a funtion to copy a block of memory to another
location and a funtion to dump with contents of a specified block of
memory. This one includes a series of overloaded operators to add
together, assign one memory to equal another, check if two memory
equal eachother, and output a memory with cout
*/





using namespace std;


/*Constructor accepts an integer that defines the memory size*/

	memory::memory(int s){
	size=(s);
	m=new int[size];
	for(int i = 0; i <= size; i++) m[i] = 0;
	}


//copy constructor
    void memory::copy(const memory& x ){
        size=x.size;
        for(int i =0;i<size;i++)m[i]=x.m[i];
    }




/*Overloaded + operator to add to memeory locations together*/

    memory memory::operator+(const memory& other){
    memory x(size+other.size);
    for(int i =0;i<=size;i++) x.m[i]=m[i];
    for(int i = 0;i<=other.size;i++) x.m[i+size]=other.m[i];
    return x;
    }




/*overlaoded [] operator that will store or retrieve a value from any location*/
    int memory::operator[](int num){
        return m[num];

    }




/*equality operator to see if two memory locations are equal
they are considered equal if corresponding locations are equal to
each other*/

    bool memory::operator==(const memory& other){
    bool check=false;
    int countA=size;
    int countB=0;

    for(int i =0; i<size; i++) {
        if (m[i]==other.m[i])countB++;
    }
    if (countB==countA)check=true;
    return check;
    }




/*overloaded output operator*/

    ostream &operator<<(ostream &out,const memory& x){


        int count=0;
		out<<endl<<"Memory Contents --ALL"<<endl<<endl;
        	for(int i = 0; i<x.size; i++){
			count++;
			out<<right << setw(4) <<x.m[i];
			if(count%5==0)out<<endl;
			}



    return out;
    }



/*overloaded assignment (=) operator that will assign one memory location
to another, keeping in mind the memory location may be different lengths*/
    memory memory::operator=(const memory& other){

     if (this != &other){

     copy(other);

     }

    }



/*Method to store an integer at any memory location
an error msg is printed if the memory location does not exist*/
	void memory::store(int loc, int n ){
	if(loc<=size) m[loc]=n;
	else cout<< "The memory location does not exist";
	}

/*Method to retrieve an integer from any memory location
-1 is returned if the memory location does not exist*/
	int memory::retrieve(int loc){
	if(loc<=size){
	int r= m[loc];
	return r;
	}
	else return -1;
	}

/*Method that will allow block copies, a region of memory can be copied to anothe location
returns an error message if specified copy parameters would produce an error*/
	void memory::copy(int loc1, int num, int loc2){

		int i =0;
        	int a,b;
		bool check=true;
		a=loc1+num;
		b=loc2+num;
        	if(a>size)check=false;
		if(b>size)check=false;
        	if(loc1<loc2&&a>loc2)false;

		if (check==true){
			while ( i<= num){
        		m[loc2+i] = m[loc1+i];
			i++;
			}
		}
		else cout<<endl<< "The call to copy produces an error with the given 				parameters"<<endl<<endl;
        }



/*Method dump that will let the user dump the contents of a given range of memory
returns an error message if specified dump parameters would produce an error*/
	void memory::dump(int loc, int num){
	int count=0;
	bool check=true;
        if (loc+num>size)check=false;



	if (num>=0&&check==true){

		cout<<endl<<"Memory Contents -- Within Specified Parameters"<<endl<<endl;
		for(int i = loc; i<=(num+loc); i++) {
			count++;
			cout<<right << setw(4)<<m[i];
			if(count%5==0 && count>=1)cout<<endl;

			}

	}

	else if(num<0&&check==true){
		count=0;
		cout<<endl<<"Memory Contents --ALL"<<endl<<endl;
        	for(int i = 0; i<size; i++){
			count++;
			cout<<right << setw(4) <<m[i];
			if(count%5==0)cout<<endl;
			}
			delete m;
			cout<<endl;
	}
	else cout<<"The call to dump memory produces an error with the given parameters"<<endl<<endl;




}












































































































































































































































































































