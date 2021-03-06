#ifndef _MULTICAST_COMMUNICATION_QUOTE_MESSAGE_H_
#define _MULTICAST_COMMUNICATION_QUOTE_MESSAGE_H_

#include <boost/shared_ptr.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign.hpp>
#include <map>

namespace multicast_communication
{
	class quote_message
	{
		std::map<char, double> denominators_;
		std::map<char, uint32_t> time_stamp_;

		std::string security_symbol_;
		double bid_price_;
		double bid_volume_;
		double offer_price_;
		double offer_volume_;

		uint32_t time_;
	public:
		quote_message();

		std::string security_symbol() const;
		double bid_price() const;
		double bid_volume() const;
		double offer_price() const;
		double offer_volume() const;

		uint32_t time() const;

		bool initialize(const std::string& msg);
	private:
		bool init_short(const std::string& body);
		bool init_long(const std::string& body);
	};

	typedef boost::shared_ptr< quote_message > quote_message_ptr;
}

#endif // _MULTICAST_COMMUNICATION_QUOTE_MESSAGE_H_
