#pragma once

                            //  base
#define REGISTRATION                     "registration"  //  completed + test
//  input: nickname, password; output: user_id; error:"null" (если пользователь уже существует)

#define AUTHENTICATION                   "autorization"  //  completed + test
//  input: nickname, password; output: user_id; error:"null" (если введены некорректные данные)





                            //  synchro
#define GET_EVENTS                       "get_events"  //  in process + test
//  input: user_id, date; output: set<event_t> [description, time_begin, time_end]

#define GET_CONTACTS                     "get_contacts"  //  in process + test
//  input: user_id; output: set<string> [nickname]

#define GET_GROUPS                       "get_groups"  // in process + test
//  input: user_id; output: set<string> [title]





                            //  general data
#define WRITE_GENERAL_DATA              "write_general"  //  in process
//  input: data...; output: OK

#define GET_GENERAL_DATA                "get_general"   //  in process
//  input: id; output: data




                            //  personal data
#define WRITE_PERSONAL_DATA              "write_personal"  //  in process
//  input: data...; output: OK

#define GET_PERSONAL_DATA                "get_personal"  //  in process
//  input: id; output: data



                            //  user address
#define WRITE_ADDRESS                    "write_address"  //  in process
//  input: data...; output: OK

#define GET_ADDRESS                      "get_address"  //  in process
//  input: id; output: data




                            //  event
#define ADD_EVENT                        "add_event"  //  completed + test
//  input: user_id, data, description, time_begin, time_end; output: event_id

#define WRITE_EVENT                      "rewrite_event"  //  completed + test
//  input: user_id, data, description, time_begin, time_end; output: OK

#define RM_EVENT                         "delete_event"  //  completed + test
//  input: user_id, data, description, time_begin, time_end; output: OK



                            //  list_contacts
#define ADD_USER_CONTACTS                "add_friend"  //  completed + test
//  input: user_id, nickname; output: OK

#define RM_USER_CONTACTS                 "delete_friend"  //  completed + test
//  input: user_id, nickname; output: OK




                            //  group
#define ADD_GROUP                        "create_group"  //  completed + test
//  input: title, nickname; output: group_id

#define WRITE_GROUP                      "rewrite_group"  //  completed + test
//  input: title; output OK

#define RM_GROUP                         "delete_group"  //  completed + test
//  input: title; output OK


#define GET_MEMBERS                         "get_group_members"  //  completed + test
//  input: group_id; output: members




#define ADD_USER                         "invite"  //  completed + test
//  input: nickname, title(group); output: OK

#define RM_USER                          "kick"  //  completed + test
//  input: nickname, title(group); output: OK




//  meetup in group
#define SEARCH_FREE_TIME                 "get_meetup"
//  input: title, date; output: set<meetup_t>[description, time_begin, time_end]


#define JOIN                             "join_group"  //  В первом приближении похоже на add_user
//  input: nickname, title(group); output: OK

#define LEAVE                            "leave_group"  //  В первом приближении похоже на rm_user
//  input: nickname, title(group); output: OK

//#define SEARCH_GROUP                     "search_group"   //  Данный фукнционал пока не нужен
//  input: title; output: title, members; error:"null" (не найдена такая группа)

//#define HISTORY_MEETUP                   "get_history"
//  input: title; output: set<meetup_t>[description, time_begin, time_end, date]


/*
Идеи по функционалу:
 - match (голосование по времени встречи)
 - в Table event_m добавить поле event_name
*/
