#include <iostream>
using namespace std;

class proto{
public:
	string name;

	void setName(string n);

	string getName();

	~proto(){
	}
};

void proto::setName(string n){
	name = n;
}

string proto::getName(){
	return name;
}

void arrayFunction(proto array[3]){
	for (int i = 0; i < 3; i++){
		array[i].name = "item ";
		array[i].name += to_string(i + 1);
	}
	cout << array << endl;
}

int main(){
	proto array [3];
	cout << array << endl;
	cout << array[0].name << endl;
	cout << &array[0] << endl;
	cout << array[1].name << endl;
	cout << &array[1] << endl;
	cout << array[2].name << endl;
	cout << &array[2] << endl;

	arrayFunction(array);
	cout << array << endl;
	cout << array[0].name << endl;
	cout << &array[0] << endl;
	cout << array[1].name << endl;
	cout << &array[1] << endl;
	cout << array[2].name << endl;
	cout << &array[2] << endl;

}