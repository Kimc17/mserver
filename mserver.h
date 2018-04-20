
#ifndef MSERVER_MSERVER_H
#define MSERVER_MSERVER_H

#include "EstructuraData.h"
#include <stdlib.h>
#include "EstructuraData.h"
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>
#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //Permite el write
#include<pthread.h> //Biblioteca de Threads , asociada a lpthread
#include <jsoncpp/json/json.h>


class Server {
public:
    int crear();



};



#endif //MSERVER_MSERVER_H
