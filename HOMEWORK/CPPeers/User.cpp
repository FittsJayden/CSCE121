# include <string>
# include <iostream>
# include <stdexcept>
# include "User.h"

using std::string, std::vector;

User::User(string userName) : userName(userName), userPosts{} {
    if (userName == "") {
        throw std::invalid_argument("username is empty");
    }
    if (userName[0] < 97 || userName[0] > 122) {
        throw std::invalid_argument("username doesn not begin with a lowercase letter");
    }
    for (unsigned int i = 0; i < userName.size(); i++) {
        if (isupper(userName[i])) {
            throw std::invalid_argument("username has uppercase letters");
        }
    }
}

string User::getUserName() {
    // TODO: implement getter
    return this-> userName;
}

vector<Post*>& User::getUserPosts() {
    // TODO: implement getter
    return this-> userPosts;
}

void User::addUserPost(Post* post) {
    // TODO: add post to user posts
    if (post == nullptr) {
        throw std::invalid_argument("no posts to add");
    }
    else {
        userPosts.push_back(post);
    }
}
