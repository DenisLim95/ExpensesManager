//
//  foodItem.cpp
//  ExpensesItemTry1
//
//  Created by Denis Manuel Lim on 8/1/17.
//  Copyright © 2017 Denis Manuel Lim. All rights reserved.
//

#include "foodItem.h"
#include <iostream>

std::string nameFood; // name
std::string desc; // description
double qoh; // quantity on hand
std::string unitFood; // units
double rateFood; // price per unit
std::string typeFood;


// Complete constructor
foodItem::foodItem(std::string inName, std::string inDesc, double inQoh, std::string inUnit, std::string inType, double inRate) {
    
    setName(inName);
    setDesc(inDesc);
    setQoh(inQoh);
    setUnit(inUnit);
    setRate(inRate);
    setType(inType);

}

// Constructor with default qoh = 0

foodItem::foodItem(std::string inName, std::string inDesc, std::string inUnit, std::string inType, double inRate) {
    
    setName(inName);
    setDesc(inDesc);
    setQoh(0);
    setUnit(inUnit);
    setRate(inRate);
    setType(inType);
    
}

// Getters

std::string foodItem::getName() {
    return nameFood;
}

std::string foodItem::getDesc() {
    return desc;
}

double foodItem::getQoh() {
    return qoh;
}

std::string foodItem::getUnit() {
    return unitFood;
}

double foodItem::getRate() {
    return rateFood;
}

std::string foodItem::getType() {
    return typeFood;
}






// Setters

void foodItem::setName(std::string inName) {
    nameFood = inName;
}

void foodItem::setDesc(std::string inDesc) {
    desc = inDesc;
}

void foodItem::setQoh(double inQoh) {
    qoh = inQoh;
};

void foodItem::setUnit(std::string inUnit) {
    unitFood = inUnit;
};

void foodItem::setRate(double inRate) {
    rateFood = inRate;
};

void foodItem::setType(std::string inType) {
    typeFood = inType;
}



























