#include <iostream>
#include "DynamicArray/DynamicArray.h"

using namespace std;

int main() {
    DynamicArray dynamicArray;
    while(true) {
        cout << "Choose the command: " << endl;
        int command;
        if (!(cin >> command)) {
            cout << "Enter valid command" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (command) {
            case 1 : {
                cout << "Enter text to append: " << endl;
                char *text = new char[256];
                cin.getline(text, 256);
                dynamicArray.PushBack(text);
                delete[] text;
                break;
            }
            case 2: {
                dynamicArray.AddNewline();
                cout << "New line is started" << endl;
                break;
            }
            case 3: {
                char filename[256];
                while(true) {
                    cout << "Enter the file name for saving: " << endl;
                    cin >> filename;
                    if(strstr(filename, ".txt") != nullptr) {
                        break;
                    }
                    cout << "Invalid file name, try again with '.txt' "<< endl;;
                }
                dynamicArray.SaveInfo(filename);
                cout << "Text has been saved successfully" << endl;
                break;
            }
            case 4: {
                char filename[256];
                while(true) {
                    cout << "Enter the file name for loading: " << endl;
                    cin >> filename;
                    if(strstr(filename, ".txt") != nullptr) {
                        break;
                    }
                    printf("Invalid file name, try again with '.txt' \n");
                }
                dynamicArray.LoadInfo(filename);
                cout << "Text has been loaded successfully" << endl;
                break;
            }
            case 5: {
                dynamicArray.Print();
                cout << endl;
                break;
            }
            case 6: {
                cout << "Choose line and index: ";
                int line, index;
                cin >> line >> index;
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                cout << "Enter text to insert: ";
                char *text = new char[256];
                cin.getline(text, 256);
                dynamicArray.Insert(line, index, text);
                delete[] text;
                break;
            }
            case 7: {
                cout << "Enter text to search: ";
                char *text = new char[256];
                cin.getline(text, 256);
                dynamicArray.Search(text);
                delete[] text;
                break;
            }
            case 8: {
                cout << "Choose line, index and number of symbols: ";
                int line, index, symbols;
                cin >> line >> index >> symbols;
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                dynamicArray.Delete(line, index, symbols);
                break;
            }
            case 11: {
                cout << "Choose line, index and number of symbols: ";
                int line, index, symbols;
                cin >> line >> index >> symbols;
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                dynamicArray.Cut(line, index, symbols);
                break;
            }
            case 12 : {
                cout << "Choose line and index: ";
                int line, index;
                cin >> line >> index;
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                dynamicArray.Paste(line, index);
                break;
            }
            case 13 : {
                cout << "Choose line and index and number of symbols: ";
                int line, index, symbols;
                cin >> line >> index >> symbols;
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                dynamicArray.Copy(line, index, symbols);
                break;
            }
            case 14: {
                cout << "Choose line and index: ";
                int line, index;
                cin >> line >> index;
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                cout << "Write text: ";
                char *text = new char[256];
                cin.getline(text, 256);
                dynamicArray.InsertReplacement(line, index, text);
                delete[] text;
                break;
            }
            default: {
                cout << "Wrong command" << endl;
                break;
            }
        }

    }
}