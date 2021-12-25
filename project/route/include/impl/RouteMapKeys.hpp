#pragma once

//  base
#define REGISTRATION                     "registration"  //  completed + test
//  input: nickname, password; output: user_id; error:"null" (если пользователь уже существует)

#define AUTHENTICATION                   "autorization"  //  completed + test
//  input: nickname, password; output: user_id; error:"null" (если введены некорректные данные)



//  synchro
#define GET_EVENTS                       "get_events"  //  completed
//  input: user_id, date; output: set<event_t> [description, time_begin, time_end]

#define GET_CONTACTS                     "get_friends"  //  completed
//  input: user_id; output: set<sring> [nickname]

#define GET_GROUPS                       "get_groups"
//  input: user_id; output: set<string> [title]



//  personal data
#define WRITE_PERSONAL_DATA              "..."



//  user address
#define WRITE_ADDRESS                    "..."



//  event
#define ADD_EVENT                        "add_event"  //  completed + test
//  input: user_id, data, description, time_begin, time_end; output: OK

#define WRITE_EVENT                      "change_event"  //  completed
//  input: user_id, data, description, time_begin, time_end; output: OK

#define RM_EVENT                         "delete_event"  //  completed
//  input: user_id, data, description, time_begin, time_end; output: OK



//  list_contacts
#define ADD_USER_CONTACTS                "add_friend"  //  completed + test
//  input: user_id, nickname; output: OK

#define RM_USER_CONTACTS                 "delete_friend"  //  completed + test
//  input: user_id, nickname; output: OK



//  group
#define ADD_GROUP                        "create_group"
//  input: title; output: group_id ???

#define WRITE_GROUP                      "change_group"
//  input: title; output OK

#define RM_GROUP                         "delete_group"
//  input: title; output OK

#define ADD_USER                         "invite"
//  input: nickname, title(group); output: OK

#define RM_USER                          "kick"
//  input: nickname, title(group); output: OK

#define JOIN                             "join_group"
//  input: nickname, title(group); output: OK

#define LEAVE                            "leave_group"
//  input: nickname, title(group); output: OK

#define SEARCH_GROUP                     "search_group"
//  input: title; output: title; error:"null" (не найдена такая группа)

//  meetup in group
#define SEARCH_FREE_TIME                 "get_meetup"
//  input: title, date; output: set<meetup_t>[description, time_begin, time_end]

#define HISTORY_MEETUP                   "get_history"
//  input: title; output: set<meetup_t>[description, time_begin, time_end, date]


/*
Идеи по функционалу:
 - match (голосование по времени встречи)
*/
