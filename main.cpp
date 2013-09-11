/*
	Brian McNeese

	TruthTable generator
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//Object for each variable, keeps its name and data
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

//Obtains name of each variable and inputs 0s and 1s
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

//Writes data to Excel
void writeToExcel(vector<Variable>& variables, ofstream& excel) {
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
}

int main() {
	int var;
	vector<Variable> variables;

	cout << "Enter number of variables and press ENTER: ";
	cin >> var;

	makeVectors(variables, var);

	string filename;
	cout << "Please enter filename without extension: ";
	cin >> filename;
	ofstream excel(filename += ".csv");

	if(!excel) {
		cerr << "Could not open excel" << endl;
		exit(3);
	}

	writeToExcel(variables, excel);
	
	excel.close();
	
}