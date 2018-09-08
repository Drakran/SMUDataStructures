#include "user.h"


User::User(string id, string name, multimap<string,string> tuple, string mood)
{
    this->id = id;
    this->name = name;
    tweet = tuple;
    this->mood = mood;
    numTweet++; //Increase total numTweets
    if(mood == "0")
    {
        negTweet++; //Increase negative tweet amounts
    }
    else
    {
        posTweet++; //Increase positive tweet
    }
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
multimap<string,string> & User::getTweet()
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

/* getTotalTweets returns the number of total tweets made(static method)
 * @return numTweet the total number of tweets made (static)
 */
int User::getTotalTweets()
{
    return numTweet;
}

/* getPositive returns the number of total positive made(static method)
 * @return posTweet the total number of +tweets made (static)
 */
int User::getPositiveTweets()
{
    return posTweet;
}

/* getNegative returns the number of total negative tweets made(static method)
 * @return posTweet the total number of -tweets made (static)
 */
int User::getNegativeTweets()
{
    return negTweet;
}



