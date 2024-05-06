# include <iostream>
# include <string>
# include <stdexcept>
# include <sstream>
# include "Post.h"

using std::string, std::vector;

Post::Post(unsigned int postId, string userName, string postText) : postId(postId), userName(userName), postText(postText) {
    if (postId == 0 || userName == "" || postText == "") {
        throw std::invalid_argument("post constructor: invalid parameter values");
    }
}

unsigned int Post::getPostId() {
    return postId;
}

string Post::getPostUser() {
    return userName;
}

string Post::getPostText() {
    return postText;
}

vector<string> Post::findTags() {
    // TODO: extracts candidate tags based on occurrences of # in the post
    std::stringstream ss(postText);
    vector<string> tags = {};
    string buffer;

    while(!ss.eof()) {
        ss >> buffer;
        if (buffer[0] == '#') {
            //clear buffer of extra punctuation
            for (unsigned int i = buffer.size() - 1; i > 0; i--) {
                switch (buffer[i])
                {
                case '?':
                case '.':
                case ',':
                case '!': //not supposed to filter these cases if they aren't on the end
                    if (i == buffer.size() - 1) {
                        buffer.pop_back();
                    }
                    break;
                default:
                    if (isupper(buffer[i])) {
                        tolower(buffer[i]);
                    }
                    break;
                }
            }
        
        tags.push_back(buffer);
        }
        buffer = "";


    }
    return tags;

}
