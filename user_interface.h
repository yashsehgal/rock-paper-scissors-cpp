/**
 * This is a user details modification and management interface module of the game-project.
 * The entire code base the C++ oriented and follows C++ 11 standards of coding.
 * This is an open-source project, thus if someone wants to contribute, may contribute easily by forking and cloning the
 * project repository from my GitHub.
 * 
 * Project Developer: Yash Sehgal
 * GitHub Details: Yash Sehgal (@yashsehgal)
 * Module Language: C++ (C++ 11)
 * 
 // @author: @yashsehgal
 // @date: 17-07-2020 (Monday)
 * This file connects a datafile module which stores the game details in Text format.
 * */

/**
  // TODO: To access all the datafiles related to user-details data.
  // TODO: Create methods for managing and modifying user details.

  // ? To manage all the methods using common C++ 11 and C++ 14 datatype methods
 * */

#ifndef _USER_INTERFACE__
#define _USER_INTERFACE__

class UserInterface {
  private:
  public:
  static void changeUsername(const char * NewUsernameString) {
    std::fstream UserDetailsDatafile.open("user_details.txt", ios::app | ios::in | ios::bin);
    // continue from the username renaming feature task.
    // currently the code module is under review and support development.
  }
  protected:
};

#endif // _USER_INTERFACE__