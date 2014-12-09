#define MEMORY_H
#include <iostream>

using namespace std;


class memory{

	private:int*m;
		int size;


	public: memory(int size=100);
            void memory::copy(const memory& x );
            memory memory::operator+(const memory& other);
            memory memory::operator=(const memory& other);
            bool memory::operator==(const memory& other);
            int memory::operator[]( int num);

            friend ostream &operator<<(ostream &out, const memory&);
	        void store(int loc, int n );
            int retrieve(int loc);
            void copy(int loc1, int num, int loc2);
            void dump(int loc=0, int num= -1);




};

