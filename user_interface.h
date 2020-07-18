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

#include <fstream>
#include <string>
class UserInterface {
  private:
  public:
  static void changeUsername(const char * NewUsernameString) {
    int BufferStringLength = std::strlen(NewUsernameString);
    std::fstream UserDetailsDatafile.open("user_details.txt", ios::in | ios::bin | ios::app);
    if (std::is_open(UserDetailsDatafile) == false) std::cout << "file is unable to open" << std::endl;
    else {
      while (UserDetailsDatafile.eof()) {
        while (UserDetailsDatafile.eol()) {
          for (unsigned int count = 0; count < BufferStringLength; count++) {
            UserDetailsDatafile.seekp(0, ios::beg);
            UserDetailsDatafile.seekg(NewUsernameString, 
                UserDetailsDatafile.tellg(&NewUsernameString, sizeof(NewUsernameString)));
            int StringLocationInFile = UserDetailsDatafile.tellp();
            static char *   replacingString = std::getchar(NewUsernameString);
            std::strcpy(NewUsernameString, replacingString);
          }
        }
      }
    }
    
  }
  protected:
};

#endif // _USER_INTERFACE__