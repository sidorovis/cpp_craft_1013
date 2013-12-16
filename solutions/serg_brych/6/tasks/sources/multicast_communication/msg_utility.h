#ifndef _MSG_UTILITY_H_
#define _MSG_UTILITY_H_
#include <map>
#include <boost/lexical_cast.hpp>
#include <boost/assign.hpp>
#include <iostream>

static const std::map< const char, double > denominator_map = boost::assign::map_list_of
	('0' , 1.0)
    ('3' , 8.0) ('4' , 16.0) ('5' , 32.0) ('6' , 64.0) ('7' , 128.0) ('8' , 256.0)
    ('A' , 10.0) ('B' , 100.0) ('C' , 1000.0 ) ('D' , 10000.0 )
    ('E' , 100000.0 ) ('F' , 1000000.0 ) ('G' , 10000000.0  )
    ('H' , 100000000.0 )
	('I' , 1.0)
    ;

static const uint32_t second_in_min = 60;
static const uint32_t second_in_hour = 3600;


enum Signatures
{
	StartMessage = 0x01,
	EndMessage = 0x03,
	SeparatorMessage = 0x1F,
};

template<size_t size> double get_number(std::istream& data)
{
    char buffer[ size ];
    data.read( buffer, size );
    return boost::lexical_cast< double >( buffer, size );
}

template<size_t size> std::string get_string(std::istream& data)
{
    char buffer[ size ];
    data.read( buffer, size );
    return std::string( buffer , size );
}

static uint32_t get_time(const unsigned char value)
{
	if((value >= '0') && (value <= 'k'))
	{
		return (value - 48);
	}
	else
	{
		return 0;
	}
}


#endif //_MSG_UTILITY_H_