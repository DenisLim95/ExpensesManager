//
//  invoice.cpp
//  ExpensesItemTry1
//
//  Created by Denis Manuel Lim on 8/2/17.
//  Copyright © 2017 Denis Manuel Lim. All rights reserved.
//

#include "invoice.h"
#include <iostream>

int idNum;
double totalCost;
std::vector<invoiceItem> itemList;
std::string vendor;
std::string date;

// Constructor
invoice::invoice(std::vector<invoiceItem> inItemList, std::string inVendor, std::string inDate) {

    itemList = inItemList;
    vendor = inVendor;
    date = inDate;
    idNum = 1;
    totalCost = getTotalCost();
}




// GETTERS

int invoice::getIdNum() {
    return idNum;
}

double invoice::getTotalCost() {
    double total = 0;
    for (int i = 0; i < itemList.size(); i++) {
        total += itemList[i].getRate() * itemList[i].getQuantity();
    }
    return total;
}

std::vector<invoiceItem> invoice::getItemList() {
    return itemList;
}

std::string invoice::getItemListString() {
    std::string result = "";
    
    result += "Invoice items: \n\n";
    
    for (int i = 0; i < itemList.size(); i++) {
        double amount = itemList[i].getRate() * itemList[i].getQuantity();
        result += std::to_string(i);
        result += ". " + itemList[i].getName() + " -     Rate: $" + std::to_string(itemList[i].getRate()) + " / " + itemList[i].getUnit() + "     QTY: " + std::to_string(itemList[i].getQuantity()) + "     Amount: $" + std::to_string(amount);
    result += "\n";
    }
    result += "\n";
    return result;
}

std::string invoice::getVendorName() {
    return vendor;
}

std::string invoice::getDate() {
    return date;
}

int invoice::getTotalCount() {
    return (int) itemList.size();
}

// SETTERS

void invoice::setVendor(std::string inVendor) {
    vendor = inVendor;
}















