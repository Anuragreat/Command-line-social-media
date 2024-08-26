#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Post {
public:
    std::string content;
    std::string username;

    Post(const std::string& username, const std::string& content)
        : username(username), content(content) {}
};

class User {
public:
    std::string username;
    std::vector<std::string> following;
    std::vector<Post> posts;

    User(const std::string& username) : username(username) {}

    void follow(const std::string& otherUser) {
        following.push_back(otherUser);
        std::cout << username << " is now following " << otherUser << "!\n";
    }

    void createPost(const std::string& content) {
        posts.push_back(Post(username, content));
        std::cout << username << " created a new post!\n";
    }
};

class SocialMediaApp {
private:
    std::unordered_map<std::string, User*> users;

public:
    void createUser(const std::string& username) {
        if (users.find(username) == users.end()) {
            users[username] = new User(username);
            std::cout << "User " << username << " created successfully!\n";
        } else {
            std::cout << "User " << username << " already exists.\n";
        }
    }

    User* getUser(const std::string& username) {
        if (users.find(username) != users.end()) {
            return users[username];
        } else {
            std::cout << "User " << username << " does not exist.\n";
            return nullptr;
        }
    }

    void followUser(const std::string& follower, const std::string& followee) {
        User* followerUser = getUser(follower);
        User* followeeUser = getUser(followee);

        if (followerUser && followeeUser) {
            followerUser->follow(followee);
        }
    }

    void createPost(const std::string& username, const std::string& content) {
        User* user = getUser(username);
        if (user) {
            user->createPost(content);
        }
    }

    void viewFeed(const std::string& username) {
        User* user = getUser(username);
        if (user) {
            std::cout << "\n--- " << username << "'s Feed ---\n";
            for (const auto& followee : user->following) {
                User* followeeUser = getUser(followee);
                if (followeeUser) {
                    for (const auto& post : followeeUser->posts) {
                        std::cout << followeeUser->username << ": " << post.content << "\n";
                    }
                }
            }
        }
    }

    ~SocialMediaApp() {
        for (auto& userPair : users) {
            delete userPair.second;
        }
    }
};

int main() {
    SocialMediaApp app;

    // Create users
    app.createUser("Abhinav");
    app.createUser("Ishant");
    app.createUser("Anubhav");

    // Users follow each other
    app.followUser("Abhinav", "Ishant");
    app.followUser("Abhinav", "Anubhav");
    app.followUser("Ishant", "Anubhav");

    // Users create posts
    app.createPost("Ishant", "Hello from Ishant!");
    app.createPost("Anubhav", "Hey, Anubhav here!");
    app.createPost("Anubhav", "Good morning everyone");

    // View feed for Abhinav
    app.viewFeed("Abhinav");

    return 0;
}