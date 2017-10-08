//
//  invoice.hpp
//  ExpensesItemTry1
//
//  Created by Denis Manuel Lim on 8/2/17.
//  Copyright © 2017 Denis Manuel Lim. All rights reserved.
//

#include <iostream>
#include <vector>
#include "invoiceItem.h"
#include "foodItem.h"

class invoice {
    
public:
    
    // Constructor
    invoice (std::vector<invoiceItem> itemList, std::string vendor, std::string date);
    
    // Getters
    double getTotalCost();
    std::vector<invoiceItem> getItemList();
    std::string getItemListString();
    int getIdNum();
    std::string getVendorName();
    std::string getDate();
    int getTotalCount();
    
    // Setters
    void setVendor(std::string vendorName);
    
    
 
    
private:
    
    
    int idNum;
    int totalCount;
    double totalCost;
    std::vector<invoiceItem> itemList;
    std::string vendor;
    std::string date;
};

