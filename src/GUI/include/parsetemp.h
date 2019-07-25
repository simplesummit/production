#ifndef PARSETEMP_H
#define PARSETEMP_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <thread>
#include <unistd.h>

class ParseTemp {
public:
	
    int GetUsage(std::string cmd) {
        std::string data;
        unsigned int result;
        FILE * stream;
        const int max_buffer = 256;
        char buffer[max_buffer];
        
        cmd.append(" 2>&1");
        stream = popen(cmd.c_str(), "r");
        if(stream) {
            while(!feof(stream))
                if(fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
            pclose(stream);
        }
        std::size_t cpu_ind = data.find(" CPU [");
	std::size_t cpu_end = data.find("]");
	std::cout << cpu_ind << " --- " << cpu_end << std::endl;
    }
private:
};
#endif
