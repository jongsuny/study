#include "jcc.hpp"
#include "pugixml.hpp"
#include "parser.hpp"
#include "path.hpp"
using namespace std;
using namespace jcc;
using namespace jcc::parser;
void print_help() {
	cout <<"Jingdong JXML Compiler, version v" << VERSION<< endl;
	cout <<"Usage: ./jcc [-d] [-o OUTPUT] [-xc XComponentDefine] [-om XComponentDefine] <FILES... | -s <SINGLE_FILE>" << endl;
	cout<<"Options :" << "" <<endl;
	cout<<"-d :" << " output code for debug" <<endl;
	cout<<"-o :" << " output destination (default stdout)" <<endl;
	cout<<"-xc :" << " output simplified code for custom component" <<endl;
	cout<<"-cc :" << " output compelete code for custom component" <<endl;
	cout<<"-s :" << " read from stdin" <<endl;
	cout<<"XComponentDefine :" << "" <<endl;
	cout<<"\t'<wxml_cout> <<wxml_path_i> <xcompo_cout> <xcompos...> ...>"<<endl;
	cout<<"\texample :" << " '2 /page/index.wxml 2 mytag mygame /page/log.wxml 1 mytag'" <<endl;
}
int parse_config(int argc, char **argv, jcc_config *config) {
   	int i = 0;
    int lastarg;
    int exit_status = 1;
    int idx = 0;
    config->count = 0;
    cout << "argc:" << argc <<endl;
    for (i = 1; i < argc; i++) {
        lastarg = (i == (argc-1));

        if (!strcmp(argv[i],"-h")) {
        	exit_status = 0;
            goto usage;
        } else if (!strcmp(argv[i],"-c")) {
            if (lastarg) goto invalid;
            config->depth = atoi(argv[++i]);
        } else if (!strcmp(argv[i],"-d")) {
            config->debug = true;
        } else if (!strcmp(argv[i],"-o")) {
            config->out = strdup(argv[++i]);
        } else if (!strcmp(argv[i],"-xc")) {
            // config.csv = 1;
        } else if (!strcmp(argv[i],"-cc")) {
            // config.csv = 1;
        } else {
            if (argv[i][0] == '-') {
            	goto invalid;
            } else {
            	config->input[idx++] = strdup(argv[i]);
            	config->count++;
            }
        }
    }
    return i;

invalid:
    printf("Invalid option \"%s\" or option argument missing\n\n",argv[i]);

usage:
    print_help();
    exit(exit_status);
}

void print_config(jcc_config *config) {
	cout<<"==================================" <<endl;
	cout<<"config debug print" <<endl;
	cout<<"debug: "<< boolalpha<< config->debug <<endl;
	if(config->out == NULL) {
		cout<<"out: stdout " <<endl;
	} else {
		cout<<"out: "<< config->out <<endl;	
	}
	cout<<"input file count: "<< config->count <<endl;	
	if(config->count > 0) {
		for(int idx = 0; idx < config->count; idx++) {
			cout <<"input[" << idx <<"]: "<< config->input[idx] <<endl;		
		}
	}
}
void pugi_test() {
	pugi::xml_document doc;  
	if (!doc.load_file("/Users/jinjinzhe/jingdong/docs/smallapp/projects/jcc/cart.xml", pugi::parse_full, pugi::encoding_utf8))//加载xml文件，如果是新建，用load_buffer  
	{    
	  std::cout<<"nothing Loading!"<<std::endl;    
	}  
	pugi::xml_node rootNode = doc.child("root");//这里可以让指针指向已有的节点，假如有root节点  
	pugi::xml_node childNode;         
	childNode=rootNode.append_child("ddddddd");  
	childNode.append_attribute("444");  
	childNode.append_attribute("555");  

	childNode=rootNode.append_child("44444");  
	childNode.set_name("rrrrr");  
	childNode.append_child(pugi::node_pcdata).set_value("777777777777777777");  
	rootNode.insert_child_after("safe",childNode);//在节点之后插 入   

	doc.print(std::cout);//打印doc  
	doc.save_file("test_out.xml");//保存文件 
}


int main(int argc, char ** argv) {
	jcc_config config, *config_ptr;
	enum jcc_node_type type = node_element;
	config_ptr = &config;
	memset(&config,0, sizeof(jcc_config));
	parse_config(argc, argv, config_ptr);
    print_config(config_ptr);
    pugi_test();
    cout << type << endl;
	jcc_io io;
	size_t length;
	jcc_parse_status status = io.open("/Users/jinjinzhe/jingdong/docs/smallapp/projects/jcc/cart.xml", "rb");
	cout<<io.size(length)<<",szie:"<<length<<endl;
	jcc_buffer buffer;
	io.read(&buffer, length);
	cout<<"contents:"<<buffer.data<<endl;
	cout<<"filename:"<<io.getFileName()<<endl;
	Path p(io.getFileName());
	cout<<p.extension()<<endl;
	cout<<p.up()<<endl;
	
	Path pa("test");
	cout<<pa.separator<<endl;
	return 0;
}
