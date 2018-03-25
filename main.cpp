#include "jcc.hpp"
using namespace std;
using namespace jcc;
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
void parse_config(int argc, char **argv, jcc_config *config) {
	int ch;
    printf("\n\n");
    printf("optind:%d，opterr：%d\n",optind,opterr);
    char *string = "a::b:c:d";
    printf("-----------parse config---------------\n");
	while ((ch = getopt(argc, argv, string)) != -1)
	{
		printf("opt = %c\t\t", ch);
        printf("optarg = %s\t\t",optarg);
        printf("optind = %d\t\t",optind);
        printf("argv[optind] = %s\n",argv[optind]);
	 //   	switch (ch) 
		// {
  //      		case 'a':
	 //               printf("HAVE option: -a\n\n");   
	 //               break;
  //      		case 'b':
	 //               printf("HAVE option: -b\n"); 
	 //               printf("The argument of -b is %s\n\n", optarg);
	 //               break;
  //      		case 'c':
	 //               printf("HAVE option: -c\n");
	 //               printf("The argument of -c is %s\n\n", optarg);
	 //               break;
  //      		case 'd':
	 //           	config->debug = true;
	 //            break;
  //     		case 'o':
	 //            printf("HAVE option: -o\n");
	 //            printf("The argument of -o is %s\n\n", optarg);
	 //          break;
  // 			case '?':
	 //               printf("Unknown option: %c\n",(char)optopt);
	 //               break;
  //      		default:
  //      			printf("Unknown option: %c found!\n",(char)optopt);
	 //    }
	}
}

/* Returns number of consumed options. */
int parseOptions(int argc, char **argv, jcc_config *config) {
	// int opt;
 //    char *string = "a::b:c:d";
 //    while ((opt = getopt(argc, argv, string))!= -1)
 //    {  
 //        printf("opt = %c\t\t", opt);
 //        printf("optarg = %s\t\t",optarg);
 //        printf("optind = %d\t\t",optind);
 //        printf("argv[optind] = %s\n",argv[optind]);
 //    }
    int i;
    int lastarg;
    int exit_status = 1;
    int idx = 0;
    config->count = 0;

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
	cout<<"out: "<< config->out <<endl;
	if(config->count > 0) {
		for(int idx = 0; idx < config->count; idx++) {
			cout <<"input[" << idx <<"]: "<< config->input[idx] <<endl;		
		}
	}
}

int main(int argc, char ** argv) {
	xml_node_type node_type;
	jcc_config config, *config_ptr;
	config_ptr = &config;
	parseOptions(argc, argv, config_ptr);
	//cout<<"test" <<endl;
	//cout<<node_type <<endl;

    //print_help();

    // parse_config(argc, argv, config_ptr);
    
    print_config(config_ptr);
	return 0;
}
