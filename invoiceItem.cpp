//
//  invoiceItem.cpp
//  ExpensesItemTry1
//
//  Created by Denis Manuel Lim on 8/2/17.
//  Copyright © 2017 Denis Manuel Lim. All rights reserved.
//
#include <iostream>
#include "invoiceItem.h"
#include <string>

std::string name;
double rate;
std::string unit;
double quantity;


// Constructor

invoiceItem::invoiceItem(std::string inName, double inRate, std::string inUnit, double inQuantity) {
    name = inName;
    rate = inRate;
    unit = inUnit;
    quantity = inQuantity;
}

invoiceItem::invoiceItem(std::string inName, double inRate, std::string inUnit) {
    name = inName;
    rate = inRate;
    unit = inUnit;
    quantity = 1;
}


// GETTERS
std::string invoiceItem::getName() {
    return name;
}

double invoiceItem::getRate() {
    return rate;
}

std::string invoiceItem::getUnit() {
    return unit;
}

double invoiceItem::getQuantity() {
    return quantity;
}

// SETTERS
void invoiceItem::setQuantity(double inQuantity) {
    quantity = inQuantity;
}




































