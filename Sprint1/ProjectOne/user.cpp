#include "user.h"

User::User(string id, string name, multimap<string,string> tuple, string mood)
{
    this->id = id;
    this->name = name;
    tweet = tuple;
    this->mood = mood;
}
/* GetId returns the numerical id of the user object
 * @return the id in string form
 */
string User::getID()
{
    return id;
}

/* getName returns the username of the twitter user
 * @return the username in string form
 */
string User::getName()
{
    return name;
}

/* getTweet returns a multimap of the partofspeech(key)
 * and word of one tweet for one user
 * @return a multimap of of<partofspeech,word>
 */
multimap<string,string> User::getTweet()
{
    return tweet;
}

/* getMood returns the mood of the user in string form
 * @return the mood in string form
 */
string User::getMood()
{
    return mood;
}
