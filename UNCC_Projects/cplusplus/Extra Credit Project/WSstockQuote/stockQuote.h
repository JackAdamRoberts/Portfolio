#include "soapH.h"    // include the generated proxy
#include <string>
#include <iostream>
#include <cstdlib>
#include "DelayedStockQuoteSoap.nsmap" //include namespace map

using namespace std;

double getQuote(string theName){
  struct soap *soap = soap_new();  //new soap instance
  _ns1__GetQuickQuote* mySymbol = new _ns1__GetQuickQuote;  //input class instance, determined from quote.h
  _ns1__GetQuickQuoteResponse* myResult = new _ns1__GetQuickQuoteResponse; //output class instance

  string* theStr = &theName;//convert string to string*
  string theL1 = "0";
  string* theL2 = &theL1;
  mySymbol->StockSymbol=theStr;   //update input class instance with stock symbol
  mySymbol->LicenseKey=theL2;  //licenseKey is 0 for testing

  if (soap_call___ns1__GetQuickQuote(soap, NULL, NULL, mySymbol, myResult) == 0){  //soap method for getting stock quote, determined from quote.h
	string result = myResult->GetQuickQuoteResult; //get stock quote from output class instance
	if(result.compare("0.00")!=0){//if the company really exists and has a stock quote
        return atof(result.c_str());
	}else{
		return -1; // Company does not have a quote
	}
  }
  else{
    soap_print_fault(soap, stderr);
  }
  soap_destroy(soap); //destroy soap instance
  return -1;
}

double getCopper(int month, int year, int d = 0)
{
   static double DEFAULT = 3;
   char abbrv[10];

   if (d == 1) return DEFAULT;
   else
   {
      if (year > 100) year -= 2000;
	  abbrv[0] = 'H'; abbrv[1] = 'G';
	  abbrv[5] = '.'; abbrv[6] = 'C';
	  abbrv[7] = 'M'; abbrv[8] = 'X'; abbrv[9] = '\0';
	  abbrv[3] = 48 + year / 10;
	  abbrv[4] = 48 + year % 10;
	  switch (month)
	  {
	     case 1: abbrv[2] = 'F'; break;
		 case 2: abbrv[2] = 'G'; break;
		 case 3: abbrv[2] = 'H'; break;
		 case 4: abbrv[2] = 'J'; break;
		 case 5: abbrv[2] = 'K'; break;
		 case 6: abbrv[2] = 'M'; break;
		 case 7: abbrv[2] = 'N'; break;
		 case 8: abbrv[2] = 'Q'; break;
		 case 9: abbrv[2] = 'U'; break;
		 case 10: abbrv[2] = 'V'; break;
		 case 11: abbrv[2] = 'X'; break;
		 case 12: abbrv[2] = 'Z'; break;
		 default: return DEFAULT;
	  }
	  double price = getQuote(abbrv);
	  if (price < 1) price = DEFAULT;
	  return price;
   }
}

double getSilver(int month, int year, int d = 0)
{
   static double DEFAULT = 20;
   char abbrv[10];

   if (d == 1) return DEFAULT;
   else
   {
      if (year > 100) year -= 2000;
	  abbrv[0] = 'S'; abbrv[1] = 'I';
	  abbrv[5] = '.'; abbrv[6] = 'C';
	  abbrv[7] = 'M'; abbrv[8] = 'X'; abbrv[9] = '\0';
	  abbrv[3] = 48 + year / 10;
	  abbrv[4] = 48 + year % 10;
	  switch (month)
	  {
	     case 1: abbrv[2] = 'F'; break;
		 case 2: abbrv[2] = 'G'; break;
		 case 3: abbrv[2] = 'H'; break;
		 case 4: abbrv[2] = 'J'; break;
		 case 5: abbrv[2] = 'K'; break;
		 case 6: abbrv[2] = 'M'; break;
		 case 7: abbrv[2] = 'N'; break;
		 case 8: abbrv[2] = 'Q'; break;
		 case 9: abbrv[2] = 'U'; break;
		 case 10: abbrv[2] = 'V'; break;
		 case 11: abbrv[2] = 'X'; break;
		 case 12: abbrv[2] = 'Z'; break;
		 default: return DEFAULT;
	  }
	  double price = getQuote(abbrv);
	  if (price < 1) price = DEFAULT;
	  return price;
   }
}
double getGold(int month, int year, int d = 0)
{
   static double DEFAULT = 20;
   char abbrv[10];

   if (d == 1) return DEFAULT;
   else
   {
      if (year > 100) year -= 2000;
	  abbrv[0] = 'S'; abbrv[1] = 'I';
	  abbrv[5] = '.'; abbrv[6] = 'C';
	  abbrv[7] = 'M'; abbrv[8] = 'X'; abbrv[9] = '\0';
	  abbrv[3] = 48 + year / 10;
	  abbrv[4] = 48 + year % 10;
	  switch (month)
	  {
	     case 1: abbrv[2] = 'F'; break;
		 case 2: abbrv[2] = 'G'; break;
		 case 3: abbrv[2] = 'H'; break;
		 case 4: abbrv[2] = 'J'; break;
		 case 5: abbrv[2] = 'K'; break;
		 case 6: abbrv[2] = 'M'; break;
		 case 7: abbrv[2] = 'N'; break;
		 case 8: abbrv[2] = 'Q'; break;
		 case 9: abbrv[2] = 'U'; break;
		 case 10: abbrv[2] = 'V'; break;
		 case 11: abbrv[2] = 'X'; break;
		 case 12: abbrv[2] = 'Z'; break;
		 default: return DEFAULT;
	  }
	  double price = getQuote(abbrv);
	  if (price < 1) price = DEFAULT;
	  return price;
   }
}
double getWheat(int month, int year, int d = 0)
{
   static double DEFAULT = 20;
   char abbrv[10];

   if (d == 1) return DEFAULT;
   else
   {
      if (year > 100) year -= 2000;
	  abbrv[0] = 'S'; abbrv[1] = 'I';
	  abbrv[5] = '.'; abbrv[6] = 'C';
	  abbrv[7] = 'M'; abbrv[8] = 'X'; abbrv[9] = '\0';
	  abbrv[3] = 48 + year / 10;
	  abbrv[4] = 48 + year % 10;
	  switch (month)
	  {
	     case 1: abbrv[2] = 'F'; break;
		 case 2: abbrv[2] = 'G'; break;
		 case 3: abbrv[2] = 'H'; break;
		 case 4: abbrv[2] = 'J'; break;
		 case 5: abbrv[2] = 'K'; break;
		 case 6: abbrv[2] = 'M'; break;
		 case 7: abbrv[2] = 'N'; break;
		 case 8: abbrv[2] = 'Q'; break;
		 case 9: abbrv[2] = 'U'; break;
		 case 10: abbrv[2] = 'V'; break;
		 case 11: abbrv[2] = 'X'; break;
		 case 12: abbrv[2] = 'Z'; break;
		 default: return DEFAULT;
	  }
	  double price = getQuote(abbrv);
	  if (price < 1) price = DEFAULT;
	  return price;
   }
}

