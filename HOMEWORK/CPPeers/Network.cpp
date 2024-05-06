# include <iostream>
# include <fstream>
# include <sstream>
# include <stdexcept>
# include "Network.h"

using std::string, std::vector;

Network::Network() : users{}, posts{}, tags{} {}

void Network::loadFromFile(string fileName) {
    // TODO: load user and post information from file
    std::ifstream dataList;
    dataList.open(fileName);

    if (dataList.fail()) {
        throw std::invalid_argument("file couldn't be opened");
    }

    while(!dataList.eof()) {
        string buffer;
        dataList >> buffer;
        if (buffer.empty()) {
                    break;
                }

        try {
            if (buffer == "User") {
                dataList >> buffer;
                addUser(buffer);
            }
            else if (buffer == "Post") {
                

                unsigned int postId;
                string userName;
                string postText;

                dataList >> postId >> userName;
                getline(dataList, postText);


                if (dataList.fail()) {
                    throw std::runtime_error("post format incorrect");
                }

                addPost(postId, userName, postText);
            }
            else {
                std::cout << buffer << std::endl;
                throw std::runtime_error("bad file format");
            }
        }
        catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
            throw std::runtime_error("");
        }
    }
    
}

void Network::addUser(string userName) {
    // TODO: create user and add it to network
    for (unsigned int i = 0; i < userName.size(); i++) {
        if (isupper(userName[i])) {
            tolower(userName[i]);
        }
    }


    for (unsigned int i = 0; i < users.size(); i++) {
        if (userName == users[i]->getUserName()) {
            throw std::invalid_argument("username already taken");
        }
    }
    
    users.push_back(new User(userName));
    std::cout << "Added User " << userName << std::endl;

}

void Network::addPost(unsigned int postId, string userName, string postText) {
    // TODO: create post and add it to network
    bool userExists = false;
    int userIndex;
    int postIndex;
    int tagIndex;

    for (unsigned int i = 0; i < posts.size(); i++) {
        if (postId == posts[i]->getPostId()) {
            throw std::invalid_argument("post ID already exists");
        }
    }

    for (unsigned int i = 0; i < users.size(); i++) {
        if (userName == users[i]->getUserName()) {
            userExists = true;
            userIndex = i;
        }
    }

    if (userExists == false) {
        throw std::invalid_argument("no user exists for this post");
    }
    Post* newPost = new Post(postId, userName, postText);
    posts.push_back(newPost);
    postIndex = posts.size() - 1;
    users[userIndex]->addUserPost(newPost);

    vector<string> tags = posts[postIndex]->findTags();

    for (unsigned int i = 0; i < tags.size(); i++) {
        bool tagExists = false;
        for (unsigned int j = 0; j < this->tags.size(); j++) {
            if (this->tags[j]->getTagName() == tags[i]) {
                tagExists = true;
                tagIndex = j;
            }
        }
        if (!tagExists) {
            try {
                this->tags.push_back(new Tag(tags[i]));
                this->tags[this->tags.size() - 1]->addTagPost(newPost);
            }
            catch(string error) {
                throw std::runtime_error("bad tag");
            }
        }
        else {
            this->tags[tagIndex]->addTagPost(newPost);
        }

    }

    std::cout << "Added Post " << postId << " by " << userName << std::endl;

}

vector<Post*> Network::getPostsByUser(string userName) {
    // TODO: return posts created by the given user
    if (userName == "") {
        throw std::invalid_argument("username is empty");
    }

    for (User* u : users) {
        if (u->getUserName() == userName) {
            return u->getUserPosts();
        }
    }
    throw std::invalid_argument("no user found");
}

vector<Post*> Network::getPostsWithTag(string tagName) {
    // TODO: return posts containing the given tag
    if (tagName == "") {
        throw std::invalid_argument("tag is empty");
    }

    for (Tag* t : tags) {
        if (t->getTagName() == tagName) {
            return t->getTagPosts();
        }
    }
    throw std::invalid_argument("no tag found");

}

vector<string> Network::getMostPopularHashtag() {
    // TODO: return the tag occurring in most posts
    vector<string> mostTags = {tags[0]->getTagName()};
    int mostTagsIndexs = 0;

    if (tags.empty()) {
        return {};
    }

    for (unsigned int i = 1; i < tags.size(); i++) {
        if (tags[i]->getTagPosts().size() > tags[mostTagsIndexs]->getTagPosts().size()) {
            mostTags = {tags[i]->getTagName()};
            mostTagsIndexs = i;
        }
        else if (tags[i]->getTagPosts().size() == tags[mostTagsIndexs]->getTagPosts().size()) {
            mostTags.push_back(tags[i]->getTagName());
        }
    }

    return mostTags;
}

Network::~Network() {
    for (unsigned int i = 0; i < users.size(); ++i) {
        delete users.at(i);
    }

    for (unsigned int i = 0; i < tags.size(); ++i) {
        delete tags.at(i);
    }
    
    for (unsigned int i = 0; i < posts.size(); ++i) {
        delete posts.at(i);
    }
}
