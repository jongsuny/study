#ifndef HEADER_JCC_HPP
#define HEADER_JCC_HPP



// Include STL headers
#ifndef PUGIXML_NO_STL
#	include <iterator>
#	include <iosfwd>
#	include <string>
#endif

#include <stddef.h>
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
		
	}jcc_config;
	// Tree node types
	enum xml_node_type
	{
		node_null,			// Empty (null) node handle
		node_document,		// A document tree's absolute root
		node_element,		// Element tag, i.e. '<node/>'
		node_pcdata,		// Plain character data, i.e. 'text'
		node_cdata,			// Character data, i.e. '<![CDATA[text]]>'
		node_comment,		// Comment tag, i.e. '<!-- text -->'
		node_pi,			// Processing instruction, i.e. '<?name?>'
		node_declaration,	// Document declaration, i.e. '<?xml version="1.0"?>'
		node_doctype		// Document type declaration, i.e. '<!DOCTYPE doc>'
	};
	enum xml_encoding
	{
		encoding_auto,		// Auto-detect input encoding using BOM or < / <? detection; use UTF8 if BOM is not found
		encoding_utf8,		// UTF8 encoding
		encoding_utf16_le,	// Little-endian UTF16
		encoding_utf16_be,	// Big-endian UTF16
		encoding_utf16,		// UTF16 with native endianness
		encoding_utf32_le,	// Little-endian UTF32
		encoding_utf32_be,	// Big-endian UTF32
		encoding_utf32,		// UTF32 with native endianness
		encoding_wchar,		// The same encoding wchar_t has (either UTF16 or UTF32)
		encoding_latin1
	};
	// Forward declarations
	struct xml_attribute_struct;
	struct xml_node_struct;

	class xml_node_iterator;
	class xml_attribute_iterator;
	class xml_named_node_iterator;

	class xml_tree_walker;

	struct xml_parse_result;

	class xml_node;

	class xml_text;

}

#endif