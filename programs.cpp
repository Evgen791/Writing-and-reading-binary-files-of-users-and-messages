#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

 class User
{
  string _name;
  string _login;
  string _pass;
public:User (string name, string login, string pass)
  {
    _name = name;
    _login = login;
    _pass = pass;
  }
  string getName ()
  {
    return _name;
  }
  string getLogin ()
  {
    return _login;
  }
  string getPass ()
  {
    return _pass;
  }
};


 
class Message
{
  string _text;
  string _sender;
  string _receiver;
public:Message (string text, string sender, string receiver)
  {
    _text = text;
    _sender = sender;
    _receiver = receiver;
  }
  string getText ()
  {
    return _text;
  }
  string getSender ()
  {
    return _sender;
  }
  string getReceiver ()
  {
    return _receiver;
  }
};


 
int
main ()
{
  string user_file = "users.bin";
  string message_file = "messages.bin";
  
 
// // Запись объектов класса User в файл
User user1 ("Alex", "alex_login", "12345");
  
User user2 ("Boris", "boris_login", "67890");
  
ofstream user_out (user_file, ios::binary | ios::out);
  
user_out.write ((char *) &user1, sizeof (user1));
  
user_out.write ((char *) &user2, sizeof (user2));
  
user_out.close ();
  
 
// Запись объектов класса Message в файл
Message message1 ("Hello, Boris!", "Alex", "Boris");
  
Message message2 ("Hi, Alex!", "Boris", "Alex");
  
ofstream message_out (message_file, ios::binary | ios::out);
  
message_out.write ((char *) &message1, sizeof (message1));
  
message_out.write ((char *) &message2, sizeof (message2));
  
message_out.close ();
  
 
// Чтение объектов класса User из файла
ifstream user_in (user_file, ios::binary | ios::in);
  
User user_temp1 ("", "", "");
  
User user_temp2 ("", "", "");
  
user_in.read ((char *) &user_temp1, sizeof (user_temp1));
  
user_in.read ((char *) &user_temp2, sizeof (user_temp2));
  
user_in.close ();
  
cout << "User 1: Name-" << user_temp1.
    getName () << ", Login-" << user_temp1.
    getLogin () << ", Password-" << user_temp1.getPass () << endl;
  
cout << "User 2: Name-" << user_temp2.
    getName () << ", Login-" << user_temp2.
    getLogin () << ", Password-" << user_temp2.getPass () << endl;
  
 
// Чтение объектов класса Message из файла
    
ifstream message_in (message_file, ios::binary | ios::in);
  
Message message_temp1 ("", "", "");
  
Message message_temp2 ("", "", "");
  
message_in.read ((char *) &message_temp1, sizeof (message_temp1));
  
message_in.read ((char *) &message_temp2, sizeof (message_temp2));
  
message_in.close ();
  
cout << "Message 1: Text-" << message_temp1.
    getText () << ", Sender-" << message_temp1.
    getSender () << ", Receiver-" << message_temp1.getReceiver () << endl;
  
cout << "Message 2: Text-" << message_temp2.
    getText () << ", Sender-" << message_temp2.
    getSender () << ", Receiver-" << message_temp2.getReceiver () << endl;
  
 
return 0;

}
