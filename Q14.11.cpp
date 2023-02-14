//QUESTION 14.11
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int RECORD_SIZE = 100;

struct Tool {
  int id;
  std::string name;
  int quantity;
  double cost;
};

void initializeFile(std::fstream& file) {
  Tool emptyTool = { 0, "", 0, 0.0 };
  file.seekp(0);
  for (int i = 0; i < RECORD_SIZE; i++) {
    file.write(reinterpret_cast<char*>(&emptyTool), sizeof(Tool));
  }
}

void inputData(std::fstream& file) {
  Tool tool;
  std::cout << "Enter tool ID: ";
  std::cin >> tool.id;
  std::cout << "Enter tool name: ";
  std::cin >> tool.name;
  std::cout << "Enter tool quantity: ";
  std::cin >> tool.quantity;
  std::cout << "Enter tool cost: ";
  std::cin >> tool.cost;

  file.seekp((tool.id - 1) * sizeof(Tool));
  file.write(reinterpret_cast<char*>(&tool), sizeof(Tool));
}

void listTools(std::fstream& file) {
  file.seekg(0);
  Tool tool;
  while (file.read(reinterpret_cast<char*>(&tool), sizeof(Tool))) {
    if (tool.id != 0) {
      std::cout << "Record #" << tool.id << " Tool Name: " << tool.name << " Quantity: " << tool.quantity << " Cost: " << tool.cost << std::endl;
    }
  }
}

void deleteRecord(std::fstream& file) {
  int id;
  std::cout << "Enter the ID of the record to delete: ";
  std::cin >> id;

  Tool emptyTool = { 0, "", 0, 0.0 };
  file.seekp((id - 1) * sizeof(Tool));
  file.write(reinterpret_cast<char*>(&emptyTool), sizeof(Tool));
}

void updateRecord(std::fstream& file) {
  int id;
  std::cout << "Enter the ID of the record to update: ";
  std::cin >> id;

  file.seekg((id - 1) * sizeof(Tool));
  Tool tool;
  file.read(reinterpret_cast<char*>(&tool), sizeof(Tool));

  std::cout << "Enter updated tool name: ";
  std::cin >> tool.name;
  std::cout << "Enter updated tool quantity: ";
  std::cin >> tool.quantity;
  std::cout << "Enter updated tool cost: ";
  std::cin >> tool.cost;

  file.seekp((id - 1) * sizeof(Tool));
  file.write(reinterpret_cast<char*>(&tool), sizeof(Tool));
}

int main()
{
 std::fstream file("hardware.dat");
char choice;
do
{
cout << "Enter your choice: " << endl;
cout << "1. Input tool data" << endl;
cout << "2. List all tools" << endl;
cout << "3. Delete a record" << endl;
cout << "4. Update a record" << endl;
cout << "5. Quit" << endl;
cin >> choice;
switch(choice)
{
case '1':
inputData(file);
break;
case '2':
listTools(file);
break;
case '3':
deleteRecord(file);
break;
case '4':
updateRecord(file);
break;
case '5':
cout << "Exiting program..." << endl;
break;
default:
cout << "Invalid choice. Try again." << endl;
}
} while(choice != '5');
file.close();
return 0;
}
