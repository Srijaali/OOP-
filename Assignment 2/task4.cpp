/*
Name: Syeda Rija Ali
ID: 23K-0057
Desc: Social Media app using inheritance
*/

#include <iostream>
using namespace std;

class Post
{
private:
    static int nextID;
    int postID;
    string content;
    int likes;
    int comments;
    int views;

public:
    Post(string cont) : content(cont), likes(2), comments(2), views(2)
    {
        postID = nextID++;
    }
    void postLikes()
    {
        likes++;
    }
    void postComments()
    {
        comments++;
    }
    void postViews()
    {
        views++;
    }

    int getLikes() const
    {
        return likes;
    }
    int getComments() const
    {
        return comments;
    }
    int getViews() const
    {
        return views;
    }

    void increaseComments(int comm)
    {
        comments *= comm;
    }
    void increaseLikes(int like)
    {
        likes *= like;
    }
    void increaseViews(int view)
    {
        views *= view;
    }
    void display()
    {
        cout << "Post ID: " << postID << endl;
        cout << "Content: " << content << endl;
        cout << "Likes: " << likes << endl;
        cout << "Comments: " << comments << endl;
        cout << "Views: " << views << endl;
    }
};

int Post::nextID = 1;

class User
{
private:
    string username;
    string email;
    string password;

    string passwordEncrypt(string &pass)
    {
        string hpassword = " ";
        for (char ch : pass)
        {
            hpassword += to_string(ch + 1);
        }

        return hpassword;
    }

public:
    User(string user, string em, string pass) : username(user), email(em)
    {
        password = passwordEncrypt(pass);
    }

    bool userVerification(string user, string pass)
    {
        string hpassword = passwordEncrypt(pass);
        if ((username == user) && (password == pass))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string getUsername() const
    {
        return username;
    }

    string getPassword() const
    {
        return password;
    }

    virtual int likes() const
    {
        return 0;
    }
    virtual int comments() const
    {
        return 0;
    }
    virtual int views() const
    {
        return 0;
    }
};

class RegularUser : public User
{
private:
    static const int MAX_FEED_SIZE = 10;
    Post *feed[MAX_FEED_SIZE];
    int size;

public:
    RegularUser(string user, string em, string pass) : User(user, em, pass), size(0) {}

    void addToFeed(Post *post)
    {
        if (size < MAX_FEED_SIZE)
        {
            feed[size++] = post;
            post->postLikes();
            post->postComments();
            post->postViews();
        }
        else
        {
            cout << "Feed is full!" << endl;
        }
    }

    void viewFeed()
    {
        cout << "Feed of " << getUsername() << ":" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "\nPost " << i + 1 << ":" << endl;
            feed[i]->display();
        }
    }

    int likes() const 
    {
        int totalLikes = 0;
        for (int i = 0; i < size; i++)
        {
            totalLikes += feed[i]->getLikes();
        }
        return totalLikes;
    }

    int comments() const 
    {
        int totalComments = 0;
        for (int i = 0; i < size; i++)
        {
            totalComments += feed[i]->getComments();
        }
        return totalComments;
    }

    int views() const 
    {
        int totalViews = 0;
        for (int i = 0; i < size; i++)
        {
            totalViews += feed[i]->getViews();
        }
        return totalViews;
    }
};

class BusinessUser : public User
{
private:
    static const int promotionLimit = 10;
    int count;
    int totalLikes;
    int totalComments;
    int totalViews;

public:
    BusinessUser(string user, string em, string pass) : User(user, em, pass), count(0), totalLikes(0), totalComments(0), totalViews(0) {}
    void promotePost(Post *post)
    {
        if (count < promotionLimit)
        {
            cout << "Post has been promoted for " << getUsername() << "!" << endl;
            post->increaseComments(2);
            post->increaseLikes(2);
            post->increaseViews(3);

            totalComments += post->getComments();
            totalLikes += post->getLikes();
            totalViews += post->getViews();
            count++;
        }
        else
        {
            cout << "Reached Promotion Limit!" << endl;
        }
    }
    int likes() const 
    {
        return totalLikes;
    }
    int comments() const 
    {
        return totalComments;
    }
    int views() const 
    {
        return totalViews;
    }
};

int main()
{
        cout << "Name: Syeda Rija Ali" << endl;
        cout << "ID: 23K-0057" << endl;
        cout << endl;

    RegularUser regular("Asher", "asher12@regularuser.com", "asher123");
    BusinessUser business("Amna", "amna.234@businessuser.com", "amna234");

    Post p1("Moving to New House");
    Post p2("A day in my Life!");
    Post p3("Travel through my Journey!");

    regular.addToFeed(&p1);
    regular.addToFeed(&p2);

    cout << "\nREGULAR USER" << endl;
    regular.viewFeed();
    cout << "Total Likes: " << regular.likes() << endl;
    cout << "Total Coments: " << regular.comments() << endl;
    cout << "Total Views: " << regular.views() << endl;

    cout << "\nBUSINESS USER" << endl;
    cout << "Feed of " << business.getUsername() << endl;
     business.promotePost(&p3);
    cout << "Total Likes: " << business.likes() << endl;
    cout << "Total Coments: " << business.comments() << endl;
    cout << "Total Views: " << business.views() << endl;

    return 0;
}
