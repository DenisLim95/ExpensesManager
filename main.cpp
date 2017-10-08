//
//  main.cpp
//  ExpensesItemTry1
//
//  Created by Denis Manuel Lim on 8/1/17.
//  Copyright © 2017 Denis Manuel Lim. All rights reserved.
//

#include <iostream>
#include "foodItem.h"
#include "invoice.h"
#include "invoiceItem.h"
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <typeinfo>
#include <fstream>


// Creating the item book
std::vector<foodItem> foodBook = {};

// Create invoice keeper
std::vector<invoice> invoiceKeeper = {};

// String type
std::string stringTypeCode = "NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE";


// Maybe make loading process automatic.


// Maybe make it so that file that is overwritten doesn't get deleted, but new data is added to file.


// Maybe make it so that you can add item directly when adding invoice instead of adding first.
// In adding invoice option, add last choice that is "add new item" and there it transfers to the adding item to foodbook method.



// Export item list METHOD
void exportItemsFile() {
    // output file
    std::ofstream itemFileOut;
    
    itemFileOut.open ("/Users/denismanuellim/Desktop/ExpensesItemTry1/FoodItems.txt");
    
    // Outputting item file
    if (!itemFileOut.is_open()) {
        std::cout << "Error! File could not be created!\n\n";
    } else {
        itemFileOut << "************* Item Book **************\n\n";
        itemFileOut << "Total number of items: " << foodBook.size();
        itemFileOut << "\n\n";
        
        for (int i = 0; i < foodBook.size(); i++) {
            itemFileOut << "* ITEM " << std::to_string(i) << " *\n";
            itemFileOut << "Item: " << foodBook[i].getName() << "\n";
            itemFileOut << "Description: " << foodBook[i].getDesc() << "\n";
            itemFileOut << "Unit: " << foodBook[i].getUnit() << "\n";
            itemFileOut << "Type: " << foodBook[i].getType() << "\n";
            itemFileOut << "Rate: $" << foodBook[i].getRate() << "\n";
            itemFileOut << "\n";
        }
        
        std::cout << "FOOD BOOK DATA WAS SAVED. _____________\n";
    }
    
    itemFileOut.close();
}


// Export invoice list METHOD
void exportInvFile() {
    std::ofstream invFileOut;
    invFileOut.open ("/Users/denismanuellim/Desktop/ExpensesItemTry1/Invoices.txt");
    
    // Outputting invoices
    if (!invFileOut.is_open()) {
        std::cout << "Error! File could not be created!\n\n";
    } else {
        invFileOut << "************* Invoices **************\n";
        
        double absTotal = 0;
        
        // Printing total number of invoices
        invFileOut << "Total # of invoices: " << invoiceKeeper.size() << "\n\n";
        
        
        // Printing each invoice
        for (int i = 0; i < invoiceKeeper.size(); i++) {
            // Grabbing each invoice
            invoice tempInvoice = invoiceKeeper[i];
            
            // Print vendor name
            invFileOut << "** " << tempInvoice.getVendorName() << "(" << tempInvoice.getDate() << ")" << " **\n\n" << std::endl;
            
            // Print total items in this invoice
            invFileOut << "Total # of items: " << tempInvoice.getTotalCount() << "\n\n";
            
            // Print Invoice item list
            invFileOut << tempInvoice.getItemListString() << std::endl;
            invFileOut << "\n\n\n" << std::endl;
            invFileOut << "                      TOTAL: $ " << tempInvoice.getTotalCost() << std::endl;
            
            // Get total of all invoices
            absTotal += tempInvoice.getTotalCost();
            
            
            invFileOut << "**********************************************\n";
            
        }
        invFileOut << "\n\n\n                                ABSOLUTE TOTAL: $ " << absTotal;
        invFileOut << "\n\n\n";
        
        std::cout << "INVOICES DATA WAS SAVED. _____________\n";
    }
    invFileOut.close();
}


// Adding new food item METHOD
void addNewFoodItem() {
    std::cout << "**********************************************" << std::endl;
    // Getting name of new item
    std::cout << "Please enter new item name: ";
    std::string tempName;
    std::getline (std::cin, tempName);
    
    std::cout << "Enter description of new item: ";
    std::string tempDesc;
    std::getline (std::cin, tempDesc);
    std::cout << "\n\n";
    
    // Getting units
    std::vector<std::string> unitGuide= {"Each","lb","Case","Bag", "Bunch"};
    for (int i = 0; i < unitGuide.size(); i++) {
        std::cout << i + 1 << ". " << unitGuide[i] << std::endl;
    }
    
    std::cout << "Enter correct units: ";
    int unitNum;
    std::cin >> unitNum;
    while (unitNum < 1 || unitNum > unitGuide.size()) {
        std::cout << "Error. Enter # of corresponding unit: ";
        std::cin >> unitNum;
    }
    std::string tempUnit;
    tempUnit = unitGuide[unitNum - 1];
    std::cout << "\n\n";
    
    // Getting type of food
    std::vector<std::string> typeGuide = {"Produce","Fruit & Nuts","Seafood","Dairy","Sauces & Oil", "Juice", "Cleaning & To Go"};
    for (int i = 0; i < typeGuide.size(); i++) {
        std::cout << i + 1 << ". " << typeGuide[i] << std::endl;
    }
    std::cout << "Enter correct type: ";
    int typeNum;
    std::cin >> typeNum;
    while ((typeNum < 1) || (typeNum > typeGuide.size())) {
        std::cout << "Error. Enter # of corresponding type: ";
        std::cin >> typeNum;
    }
    std::cin.ignore();
    std::string tempType;
    tempType = typeGuide[typeNum - 1];
    
    std::cout << "\n\n";
    // Getting cost of item
    std::cout << "Enter cost of new item: ";
    std::string tempRateString;
    std::getline (std::cin, tempRateString);
    double tempRate = std::stod(tempRateString);
    
    foodBook.push_back(foodItem(tempName, tempDesc, tempUnit, tempType, tempRate));
    std::cout << "**********************************************" << std::endl;
    std::cout << "\n\n\n";
    
    std::cout << "ITEM HAS BEEN SUCCESSFULLY ADDED TO ITEM LIST\n\n\n";
    
    std::cout << "**********************************************" << std::endl;
    std::cout << "\n\n\n";

}

// print Food Book Method
void printItemBook() {
    std::cout << "**********************************************" << std::endl;
    std::cout << "\n\n\n";
    
    std::cout << "** Food List **\n" << std::endl;
    
    if (foodBook.size() < 1) {
        std::cout << "* EMPTY *\n" << std::endl;
    }
    
    // Printing the items
    for (int i = 0; i < foodBook.size(); i++) {
        std::cout << "* ITEM " << std::to_string(i) << " *" << std::endl;
        std::cout << "Item: " << foodBook[i].getName() << std::endl;
        std::cout << "Description: " << foodBook[i].getDesc() << std::endl;
        std::cout << "Unit: " << foodBook[i].getUnit() << std::endl;
        std::cout << "Type: " << foodBook[i].getType() << std::endl;
        std::cout << "Rate: $" << foodBook[i].getRate() << std::endl;
        std::cout << std::endl;
    }
    
    std::cout << "\n\n\n";
    std::cout << "**********************************************" << std::endl;
    std::cout << "\n\n\n";
}

// Print invoices METHOD
void printInvoiceKeeper() {
    std::cout << "**********************************************" << std::endl;
    std::cout << "\n\n\n";
    
    double absTotal = 0;

    // Printing each invoice
    for (int i = 0; i < invoiceKeeper.size(); i++) {
        // Grabbing each invoice
        invoice tempInvoice = invoiceKeeper[i];
        
        // Print vendor name and date
        std::cout << "** " << tempInvoice.getVendorName() << " (" << tempInvoice.getDate() << ") **\n";
        std::cout << "\n";
        
        
        // Print Invoice item list
        std::cout << tempInvoice.getItemListString() << std::endl;
        std::cout << "\n\n\n" << std::endl;
        std::cout << "                      TOTAL: $ " << tempInvoice.getTotalCost() << "\n\n" << std::endl;
        
        std::cout << "_________________________________________________________________________\n\n";
        
        // Get total of all invoices
        absTotal += tempInvoice.getTotalCost();
    }
    
    std::cout << "\n\n\n                                ABSOLUTE TOTAL: $ " << absTotal;
    std::cout << "\n\n\n";
    std::cout << "**********************************************" << std::endl;
    std::cout << "\n\n\n";
}

// TRACK NUMBER OF ITEMS METHOD - Get the frequency of each item
void findItemFrequency() {
    for (int i = 0; i < foodBook.size(); i++) {
        // Maybe assign a number to each item, instead of copying entire string.
        
        
        // Make an array of objects that each have a name and an int value corresponding to quantity
        // Do either string comparison to record each item OR
        // Make a list where the position of each item is its number. Record everything with this known number correspondence.
        
        
        std::string findName;
        findName = foodBook[i].getName();
        
        // Food Book already contains the list of items, but you should count your quantity on hand by scanning the invoices.
        // Therefore, you need to update your invoice importing method to also after scanning each item, add item quantity on hand.
        
        std::string QOH[] = {};
        // This is the array of strings that is going to hold
        
        
        //
        
        
        
    }
    
}


 
// CREATE INVOICE METHOD
invoice createInvoice(std::vector<foodItem> foodBookTry) {
    
    bool moreItems = true;
    
    // Create vector of invoice items
    int counter = 0;
    std::vector<invoiceItem> invItemList = {};
    
    // Record vendor name into invoice
    std::cout << "Please enter invoice vendor: ";
    std::string vendor;
    std::getline (std::cin, vendor);
    
    std::vector <std::string> dateGuide = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    
    std::cout << "Enter invoice date in this format, including zeros (MM/DD/YY): ";
    std::string dateIn;
    std::getline (std::cin, dateIn);
    
    
    while (moreItems) {
        
        // Present items
        printItemBook();
        
        // Ask which item want to add and how many
        std::cout << "Enter item # to add: ";
        int itemNum;
        std::cin >> itemNum;

        // Check if item # is valid
        while (itemNum < 0 || itemNum >= foodBookTry.size()) {
            std::cout << "ERROR: Please enter a valid item #: ";
            std::cin >> itemNum;
        }
        
        std::cout << "Enter quantity: ";
        double howMany;
        std::cin >> howMany;
        
        // Create invoice item
        invoiceItem newItem = invoiceItem(foodBookTry[itemNum].getName(), foodBookTry[itemNum].getRate(), foodBookTry[itemNum].getUnit(), howMany);
        
//        std::cout << "\n\nName: " << newItem.getName() << std::endl;
//        std::cout << "\n\nQuantity: " << newItem.getQuantity() << std::endl;
//        std::cout << "\n\nRate: " << newItem.getRate() << std::endl;
//        std::cout << "\n\nUnit: " << newItem.getUnit() << std::endl;
        
        
        // Add invoice item to vector
        
        invItemList.push_back(newItem);
        std::cout << "\n* ITEM HAS BEEN ADDED TO INVOICE *\n\n" << std::endl;
        
        
        // ask about adding more items and turn moreItems = false if not so.
        std::cout << "\n\n1. yes" << std::endl;
        std::cout << "2. no" << std::endl;
        std::cout << std::endl;
        std::cout << "Would you like to add more items?: ";
        int moreItemQ;
        std::cin >> moreItemQ;
        if (std::cin.fail()) {
            moreItemQ = 2;
        }
        
        switch (moreItemQ) {
            case 2:
                moreItems = false;
                break;
            default:
                break;
        }
        std::cout << "\n\n*******************************\n\n" << std::endl;
        
        counter++;
    }
    
    // Create invoice from the items vector
    invoice newInvoice = invoice(invItemList, vendor, dateIn);
    
    return newInvoice;
}

// Importing food list METHOD
void importFoodList() {
    std::cout << "Enter name of file including extention (.txt): ";
    std::string fileName;
    std::getline (std::cin, fileName);
    fileName = "/Users/denismanuellim/Desktop/ExpensesItemTry1/" + fileName;
    
    
    std::ifstream myfile(fileName);
    std::string data;
    
    
    if (myfile.is_open()) {
        
        std::string inName;
        std::string inDesc;
        std::string inUnit;
        std::string inType;
        double inRate;
        
        getline (myfile,data);
        getline (myfile,data);
        getline (myfile,data);
        std::cout << data << std::endl;
        // Getting total number of items in Item book
        int totalItemCount = std::stoi(data.substr(23));
        getline (myfile,data);
        
        std::cout << std::endl;
        
        for (int i = 0; i < totalItemCount; i++) {
            // ignore item number
            getline (myfile,data);
            
            // Grabbing name
            getline (myfile,data);
            inName = data.substr(6);
            
            // Grabbing description
            getline (myfile,data);
            inDesc = data.substr(13);
            
            // Grabbing units
            getline (myfile,data);
            inUnit = data.substr(6);
            
            // Grabbing Type
            getline (myfile,data);
            inType = data.substr(6);
            
            // Grabbing Rate
            getline (myfile,data);
            inRate = std::stod(data.substr(7));
            
            // Create food Item
            foodItem importedItem = foodItem(inName,inDesc,inUnit,inType,inRate);
            foodBook.push_back(importedItem);
            
            // Skip enough lines to get next item
            getline (myfile,data);
            
        }
        std::cout << "\n** FOOD LIST SUCCESSFULLY LOADED **\n\n" << std::endl;
        
    } else {
        std::cout << "Unable to find file" << std::endl;
    }
    myfile.close();
};


// Importing invoices METHOD
void importInvoiceList() {
    
    // Asking for file name
    std::cout << "Enter name of file including extention (.txt): ";
    std::string fileName;
    std::getline (std::cin, fileName);
    fileName = "/Users/denismanuellim/Desktop/ExpensesItemTry1/" + fileName;
    
    
    std::ifstream myfile(fileName);
    std::string data;
    
    
    
    if (myfile.is_open()) {
        
        std::string invoiceVendor;
        std::string invItem;
        double invoiceRate;
        std::string invoiceUnit;
        double invoiceQ;
        std::string invoiceDate;
        
        getline (myfile,data);
        getline (myfile,data);
        
        // Get total number of invoices
        int numInvoices;
        int countStart = 21;
        numInvoices = std::stoi(data.substr(countStart));
        
        getline (myfile,data);
        
        
        
        // CYCLE BEGINS HERE
        
        
        // Cycle through invoices
        for (int i = 0; i < numInvoices; i++) {
            
            // Get vendor name
            
            getline (myfile,data);
            
            int vendorStart = 3;
            int vendorEnd = (int) data.find("(");
            
            
            invoiceVendor = data.substr(vendorStart, vendorEnd - vendorStart);
            // Get Invoice Date
            int dateStart = vendorEnd + 1;
            int dateEnd = (int) data.find(")");
            invoiceDate = data.substr(dateStart, dateEnd - dateStart);
            
            getline (myfile,data);
            getline (myfile,data);
            getline (myfile,data);
            
            // Get number of items in invoice
            int numItemsStart = 18;
            int numItems = std::stoi(data.substr(numItemsStart));
            
            getline (myfile,data);
            getline (myfile,data);
            getline (myfile,data);
            getline (myfile,data);
            
            // Create vector of invoice items, still not an actual invoice
            std::vector<invoiceItem> invoiceList;
            
            // Cycle through invoice items
            
            for (int j = 0; j < numItems; j++) {
                
                // Get Item
                int itemStart = 3;
                int itemEnd = (int) data.find(" -");
                invItem = data.substr(itemStart, itemEnd - itemStart);
                
                
                // Get Rate
                int rateStart = (int) (data.find("$") + 1);
                int rateEnd = (int) data.find("     ");
                invoiceRate = std::stod(data.substr(rateStart, rateEnd - rateStart));
                
                
                // Get Unit
                int unitStart = (int) (data.find("/ ") + 2);
                int unitEnd = (int) data.find("     Q");
                invoiceUnit = data.substr(unitStart, unitEnd - unitStart);
                
                // Get Quantity
                int qStart = (int) (data.find("QTY: ") + 5);
                int qEnd = (int) data.find("     Am");
                invoiceQ = std::stod(data.substr(qStart, qEnd - qStart));
                
                // Create the invoice item
                invoiceItem importedInvItem = invoiceItem(invItem, invoiceRate, invoiceUnit, invoiceQ);
                
                invoiceList.push_back(importedInvItem);
                
                if (numItems > 1) {
                    getline (myfile,data);
                }
            }
            
            // Create temporary invoice
            invoice tempInvoice = invoice(invoiceList, invoiceVendor, invoiceDate);
            invoiceKeeper.push_back(tempInvoice);
            getline (myfile,data);
            getline (myfile,data);
            getline (myfile,data);
            getline (myfile,data);
            getline (myfile,data);
            getline (myfile,data);
            getline (myfile,data);
            
            std::cout << data << std::endl;
        }
        std::cout << "\n** INVOICES SUCCESSFULLY LOADED **\n\n" << std::endl;
        
    } else {
        std::cout << "Unable to find file" << std::endl;
    }
    myfile.close();
    
    
}




// ********************************* MAIN ****************************************

int main() {
    
    bool mainExit = false;
    
    
    std::cout << " ********** Welcome to Denis' Food Book **********\n" << std::endl;
    
    while (!mainExit) {
        
        // Creating empty inventory
        
        std::cout << "  1. Add an invoice" << std::endl;
        std::cout << "  2. Add a new item to item book" << std::endl;
        std::cout << "  3. View item book" << std::endl;
        std::cout << "  4. Print Invoices" << std::endl;
        std::cout << "  5. Load food list from file" << std::endl;
        std::cout << "  6. Load invoices from file" << std::endl;
        std::cout << "  7. Print Quantity on Hand" << std::endl;
        std::cout << "  8. Close program\n" << std::endl;
        std::cout << "What would you like to do?: ";
        
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        
        
        
        
        switch (choice) {
                
            // CREATE INVOICE
            case 1: {
                if (foodBook.empty()) {
                    std::cout << "\n** Sorry, cannot create invoice since you have no items on record. **\n" << std::endl;
                } else {
                    // Create Invoice
                    invoice newInvoice = createInvoice(foodBook);
                    
                    // Add invoice to invoiceKeeper
                    invoiceKeeper.push_back(newInvoice);
                }
                break;
            }
                
            // ENTER NEW ITEMS TO ITEM BOOK
            case 2: {
                
                addNewFoodItem();
                
                break;
            }
                
            // DISPLAY ITEM BOOK
            case 3: {

                printItemBook();
                break;

            }
            
            // DISPLAY INVOICE KEEPER
            case 4: {
                printInvoiceKeeper();
                break;
            }
                
            // LOAD FOOD LIST FROM FILE
            case 5: {
                
                importFoodList();
                
                break;
            }
            
            // LOAD INVOICES FROM FILE
            case 6: {
                
                importInvoiceList();
                break;
            }
                
            case 7: {
                findItemFrequency();
                break;
            }
                
            // Exit choice
            case 8: {
            
                mainExit = true;
                
                std::cout << "1. Yes\n2. No\n\n";
                std::cout << "\n\n Want to save?: ";
                
                int saveData;
                std::cin >> saveData;
                
                while (saveData < 1 || saveData > 2) {
                    std::cout << "Error. Please enter valid option: ";
                    std::cin >> saveData;
                }
                
                if (saveData == 1) {
                    
                    exportItemsFile();
                    exportInvFile();
   
                }
                
                break;
            }
                
            default:
                break;
        };
        

    }
    

}
