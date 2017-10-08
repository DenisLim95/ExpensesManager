//
//  invoiceItem.hpp
//  ExpensesItemTry1
//
//  Created by Denis Manuel Lim on 8/2/17.
//  Copyright © 2017 Denis Manuel Lim. All rights reserved.
//

#pragma once
#include <iostream>
#include <string>

class invoiceItem {
    
public:
    
    // Constructor
    invoiceItem(std::string inName, double inRate, std::string inUnit, double quantity);
    
    // Constructor w/ no quantity specified defaulted to 1
    invoiceItem(std::string inName, double inRate, std::string inUnit);
    
    // Getters
    std::string getName();
    
    double getRate();
    
    std::string getUnit();
    
    double getQuantity();
    
    // Setters
    void setQuantity(double quantity);
    
private:
    std::string name;
    double rate;
    std::string unit;
    double quantity;
};




























