#include "../include/PGConnection.hpp"

    PGconn* PGConnection::GetConnection()
    {
        static PGConnection object;

        if (PQstatus(object.connection) != CONNECTION_OK && PQsetnonblocking(object.connection, 1) != 0 ) 
        {
            printf("Connection to database faild: %s\n", PQerrorMessage(object.connection));
            PQfinish(object.connection);
            exit(1);
        } 
        
        return object.connection;
    };

    void PGConnection::CloseConnection()
    {
        PQfinish(GetConnection());
        exit(1);
    };