#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Variable {
public:
	Variable(const string& name) : name(name) {}
	void addData(const int& data) {
		this->data.push_back(data);
	}
	string getName() const {
		return name;
	}
	vector<int> getData() const {
		return data;
	}
private:
	string name;
	vector<int> data;
};

void makeVectors(vector<Variable>& variables, int numVars) {
	int rows = 1;
	int divider = 2;
	int count = 0;
	for(int i = 0; i < numVars; ++i) {
		rows *= 2;
	}
	while(numVars > 0) {
		string name;
		cout << "Enter name of variable: ";
		cin >> name;
		Variable var(name);
		while(count < rows) {
			for(int i = 0; i < rows/divider; ++i) {
				var.addData(0);
				++count;
			}
			for(int i = 0; i < rows/divider; ++i) {
				var.addData(1);
				++count;
			}
		}
		variables.push_back(var);
		count = 0;
		divider *= 2;
		--numVars;
	}
}

int main() {
	int var;
	vector<Variable> variables;

	cout << "Enter number of variables and press ENTER: ";
	cin >> var;

	makeVectors(variables, var);
	/*
	for(size_t i = 0; i < variables.size(); ++i) {
		cout << variables[i].getName() << " ";
	}
	cout << endl;

	for(size_t i = 0; i < variables[0].getData().size(); ++i) {
		for(size_t j = 0; j < variables.size(); ++j) {
			cout << variables[j].getData()[i] << " ";
		}
		cout << endl;
	}
	*/
	/*
	fstream ofs("file.txt");

	if(!ofs) {
		cerr << "Could not open" << endl;
		exit(3);
	}

	for(size_t i = 0; i < variables.size(); ++i) {
		ofs << variables[i].getName() << ",";
	}
	ofs << endl;
	
	for(size_t i = 0; i < variables[0].getData().size(); ++i) {
		for(size_t j = 0; j < variables.size(); ++j) {
			ofs << variables[j].getData()[i] << ",";
		}
		ofs << endl;
	}

	ofs.close();
	*/
	string filename;
	cout << "Please enter filename without extension: ";
	cin >> filename;
	ofstream excel(filename += ".csv");

	if(!excel) {
		cerr << "Could not open excel" << endl;
		exit(3);
	}

	for(size_t i = 0; i < variables.size(); ++i) {
		excel << variables[i].getName() << ",";
	}
	excel << endl;
	
	for(size_t i = 0; i < variables[0].getData().size(); ++i) {
		for(size_t j = 0; j < variables.size(); ++j) {
			excel << variables[j].getData()[i] << ",";
		}
		excel << endl;
	}

	excel.close();
	
}