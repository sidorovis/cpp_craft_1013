#ifndef BINFILEREADER_INCLUDED
#define BINFILEREADER_INCLUDED 

#include <iostream>
#include <string>
#include <fstream>
#include <stdint.h>
#include "dataStructs.h"

class binFileReader{
private:
    std::string fName;
    std::fstream ifs;

    binFileReader(const binFileReader& that);
    binFileReader operator=(const binFileReader& that);

public:
    binFileReader(const std::string& filename);
    ~binFileReader();

    bool fileOk;

    template<class T>
    bool readRawValue(T& value);
    bool readRawValue(std::string& value, const size_t length);

    bool readQuoteHeader(tqHeader_t& quoteHeader);
    bool readShortQuote(shortQuote_t& shortQuote);
    bool readLongQuote(longQuote_t& longQuote);
    bool readShortTrade(shortTrade_t& shortTrade);
    bool readLongTrade(longTrade_t& longTrade);
};


template<class T>
bool binFileReader::readRawValue(T& value){
   if (ifs.eof()){
	   fileOk = false;
       return false;
   } else {
       ifs.read( (char*)&value, sizeof value);
       return true;
   }
}


#endif
