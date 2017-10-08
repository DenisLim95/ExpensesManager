//
//  foodItem.hpp
//  ExpensesItemTry1
//
//  Created by Denis Manuel Lim on 8/1/17.
//  Copyright © 2017 Denis Manuel Lim. All rights reserved.
//

#pragma once
#include <stdio.h>
#include <iostream>

class foodItem {

public:
    // Constructor
    foodItem(std::string name, std::string desc, double qoh, std::string unit, std::string type, double rate);
    
    // Constructor without quantity on hand
    foodItem(std::string name, std::string desc, std::string unit, std::string type, double rate);
    
    // Getters
    std::string getName();
    std::string getDesc();
    double getQoh();
    std::string getUnit();
    double getRate();
    std::string getType();
    
    // Setters
    void setName(std::string name);
    void setDesc(std::string desc);
    void setQoh(double qoh);
    void setUnit(std::string unit);
    void setRate(double rate);
    void setType(std::string type);
    
private:
    
    std::string nameFood; // name
    std::string typeFood;
    std::string desc; // description
    double qoh; // quantity on hand
    std::string unitFood; // units
    double rateFood; // price per unit
    
};

