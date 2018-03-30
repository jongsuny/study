#ifndef HEADER_JCC_HPP
#define HEADER_JCC_HPP


#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <getopt.h>          /*所在头文件 */
#include <string>
#include <iostream>
#include <fstream>

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
	template <typename T> struct auto_release
	{
		typedef void (*D)(T*);

		T* data;
		D deleter;

		auto_release(T* data_, D deleter_): data(data_), deleter(deleter_)
		{
		}

		~auto_release()
		{
			if (data) deleter(data);
		}

		T* release()
		{
			T* result = data;
			data = NULL;
			return result;
		}
	};
	

	enum jcc_parse_status {
		status_ok = 0,				// No error

		status_file_not_found,		// File was not found during load_file()
		status_io_error,			// Error reading from file/stream
		status_out_of_memory,		// Could not allocate memory
		status_internal_error,		// Internal error occurred

		status_unrecognized_tag,	// Parser could not determine tag type

		status_bad_pi,				// Parsing error occurred while parsing document declaration/processing instruction
		status_bad_comment,			// Parsing error occurred while parsing comment
		status_bad_cdata,			// Parsing error occurred while parsing CDATA section
		status_bad_doctype,			// Parsing error occurred while parsing document type declaration
		status_bad_pcdata,			// Parsing error occurred while parsing PCDATA section
		status_bad_start_element,	// Parsing error occurred while parsing start element tag
		status_bad_attribute,		// Parsing error occurred while parsing element attribute
		status_bad_end_element,		// Parsing error occurred while parsing end element tag
		status_end_element_mismatch,// There was a mismatch of start-end tags (closing tag had incorrect name, some tag was not closed or there was an excessive closing tag)

		status_append_invalid_root,	// Unable to append nodes since root type is not node_element or node_document (exclusive to xml_node::append_buffer)

		status_no_document_element	// Parsing resulted in a document without element nodes
	};
	// Writer interface for node printing (see xml_node::print)
	class xml_writer
	{
		public:
			virtual ~xml_writer() {}

		// Write memory chunk into stream/file/whatever
		virtual void write(const void* data, size_t size) = 0;
	};
	// void* allocate(size_t size) {
	// 	return malloc(size);
	// }
	// void deallocate(void *memory) {
	// 	free(memory);
	// }

	typedef struct jcc_buffer {
		char * data;
		size_t size;
	} jcc_buffer;

	class jcc_io {
		public:
			jcc_io(){};
			// jcc_parse_status open(std::string _path, std::string _pattern);
			jcc_parse_status open(const char *_filename, const char *mode);
			void close();
			jcc_parse_status read(jcc_buffer *buffer, size_t length);
			jcc_parse_status size(size_t& file_size);
			const char *getFileName();
			const char *getFileDir();
			virtual ~jcc_io() {}
		protected:
			const char *filename;
			const char *dir;
			FILE *file;
	};
}

#endif