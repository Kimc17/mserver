#include "mserver.h"
#include "List.h"
/* Pasos para la ejecucion del servidor:
 * 1. Abrir una terminal
 * 2. Cambiar el directorio con: cd C-
 * 3. Escribir el comando g++ -pthread  mserver.cpp -o mserver -ljsoncpp -std=c++11

 * 4. Ingresar ./mserver
*/

using namespace std;
void *manejador_conexion(void *);
int socket_desc , client_sock , c;
struct sockaddr_in server , client;
char *memoria;
List<EstructuraData> *metaData;

int top=0;
int limite=1024;


int main(){

    Server* server= new Server;
    server->crear();


    return 0;

}


int Server::crear() {

    //Crea el socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("No se pudo crear el socket");
    }
    puts("\n\n                           ********MSERVER********                 ");
    puts("\n\nEscuchando en el puerto 8888\n ");

    //Prepara el socket(esto es definido)
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );




    // Se reserva memoria y se asigana la direccion al puntero memoria

    memoria = (char*)(malloc(sizeof(char)*1024));

    metaData=  new List<EstructuraData>;





    //Para ver si se asigno correctamente la memoria
    if (memoria  == NULL) {
        puts("Error al intentar reservar memoria");
    }else{
        puts("Reservados 1024 bytes de memoria");
    }


    //Enlazar el servidor
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("Enlace fallido");
        return 1;
    }


    //Escuhar si llegan conexiones
    listen(socket_desc , 3);




    //Se aceptan y  esperan las conexiones
    puts("Esperando por conexiones...");
    c = sizeof(struct sockaddr_in);
    pthread_t thread_id;

    while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Conexion aceptada");

        //Creacion del hilo para mas de un cliente
        if( pthread_create( &thread_id , NULL ,  manejador_conexion, (void*) &client_sock) < 0)
        {
            perror("No se pudo crear el thread");
            return 1;
        }

        //pthread_join( thread_id , NULL); // Esta es la base del Thread
    }

    if (client_sock < 0)
    {
        perror("Fallo aceptado");
        return 1;
    }



}

/*
 * Este es el manejador de conexiones para cada cliente
 */


using namespace std;
void *manejador_conexion(void *socket_desc) {

    //Se obtiene el descriptor del socket
    int sock = *(int *) socket_desc;
    int read_size;
    char client_message[200];
    const char *message;

    //Enviar mensajes al cliente
    //message = "Preparado para recibir datos\n";
    //write(sock , message , strlen(message));

    //Recibir mensajes al cliente
    while ((read_size = recv(sock, client_message, 200, 0)) > 0) {
        //Final del marcador del string respuesta
        client_message[read_size] = '\0';


        string mensaje = client_message;
        Json::Reader reader;
        Json::Value obj;
        reader.parse(mensaje, obj);

        string Ptr;
        if (top < limite) {
            string nombre = obj["nombre"].asString();

            stringstream a(obj["tamanio"].asString());
            int tamanio = 0;
            a >> tamanio;
            memoria += tamanio;
            top += tamanio;
            string tipo = obj["tipo"].asString();

            stringstream c(obj["referencias"].asString());
            int referencias = 0;
            c >> referencias;

            string tipoReferencia = obj["TipoReferencia"].asString();
            string valores;

            stringstream s(obj["tamanio"].asString());
            float scope = 0;
            s >> scope;
            if (tipo == "char") {
                string val = obj["valor"].asString();
                *(memoria + tamanio) = valores[1];

                std::ostringstream oss;
                oss << (void *) (memoria + tamanio);
                std::string ptr = oss.str();
                Ptr = ptr;
                std::cout << "Se obtiene" << ptr << '\n';
                valores=val;

            } else if (tipo == "int") {
                string val = obj["valor"].asString();
                stringstream a(obj["tamanio"].asString());
                int valor = 0;
                a >> valor;
                *(int *) (memoria + tamanio) = valor;



                std::ostringstream oss;
                oss << (void *) (int *) (memoria + tamanio);
                std::string ptr = oss.str();
                Ptr = ptr;
                std::cout << "Se obtiene" << ptr << '\n';
                valores=val;

            }/* else if(tipo == "borrar") {
                for (int i = 0; i < metaData->length(); i++) {

                    if (scope ==metaData->Get(i).getScope()){
                        stringstream c(metaData->Get(i).getPtr());
                        int temp= 0;
                        c >> temp;
                        memoria-= metaData->Get(i).getTamanio();
                        top-= metaData->Get(i).getTamanio();
                        delete(metaData->Get(i));
                        for(int b = 0; b < metaData->length(); b++) {
                            *(string *) (temp - tamanio) = metaData->Get(i+b).getValor();
                            std::ostringstream oss;
                            oss << (string *) (temp - tamanio);
                            std::string ptr = oss.str();
                            metaData->Get(i+b).setPtr(ptr);
                            stringstream e(metaData->Get(i+b).getPtr());
                            e >> temp;

                        }

                    }
                }


            }*/else if (tipo == "float") {
                string val = obj["valor"].asString();
                stringstream a(obj["tamanio"].asString());
                float valor = 0;
                a >> valor;
                *(float *) (memoria + tamanio) = valor;

                std::ostringstream oss;
                oss << (void *) (float *) (memoria + tamanio);
                std::string ptr = oss.str();
                Ptr = ptr;

                std::cout << "Se obtiene" << ptr << '\n';

                valores=val;
            } else if(tipo == "reference"){

                if (metaData->isEmpty()){
                    cout<< "fallo: lista vacia";
                }else {
                    for (int i = 0; i < metaData->length(); i++) {
                        string val = metaData->Get(i).getPtr();
                        valores=val;

                        if (metaData->Get(i).getValor() == obj["valor"].asString()) {

                                *(string *) (memoria + tamanio) = metaData->Get(i).getPtr();
                                std::ostringstream oss;
                                oss << (void *) (string *) (memoria + tamanio);
                                std::string ptr = oss.str();
                                Ptr = ptr;
                            int c= metaData->Get(i).getReferencias();
                            c++;
                            metaData->Get(i).setReferencias(c);

                            }
                        }
                    }

                }


            else if (tipo == "long");
            {

                stringstream a(obj["tamanio"].asString());
                long valor = 0;
                a >> valor;
                *(long *) (memoria + tamanio) = valor;

                std::ostringstream oss;
                oss << (void *) (long *) (memoria + tamanio);
                std::string ptr = oss.str();
                Ptr = ptr;

                std::cout << "Se obtiene" << ptr << '\n';
            }


            memoria += tamanio;
            EstructuraData estruct;
            estruct.setAtributos(nombre, Ptr, valores, tipo, referencias, tipoReferencia,scope, tamanio);

            metaData->Insert(estruct);



                Json::Value event;
                event["tipo"] = estruct.getTipo();
                event["nombre"] = estruct.getNombre();
                event["valor"] = estruct.getValor();
                event["posmemoria"] = estruct.getPtr();
                event["referencias"] = estruct.getReferencias();
                event["tipoReferencia"] = estruct.getReferencias();


                string mensaje = event.toStyledString();
                char client_resp[mensaje.size()];
                for (int i = 0; i < mensaje.size(); i++) {
                    client_resp[i] = mensaje[i];
                }


                //Enviar mensaje de vuelta al cliente
                write(sock, client_resp, strlen(client_resp));
            }
         else {
            char client_resp[53] = "sin memoria disponible\n\n";

            //Enviar mensaje de vuelta al cliente
            write(sock, client_resp, strlen(client_resp));
            cout << "sin memoria disponible";
        }


        cout << "El tamaño de la lista  es ahora" << metaData->length();

        cout << "El mensaje recibido es " << client_message << endl;
        //limpiar el mensaje
        //memset(client_message, 0, 2000);

    }
    // Si se desconecta el cliente (en este caso se cierra la terminal)
    if (read_size == 0) {
        puts("Cliente desconectado");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("Fallo");
    }

    }


