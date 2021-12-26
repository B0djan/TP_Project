#include <PGConnection.hpp>

#include <DataBaseConnectorImpl.hpp>

namespace DatabaseConnector {
    namespace Synchro {
        std::set<std::string> Contacts(const std::string& user_id) {
            char command[] = "SELECT fk_user_id, nickname "
                             "FROM contacts LEFT JOIN user_m ON fk_friend_id = user_id"
                             "WHERE fk_user_id = $1";

            const char *arguments[1];

            arguments[0] = user_id.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

            std::set<std::string> friends;

            if (PQgetisnull(res, 0, 1))
                return friends;

            int n_rows = PQnfields(res);

            for (int i = 0; i < n_rows; i++) {
                char *Friend = PQgetvalue(res, i, 1);

                friends.insert(Friend);
            }

            return friends;
        };

        std::set<event_t> Events(const event_t& event) {
            char command[] = "SELECT description, time_begin, time_end FROM event_m WHERE (date = $1, fk_user_id = $2)";

            const char* arguments[2];

            arguments[0] = event.date.c_str();
            arguments[1] = event.user_id.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 2, NULL, arguments, NULL, NULL, 0);

            std::set<event_t> events;

            if (PQgetisnull(res, 0, 1))
                return events;

            int n_rows = PQntuples(res);

            for (int i = 0; i < n_rows; i++) {
                event_t event;
                event.description = PQgetvalue(res, i, 0);
                event.time_begin = PQgetvalue(res, i, 1);
                event.time_end = PQgetvalue(res, i, 2);

                events.insert(event);
            }

            return events;
        };

        std::set<std::string> Groups(const std::string &user_id) {

            char command[] = "SELECT fk_user_id, title "
                             "FROM group_members "
                             "LEFT JOIN group_m "
                             "ON fk_group_id = group_id "
                             "WHERE fk_user_id = $1";

            const char *arguments[1];

            arguments[0] = user_id.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

            std::set<std::string> groups;

            if (PQgetisnull(res, 0, 1))
                return groups;                // в верхней функции првоерить пустое ли множество, если да то Not found

            int n_rows = PQnfields(res);

            for (int i = 0; i < n_rows; i++) {
                char *Group_name = PQgetvalue(res, i, 1);

                groups.insert(Group_name);
            }

            return groups;
        }
    }
}