#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
/*************************************************************************
** Author : Marwa Hammami
** Program : hw4, q1
** Date Created : April 5, 2024
** Date Last Modified : April 5, 2024
** Usage : No command line arguments
**
** Problem:
Accept the following information from the user (keyboard):
- Hw1, hw2 and hw3 (out of 100)
- Midterm (out of 100)
- Final exam (out of 100)
Calculate the total grade out of 100 based on the following grading scale:
Hws --> 30% (10% each)
Midterm --> 30%
Final Exam --> 40%
*************************************************************************/


using namespace std;

// Base class
class SocialMediaAccount {
protected:
    string username;
public:
    SocialMediaAccount() {}
    SocialMediaAccount(string uname) : username(uname) {}

    string getUsername() const {
        return username;
    }
};

// Derived class Twitter
template<typename T>
class Twitter : public SocialMediaAccount {
private:
    int retweetCount;
public:
    Twitter() : retweetCount(0) {}
    Twitter(string uname) : SocialMediaAccount(uname), retweetCount(0) {}

    int getRetweetCount() const {
        return retweetCount;
    }

    void setRetweetCount(int count) {
        retweetCount = count;
    }

    void RT() {
        retweetCount++;
    }
};

// Derived class Instagram
template<typename T>
class Instagram : public SocialMediaAccount {
private:
    int likeCount;
public:
    Instagram() : likeCount(0) {}
    Instagram(string uname) : SocialMediaAccount(uname), likeCount(0) {}

    int getLikeCount() const {
        return likeCount;
    }

    void setLikeCount(int count) {
        likeCount = count;
    }

    void Like() {
        likeCount++;
    }
};

// Profile struct
struct Profile {
    int userId;
    string username;
};

// Main function
int main() {
    // Define Twitter and Instagram objects
    Twitter<string> TS;
    Twitter<Profile> TP;
    Instagram<string> IS;
    Instagram<Profile> IP;

    // Test functions with randomly created users
    srand(time(0)); // Seed the random number generator
    string usernames[] = {"user1", "user2", "user3", "user4", "user5"};
    vector<Profile> profiles;

    // Generate random profiles
    for (int i = 0; i < 5; i++) {
        Profile profile;
        profile.userId = i + 1;
        profile.username = usernames[rand() % 5]; // Randomly select a username
        profiles.push_back(profile);
    }

    // Test Twitter string
    cout << "Testing Twitter<string>:\n";
    for (int i = 0; i < 5; i++) {
        TS.RT(); // Increment retweet count
        cout << "User " << TS.getUsername() << " retweeted " << TS.getRetweetCount() << " times.\n";
    }

    // Test Twitter profile 
    cout << "\nTesting Twitter<Profile>:\n";
    for (int i = 0; i < profiles.size(); i++) {
        TP.RT(); // Increment retweet count
        cout << "User " << TP.getUsername() << " retweeted " << TP.getRetweetCount() << " times.\n";
    }

    // Test Instagram<string>
    cout << "\nTesting Instagram<string>:\n";
    for (int i = 0; i < 5; i++) {
        IS.Like(); // Increment like count
        cout << "User " << IS.getUsername() << " liked " << IS.getLikeCount() << " posts.\n";
    }

    // Test Instagram<Profile>
    cout << "\nTesting Instagram<Profile>:\n";
    for (int i = 0; i < profiles.size(); i++) {
        IP.Like(); // Increment like count
        cout << "User " << IP.getUsername() << " liked " << IP.getLikeCount() << " posts.\n";
    }

    return 0;
}
