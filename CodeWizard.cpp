//
//  CodeWizard.cpp
//  
//
//  Created by Abdulla on 24.02.2023.
//

#include "CodeWizard.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string dataType;
    cout << "Enter data type for linked list (e.g. int, string, etc.): ";
    cin >> dataType;
    
    ofstream outFile("linked_list_" + dataType + ".cpp");
    
    // Generate code for linked list
    outFile << "#include <iostream>\n";
    outFile << "#include <memory>\n\n";
    outFile << "using namespace std;\n\n";
    outFile << "template<typename T>\n";
    outFile << "class Node {\n";
    outFile << "public:\n";
    outFile << "    T data;\n";
    outFile << "    shared_ptr<Node<T>> next;\n";
    outFile << "    Node(T val) : data(val), next(nullptr) {}\n";
    outFile << "};\n\n";
    outFile << "template<typename T>\n";
    outFile << "class LinkedList {\n";
    outFile << "public:\n";
    outFile << "    shared_ptr<Node<T>> head;\n";
    outFile << "    LinkedList() : head(nullptr) {}\n\n";
    outFile << "    void insert(T val) {\n";
    outFile << "        auto node = make_shared<Node<T>>(val);\n";
    outFile << "        if (head == nullptr) {\n";
    outFile << "            head = node;\n";
    outFile << "        } else {\n";
    outFile << "            auto curr = head;\n";
    outFile << "            while (curr->next != nullptr) {\n";
    outFile << "                curr = curr->next;\n";
    outFile << "            }\n";
    outFile << "            curr->next = node;\n";
    outFile << "        }\n";
    outFile << "    }\n\n";
    outFile << "    void print() {\n";
    outFile << "        auto curr = head;\n";
    outFile << "        while (curr != nullptr) {\n";
    outFile << "            cout << curr->data << \" -> \";\n";
    outFile << "            curr = curr->next;\n";
    outFile << "        }\n";
    outFile << "        cout << \"nullptr\" << endl;\n";
    outFile << "    }\n";
    outFile << "};\n";
    
    cout << "Code generated successfully!\n";
    return 0;
}
