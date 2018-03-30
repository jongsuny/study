#ifndef HEADER_JCC_PARSER_HPP
#define HEADER_JCC_PARSER_HPP

namespace jcc {
	namespace parser {
		// Tree node types
		enum jcc_node_type
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

		// Forward declarations
		struct xml_attribute_struct;
		typedef struct jcc_node {
			int line_num;
			int col_num;
			char *origin_name;
			jcc_node *parent;
			jcc_node *next_sibling;
		} jcc_node;

		class xml_node_iterator;
		class xml_attribute_iterator;
		class xml_named_node_iterator;

		class xml_tree_walker;

		struct xml_parse_result;

		class xml_node;

		class xml_text;

	}
}


#endif