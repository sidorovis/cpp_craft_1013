#include <boost/test/test_tools.hpp>

namespace multicast_communication
{
	namespace tests_
	{
		void quote_message_tests();
		void trade_message_tests();
		void config_reader_tests();
		
		void market_data_processor_tests();
		void market_data_receiver_tests();
	}
}

namespace async_udp
{
	namespace tests_
	{
		void udp_listner_tests();
	}
}
