#ifndef HEADER_JCC_HPP
#define HEADER_JCC_HPP



// Include STL headers
#ifndef PUGIXML_NO_STL
#	include <iterator>
#	include <iosfwd>
#	include <string>
#endif

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include<getopt.h>          /*所在头文件 */

#include <iostream>

#define VERSION "0.0.1"
namespace jcc
{
	typedef struct 
	{
		bool debug;
		char* out;
		char* input[128];
		int count;
		bool test;
		int depth;
		
	} jcc_config;
	// Writer interface for node printing (see xml_node::print)
	class xml_writer
	{
		public:
			virtual ~xml_writer() {}

		// Write memory chunk into stream/file/whatever
		virtual void write(const void* data, size_t size) = 0;
	};
	void* allocate(size_t size) {
		return malloc(size);
	}
	void deallocate(void *memory) {
		free(memory);
	}

}

#endif